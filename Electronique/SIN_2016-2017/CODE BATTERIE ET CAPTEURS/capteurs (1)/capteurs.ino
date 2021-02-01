const int capteur1 = 2;
const int capteur2 = 3;
const int capteur3 = 4;
const int capteur4 = 5;

int etatcapteur1;
int etatcapteur2;
int etatcapteur3;
int etatcapteur4;

void setup() {
  pinMode(capteur1, INPUT );
  pinMode(capteur2, INPUT );
  pinMode(capteur3, INPUT );
  pinMode(capteur4, INPUT );
  
  Serial.begin(9600);
}

void loop() {
  lecturecapteur();
  delay(1000);
  
}
