//GESTION BOUTON
const byte pinbouton = 2;
boolean etatbouton = 0;
//--------------

//GESTION RS232 ENTREE
#include <SoftwareSerial.h>
const int RXentree = 5;                   // à renseigner.
const int TXentree = 6;                   // à renseigner.
SoftwareSerial entree(RXentree, TXentree);   // RX, TX
//--------------

//GESTION RS232 SORTIE
#include <SoftwareSerial.h>
const int RXsortie = 10;                   // à renseigner.
const int TXsortie = 11;                   // à renseigner.
SoftwareSerial sortie(RXsortie, TXsortie);   // RX, TX
//--------------

//VARIABLE
boolean action1realise = 0;
boolean action2realise = 0;
boolean action3realise = 0;
boolean action4realise = 0;


unsigned long temps;
char fonction;
//--------------

//TABLEAU
char tableau[99];
char tableau2[99];
char qe;
int n = 0;
int x=0;
int i = 0;
//--------------


void setup() {
  //GESTION BOUTON
  pinMode(pinbouton, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinbouton), interruption, FALLING);
  //--------------
  //GESTION RS232 ENTREE
  entree.begin(57600);
  //--------------

  //GESTION RS232 SORTIE
  sortie.begin(57600);
  //--------------
  Serial.begin(9600);
}
void loop() {

  entree.begin(57600);
  while (!entree.available()) {
    Serial.println("On ne recoit plus rien");
    if (tableau[1] == 'Z') {
Serial.println("On a recu Z donc on envoie Y");
      entree.write('Y');
      

      temps=millis();
      transmission();
     // entree.begin(57600);
     // n = 0;
     // while (!entree.available()) {}
    }
  }
  Serial.println("Stockage de la reception");
  tableau[n] = entree.read();
  Serial.println(tableau[n]);
  n++;
  



  /*
    if (entree.read() != 'Z') {
      Serial.println("Message recu");
      tableau[n] = entree.read();
      n++;
    }
    else {
      Serial.println("Envoye");
      i = n;

      entree.write('Y');
    }
  */


}

