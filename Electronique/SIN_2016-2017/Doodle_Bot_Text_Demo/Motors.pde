void Motors()                                      // control left and right motor "H" bridges
{
  int lmotor=abs(lspeed);                          // create temporary speed variables used for speed correction
  int rmotor=abs(rspeed);
  
  if(lmotor>255) lmotor=255;                       // limit maximum left  motor speed value 
  if(rmotor>255) rmotor=255;                       // limit maximum right motor speed value  
  
  digitalWrite(Ldirpin,(lspeed<0));                // set left  direction depending on lspeed being positive or negative
  analogWrite (Lpwmpin,lmotor);                    // set left  speed to absolute value of lspeed (ignores + or -)
  
  digitalWrite(Rdirpin,(rspeed<0));                // set right direction depending on rspeed being positive or negative
  analogWrite (Rpwmpin,rmotor);                    // set right speed to absolute value of rspeed (ignores + or -)
}
