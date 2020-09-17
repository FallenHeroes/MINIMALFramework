
#include <SPI.h>
#include <MFRC522.h>
 
#define RST_PIN 5 
#define SS_PIN 53

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 
void