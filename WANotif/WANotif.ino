#include <WiFi.h>
#include <ThingerESP32.h>
#include <ESP32Servo.h>
#include <HTTPClient.h>
#include <UrlEncode.h>  // Install via Library Manager

// Thinger.io credentials
#define USERNAME "Tezo"
#define DEVICE_ID "wildan123"
#define DEVICE_CREDENTIAL "Mt1v+M1WL?ymDYh#"

// WiFi credentials
#define SSID "Tezo"
#define PASSWORD "123445679"

ThingerESP32 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

// CallMeBot WhatsApp credentials
String whatsappNumber = "+6285216550347";  // Ganti dengan nomor kamu
String whatsappApiKey = "4466232";         // Ganti dengan API key dari CallMeBot

// Pin definisi
#define TRIG_OPEN 13
#define ECHO_OPEN 12
#define TRIG_FULL 14
#define ECHO_FULL 27
#define SERVO_PIN 26
#define BUZZER_PIN 25
#define LED_HIJAU 32
#define LED_MERAH 33

Servo servo;

float distance_open = 0;
float distance_full = 0;
float persen_penuh = 0;
bool is_full = false;

int threshold_open = 20;
int threshold_full = 10;
int jarak_max_tong = 25;

bool lid_is_opening = false;
unsigned long lid_open_time = 0;
const unsigned long lid_open_duration = 5000;  // waktu buka tutup
const unsigned long open_cooldown = 5000;
unsigned long last_open_trigger = 0;

bool notif_sent = false;

// ===== FUNGSI PENDUKUNG =====
float readUltrasonic(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);
  if (duration == 0) return -1;
  return duration * 0.034 / 2.0;
}

float readAverageUltrasonic(int trigPin, int echoPin, int times = 5) {
  float total = 0;
  int valid = 0;
  for (int i = 0; i < times; i++) {
    float d = readUltrasonic(trigPin, echoPin);
    if (d > 0) {
      total += d;
      valid++;
    }
    delay(20);
  }
  return (valid > 0) ? (total / valid) : -1;
}

// ✅ Servo buka perlahan
void openLid() {
  for (int pos = 0; pos <= 90; pos++) {
    servo.write(pos);
    delay(10); // lebih besar = lebih lambat
  }
  lid_is_opening = true;
  lid_open_time = millis();
  last_open_trigger = millis();
  Serial.println("🚪 Tutup terbuka perlahan.");
}

// ✅ Servo tutup perlahan
void closeLid() {
  for (int pos = 90; pos >= 0; pos--) {
    servo.write(pos);
    delay(10); // lebih besar = lebih lambat
  }
  lid_is_opening = false;
  Serial.println("🤖 Tutup tertutup perlahan.");
}

// ✅ Kirim WhatsApp via CallMeBot
void sendWhatsapp(String message) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = "https://api.callmebot.com/whatsapp.php?phone=" + whatsappNumber +
                 "&text=" + urlEncode(message) + "&apikey=" + whatsappApiKey;

    http.begin(url);
    int httpCode = http.GET();
    if (httpCode == 200) {
      Serial.println("✅ WhatsApp terkirim.");
    } else {
      Serial.print("❌ WhatsApp gagal. Code: ");
      Serial.println(httpCode);
    }
    http.end();
  } else {
    Serial.println("⚠️ WiFi tidak terhubung.");
  }
}

// ===== SETUP =====
void setup() {
  Serial.begin(115200);
  thing.add_wifi(SSID, PASSWORD);

  pinMode(TRIG_OPEN, OUTPUT);
  pinMode(ECHO_OPEN, INPUT);
  pinMode(TRIG_FULL, OUTPUT);
  pinMode(ECHO_FULL, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_HIJAU, OUTPUT);
  pinMode(LED_MERAH, OUTPUT);

  servo.attach(SERVO_PIN);
  closeLid();  // posisi awal tertutup

  // Monitoring endpoint ke Thinger.io
  thing["distance_open"] >> outputValue(distance_open);
  thing["distance_full"] >> outputValue(distance_full);
  thing["persen_penuh"] >> outputValue(persen_penuh);
  thing["full_status"] >> outputValue((int)is_full);

  // Manual buka tutup
  thing["buka_tutup"] << [](pson &in) {
    if ((bool)in && !lid_is_opening && millis() - last_open_trigger > open_cooldown) {
      openLid();
    }
  };

  // Manual kirim email
  thing["send_email"] << [](pson &out) {
    pson data;
    data["level"] = (int)persen_penuh;
    thing.call_endpoint("email_penuh", data);
  };

  // Manual kirim WhatsApp
  thing["send_whatsapp"] << [](pson &out) {
    String msg = "⚠️ Tempat sampah penuh! Level: " + String((int)persen_penuh) + "%";
    sendWhatsapp(msg);
  };
}

// ===== LOOP =====
void loop() {
  thing.handle();

  distance_open = readAverageUltrasonic(TRIG_OPEN, ECHO_OPEN);
  distance_full = readAverageUltrasonic(TRIG_FULL, ECHO_FULL);

  if (distance_full > 0 && distance_full < jarak_max_tong) {
    persen_penuh = ((jarak_max_tong - distance_full) / jarak_max_tong) * 100.0;
    persen_penuh = constrain(persen_penuh, 0, 100);
  } else {
    persen_penuh = 0;
  }

  Serial.print("Tangan: "); Serial.print(distance_open); Serial.print(" cm | ");
  Serial.print("Isi Tong: "); Serial.print(distance_full); Serial.print(" cm | ");
  Serial.print("Persen: "); Serial.print(persen_penuh); Serial.println(" %");

  // Tutup otomatis setelah dibuka
  if (lid_is_opening && millis() - lid_open_time >= lid_open_duration) {
    closeLid();
  }

  // Otomatis buka jika tangan dekat
  if (!lid_is_opening && distance_open > 0 && distance_open < threshold_open &&
      millis() - last_open_trigger > open_cooldown) {
    openLid();
  }

  // Deteksi penuh
  if (distance_full > 0 && distance_full < threshold_full) {
    is_full = true;
    digitalWrite(LED_MERAH, HIGH);
    digitalWrite(LED_HIJAU, LOW);
    digitalWrite(BUZZER_PIN, HIGH);

    if (!notif_sent && WiFi.status() == WL_CONNECTED) {
      // Email
      pson data;
      data["level"] = (int)persen_penuh;
      thing.call_endpoint("email_penuh", data);

      // WhatsApp
      String msg = "🚮 Tong sampah penuh! " + String((int)persen_penuh) + "%";
      sendWhatsapp(msg);

      notif_sent = true;
      Serial.println("📧 Email & WhatsApp dikirim.");
    }
  } else if (distance_full >= threshold_full) {
    is_full = false;
    digitalWrite(LED_MERAH, LOW);
    digitalWrite(LED_HIJAU, HIGH);
    digitalWrite(BUZZER_PIN, LOW);
    notif_sent = false;
  }

  delay(100);  // Delay antar loop
}
