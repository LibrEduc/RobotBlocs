int M1NA = 2; // M1A --> rouge
int M1NB = 4; // M1B --> bleu
int M1PWM = 9; // Etat haut 

int M2NA = 7; // M2A --> vert
int M2NB = 8; // M2B --> noir
int M2PWM = 10;

//int courant=2;
int tempo = 1;
int PAS=0;

void setup() {
  Serial.begin(9600);
  pinMode(M1NA, OUTPUT);
  pinMode(M1NB, OUTPUT);
  pinMode(M1PWM, OUTPUT);
  pinMode(M2NA, OUTPUT);
  pinMode(M2NB, OUTPUT);
  pinMode(M2PWM, OUTPUT);

  digitalWrite(M1PWM, HIGH);
  digitalWrite(M2PWM, HIGH);

}

void loop() {
  // Test pour avancer de 200pas dans un sens puis dans l'autre en fonction de la position ou je suis.
  for (int i = 0; i < 200; i++) {
    PAS = PAS + 1;
    if (PAS == 5) {
      PAS = 1;
    }
       // Serial.println(PAS);

    switch (PAS) {
      case 1:
        {
          pas1();
        }
        break;
      case 2:
        {
          pas2();
        }
        break;
      case 3:
        {
          pas3();
        }
        break;
      case 4:
        {
          pas4();
        }
        break;
    }
  }    pas0();

  for (int y = 0; y <200; y++) {
    PAS = PAS - 1;

    if (PAS == 0) {
      PAS = 4;
    }


    switch (PAS) {
      case 1:
        {
          pas1();
        }
        break;
      case 2:
        {
          pas2();
        }
        break;
      case 3:
        {
          pas3();
        }
        break;
      case 4:
        {
          pas4();
        }
        break;
    }
  }
  pas0();
}


