# 🛡️ STM32 Smart Home Hub

An advanced IoT-based Smart Home Monitoring system developed using the **STM32F103C8T6 (Blue Pill)**. This project integrates environmental sensing with security monitoring, featuring real-time data visualization on an I2C-enabled LCD.

## 🌟 Features
* **Real-time Environmental Monitoring:** Tracks Temperature and Humidity using the DHT22 sensor.
* **Intruder Detection:** Utilizes a PIR (Passive Infrared) sensor to detect motion.
* **Visual & Serial Alerts:** On-board LED (PC13) and Serial Monitor alerts when motion is detected.
* **Optimized I2C Communication:** Uses a 16x2 LCD with an I2C backpack to minimize wiring (SDA/SCL).
* **Wokwi Simulation Ready:** Optimized for cloud-based hardware simulation.

## 🛠️ Hardware Components
* **Microcontroller:** STM32F103C8T6 (Blue Pill)
* **Display:** I2C LCD 16x2
* **Climate Sensor:** DHT22 (Digital Temperature & Humidity)
* **Motion Sensor:** PIR Sensor
* **Indication:** On-board LED (PC13)

## 📡 Pin Mapping
| Component | Pin | Function |
| :--- | :--- | :--- |
| **I2C LCD SDA** | PB7 | I2C Data Line |
| **I2C LCD SCL** | PB6 | I2C Clock Line |
| **DHT22 Data** | PA0 | Climate Input |
| **PIR Output** | PA1 | Motion Input |
| **On-board LED** | PC13 | Alarm Indicator |

## 💻 Software Dependencies
The following libraries must be installed in the environment:
1.  `LiquidCrystal I2C` by Frank de Brabander
2.  `DHT sensor library` by Adafruit
3.  `Adafruit Unified Sensor` (Dependency)

## 🚀 How to Run (Wokwi)
1.  Upload `sketch.cpp` and `diagram.json` to a Wokwi STM32 project.
2.  Add the required libraries via the **Library Manager**.
3.  Click the **Green Play Button** to start the simulation.
4.  Interact with the sensors:
    * Click DHT22 to change Temperature/Humidity.
    * Click PIR to simulate Motion.

## 📜 Academic Context
This project was developed as part of an **Embedded Systems** portfolio, demonstrating knowledge in:
* I2C Communication Protocols.
* Register-level pin configuration (GPIO).
* Hardware Abstraction Layer (HAL) implementation.
* IoT system architecture and sensor interfacing.

