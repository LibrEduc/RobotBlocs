#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // Broche utilisé pour la communication

const byte rxAddr[6] = "00001";  // adresse

void setup()
{
  while (!Serial);
  Serial.begin(9600);
  
  radio.begin();
  radio.openReadingPipe(0, rxAddr);
  
  radio.startListening();
}

void loop()
{
  if (radio.available())  // Si on reçoit quelques choses
  {
    char text[32] = {0};   // on stock dans un tableau
    radio.read(&text, sizeof(text));
    
    Serial.println(text); //lire le texte dans moniteur série
  }
}
////http://starter-kit.nettigo.eu/2014/connecting-and-programming-nrf24l01-with-arduino-and-other-boards/
