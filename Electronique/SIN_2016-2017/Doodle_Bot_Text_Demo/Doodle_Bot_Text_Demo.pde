
#include "Constants.h"
#include "IOpins.h"

int volts;                                         // battery voltage
int pause=-1;                                      // a value of -1 means the battery voltage is ok, 0 and 1 are used to flash LED on D13 when the battery is flat
byte pen;
byte turn;

int lspeed;                                        // left  speed -255 to +255 (negative values are reverse)
int rspeed;                                        // right speed -255 to +255 (negative values are reverse)
int dspeed=80;                                     // draw  speed  +50 to +200

volatile int rcount;
volatile int lcount;

void setup()
{
  attachInterrupt(0,Rcount,CHANGE);
  attachInterrupt(1,Lcount,CHANGE);
  
  Serial.begin(57600);                             // initialize serial interface - 9600 baud   
  pinMode(Ldirpin,OUTPUT);                         // set left  direction pin as an output pin
  pinMode(Rdirpin,OUTPUT);                         // set right direction pin as an output pin
  pinMode(Srvopin,OUTPUT);                         // set servo  control  pin as an output pin
  
  digitalWrite(2,1);                               // enable pullup resistor on D2
  digitalWrite(3,1);                               // enable pullup resistor on D3
  
  Up();                                            // start the program with the pen raised
  delay(1000);
  
}

void loop()
{ 
  volts=analogRead(Battery)/10;
  
  if(volts<lowbat || pause!=-1)                    // once voltage falls below lowbat value
  {
    lspeed=0;                                      // stop left  motor
    rspeed=0;                                      // stop right motor
    Motors();                                      // update motor control pins
    if (pause<0) Up();                             // make sure pen is raised when battery first falls below lowbat value
    pause++;                                       // increment pause
    if(pause>1) pause=0;                           // toggle pause between 0 and 1 once battery is flat
    digitalWrite(13,pause);                        // flash LED on D13
    delay(200);                                    // set flashing LED speed
    return;                                        // reset loop
  }
                                                   // current is proportional to voltage and power = voltage x current
                                                   // As the battery voltage drops dspeed increases to maintain a constant speed
  
  dspeed=26214/volts*10/volts;                     // draw speed power correction factor=100% when battery=5V (analog reading = 512)
  dspeed=dspeed*8/10;                              // adjust speed to reduce overshoot
   
  I();Space();A();M();Space();A();Space();R();O();B();O();T();Space();END();
  //A();B();C();D();E();F();G();H();I();J();K();L();M();N();O();P();Q();R();S();T();U();V();W();X();Y();Z();END();
  //N0();N1();N2();N3();N4();N5();N6();N7();N8();N9();END();
}


  





