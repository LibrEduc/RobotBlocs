/**************
  // Réception de données via le port Série Logiciel :

  // Attention les câbles RX et TX doivent être croisés.
  // Ne pas oublier de relier les masses des 2 cartes (GND) entre la carte émitrice et la carte réceptrice !
***************/

#include <SoftwareSerial.h>
const int RX = 10;                   // à renseigner.
const int TX = 11;                   // à renseigner.

SoftwareSerial mySerial(RX, TX);   // RX, TX

void setup() {
  mySerial.begin(57600);           // définition du port Série Logiciel
  Serial.begin(9600);              // Ouverture du port Série de la carte pour le moniteur
  }
  

void loop() {

while (!Serial) {}
  //Serial.println("Attente réception !");

  if (mySerial.available())        //-- Si des données sont présentes
  { 
    Serial.write(mySerial.read()); //-- Affichage sur la console des données
    
  }
}
