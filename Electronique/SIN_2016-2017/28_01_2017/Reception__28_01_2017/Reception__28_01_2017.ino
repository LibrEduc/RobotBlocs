char myInts[99];
char qe;
int i = 0;
int x = 0;
int z;
#include <SoftwareSerial.h>
const int RX = 10;                   // à renseigner.
const int TX = 11;                   // à renseigner.
SoftwareSerial mySerial(RX, TX);   // RX, TX
int bp = 2;

void setup() {
  mySerial.begin(57600);           // définition du port Série Logiciel
  Serial.begin(9600);              // Ouverture du port Série de la carte pour le moniteur

  pinMode(bp, INPUT_PULLUP);
}

void loop() {
  /* // BOUCLE DE REBOOT MANUEL SANS REDEMARAGE DES CARTES : SE FAIT AVEC UN BOUTON POUSSOIR EN D2
    if (digitalRead(2) == 0) {
    x = 0;
    i = 0;
    z = 0;
    while (digitalRead(2) == 0) {}
    delay(1000);
    }
    Serial.println(digitalRead(2));
  */

  if (x == 0) {                                  //!Permet de ne lire qu'une fois l'information à partir du moment ou la communication est faite
    Serial.println("Attente de reception");
    if (mySerial.available())                       //:Si on reçoit quelque chose alors :
    {
      qe = mySerial.read();                            //Lecture de ce que je reçoit
      Serial.print(qe);
      myInts[i] = qe;                                  //Stockage de ce que je reçoit dans un tableau en fonction de i
      i++;                                             //Incrémentation de i pour stocker la prochaine donnée éventuelle dans le tableau
      if (qe == 'A')                                       //;Si on reçoit A, cela signifie que l'on a reçu la totalité des données
      {
        Serial.println("J ai lu A");            
        mySerial.write('Z');                                   //On envoie Z pour signifier que l'on a bien compris le message
        x = 1;                                                 //Dans ce cas on n'a plus d'information à lire donc x=1 pour ne pas recommencer la grande boucle de lecture
        z = i;                                                 //On sauvegarde la valeur de i dans z 
      }                                                    //;
    }                                                //:
  }                                               //!
  else {                                          //!Sinon si on a déja lu les informations on va les traiter
    Serial.println("start");
    for (i = 0; i < z; i++) {                        //-Pour i allant de 0 à z(= à i) on va lire le tableau (afin de potentiellement le renvoyer
      Serial.println(myInts[i]);
    }                                                //-
    Serial.println("stop");
  }                                               //!
}


