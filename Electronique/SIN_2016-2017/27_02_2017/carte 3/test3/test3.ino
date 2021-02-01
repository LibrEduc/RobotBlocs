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
unsigned long temps;
//--------------

//TABLEAU
char tableau[99];
int n = 0;
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

  while (!entree.available()) {                         //a lorsque l'on ne reçoit plus rien et si l'on a reçu Z alors cela signifie qu'on essaye de compter les cartes on signale que l'on a reçu et on restransmet le chiffre +1 à l'autre carte
    Serial.println("Bloque");
    if (tableau[1] == 'Z') {
      entree.write('Y');
      Serial.println(tableau[0]);
      temps = millis();
      transmission();
      entree.begin(57600);
      n = 0;
      while (!entree.available()) {}
    }
    n = 0;
  }                                                     //a
  tableau[n] = entree.read();                           //b lecture des entrée
  n++;                                                  //b



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

