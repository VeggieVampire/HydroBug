#include <SoftwareSerial.h>  // [ADD] Include library for software-based serial communication

// [DEFINE] HC-12 module pin configuration
#define ARDUINO_TX 8  // [CONFIG] Arduino TX pin connected to HC-12 RX
#define ARDUINO_RX 7  // [CONFIG] Arduino RX pin connected to HC-12 TX
#define SENSOR_PIN A0 // [CONFIG] Analog pin used for water level sensor

// [INIT] Initialize software serial for HC-12 communication
SoftwareSerial hc12(ARDUINO_TX, ARDUINO_RX);  // TX, RX

// [DEFINE] Thresholds for water detection
const int threshold = 200;        // [SET] Minimum level to detect water presence
const int fullWaterLevel = 600;   // [SET] Level to trigger full water alert

void setup() {
  Serial.begin(9600);       // [INIT] Begin Serial monitor communication for debugging
  hc12.begin(9600);         // [INIT] Begin HC-12 communication at 9600 baud
  pinMode(SENSOR_PIN, INPUT); // [CONFIG] Set sensor pin as input
  Serial.println("HydroBug Monitoring Started"); // [INFO] System startup message
}

void loop() {
  // [READ] Get current sensor value from analog pin
  int sensorValue = analogRead(SENSOR_PIN);
  Serial.print("Sensor Value: ");            // [DEBUG] Print raw sensor reading
  Serial.println(sensorValue);

  // [LOGIC] Determine water status based on sensor value
  String message = "";
  if (sensorValue > fullWaterLevel) {
    message = "FULL WATER DETECTED: " + String(sensorValue); // [ALERT] Full water warning
  } else if (sensorValue > threshold) {
    message = "WATER DETECTED: " + String(sensorValue);      // [ALERT] Water presence warning
  }

  // [TRANSMIT] Send message over HC-12 if water was detected
  if (message != "") {
    delay(100);  // [WAIT] Brief delay to stabilize signal
    hc12.println(message);                      // [SEND] Send alert wirelessly via HC-12
    Serial.println("📤 Sent via HC-12: " + message); // [DEBUG] Confirm transmission
  }

  delay(1000);  // [WAIT] Wait 1 second before next reading
}
