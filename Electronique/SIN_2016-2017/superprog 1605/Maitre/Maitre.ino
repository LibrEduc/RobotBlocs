//LED BATTERIE PONT DIVISEUR
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN            6
#define NUMPIXELS      1

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

const int ledRouge = 9; // Constante pour la broche 9
const int ledVert = 5; // Constante pour la broche 5
const int ledBleu = 6; // Constante pour la broche 6
const int R = 1;
const int V = 1;
const int B = 1;
const int batterie=A1;
int lecturebatterie;
float voltage = 0;
//--------------

//GESTION BOUTON
const byte pinbouton = 2;
boolean etatbouton = 0;
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
#include <SPI.h>
#include <nRF24L01.h>   // Différentes bibliothèques 
#include <RF24.h>    // utile à l'utilisation du module
RF24 radio(7, 8);  // broche utilisé pour la communication
const byte rxAddr[6] = "00001";
char text;   // on stock dans un tableau

//char tableau2[99];

//int e=7;

boolean recu = 0;
boolean envoi = 0;
//--------------

void setup() {
  #if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
pixels.begin();

  //GESTION BOUTON
  pinMode (ledVert, OUTPUT);
  pinMode (ledRouge, OUTPUT);
  pinMode (ledBleu, OUTPUT);
  //--------------

  //GESTION BOUTON
  pinMode(pinbouton, INPUT_PULLUP);
  //--------------

  //GESTION RS232 SORTIE
  sortie.begin(57600);
  //--------------

  //COMMUNICATION PC
  Serial.begin(9600);
          Serial.println("Bloc de nouveau oparationnel !");

  //--------------

    radio.begin(); //Ouverture de la communication

  radio.setRetries(15, 15);
  radio.openWritingPipe(rxAddr);
  radio.stopListening();
}

void loop() {

  sortie.begin(57600);
  Serial.println("Attente de l'appuie sur le bouton");
  lecturedebatterie();
  while (digitalRead(pinbouton) == 0) {
    action1realise0();  //LECTURE DU NOMBRE DE BLOCKS
    action2realise0();  //LECTURE DES FONCTIONS DE BLOCKS
    action2realise1();  //COMMUNICATION RADIO
  }
}

