#define DIR 2
#define PAS 3

int tempo=1500;
int tempo2 = 1000;

void setup()
{
  Serial.begin(9600);
  pinMode(DIR,OUTPUT);
  pinMode(PAS,OUTPUT);

  digitalWrite(DIR, HIGH );
}

void loop()
{
  //Serial.println("1");
  digitalWrite(PAS,HIGH);
  //delay(tempo2);
  delayMicroseconds(tempo);
  //Serial.println("2");
  digitalWrite(PAS,LOW);
  //delay(tempo2);
  delayMicroseconds(tempo);
}
