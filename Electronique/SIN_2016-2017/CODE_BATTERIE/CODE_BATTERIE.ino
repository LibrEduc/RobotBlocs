unsigned long time;
unsigned long savetime=0;

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

int analogValue;
float voltage = 0;

#define PIN            6


#define NUMPIXELS      1


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500;

void setup() {

#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif

  Serial.begin(9600);
  pixels.begin();
}

void loop() {
  
  time = millis();
  Serial.println(time);
  if((time-savetime)>=120000){
    Serial.println("WESH");
  analogValue = analogRead(A1);
  voltage = 0.0097 * analogValue;
  Serial.println(voltage);
  
  if (voltage < 7.03) {
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));
    pixels.show();
  }

  if ((voltage > 7.03) && (voltage < 9.06)) {
    pixels.setPixelColor(0, pixels.Color(255, 127, 0));
    pixels.show();
  }

  if (voltage > 9.06) {
    pixels.setPixelColor(0, pixels.Color(0, 255, 0));
    pixels.show();
  }savetime=time;}
}
