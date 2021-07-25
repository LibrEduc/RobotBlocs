#include <SoftwareSerial.h>
#define rxPin 1 // Broche 11 en tant que RX, à raccorder sur TX du HC-05
#define txPin 0 // Broche 10 en tant que TX, à raccorder sur RX du HC-05
SoftwareSerial mySerial(rxPin, txPin);

void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  mySerial.begin(9600);
  Serial.begin(9600);

}

void loop() {

int x;
int i = 0;
int z = 0;
analogWrite(3,100);
while (z < 16) {

int trame[i++] = Serial.read() ;
 
    if (trame[i] == 1){ //commande tourner droite
        digitalWrite(7,HIGH);
        digitalWrite(8,LOW);
        analogWrite(10,150);
        analogWrite(9,150);
        delay(300);
        analogWrite(10,0);
        analogWrite(9,0);
        i++;
        z++;
   }
    else if (trame[i] == 2) { //commande avancer
        digitalWrite(7,LOW);
        digitalWrite(8,LOW);
        analogWrite(10,150);
        analogWrite(9,150);
        delay(500);
        analogWrite(10,0);
        analogWrite(9,0);
        i++;
        z++;;
   }
      else if (trame[i] == 3) { //commande tourner gauche
        digitalWrite(7,LOW);
        digitalWrite(8,HIGH);
        analogWrite(10,150);
        analogWrite(9,150);
        delay(300);
        analogWrite(10,0);
        analogWrite(9,0);
        i++;
        z++;
  }
    else if (trame[i] == 4) { //commande reculer
        digitalWrite(7,HIGH);
        digitalWrite(8,HIGH);
        analogWrite(10,150);
        analogWrite(9,150);
        delay(500);
        analogWrite(10,0);
        analogWrite(9,0);
        i++;
        z++; 
       
  }
}
  analogWrite(3,0);
}
