/*******
Project: Monitoring Suhu & Kelembaban dengan ESP32, DHT22, Firebase, dan MIT App Inventor
Board: ESP32
Input: DHT22
Output: Firebase -> MIT App Inventor
*******/

#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include "DHT.h"

// Informasi WiFi
#define WIFI_SSID "Tezo"
#define WIFI_PASSWORD "123445679"

// Firebase
#define API_KEY "AIzaSyAES84KaYtKsCEIXBUhvFQ87gZ0Zpj5GKM" // Lihat di Firebase Console > Project Settings > Web API Key
#define DATABASE_URL "https://monitoring-dht22-5065b-default-rtdb.firebaseio.com/" // Tanpa "https://"

#define DHTPIN 5 // GPIO 5 (bukan D5)
#define DHTTYPE DHT11

// Objek untuk Firebase dan DHT
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  delay(1000);
  dht.begin();

  // Koneksi WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Menghubungkan ke WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println("\nTerhubung ke WiFi!");

  // Konfigurasi Firebase
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;

  // Jika tidak perlu autentikasi user, kosongkan email & password
  auth.user.email = "dht11@gmail.com";
  auth.user.password = "123445678";

  // Inisialisasi Firebase
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Gagal membaca dari sensor DHT!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("Humidity: ");
  Serial.println(humidity);

  // Kirim ke Firebase
  if (Firebase.RTDB.setFloat(&fbdo, "Temperature", temperature)) {
    Serial.println("Suhu berhasil dikirim");
  } else {
    Serial.print("Gagal kirim suhu: ");
    Serial.println(fbdo.errorReason());
  }

  if (Firebase.RTDB.setFloat(&fbdo, "Humidity", humidity)) {
    Serial.println("Kelembaban berhasil dikirim");
  } else {
    Serial.print("Gagal kirim kelembaban: ");
    Serial.println(fbdo.errorReason());
  }

  Serial.println("--------");
  delay(5000); // Baca setiap 5 detik
}