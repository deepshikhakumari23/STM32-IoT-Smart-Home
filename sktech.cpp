#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h> // Changed this line

// 1. Initialize Objects
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define DHTPIN PA0
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE); // Adafruit style initialization

// 2. Pin Definitions
#define PIR_PIN PA1
#define LED_PIN PC13

void setup() {
  Serial.begin(115200);
  Wire.begin();
  
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  
  // Initialize Sensors
  dht.begin(); // Start Adafruit DHT
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
  // Welcome Screen
  lcd.setCursor(0, 0);
  lcd.print("  SMART HOME   ");
  lcd.setCursor(0, 1);
  lcd.print("   BY SWEETY   ");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read Sensor Data
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  int motion = digitalRead(PIR_PIN);

  // --- Line 1: Temperature & Humidity ---
  lcd.setCursor(0, 0);
  if (isnan(t) || isnan(h)) {
    lcd.print("Sensor Error...");
  } else {
    lcd.print("T:");
    lcd.print(t, 1);
    lcd.print("C  H:");
    lcd.print(h, 0);
    lcd.print("%   ");
  }

  // --- Line 2: Security Status ---
  lcd.setCursor(0, 1);
  if (motion == HIGH) {
    digitalWrite(LED_PIN, LOW); // LED ON
    lcd.print("MOTION DETECTED!");
  } else {
    digitalWrite(LED_PIN, HIGH); // LED OFF
    lcd.print("SYSTEM SECURE   ");
  }

  delay(1000);
}