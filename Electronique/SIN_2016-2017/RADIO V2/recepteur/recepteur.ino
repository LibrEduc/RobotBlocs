#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
char text;   // on stock dans un tableau
RF24 radio(7, 8); // Broche utilisé pour la communication
const byte rxAddr[6] = "00001";  // adresse

boolean action1 = 0;
boolean action2 = 0;
int x;
char tableau[99];



void setup()
{
  while (!Serial);
  Serial.begin(9600);
  radio.begin();

  radio.openReadingPipe(0, rxAddr);
  radio.startListening();
}

void loop()
{
  while (action1 == 0) {
    Serial.println("onrecoitrien");

    if (radio.available())  // Si on reçoit quelques choses
    {
      radio.read(&text, sizeof(text));
      Serial.println(text); //lire le texte dans moniteur série
      if (text == 'Z') {
        Serial.println("onrecoitZ");
        radio.setRetries(15, 15);
        radio.openWritingPipe(rxAddr);
        radio.stopListening();
        Serial.println("onecritY");

        radio.write(&("Y"), sizeof("Y"));
        action1 = 1;
      }
    }

  }
  radio.openReadingPipe(0, rxAddr);
  radio.startListening();

  while (action2 == 0) {

    if (radio.available())  // Si on reçoit quelques choses
    {
      Serial.println("onrecoitlesformes");


      radio.read(&tableau[x], sizeof(tableau[x]));
      Serial.println(tableau[x]); //lire le texte dans moniteur série

      if (tableau[x] == 'Z') {
        //dessin des formes
        for (int i = 1; i <= x; i++) {
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

        Serial.println("redemarrage dans 5secondes"); //lire le texte dans moniteur série
        delay(5000);
        asm("jmp 0x00");
      }
      x++;
    }
  }

}


