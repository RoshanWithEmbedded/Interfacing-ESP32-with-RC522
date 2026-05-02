//ESP32+RC522+LED+BUZEER
#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 5
#define RST_PIN 27
#define LED 2
#define BUZZER 4

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

String authorizedUID = "83 8B B2 4D";

void setup() {
  Serial.begin(115200);
  SPI.begin();
  mfrc522.PCD_Init();
  delay(500);

  lcd.init();
  lcd.backlight();

  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  lcd.print("Scan Your Card");
}

void loop() {

  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  String uid = "";

  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] < 0x10) uid += "0";
    uid += String(mfrc522.uid.uidByte[i], HEX);
    if (i < mfrc522.uid.size - 1) uid += " ";
  }

  uid.toUpperCase();

  Serial.println(uid);

  lcd.clear();
  lcd.setCursor(0, 0);

  if (uid == authorizedUID) {
    lcd.print("Access Granted");

    digitalWrite(LED, HIGH);

    digitalWrite(BUZZER, HIGH);
    delay(300);
    digitalWrite(BUZZER, LOW);

  } else {
    lcd.print("Access Denied");

    digitalWrite(LED, LOW);

    for(int i=0; i<2; i++){
      digitalWrite(BUZZER, HIGH);
      delay(200);
      digitalWrite(BUZZER, LOW);
      delay(200);
    }
  }

  lcd.setCursor(0, 1);
  lcd.print(uid.substring(0,16));

  delay(1500);

  digitalWrite(LED, LOW);
  digitalWrite(BUZZER, LOW);

  lcd.clear();
  lcd.print("Scan Again");

  mfrc522.PICC_HaltA();
}