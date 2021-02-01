#include <SPI.h>
#include <nRF24L01.h>   // Différentes bibliothèques 
#include <RF24.h>    // utile à l'utilisation du module
RF24 radio(7, 8);  // broche utilisé pour la communication
const byte rxAddr[6] = "00001";
char text;   // on stock dans un tableau

char tableau2[99];

int e=7;

boolean recu = 0;
boolean envoi = 0;

void setup()
{
tableau2[0]='A';
tableau2[1]='B';
tableau2[2]='C';
tableau2[3]='D';
tableau2[4]='E';
tableau2[5]='F';
  Serial.begin(9600);

  radio.begin(); //Ouverture de la communication

  radio.setRetries(15, 15);
  radio.openWritingPipe(rxAddr);
  radio.stopListening();
}


void loop()
{

 // BOUCLE IMAGINAIRE AVANT D'ARRIVER A L'ENVOIE DES DONNEES PAR RADIO
  for(int i = 0; i < 50; i++) {
    Serial.println("cavacommencer"); //lire le texte dans moniteur série
    //delay(10);
  }
  //delay(5000);
    Serial.println("CACOMMENCE"); //lire le texte dans moniteur série

radio.write(&("Z"), sizeof("Z"));
while (recu == 0) {
  radio.openReadingPipe(0, rxAddr);
  radio.startListening();
      Serial.println("onnerecoitrien"); //lire le texte dans moniteur série

  if (radio.available())  // Si on reçoit quelques choses
  {
    radio.read(&text, sizeof(text));
    Serial.println(text); //lire le texte dans moniteur série
    if (text == 'Y') {
      Serial.println("onrecoitY"); //lire le texte dans moniteur série
      recu = 1;
    }
  }
}

while (envoi == 0) {
   // BOUCLE D'ECRITURE DES FORMES

        Serial.println("onecritlesformes"); //lire le texte dans moniteur série

  radio.setRetries(15, 15);
  radio.openWritingPipe(rxAddr);
  radio.stopListening();

for (int x = 0; x < e - 1; x++) {                      //-Pour i allant de 0 à z(= à i) on va lire le tableau (afin de potentiellement le renvoyer
      radio.write(&tableau2[x], sizeof(tableau2[x]));
    }      
  
      // radio.write(&("Z"), sizeof("Z");
radio.write(&("Z"), sizeof("Z"));

  Serial.println("redemarrage dans 5secondes"); //lire le texte dans moniteur série
  delay(5000);
  asm("jmp 0x00");
}
}
