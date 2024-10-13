/*
Electronics Studio
@file only_Serial.ino
@date  15-08-2024
@url https:https://github.com/electronicsstudio
*/

#include <SoftwareSerial.h>

// The serial connection to the GPS module using pins 10 and 11 on the Nano
SoftwareSerial ss(10, 11); // RX 10, TX 11   this pin i used for Arduino nano

void setup() {
  // Begin serial communication at 115200 for the main Serial (USB connection)
  Serial.begin(115200);
  
  // Begin software serial communication at 115200 for the GPS
  ss.begin(115200);
}

void loop() {
  while (ss.available() > 0) {
    // Get the byte data from the GPS
    byte gpsData = ss.read();
    
    // Send the GPS data to the Serial monitor
    Serial.write(gpsData);
    delay(10); // Slight delay to avoid flooding the serial buffer
  }
}
