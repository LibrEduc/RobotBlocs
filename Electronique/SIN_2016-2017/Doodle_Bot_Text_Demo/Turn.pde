void Turn(int angle)                               // +angle=CW, -angle=CCW, +/-8 =90degrees 1 motor, +/- 32+4=90 degrees 2 motors
{
  if(angle==45) angle=34;
  if(angle==-45) angle=-34;
  if(angle==90) angle=36;
  if(angle==-90) angle=-36;
  if(angle==135) angle=38;
  if(angle==-135) angle=-38;
  if(angle==180) angle=40;
  if(angle==-180) angle=-40;
  if(angle==225) angle=42;
  if(angle==-225) angle=-42;
  if(angle==270) angle=44;
  if(angle==-270) angle=-44;
  if(angle==315) angle=46;
  if(angle==-315) angle=-46; 
  if(angle==360) angle=48;
  if(angle==-360) angle=-48;
  

  byte oldpen=pen;
  byte flag=0;
  if(abs(angle)>32)                                // angles greater than 32 pivot on the spot
  {                                                // angles 1-32 stop one wheel only and pivot on that wheel.
    Up();
    turn=1;
    Go(5);
    turn=0;
    flag=1;
  }
  lcount=0;
  rcount=0;
  
  if(angle<0)
  {
    rspeed=dspeed;
    lspeed=0;
    if(angle<-32) 
    {
      lspeed=-dspeed;
      angle+=32;
    }
  }
  else
  {
    lspeed=dspeed;
    rspeed=0;
    if(angle>32) 
    {
      rspeed=-dspeed;
      angle-=32;
    }
  }
  angle=abs(angle);
  int ols=lspeed;
  int ors=rspeed;
  Motors();

  if(lspeed==0 || rspeed==0)                       // pivot about one wheel
  {  
    while(lcount<angle && rcount<angle)
    {
    }
  }
  else                                             // pivot about a point
  {
    while(lcount<angle || rcount<angle)
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
  }
  Stop();
  if(flag==1)                                      // pivot about a point
  {
    turn=1;
    Go(-5);
    turn=0;
    if(oldpen==1) Down();
  }
}



