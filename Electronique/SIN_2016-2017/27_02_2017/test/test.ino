//GESTION BOUTON
const byte pinbouton = 2;
boolean etatbouton = 0;
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

unsigned long temps;
//--------------

//TABLEAU
char qe;
char tableau1[99];
char tableau2[99];
int x=0;
int n = 0;
int i = 0;
//--------------


void setup() {
  //GESTION BOUTON
  pinMode(pinbouton, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinbouton), interruption, FALLING);
  //--------------

  //GESTION RS232 SORTIE
  sortie.begin(57600);
  //--------------

  Serial.begin(9600);
}
void loop() {

  while (etatbouton == 0) {                                                                //a Ici temps que l'on a pas appuyé sur le bouton il ne se passera rien.
    Serial.println("Attente de l'appuie sur le bouton");
  }                                                                                        //a

  while (action1realise == 0) {                                                              //b Réalisation de l'action 1 qui consiste à compter le nombre de block
    Serial.println("Action1realise 0");
    if ((millis() - temps) <= 500) {                                                         //c-0 Pour verifier qu'il y a des block on envoie un caractère en l'attente d'une réponse si réponse alors le block fait la meme chose à coté si pas de réponse alors pas d'autres block
            Serial.println(millis());
      Serial.println(temps);

      Serial.println(millis()-temps);
      Serial.println("Temps inferieur a deux secondes");
      if (!sortie.available()) {                                                                  //d-0 Si l'on ne reçoit rien alors on écrit 1Z 1=block maitre et Z=STOP
        sortie.write("1Z");
        Serial.println("Ecriture de 1Z");
        delay(100);
      }                                                                                           //d-0
      else {                                                                                      //d-1 Si l'on recoit qqchose alors on vérifie que l'on recoit Y qui signifira que l'on a bien une carte à coté
        //Serial.println("On recoit bien quelque chose");
        if (sortie.read() == 'Y') {
          Serial.println("Lecture de la lettre Y");
          action1realise = 1;
        }
        //else{Serial.println("Mais on ne sait pas quoi");}
      }                                                                                           //d-1
    }                                                                                         //c-0
    else {                                                                                    //c-1 Si l'on a dépassé le temps de vérification sela signifie qu'il n'y a pas d'autre carte = réinitialisation totale
      Serial.println("Temps depasse et aucune carte detectee");
      delay(5000);
      erreur();
    }                                                                                         //c-1 
  }

  while (action2realise == 0) {                                  //!Permet de n'envoyer qu'une seule fois l'information à partir du moment ou la communication est faite
    Serial.println("Action2realise 0");
  sortie.begin(57600);
 if (sortie.available())                       //:Si on reçoit quelque chose alors :
      {
        Serial.println("On recoit quelque chose");
        qe = sortie.read();                            //Lecture de ce que je reçoit
        //Serial.print(qe);
        tableau2[x] = qe;                                  //Stockage de ce que je reçoit dans un tableau en fonction de i
        x++;                                             //Incrémentation de i pour stocker la prochaine donnée éventuelle dans le tableau
        if (qe == 'Z')                                       //;Si on reçoit A, cela signifie que l'on a reçu la totalité des données
        {
          Serial.println("On recoit Z");
            sortie.begin(57600);

          sortie.write('Y');                                   //On envoie Z pour signifier que l'on a bien compris le message
          delay(100);
          i = x;                                                 //On sauvegarde la valeur de i dans z
          action2realise = 1;
        }                                                    //;
      }
      else{Serial.println("Non, on ne recoit rien");}
  }   
  while(action2realise == 1) { Serial.println("start");
    for (x = 0; x < i-1; x++) {                        //-Pour i allant de 0 à z(= à i) on va lire le tableau (afin de potentiellement le renvoyer
      Serial.println(tableau2[x]);
    }                                                //-
    Serial.println("stop");}
  Serial.println("fin");
}                                                                                         //b

