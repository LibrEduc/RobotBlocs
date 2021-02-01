/**********************************************
  // Transfert de données d'une carte arduino à une autre.
  // Ce sketch envoie le message Hello à une autre carte connectée.

  // Branchements :
  // * RX connecté sur pin 10 (connecté à TX sur l'autre carte)
  // * TX connecté sur pin 11 (connect à RX sur l'autre carte)
  // * Et ne pas oublier de relier les masses des 2 cartes (GND)
 ****************************************/

#include <SoftwareSerial.h>
const int RX = ;           // à renseigner.
const int TX = ;           // à renseigner.

SoftwareSerial mySerial(RX, TX); // RX, TX

void setup()
{ 
  mySerial.begin(57600);   // définition du port Série Logiciel
}

void loop() //-- Toutes les 2 secondes envoi d'un message
{ if (mySerial.available())
  {
    mySerial.write("Hello");
  }
  delay(2000); //-- Attente de 2 secondes avant de recommencer
}
