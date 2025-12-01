#include <ESP32Servo.h>

#define TRIG_PIN 23
#define ECHO_PIN 22
#define SERVO_PIN 26

Servo servo;

long duration;
float distance;

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  servo.setPeriodHertz(50);
  servo.attach(SERVO_PIN, 500, 2400);  // Pulse width utk SG90
  servo.write(0); // Posisi awal tertutup
}

void loop() {
  // Trigger ultrasonic
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance < 20) {
    servo.write(180);  // Buka
    delay(3000);       // Tunggu 3 detik
    servo.write(100);   // Tutup
  }
 
  delay(500);
}
