
#include <SPI.h>
#include <MFRC522.h>
 
#define RST_PIN 5 
#define SS_PIN 53

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  // Serial.println("Writing it");
  // writeMacAddressIntoTag("");
  // Serial.println("Done");
  
}
void loop() 