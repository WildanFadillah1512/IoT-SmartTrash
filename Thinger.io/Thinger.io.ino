/***************************************
 * Project Monitoring Suhu Kelembaban dg thinger.io
 * Board  : NodeMCU ESP8266 V3
 * Input  : DHT11
 * Output : thinger.io
 * 99 Proyek IoT
 * www.ardutech.com
 ****************************************/
#include <DHT.h>
#include <ThingerESP32.h>
//---GANTI SESUAI DENGAN USER NAME Thinger.io  ANDA
#define USERNAME "Tezo" 
//---GANTI SESUAI DENGAN DEVICE ID Thinger.io  ANDA
#define DEVICE_ID "MonDHT11" 
//---GANTI SESUAI DENGAN TOKEN Thinger.io  ANDA
#define DEVICE_CREDENTIAL "xb9BvClao2XdsK$Y"
//---GANTI SESUAI DENGAN JARINGAN WIFI
//---HOTSPOT ANDA
#define SSID "Tezo"       // Nama Hotspot/WiFi
#define SSID_PASSWORD "123445679"  //  Password

#define DHTPIN 5
#define DHTTYPE DHT11

ThingerESP32 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);
DHT dht(DHTPIN, DHTTYPE);
float hum,temp;
//======================================
void setup() {
  Serial.begin(9600);
  Serial.println("Baca DHT11");
  dht.begin();
  thing.add_wifi(SSID, SSID_PASSWORD);
  thing["dht11"] >> [](pson& out){
    out["humidity"] = hum;
    out["celsius"] = temp;
  };
}
//======================================
void loop() {  
  thing.handle();  
  float h = dht.readHumidity(); 
  float t = dht.readTemperature(); 
  float f = dht.readTemperature(true); 
  hum = h;
  temp = t;
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" *C");

  delay(2000);
}