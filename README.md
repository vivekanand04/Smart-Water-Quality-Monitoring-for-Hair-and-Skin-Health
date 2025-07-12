# Smart Water Quality Monitoring System for Hair and Skin Health  
**IoT Internship Project – NIT Arunachal Pradesh (August 2024 – February 2025)**

## 📍 Location
National Institute of Technology (NIT), Arunachal Pradesh

## 🧑‍💻 Role
**IoT Intern** – Smart Water Quality Monitoring for Hair and Skin Health

## 📝 Overview
This project focused on building a real-time IoT-based **Smart Water Quality Monitoring System** aimed at identifying water quality issues contributing to hair and skin problems among students. The system uses multiple sensors to monitor key water parameters and provides actionable insights via a cloud dashboard.

## 🎯 Objectives
- Monitor **pH**, **turbidity**, **temperature**, **flow rate**, and **water level** using sensors.
- Identify correlations between water quality and hair/skin complaints.
- Provide real-time data to a cloud dashboard using **Cayenne IoT platform**.
- Automatically control a water pump based on tank levels and water quality.
- Helped 23% of NIT AP students improve water usage habits and reduce hair-related issues.

## 🔧 Hardware Components
- Arduino Mega
- ESP8266 WiFi Shield
- pH Sensor (DFRobot)
- Turbidity Sensor
- DS18B20 Temperature Sensor
- Ultrasonic Sensor (for water level)
- Flow Meter
- Relay Module
- LED and Push Button

## ☁️ Cloud Platform
- **Cayenne IoT Dashboard** for real-time visualization and control
- MQTT protocol for lightweight communication

## 💻 Features
- Real-time sensor data upload (pH, turbidity, temperature, flow, and level)
- Automated pump control based on water level and quality
- Remote monitoring and actuator control via Cayenne cloud
- Manual override for safety and manual testing

## 🧠 Impact
- Enabled data-driven decisions on water usage
- Reduced hair/skin health complaints among 23% of students
- Promoted awareness about water quality among campus residents

## 🧾 Code Highlights
```cpp
// pH, temperature, turbidity, and ultrasonic sensor interfacing
// Cloud integration via CayenneMQTTESP8266Shield
// Relay-controlled pump with automated/manual modes
// Flow meter interrupt-based monitoring
// Virtual dashboard display using Cayenne.virtualWrite()



📸 Real-Time Parameters Displayed on Cayenne
Virtual Channel 1: pH Value

Virtual Channel 2: Turbidity

Virtual Channel 3: Temperature (°C)

Virtual Channel 4: Water Level (%)

Virtual Channel 5: Flow Rate (L/min)

👨‍🔧 Contributors
Vivekanand Kumar
IoT Intern, NIT Arunachal Pradesh
(August 2024 – February 2025)

🧪 Future Enhancements
Integrate Total Dissolved Solids (TDS) sensor
Predictive alerts using ML models for early detection of contamination
SMS or mobile notifications for unsafe water


## 📊 Survey Data

You can view the anonymized student water-related health survey here:  
👉 https://docs.google.com/spreadsheets/d/14DOPfDya3wGvnnWgs--PPDJaNzK_DbNzGPdlZrSlbxM/edit?usp=sharing

