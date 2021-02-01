int etatcapteur1;
int etatcapteur2;
int etatcapteur3;
int etatcapteur4;

int capteur1=1;
int capteur2=1;
int capteur3=1;
int capteur4=1;

int cbon=0;


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
const int RXsortie = 3;                   // à renseigner.
const int TXsortie = 4;                   // à renseigner.
SoftwareSerial sortie(RXsortie, TXsortie);   // RX, TX
//--------------

//VARIABLE
boolean action1realise = 0;
boolean action2realise = 0;
boolean action3realise = 0;
int action4realise = 0;


unsigned long temps;
char fonction;
//--------------

//TABLEAU
char tableau[99];
char tableau2[99];
char qe;
int n = 0;
int x = 0;
int i = 0;
int h;
//--------------


void setup() {
  //GESTION BOUTON
  pinMode(pinbouton, INPUT_PULLUP);
  //attachInterrupt(digitalPinToInterrupt(pinbouton), interruption, FALLING);
  //--------------
  //GESTION RS232 ENTREE
  entree.begin(57600);
  //--------------

  //GESTION RS232 SORTIE
  sortie.begin(57600);
  //--------------
  Serial.begin(9600);
            Serial.println("Bloc de nouveau oparationnel !");

}
void loop() {

  entree.begin(57600);
  while (!entree.available()) {
    Serial.println("On ne recoit rien");
    if (tableau[1] == 'Z') {
      Serial.println("On a recu Z donc on envoie Y");
      delay(100);

      entree.write('Y');
      delay(100);
      // entree.write('Y');


      temps = millis();
      transmission();
      // entree.begin(57600);
      // n = 0;
      // while (!entree.available()) {}
    }
  }
  //Serial.print("Stockage de la reception : ");
  tableau[n] = entree.read();
  //Serial.println(tableau[n]);
  if (tableau[n] == 'Z') {
    Serial.println("Lecture de la lettre Z = es tu la ?");
        Serial.println("Reponse par la lettre Y = oui je suis la");

        delay(10);
    entree.write('Y');
    delay(10);
    temps = millis();
    transmission();
  }
  n++;




  /*
    if (entree.read() != 'Z') {
  a      Serial.println("Message recu");
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

