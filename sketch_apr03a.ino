#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

// OLED display settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SH1106 display(OLED_RESET);

// Noise sensor analog input pin
#define NOISE_SENSOR_PIN A0

// Noise level mapping (adjust based on sensor output)
#define MIN_ANALOG 0      // Minimum analog value from sensor
#define MAX_ANALOG 1023   // Maximum analog value from sensor
#define MIN_DB 30         // Minimum dB value
#define MAX_DB 120        // Maximum dB value

// Moving average filter settings
#define SAMPLE_COUNT 5    // Number of samples for smoothing

void setup() {
    Serial.begin(115200);

    // Increase ADC speed (optional)
    ADCSRA = (1 << ADEN) | (1 << ADPS2);  // Set ADC prescaler to 16 for faster readings

    // Initialize OLED display
    display.begin(SH1106_I2C_ADDRESS, 0x3C);
    display.clearDisplay();
    
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(10, 20);
    display.println("Noise Meter");
    display.display();
    delay(1000);
}

void loop() {
    float avgSensorValue = 0;
    
    // Take multiple readings to smooth out noise fluctuations
    for (int i = 0; i < SAMPLE_COUNT; i++) {
        avgSensorValue += analogRead(NOISE_SENSOR_PIN);
    }
    avgSensorValue /= SAMPLE_COUNT; // Calculate the average

    float noiseLevel = map(avgSensorValue, MIN_ANALOG, MAX_ANALOG, MIN_DB, MAX_DB);  // Map to dB

    // Display the noise level
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(10, 10);
    display.print("Noise Level:");

    display.setCursor(30, 35);
    display.setTextSize(2);
    display.print(noiseLevel, 1);  // Display one decimal place
    display.print(" dB");

    display.display();

    Serial.print("Sensor Avg Value: ");
    Serial.print(avgSensorValue);
    Serial.print("  -> Noise Level: ");
    Serial.print(noiseLevel);
    Serial.println(" dB");

    delay(100); // Faster response time
}
