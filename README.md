# noise_level_oled_arduino-
# 📡 Arduino Noise Monitoring System with OLED Display

This project demonstrates how to **measure environmental noise levels** using an **industrial-grade sound sensor**, an **Arduino**, and an **OLED display**.

It is ideal for monitoring noise in industrial areas, workshops, or near residential zones to ensure safe and acceptable sound levels.

---

## 🎥 Project Demo

[![Watch the video](https://img.youtube.com/vi/FN1mFJYdBtc/0.jpg)](https://youtu.be/FN1mFJYdBtc?si=G6xpxLQDb1qgJhGC)

---

## 🔧 Components Used

- ✅ Arduino Uno (or compatible board)
- ✅ Industrial Sound Sensor (e.g., analog or digital output type)
- ✅ 0.96" I2C OLED Display (SSD1306)
- ✅ Breadboard and jumper wires
- ✅ 5V power supply (or USB)

---

## 📈 Project Features

- 📊 Real-time noise level monitoring
- 📟 Display of sound level (in volts or dB equivalent) on OLED screen
- 🏭 Suitable for industrial or environmental use
- 🚨 Option to trigger alerts for high noise thresholds (future update)

---

## 🧠 How It Works

1. The sound sensor captures noise levels in the environment.
2. The Arduino reads the analog values and processes the data.
3. The processed value is displayed on the OLED screen.
4. (Optional) Threshold-based alerts can be added using LEDs or buzzers.

---

## 📁 Files Included

- `noise_monitor.ino` – Arduino code for reading noise sensor and displaying data
- `README.md` – Project overview and documentation

---

## 📌 Notes

- The OLED uses the I2C protocol (`A4` = SDA, `A5` = SCL on Arduino Uno).
- Make sure to install the `Adafruit_SSD1306` and `Adafruit_GFX` libraries.
- The analog output of the sound sensor should be connected to `A0`.

---

## 🔧 Libraries Required

Install the following libraries via Arduino Library Manager:

```cpp
Adafruit SSD1306
Adafruit GFX
