#include <Arduino.h>
// Tes Motor Driver BTS7960 dengan STM32F103C8 (Blue Pill)
// Framework Arduino (PlatformIO)

#define L_EN   PA0     // Enable kiri
#define R_EN   PA1     // Enable kanan
#define L_PWM  PA8     // PWM kiri (maju)
#define R_PWM  PA9     // PWM kanan (mundur)
#define LED_PIN PC13  // Pin LED bawaan

void setup() {
  // Inisialisasi Serial Monitor
  Serial.begin(115200);
  delay(1000);
  Serial.println("=== Tes Motor Driver BTS7960 STM32F103C8 ===");

  // Set pin sebagai output
  pinMode(L_EN, OUTPUT);
  pinMode(R_EN, OUTPUT);
  pinMode(L_PWM, OUTPUT);
  pinMode(R_PWM, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  // Aktifkan driver
  digitalWrite(L_EN, HIGH);
  digitalWrite(R_EN, HIGH);

  Serial.println("Driver BTS7960 aktif, siap menguji motor...");
}

void loop() {
  // Putar maju
  Serial.println("Motor berputar MAJU dengan duty 200/255");
  analogWrite(L_PWM, 200);   // PWM duty cycle ~78%
  analogWrite(R_PWM, 0);
  digitalWrite(LED_PIN, LOW);
  delay(3000);

  // Berhenti
  Serial.println("Motor BERHENTI");
  analogWrite(L_PWM, 0);
  analogWrite(R_PWM, 0);
  digitalWrite(LED_PIN, HIGH);
  delay(2000);

  // Putar mundur
  Serial.println("Motor berputar MUNDUR dengan duty 200/255");
  analogWrite(L_PWM, 0);
  analogWrite(R_PWM, 200);
  digitalWrite(LED_PIN, LOW);
  delay(3000);

  // Berhenti
  Serial.println("Motor BERHENTI");
  analogWrite(L_PWM, 0);
  analogWrite(R_PWM, 0);
  digitalWrite(LED_PIN, HIGH); 
  delay(2000);
}