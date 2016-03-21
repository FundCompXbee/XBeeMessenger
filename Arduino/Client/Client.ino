/*************************************************
 * Student: Aaron Crawfis
 * netID: acrawfis
 * Date: 02 March 2016
 * File: Client.ino
 * Purpose: Bridge the Xbee with the computer's
 * serial interface. Simply bridge data
 ************************************************/

#include <SoftwareSerial.h>

#define BAUD_RATE

// Initialize Software Serial
SoftwareSerial XBee(2, 3);

void setup()
{
  // Begin XBee Communication
  XBee.begin(BAUD_RATE);
  // Begin Serial Communication
  Serial.begin(BAUD_RATE);
}

void loop()
{
  // Send data if available
  if (Serial.available()) XBee.write(Serial.read());
  // Receive data if available
  if (XBee.available()) Serial.write(XBee.read());
}

