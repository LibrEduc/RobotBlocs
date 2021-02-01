// Instructions to generate charactors

void Heart()
{
  Go(3);Turn(-135);Down();Go(4);Turn(45);Go(2);Turn(45);Go(1);Turn(45);Go(1);Turn(-90);Go(1);Turn(45);Go(1);Turn(45);Go(1);Turn(45);Go(2);Turn(45);Go(4);Up();Turn(-135);Go(5);
}

void Space()
{
  Stop();                                          // ensure motors are stopped
  delay(100);                                      // allow time for battery voltage to stabilize
  volts=analogRead(Battery)/10;                    // take new battery reading to maintain optimal speed
  dspeed=26214/volts*10/volts;                     // draw speed power correction factor=100% when battery=5V (analog reading = 512)
  dspeed=dspeed*8/10;                              // adjust speed to reduce overshoot
  Up();Go(4);                                      // Space
}

void END()
{
  while(1<2)
  {
    
  }
}


