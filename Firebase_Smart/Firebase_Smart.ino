#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <ESP32Servo.h>

// WiFi dan Firebase Credentials
#define WIFI_SSID "Tezo"
#define WIFI_PASSWORD "123445679"
#define API_KEY "AIzaSyDLBGVqv516Ekrmkppx5qsVIuszkUMMEdE"
#define DATABASE_URL "https://tempatsampahpintar-349ea-default-rtdb.firebaseio.com/"
#define USER_EMAIL "tempatsampah@gmail.com"
#define USER_PASSWORD "123445678"

// Firebase instance
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

// Pin konfigurasi
#define TRIG_OPEN 13
#define ECHO_OPEN 12
#define TRIG_FULL 14
#define ECHO_FULL 27
#define SERVO_PIN 26
#define BUZZER_PIN 25
#define LED_HIJAU 32
#define LED_MERAH 33

Servo servo;

// Variabel sensor dan status
float distance_open = 0;
float distance_full = 0;
float persen_penuh = 0;
bool is_full = false;
String status_tutup = "Tertutup";

int threshold_open = 20;
int threshold_full = 10;
int jarak_max_tong = 25;

bool lid_is_opening = false;
unsigned long lid_open_time = 0;
const unsigned long lid_open_duration = 5000;
const unsigned long open_cooldown = 5000;
unsigned long last_open_trigger = 0;

float readUltrasonic(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH, 30000);
  if (duration == 0) {
    Serial.println("⚠️ Sensor tidak membaca jarak.");
    return -1;
  }
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

void openLid() {
  for (int pos = 0; pos <= 90; pos++) {
    servo.write(pos);
    delay(15); // semakin besar, semakin lambat
  }
  status_tutup = "Terbuka";
  lid_is_opening = true;
  lid_open_time = millis();
  last_open_trigger = millis();
  Serial.println("🚪 Tutup terbuka perlahan.");
}

void closeLid() {
  for (int pos = 90; pos >= 0; pos--) {
    servo.write(pos);
    delay(15); // delay yang sama agar kecepatan seimbang
  }
  status_tutup = "Tertutup";
  lid_is_opening = false;
  Serial.println("🤖 Tutup tertutup perlahan.");
}

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_OPEN, OUTPUT);
  pinMode(ECHO_OPEN, INPUT);
  pinMode(TRIG_FULL, OUTPUT);
  pinMode(ECHO_FULL, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_HIJAU, OUTPUT);
  pinMode(LED_MERAH, OUTPUT);

  servo.attach(SERVO_PIN);
  closeLid();

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\n✅ WiFi Tersambung");

  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  // Hapus node lama jika ada
  Firebase.RTDB.deleteNode(&fbdo, "/lid_status");
}

void loop() {
  // Baca sensor
  distance_open = readAverageUltrasonic(TRIG_OPEN, ECHO_OPEN);
  distance_full = readAverageUltrasonic(TRIG_FULL, ECHO_FULL);

  // Hitung persentase penuh
  if (distance_full > 0 && distance_full < jarak_max_tong) {
    persen_penuh = ((jarak_max_tong - distance_full) / jarak_max_tong) * 100.0;
    persen_penuh = constrain(persen_penuh, 0, 100);
  } else {
    persen_penuh = 0;
  }

  // Deteksi penuh dan atur indikator
  if (distance_full > 0 && distance_full < threshold_full) {
    is_full = true;
    digitalWrite(LED_MERAH, HIGH);
    digitalWrite(LED_HIJAU, LOW);
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    is_full = false;
    digitalWrite(LED_MERAH, LOW);
    digitalWrite(LED_HIJAU, HIGH);
    digitalWrite(BUZZER_PIN, LOW);
  }

  // Kirim ke Firebase
  if (Firebase.ready()) {
    Firebase.RTDB.setFloat(&fbdo, "/distance_open", distance_open);
    Firebase.RTDB.setFloat(&fbdo, "/distance_full", distance_full);
    Firebase.RTDB.setFloat(&fbdo, "/persen_penuh", persen_penuh);
    Firebase.RTDB.setBool(&fbdo, "/is_full", is_full);
    Firebase.RTDB.setString(&fbdo, "/status_tutup", status_tutup);
  }

  // Tutup otomatis jika waktu habis
  if (lid_is_opening && millis() - lid_open_time >= lid_open_duration) {
    closeLid();
  }

  // Deteksi tangan dan buka jika cooldown lewat
  if (!lid_is_opening &&
      distance_open > 0 && distance_open < threshold_open && distance_open < 50 &&
      millis() - last_open_trigger > open_cooldown) {
    openLid();
  }

  delay(200); // lebih responsif
}
