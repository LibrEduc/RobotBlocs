void Go(int distance)
{
  lcount=0;                                        // reset left wheel encoder counter
  rcount=0;                                        // reset right wheel encoder counter
  
  Stop();
  delay(100);
  volts=analogRead(Battery)/10;
  dspeed=26214/volts*10/volts;                     // draw speed power correction factor=100% when battery=5V (analog reading = 512)
  dspeed=dspeed*8/10;                              // adjust speed to reduce overshoot
  
  if(distance>0)                                   // distance values>0 tell the robot to go forward
  {
    lspeed=dspeed;
    rspeed=dspeed;
  }
  else                                             // distance values less than 0 tell the robot to go backward
  {
    lspeed=-dspeed;
    rspeed=-dspeed;
  }
  distance=abs(distance);                          // distance only - ignore direction
  if(turn==0) distance*=charsize;
  int ols=lspeed;
  int ors=rspeed;
  
  
  while(lcount<distance || rcount<distance)        // travel until both wheel encoders count correct distance
  {
    if(lcount>rcount)
    {
      lspeed=0;
    }
    else
    {
      lspeed=ols;
    }
    if(rcount>lcount)
    {
      rspeed=0;
    }
    else
    {
      rspeed=ors;
    }
    Motors();
  }
  Stop();                                          // ensure both motors are completely stopped
}
