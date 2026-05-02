# 🔐 Interfacing ESP32 With RC522 RFID

## 📌 Overview

This project is a smart RFID-based access control system built using ESP32, RC522 RFID module, LCD display, LED, and buzzer. It verifies user identity using RFID cards and provides visual and audio feedback.

---

## ⚙️ Features

* RFID card authentication
* LCD display for status and UID
* LED indication for access status
* Buzzer alert (single beep / double beep)
* Serial monitor debugging

---

## 🧰 Components Used

* ESP32
* RC522 RFID Module
* 16x2 LCD (I2C)
* LED + Resistor
* Buzzer
* Jumper wires

---

## 🔌 Connections

### RC522 → ESP32 (SPI)

| RC522 | ESP32   |
| ----- | ------- |
| SDA   | GPIO 5  |
| SCK   | GPIO 18 |
| MOSI  | GPIO 23 |
| MISO  | GPIO 19 |
| RST   | GPIO 27 |
| GND   | GND     |
| 3.3V  | 3.3V    |

### LCD (I2C)

| LCD | ESP32   |
| --- | ------- |
| VCC | 5V      |
| GND | GND     |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

### LED & Buzzer

* LED → GPIO 2
* Buzzer → GPIO 4

---

## 💡 Working Principle

1. User scans RFID card
2. ESP32 reads UID using RC522
3. UID is compared with authorized UID
4. LCD displays result
5. LED & buzzer give feedback

---

## ▶️ Output

* Access Granted → LED ON + single beep
* Access Denied → LED OFF + double beep

---

## 📸 Project Images

(Add your wiring image here)

---

## 🚀 Future Improvements

* Multiple user support
* Name display instead of UID
* Attendance system
* Cloud logging (IoT)

---

## 👨‍💻 Author

**Embedded With Roshan**
