/*
  Programme du ROBOT

  Ce programme a été conçu pour faire fonctionner le robot
  Il fonctionne avec une carte Arduino NANO mais peut aussi être utilisé avec une carte Arduino UNO.

  Créé l'année scolaire 2016/2017,
  par les élèves de SIN du LYCEE EUGENE LIVET :
  Pierre NICOLAS, Hugo DENIER, Martin POREE et Sullivan LETOUZIC
  N'hésitez pas à nous contacter si vous reprenez le projet à nicolas141299@gmail.com !
*/

//CALCULS DES ANGLES
const int diametreroue = 62; // Diamètre de la roue
const int diametrentreroue = 177; // Diamètre du cercle crée par la rotation du robot
const int nbrdepas = 1600; // Nombre de pas d'un moteur
const float pi = 3.14159;
float perimetreroue;
float perimetresol;
float tourentier;
int pas;
//--------------

//BUZZER
int speakerPin = 2; // Le buzzer est branché sur la pin 7
//--------------

//MOTEURS
int dir = A0;
int istep = A1;
int sleep = A2;
int dir2 = A4;
int istep2 = A5;
int sleep2 = A3;
//--------------

//RADIO
// ATTENTION MODULE NRF24L01 SUR 3.3V !!!
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
char text;
RF24 radio(7, 8); // CE, CSN CE sur la pin 7 et CSN sur la pin 8
const byte rxAddr[6] = "00001";

//VARIABLE
boolean action1 = 0;
boolean action2 = 0;
int x;
char tableau[99];
//--------------

//SERVOMOTEUR
#include <Servo.h>
Servo servo;
//--------------

void setup() {
  //BUZZER
  pinMode(speakerPin, OUTPUT);
  //--------------

  //COMMUNICATION PC
  while (!Serial);
  Serial.begin(9600);
  Serial.println("Robot operationnel !");
  //--------------

  //COMMUNICATION RADIO
  radio.begin();
  radio.openReadingPipe(0, rxAddr);
  radio.startListening();
  //--------------

  //MOTEURS
  pinMode(dir, OUTPUT);
  pinMode(istep, OUTPUT);
  pinMode(sleep, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(istep2, OUTPUT);
  pinMode(sleep2, OUTPUT);
  //--------------
  
  //SERVOMOTEUR
myservo.attach(6);  // Le servo est branché sur la pin 6
}

void loop() {
  while (action1 == 0) { // BOUCLE POUR SAVOIR VALIDER AU BLOC MAITRE QU'ON EST LA
    Serial.println("On recoit rien");
    if (radio.available())
    {
      radio.read(&text, sizeof(text));
      Serial.println(text);
      if (text == 'Z') { // ON RECOIT Z POUR SAVOIR SI ON EST LA
        Serial.println("onrecoitZ");
        radio.setRetries(15, 15);
        radio.openWritingPipe(rxAddr);
        radio.stopListening();
        Serial.println("onecritY");

        radio.write(&("Y"), sizeof("Y")); // ON REPOND
        action1 = 1;
      }
    }
  }

  radio.openReadingPipe(0, rxAddr);
  radio.startListening();
  while (action2 == 0) { // BOUCLE POUR RECEVOIR LES FORMES
    if (radio.available())
    {
      Serial.println("on recoit les formes");
      radio.read(&tableau[x], sizeof(tableau[x])); // ON STOCKE LES FORMES
      Serial.println(tableau[x]);

      if (tableau[x] == 'Z') { // ON RECOIT Z ALORS LA COMMUNICATION EST TERMINEE
        for (int i = 1; i <= x; i++) { // ON INTERPRETE LES CARACTERES EN FORME POUR LES DESSINER
          switch (tableau[i]) {
            case 'A':
              formeA();
              break;

            case 'B':
              formeB();
              break;

            case 'C':
              formeC();
              break;

            case 'D':
              formeD();
              break;

            case 'E':
              formeE();
              break;

            case 'F':
              formeF();
              break;

            case 'G':
              formeG();
              break;

            case 'H':
              formeH();
              break;

            case 'I':
              formeI();
              break;

            case 'J':
              formeJ();
              break;

            case 'K':
              formeK();
              break;

            case 'L':
              formeL();
              break;

            case 'M':
              formeM();
              break;

            case 'N':
              formeN();
              break;

            case 'O':
              formeO();
              break;

            case 'P':
              formeP();
              break;
          }
        }
        Serial.println("redemarrage dans 5secondes"); // TOUTES LES FORMES ONT ETE REPRODUITE; ON RESET LA CARTE
        delay(5000);
        asm("jmp 0x00");
      }
      x++;
    }
  }
}
