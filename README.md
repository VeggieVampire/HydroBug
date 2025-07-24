# 💧 HydroBug: Wireless Water Level Alert System

HydroBug is an Arduino-based system that uses an analog water level sensor and an HC-12 wireless module to send water alerts from a remote location to a receiver module. Ideal for monitoring water tanks, sumps, or garden beds without needing internet or Wi-Fi.

---

## 🧰 Features

- 🚰 **Analog water level detection**
- ⚠️ **Threshold-based alerts** for water presence and full-tank warnings
- 📡 **Wireless transmission via HC-12**
- 🖥️ **Debug output to Serial Monitor**
- ⏱️ **1-second polling interval**
- 🧪 Designed for low-power, remote monitoring applications

---

## 🔌 Hardware Used

| Component        | Description                                |
|------------------|--------------------------------------------|
| Arduino (Uno/Nano) | Main microcontroller                      |
| HC-12 Module     | 433MHz wireless serial communication       |
| Water Level Sensor | Analog resistive or capacitive type      |
| Breadboard & Wires | For prototyping                          |
| Power Source     | USB or 5V regulated power                  |

---

## 🖥️ Arduino Pinout

| Arduino Pin | Connected To     |
|-------------|------------------|
| `A0`        | Water level sensor analog output |
| `7`         | HC-12 RX (Arduino receives)      |
| `8`         | HC-12 TX (Arduino transmits)     |
| `5V / GND`  | Power to sensor and HC-12        |

---

## 📟 How It Works

- The sensor provides an analog value (0–1023) based on water level.
- If the reading exceeds `200`, it reports `"WATER DETECTED"`.
- If it exceeds `600`, it sends a `"FULL WATER DETECTED"` message.
- Messages are printed to the Serial Monitor and transmitted wirelessly via HC-12.
- The system checks every second.

---

## 🧾 Code Overview

```cpp
#define ARDUINO_TX 8
#define ARDUINO_RX 7
#define SENSOR_PIN A0
