/*****************************************************************


*****************************************************************/

// Libraries
#include <SoftwareSerial.h>

// Constants
#define COMMAND_CHAR  '+'
#define BAUD_RATE     38400
#define S_READY       'Y'
#define S_BUSY        'N'

// Create Objects
SoftwareSerial XBee(2, 3);

// Variables
char rChar;
bool canWrite = false;

// Function Prototypes
void runCommand();
void readCommand();

// Setup - Run once at startup
void setup()
{
  // Initialize Serial Interfaces
  XBee.begin(BAUD_RATE);
  Serial.begin(BAUD_RATE);
}

void loop()
{
  if (Serial.available())
  { 
    
  }
  
  if (XBee.available())
  {
    rChar = XBee.read();
    if (rChar == COMMAND_CHAR) readCommand();
  }
}

void runCommand()
{
  
}

void readCommand()
{
  rChar = XBee.read();
  switch (rChar)
  {
    case S_READY:
      canWrite = true;
      break;
    case S_BUSY:
      canWrite = false;
      break;
    default:
      Serial.println("Error. Not a valid command");
      break;
  }
}

