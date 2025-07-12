// #include "DFRobot_PH.h"
// #include <EEPROM.h>
// #include "GravityTDS.h"
// #include <DallasTemperature.h>
// #include <OneWire.h>
// #define CAYENNE_DEBUG       // Uncomment to show debug messages
// #define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space
// #include <CayenneMQTTESP8266Shield.h>

// //for Ultrasonic Sensor
// int trigPin = 5;
// int echoPin = 4;
//  int duration, distance, height;

// //pH sensor
// #define PH_PIN A1
// float voltage, phValue, temperature = 25;
// DFRobot_PH ph;

// //Temperature. sensor
// #define ONE_WIRE_BUS 3
// OneWire oneWire(ONE_WIRE_BUS);
// DallasTemperature sensors(&oneWire);
//  float Celcius=0;
//  float Fahrenheit=0;
//  float temp;

//  //for turbidity
//  float turb;

// // WiFi network info.
// char ssid[] = "Moyin";
// char wifiPassword[] = "1234567890";

// // Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
// char username[] = "fa41ee80-ea45-11eb-b767-3f1a8f1211ba";
// char password[] = "5b1b558fc19b1e79aa845d1d032ae8d07b303b94";
// char clientID[] = "beca9890-f3e9-11eb-883c-638d8ce4c23d";

// // Set ESP8266 Serial object. In this example we use the Serial1 hardware serial which is available on boards like the Arduino Mega.
// #define EspSerial Serial1
// ESP8266 wifi(&EspSerial);

// #define VIRTUAL_CHANNEL 7
// #define ACTUATOR_PIN 9
// int buttonSense = 11;
//  int pump = 6;
 
//  // constants won't change. Used here to set a pin number:
// const int ledPin =  8;// the number of the LED pin

// // Variables will change:
// int ledState = LOW;             // ledState used to set the LED

// // Generally, you should use "unsigned long" for variables that hold time
// // The value will quickly become too large for an int to store
// unsigned long previousMillis = 0;        // will store last time LED was updated

// // constants won't change:
// const long interval = 1000; 

// //for flow meter
// int flowPin = 2;
// double flowRate;
// volatile int count;
// bool pumpState = 0;
// int flow;


// void setup() {
//      ph.begin();
//   sensors.begin();
//    pinMode(flowPin, INPUT);
//   attachInterrupt(digitalPinToInterrupt(2), Flow, RISING);
//   pinMode(pump, OUTPUT);
//    pinMode(trigPin, OUTPUT);
//   pinMode(echoPin, INPUT);
//   pinMode(ledPin, OUTPUT);
//   pinMode(ACTUATOR_PIN, OUTPUT);
//    pinMode(buttonSense, INPUT_PULLUP);

//   digitalWrite(pump, LOW);

//   Serial.begin(9600);
//   delay(10);
//   EspSerial.begin(9600);
//   delay(10); 
//    Cayenne.begin(username, password, clientID, wifi, ssid, wifiPassword);
// }


// void blinkk(){
//    unsigned long currentMillis = millis();

//   if (currentMillis - previousMillis >= interval) {
//     // save the last time you blinked the LED
//     previousMillis = currentMillis;

//     // if the LED is off turn it on and vice-versa:
//     if (ledState == LOW) {
//       ledState = HIGH;
//     } else {
//       ledState = LOW;
//     }

//     // set the LED with the ledState of the variable:
//     digitalWrite(ledPin, ledState);
//   }
// }

// void uSensor(){
//     digitalWrite (trigPin, HIGH);
//   delayMicroseconds (1000);
//   digitalWrite (trigPin, LOW);
//   duration = pulseIn (echoPin, HIGH);
//   distance = (duration/2) / 29.1;   
//   distance = map(distance, 2.00, 15.00, 100.00, 0.00);
// distance = constrain(distance, 0.00, 100.00);
// }

// void turbidity() {
// int sensorValue = analogRead(A2);// read the input on analog pin 0:
//   float voltage = sensorValue * (5.0 / 1024.0); 
//   turb = voltage; 
//  // Serial.println(turb);
// }

// void flowMeter() {
//   // put your main code here, to run repeatedly:
//   count = 0;      // Reset the counter so we start counting from 0 again
//   interrupts();   //Enables interrupts on the Arduino
//   delay (1000);   //Wait 1 second
//   noInterrupts(); //Disable the interrupts on the Arduino

