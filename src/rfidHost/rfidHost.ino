
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
{
  Serial.println(readMacAddressFromTag());
  // Serial.println("Nein");
  delay(700);

  mfrc522.PICC_HaltA(); // Halt PICC
  mfrc522.PCD_StopCrypto1();  // Stop encryption on PCD
} 

String readMacAddressFromTag()
{

  MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;


  byte block = 4;
  byte contentLength = 18*2;
  byte content[18*2];
  String charContent = String("");

  if ( ! mfrc522.PICC_IsNewCardPresent()) {    
    return String("Card Unavailable");
  }

  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return String("cannot read Card");
  }

  MFRC522::StatusCode status;
  
  status = mfrc522.PCD