/*
  Programme du BLOC PROGRAMMABLE

  Ce programme a été conçu pour faire fonctionner le bloc programmable.
  Il fonctionne avec une carte Arduino NANO mais peut aussi être utilisé avec une carte Arduino UNO.

  Créé l'année scolaire 2016/2017,
  par les élèves de SIN du LYCEE EUGENE LIVET :
  Pierre NICOLAS, Hugo DENIER, Martin POREE et Sullivan LETOUZIC
  N'hésitez pas à nous contacter si vous reprenez le projet à nicolas141299@gmail.com !
*/

//CAPTEURS A EFFET HALL
int etatcapteur1;
int etatcapteur2;
int etatcapteur3;
int etatcapteur4;
int capteur1 = 7; // Le capteur1 est branché sur la pin 7
int capteur2 = 8; // Le capteur2 est branché sur la pin 8
int capteur3 = 9; // Le capteur3 est branché sur la pin 9
int capteur4 = 10; // Le capteur4 est branché sur la pin 10
//--------------

//GESTION RS232 ENTREE
#include <SoftwareSerial.h>
const int RXentree = 5; // Broche RX sur la pin 5 à brancher sur le TX de sortie
const int TXentree = 6; // Broche TX sur la pin 6 à brancher sur le RX de sortie
SoftwareSerial entree(RXentree, TXentree);   // RX, TX
//--------------

//GESTION RS232 SORTIE
#include <SoftwareSerial.h>
const int RXsortie = 3; // Broche RX sur la pin 3 à brancher sur le TX d'entrée
const int TXsortie = 4; // Broche TX sur la pin 4 à brancher sur le TX d'entrée
SoftwareSerial sortie(RXsortie, TXsortie);   // RX, TX
//--------------

//VARIABLE
boolean action1realise = 0;
boolean action2realise = 0;
boolean action3realise = 0;
int action4realise = 0;
int envoi = 0;
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
  //GESTION RS232 ENTREE
  entree.begin(57600);
  //--------------

  //GESTION RS232 SORTIE
  sortie.begin(57600);
  //--------------

  //COMMUNICATION PC
  Serial.begin(9600);
  Serial.println("Bloc de nouveau operationnel !");
  //--------------
}
void loop() {
  entree.begin(57600); //INITIALISATION DE LA COMMUNICATION SUR LAQUELLE ON SOUHAITE COMMUNIQUER
  while (!entree.available()) { //ON SE BLOQUE TANT QUE L'ON NE RECOIT RIEN
    Serial.println("On ne recoit rien");
  }

  tableau[n] = entree.read();
  if (tableau[n] == 'Z') { // ON NOUS DEMANDE SI ON EST LA
    entree.write('Y'); // DONC ON REPOND
    temps = millis();
    transmission(); // ON DEMANDE S'IL Y A UN BLOC A COTE DE NOUS
  }
  n++;
}

