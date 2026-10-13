#include <Wire.h>
#include <DHT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// DHT11 settings
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// OLED settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

void setup() {
  Serial.begin(9600);

  // Start DHT11
  dht.begin();

  // Start OLED
  if (!display.begin(
        SSD1306_SWITCHCAPVCC,
        OLED_ADDRESS)) {
    Serial.println("OLED not found!");

    while (true) {
      delay(100);
    }
  }

  // Startup message
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 10);
  display.println("Temp & Humidity");
  display.println();
  display.println("Monitoring...");
  display.display();

  delay(2000);
}

void loop() {
  // Read sensor values
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);

  // Check sensor readings
  if (isnan(humidity) || isnan(temperature)) {
    display.println("SENSOR ERROR!");
    display.println();
    display.println("Check DHT11");
    display.println("DATA pin: D2");
    display.display();

    Serial.println("Failed to read DHT11!");

    delay(2000);
    return;
  }

  // Display temperature
  display.println("TEMP & HUMIDITY");
  display.println("----------------");

  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print("Temp: ");
  display.print(temperature, 1);
  display.print(" C");

  // Display humidity
  display.setCursor(0, 44);
  display.print("Hum: ");
  display.print(humidity, 0);
  display.print("%");

  // Send display content to OLED
  display.display();

  // Serial Monitor output
  Serial.print("Temperature: ");
  Serial.print(temperature, 1);
  Serial.print(" C | Humidity: ");
  Serial.print(humidity, 1);
  Serial.println(" %");

  // Update interval
  delay(2000);
}