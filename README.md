
# Smart Fertilizer Management System 🌱

### Tackling Environmental Pollution from Fertilizers

We are a team of students from LBSITW aiming to address the environmental challenges posed by excessive use of fertilizers in agriculture. Our solution focuses on optimizing fertilizer use while maintaining healthy crop growth and reducing soil degradation.

### 🌿 Problem Overview

Excessive fertilizer use degrades soil quality by killing essential microbes and disturbing the ecosystem. On the other hand, insufficient fertilizers lead to poor crop health. Our project empowers farmers to monitor soil nutrients in real-time and apply the optimal amount of fertilizer.

### 🚜 Solution

Our system leverages sensors and machine learning to provide farmers with actionable insights into their soil’s nutrient levels:

- **Sensors Used:**
  - Soil Moisture Sensor
  - NPK Sensor (measures Nitrogen, Phosphorus, Potassium levels)
  - Temperature & Humidity Sensor

- **Data Processing:**
  - Sensor data (soil moisture, nitrogen, phosphorus, potassium, temperature, and humidity) is collected and sent to an MCU.
  - The MCU transmits the data to a Flask server for processing.
  
- **Machine Learning Model:**
  - Using the **Scikit-Learn** library, a Random Forest regression model analyzes the data and predicts the optimal amount of fertilizer needed.
  
- **User Interface:**
  - Farmers can access these predictions through an easy-to-use interface on their device, enabling them to apply the right amount of fertilizer for sustainable farming.

### 🛠️ Tech Stack

- **Backend**: Flask
- **Machine Learning**: Scikit-Learn (Random Forest)
- **Hardware**: MCU, Soil Sensors (NPK, Moisture), Temperature & Humidity Sensors
- **Data Storage**: Flask Server
- **User Interface**: Device-based interface for farmers

### 🚀 Goal

Our project aims to reduce the environmental impact of fertilizers by giving farmers the tools to monitor their soil health and apply only the necessary amount of nutrients.

![Launch Screen](https://github.com/user-attachments/assets/f979baa0-99e2-4863-ba30-b7a188377058)
