/*
  Programme du BLOC MAITRE

  Ce programme a été conçu pour faire fonctionner le bloc maître.
  Il fonctionne avec une carte Arduino NANO mais peut aussi être utilisé avec une carte Arduino UNO.

  Créé l'année scolaire 2016/2017,
  par les élèves de SIN du LYCEE EUGENE LIVET :
  Pierre NICOLAS, Hugo DENIER, Martin POREE et Sullivan LETOUZIC
  N'hésitez pas à nous contacter si vous reprenez le projet à nicolas141299@gmail.com !
*/

//NEOPIXEL
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN            6  // Neopixel à brancher sur la pin 6
#define NUMPIXELS      1  // Juste en brancher une
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
//--------------

//LECTURE DE LA BATTERIE
const int batterie = A1; // La batterie est branché sur la broche analogique 1
int lecturebatterie;
float voltage = 0;
//--------------

//GESTION BOUTON
const byte pinbouton = 2; // Le bouton est branché sur la pin 2
boolean etatbouton = 0;
//--------------

//GESTION RS232 SORTIE
#include <SoftwareSerial.h>
const int RXsortie = 3;                   // Broche RX sur la pin 3 à brancher sur le TX de l'esclave (voir code Bloc1)
const int TXsortie = 4;                   // Broche TX sur la pin 4 à brancher sur le RX de l'esclave (voir code Bloc1)
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
int x = 0;
int n = 0;
int i = 0;
int b = 0;
//--------------

//RADIO
// ATTENTION MODULE NRF24L01 SUR 3.3V !!!
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8);  // CE, CSN CE sur la pin 7 et CSN sur la pin 8
const byte rxAddr[6] = "00001";
char text;
boolean recu = 0;
boolean envoi = 0;
//--------------

void setup() {
  //NEOPIXEL
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  pixels.begin();
  //--------------

  //GESTION BOUTON
  pinMode(pinbouton, INPUT_PULLUP);
  //--------------

  //GESTION RS232 SORTIE
  sortie.begin(57600);
  //--------------

  //COMMUNICATION PC
  Serial.begin(9600);
  Serial.println("Bloc de nouveau operationnel !");
  //--------------

  //COMMUNICATION RS232
  radio.begin();
  radio.setRetries(15, 15);
  radio.openWritingPipe(rxAddr);
  radio.stopListening();
  //--------------
}

void loop() {
  Serial.println("Attente de l'appuie sur le bouton");
  lecturedebatterie();
  while (digitalRead(pinbouton) == 0) {
    action1realise0();  //LECTURE DU NOMBRE DE BLOCKS
    action2realise0();  //LECTURE DES FONCTIONS DE BLOCKS
    action2realise1();  //COMMUNICATION RADIO
  }
}

