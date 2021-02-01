#include <SoftwareSerial.h>
const int RX = 10;           // à renseigner.
const int TX = 11;           // à renseigner.
int x = 0;

int bp = 2;

SoftwareSerial mySerial(RX, TX); // RX, TX ici respectivement 10 et 11

void setup()
{
  mySerial.begin(57600);   // définition du port série rs232
  Serial.begin(9600);      // Ouverture du port série pour le moniteur


  pinMode(bp, INPUT_PULLUP);
}

void loop() 
{
  /* // BOUCLE DE REBOOT MANUEL SANS REDEMARAGE DES CARTES : SE FAIT AVEC UN BOUTON POUSSOIR EN D2
  if (digitalRead(2) == 0) {
    x = 0;
    while (digitalRead(2) == 0);
    delay(1000);
  }
  Serial.println(digitalRead(2));
  */

  if (x == 0) {                                  //!Permet de n'envoyer qu'une seule fois l'information à partir du moment ou la communication est faite
    if (!mySerial.available()) {                    //:Si la liaison est libre et que je ne reçois rien alors :
      Serial.println("JeWrite");                       //"J'écris :"
      mySerial.write("D5B6C7A");                       //Le code emplacement de chaque carte et la fonction
      mySerial.write("A");                             //J'envoie A pour signaler la fin de la communication
      delay(100);                                      //J'attends 100millisecondes avant de recommencer
    }                                               //:
    else {                                          //:Sinon si je reçois quelque chose
      Serial.println("Jerecois");
      char be = mySerial.read();                     //Lecture de ce que je reçois
      Serial.println(be);
      if (be == 'Z') {                                     //?Si le caractère que je reçois est Z alors cela signifie que la communication a été validé par l'autre carte
        Serial.println("STOOPPPPPPPPP");
        x = 1;                                             //Dans ce cas on ne renvoie plus l'information donc x=1 pour ne pas recommencer la grande boucle d'écriture
      }                                                    //?
    }                                               //:
  }                                              //!
  else {                                         //!Sinon on ne fait rien du tout (pourrait être enlever)
    Serial.println("Fin");
  }                                              //!
}



