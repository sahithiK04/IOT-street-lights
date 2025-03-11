#include <Arduino.h>
#include <ESP32Servo.h>

#define LDR_PIN 34       // Analog pin for light sensor (LDR)
#define PIR_PIN 27       // Digital pin for motion sensor (PIR)
#define LED_PIN 25       // Digital pin for LED/Street Light

int ldrValue = 0;         // Stores LDR sensor value
int pirValue = 0;         // Stores PIR sensor value

void setup() {
    pinMode(LDR_PIN, INPUT);
    pinMode(PIR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(115200);
}

void loop() {
    ldrValue = analogRead(LDR_PIN);     // Read light intensity
    pirValue = digitalRead(PIR_PIN);    // Detect motion

    // Conditions for automatic lighting control
    if (ldrValue < 500 && pirValue == HIGH) { // Dark surroundings + Motion detected
        digitalWrite(LED_PIN, HIGH);    // Turn ON street light
        Serial.println("Street Light ON (Motion Detected in Dark)");
    } else {
        digitalWrite(LED_PIN, LOW);     // Turn OFF street light
        Serial.println("Street Light OFF");
    }

    delay(1000); // 1-second delay for stability
}
