# Temp-Humidity-Monitor

Arduino DHT11 temperature & humidity monitor with 0.96" I2C OLED display (128x64, SSD1306).

![Circuit](Screenshot%202026-10-14%20001424.png)

## Components
- Arduino Uno
- DHT11 temperature & humidity sensor
- 0.96" I2C OLED display (SSD1306, 128x64)
- Jumper wires, breadboard

## Wiring
| Component | Arduino Pin |
|-----------|-------------|
| OLED VCC | 5V |
| OLED GND | GND |
| OLED SDA | A4 |
| OLED SCL | A5 |
| DHT11 DATA | D2 |
| DHT11 VCC | 5V |
| DHT11 GND | GND |

## Libraries
Install from Arduino Library Manager:
- Adafruit SSD1306
- Adafruit GFX Library
- DHT sensor library (Adafruit)
- Adafruit Unified Sensor

## How it works
The DHT11 is read every 2 seconds. Temperature (°C) and humidity (%) are shown on the OLED and printed to the Serial Monitor (9600 baud). If the sensor cannot be read, an error message is displayed.

## Files
- `dht11_oled_monitor.ino`: main Arduino sketch
- `diagram.json`, `libraries.txt`, `wokwi-project.txt`: Wokwi simulation files

## Simulation
Open `diagram.json` in [Wokwi](https://wokwi.com) to simulate the project online.

## License
MIT License