//   //Start the math
//   //Take counted pulses in the last second and multiply by 2.25mL
//   flowRate = (count * 2.25);
//   //Convert seconds to minutes, giving you mL / Minute
//   flowRate = flowRate * 60;
//   //Convert mL to Liters, giving you Liters / Minute
//   flowRate = flowRate / 1000;
//   flow = (int)(flowRate);
// }

// void pHSensor() {
//   static unsigned long timepoint = millis();
//   if (millis() - timepoint > 1000U) {            //time interval: 1s
//     timepoint = millis();
//     //temperature = readTemperature();         // read your temperature sensor to execute temperature compensation
//     voltage = analogRead(PH_PIN) / 1024.0 * 5000; // read the voltage
//     phValue = ph.readPH(voltage, temperature); // convert voltage to pH with temperature compensation
//   }
//   ph.calibration(voltage, temperature);          // calibration process by Serail CMD
// }




// void loop() {
//    Cayenne.loop();
//    uSensor();
//   turbidity();
//   pHSensor();
//   blinkk();
//   flowMeter();

//  sensors.requestTemperatures(); 
// Celcius=sensors.getTempCByIndex(0);
// Fahrenheit=sensors.toFahrenheit(Celcius);
//  temp = Celcius;

// int sensorVal = digitalRead(buttonSense);
//  if (sensorVal == LOW) {
//  if(distance <= 7){
//     digitalWrite(pump, HIGH);
//   //  pumpState = 1;
//   }

//    if(distance >= 87){
//     digitalWrite(pump, LOW);
//    // pumpState = 0;
//   } 
//  }

// if (sensorVal == HIGH){
//     Serial.println("Manual Override");
//   } 

//   //Serial.println(String(phValue) +  "," + String(temp) + "," + String(turb) + "," + String(distance));
//   //delay(1000);
// } 

// void Flow() {
//   //Every time this function is called, increment "count" by 1
//   count++;
// }

// CAYENNE_OUT(1)
// {
//     Cayenne.virtualWrite(1,phValue);
//     Cayenne.virtualWrite(2,turb); 
//     Cayenne.virtualWrite(3,temp); 
//     Cayenne.virtualWrite(4,distance); 
//     Cayenne.virtualWrite(5,flowRate); 
    
// }

// CAYENNE_IN(VIRTUAL_CHANNEL){
//   CAYENNE_LOG("Channel %u, value %s", request.channel, getValue.asString());
//   int value = getValue.asInt();
//   Serial.println(value);
//  digitalWrite(ACTUATOR_PIN, value);
  
//   if( value == 1){
//   digitalWrite(pump, HIGH); 
// }
// if(value != 1){
//   digitalWrite(pump, LOW); 
//   }
  
//   }














#include "DFRobot_PH.h"               // Library for DFRobot pH sensor
#include <EEPROM.h>                   // Used to store calibration data
#include "GravityTDS.h"               // (Optional) for TDS sensor (not used in current code)
#include <DallasTemperature.h>        // For DS18B20 temperature sensor
#include <OneWire.h>                  // Needed for DallasTemperature library
#define CAYENNE_DEBUG                 // Enable Cayenne debug prints
#define CAYENNE_PRINT Serial          // Enable printing to Serial for Cayenne
#include <CayenneMQTTESP8266Shield.h> // Cayenne library for ESP8266 Wi-Fi shield

// ----- Ultrasonic Sensor -----
int trigPin = 5;                      // Trigger pin for ultrasonic
int echoPin = 4;                      // Echo pin for ultrasonic
int duration, distance, height;       // Variables for distance measurement

// ----- pH Sensor -----
#define PH_PIN A1                     // Analog pin A1 used for pH
float voltage, phValue, temperature = 25;
DFRobot_PH ph;                        // pH sensor object

// ----- Temperature Sensor (DS18B20) -----
#define ONE_WIRE_BUS 3                // OneWire bus on pin 3
OneWire oneWire(ONE_WIRE_BUS);       
DallasTemperature sensors(&oneWire);  // DS18B20 sensor setup
float Celcius = 0, Fahrenheit = 0, temp; // Temperature variables

// ----- Turbidity Sensor -----
float turb;                           // Turbidity sensor reading (from A2)

// ----- WiFi Info -----
char ssid[] = "Moyin";               // WiFi SSID
char wifiPassword[] = "1234567890";  // WiFi password

