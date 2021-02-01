#include <SPI.h>
#include <nRF24L01.h>   // Différentes bibliothèques 
#include <RF24.h>    // utile à l'utilisation du module

RF24 radio(7, 8);  // broche utilisé pour la communication

const byte rxAddr[6] = "00001"; 

void setup()
{
  radio.begin(); //Ouverture de la communication
  radio.setRetries(15, 15);
  radio.openWritingPipe(rxAddr);
  
  radio.stopListening();
}

void loop()
{
  const char text[] = "Test reception projet Blocs "; // on envoie
  radio.write(&text, sizeof(text)); 
  
  delay(1000);  // on temporise 1 seconde avant de renvoyer 
}
