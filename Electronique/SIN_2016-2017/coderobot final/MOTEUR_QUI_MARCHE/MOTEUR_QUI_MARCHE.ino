const int diametreroue=62;
const int diametrentreroue=177;
const int nbrdepas=1600;
const float pi = 3.14159;
float perimetreroue;
float perimetresol;
float tourentier;
int pas;

int dir=A0;
int istep=A1;
int sleep=A2;

int dir2=A4;
int istep2=A5;
int sleep2=A3;

void setup() {
  Serial.begin(9600);
pinMode(dir,OUTPUT);
pinMode(istep,OUTPUT);
pinMode(sleep,OUTPUT);

pinMode(dir2,OUTPUT);
pinMode(istep2,OUTPUT);
pinMode(sleep2,OUTPUT);
}

void loop() {
   carrepierre();
  //calculangle(180);
//droite(1600);
  //calculangle(360);
//droite(pas);

stop();
delay(1000);
  }