// ----- Cayenne Auth Info -----
char username[] = "YOUR_USERNAME";
char password[] = "YOUR_PASSWORD";
char clientID[] = "YOUR_CLIENT_ID";

// ESP8266 Serial connection setup (Arduino Mega uses Serial1)
#define EspSerial Serial1
ESP8266 wifi(&EspSerial);             // ESP8266 WiFi object

// ----- Virtual Channels and Actuators -----
#define VIRTUAL_CHANNEL 7             // Cayenne virtual channel
#define ACTUATOR_PIN 9                // Pin connected to relay/pump
int buttonSense = 11;                 // Physical switch input pin
int pump = 6;                         // Pump control pin

// ----- LED Blinking Setup -----
const int ledPin = 8;                 // LED pin (for blinking)
int ledState = LOW;                  // LED state toggle
unsigned long previousMillis = 0;    // Store last time LED changed
const long interval = 1000;          // Interval in ms for blinking

// ----- Flow Meter -----
int flowPin = 2;                     // Flow meter sensor pin
double flowRate;                     // Flow rate in L/min
volatile int count;                  // Pulse count from flow meter
int flow;                            // Flow as integer
bool pumpState = 0;

void setup() {
  ph.begin();                          // Initialize pH sensor
  sensors.begin();                     // Start temperature sensor
  pinMode(flowPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), Flow, RISING); // Count flow meter pulses

  pinMode(pump, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ACTUATOR_PIN, OUTPUT);
  pinMode(buttonSense, INPUT_PULLUP); // Internal pull-up for button

  digitalWrite(pump, LOW);            // Ensure pump is off initially

  Serial.begin(9600);
  EspSerial.begin(9600);
  Cayenne.begin(username, password, clientID, wifi, ssid, wifiPassword); // Connect to Cayenne
}

// ----- LED Blinking Function -----
void blinkk() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
  }
}

// ----- Ultrasonic Sensor Function -----
void uSensor() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1; // Convert to cm
  distance = map(distance, 2, 15, 100, 0); // Convert to %
  distance = constrain(distance, 0, 100);
}

// ----- Turbidity Sensor Function -----
void turbidity() {
  int sensorValue = analogRead(A2);
  float voltage = sensorValue * (5.0 / 1024.0);
  turb = voltage;
}

// ----- Flow Meter Function -----
void flowMeter() {
  count = 0;
  interrupts();
  delay(1000);
  noInterrupts();
  flowRate = (count * 2.25) * 60 / 1000; // mL to L/min
  flow = (int)(flowRate);
}

// ----- pH Sensor Function -----
void pHSensor() {
  static unsigned long timepoint = millis();
  if (millis() - timepoint > 1000U) {
    timepoint = millis();
    voltage = analogRead(PH_PIN) / 1024.0 * 5000;
    phValue = ph.readPH(voltage, temperature);
  }
  ph.calibration(voltage, temperature); // Use serial command to calibrate
}

void loop() {
  Cayenne.loop();           // Handle Cayenne cloud communication
  uSensor();                // Update distance
  turbidity();              // Update turbidity
  pHSensor();               // Update pH value
  blinkk();                 // Blink LED
  flowMeter();              // Calculate flow

  sensors.requestTemperatures();     // Get temperature
  Celcius = sensors.getTempCByIndex(0);
  Fahrenheit = sensors.toFahrenheit(Celcius);
  temp = Celcius;

  int sensorVal = digitalRead(buttonSense);
  if (sensorVal == LOW) {
    if (distance <= 7) digitalWrite(pump, HIGH);
    if (distance >= 87) digitalWrite(pump, LOW);
  } else {
    Serial.println("Manual Override");
  }
}

// Flow meter interrupt: increment count on pulse
void Flow() {
  count++;
}

// Send sensor data to Cayenne
CAYENNE_OUT(1) {
  Cayenne.virtualWrite(1, phValue);
  Cayenne.virtualWrite(2, turb);
  Cayenne.virtualWrite(3, temp);
  Cayenne.virtualWrite(4, distance);
  Cayenne.virtualWrite(5, flowRate);
}

// Receive data from Cayenne (virtual button)
CAYENNE_IN(VIRTUAL_CHANNEL) {
  CAYENNE_LOG("Channel %u, value %s", request.channel, getValue.asString());
  int value = getValue.asInt();
  Serial.println(value);
  digitalWrite(ACTUATOR_PIN, value);
  if (value == 1) digitalWrite(pump, HIGH);
  else digitalWrite(pump, LOW);
}
