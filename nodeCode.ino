#include <ESP8266WiFi.h> // For ESP8266, use <WiFi.h> for ESP32
#include <ESP8266HTTPClient.h> // For HTTP POST requests

const char* ssid = "your-SSID";      // Replace with your network SSID
const char* password = "your-PASSWORD"; // Replace with your network password

const char* serverName = "http://your-server-ip:5000/predict"; // Replace with your Flask server IP

// Define pins for sensors (Adjust based on your wiring)
const int soilMoisturePin = A0; // Analog pin for soil moisture sensor
const int temperaturePin = D1;  // Digital pin for temperature sensor (assumed)

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {  // Check Wi-Fi connection status
    HTTPClient http;

    // Read sensor data
    int soilMoistureValue = analogRead(soilMoisturePin);
    float temperatureValue = readTemperature();  // Replace with your temperature sensor logic
    int humidityValue = 60;  // Example static value; replace with actual humidity sensor
    int rainfallValue = 20;  // Example static value; replace with actual rainfall sensor
    int growthStage = 2;     // Example static value representing growth stage

    // Create the JSON payload
    String postData = "{";
    postData += "\"Soil Moisture\":" + String(soilMoistureValue) + ",";
    postData += "\"Rainfall\":" + String(rainfallValue) + ",";
    postData += "\"Humidity\":" + String(humidityValue) + ",";
    postData += "\"Temperature\":" + String(temperatureValue) + ",";
    postData += "\"Growth Stage\":" + String(growthStage);
    postData += "}";

    // Start HTTP POST request
    http.begin(serverName);
    http.addHeader("Content-Type", "application/json");

    int httpResponseCode = http.POST(postData);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(httpResponseCode);  // Print response code
      Serial.println(response);          // Print response from the Flask server
    } else {
      Serial.println("Error in sending POST");
    }

    http.end();  // Close connection
  } else {
    Serial.println("WiFi not connected");
  }

  delay(60000);  // Send data every 60 seconds
}

// Example function to read temperature (adjust based on your sensor)
float readTemperature() {
  // Your temperature sensor code here
  return 25.0;  // Return a dummy temperature for now
}
