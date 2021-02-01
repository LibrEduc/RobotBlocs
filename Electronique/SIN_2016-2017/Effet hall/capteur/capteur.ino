const int ledPin = 13; 
const int hallPin = 2;

int sensorValue; 

void setup(){
  pinMode( ledPin, OUTPUT ); 
  pinMode( hallPin, INPUT );
  Serial.begin(9600);
}

void loop() {
  // lecture du capteur a Effet Hall
  sensorValue = digitalRead( hallPin );
  // senseurValue = HIGH sans aimant
  // senseurValue = LOW  quand POLE SUD aimant
  sensorValue = not( sensorValue );
  Serial.println(sensorValue);
  // Allumer eteindre la LED
  digitalWrite( ledPin, sensorValue );
  
}
