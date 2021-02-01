 void toutdroit(int pas)
{
  int i;
  for (i = 1; i < pas; i++)
  {
    digitalWrite(dir, 1);
    digitalWrite(dir2, 1);
    
    digitalWrite(sleep, 1);
    digitalWrite(istep, 1);
    digitalWrite(sleep2, 1);
    digitalWrite(istep2, 1);

    delayMicroseconds(1000);
    digitalWrite(istep, 0);
    digitalWrite(istep2, 0);

    delayMicroseconds(1000);
  }
}

void stop()
{
  digitalWrite(sleep, 0);
  digitalWrite(sleep2, 0);

  // digitalWrite(istep,0);
}

void gauche(int pas)
{
  int i;
  for (i = 1; i < pas; i++)
  {
    digitalWrite(dir, 1);
    digitalWrite(dir2, 0);
    
    digitalWrite(sleep, 1);
    digitalWrite(istep, 1);
    digitalWrite(sleep2, 1);
    digitalWrite(istep2, 1);

    delayMicroseconds(1000);

    digitalWrite(istep, 0);
    digitalWrite(istep2, 0);


    delayMicroseconds(1000);
  }
}

void droite(int pas)
{
  int i;
  for (i = 1; i < pas; i++)
  {
    digitalWrite(dir, 0);
    digitalWrite(dir2, 1);
    
    digitalWrite(sleep, 1);
    digitalWrite(istep, 1);
    digitalWrite(sleep2, 1);
    digitalWrite(istep2, 1);

    delayMicroseconds(1000);

    digitalWrite(istep, 0);
    digitalWrite(istep2, 0);


    delayMicroseconds(1000);
  }
}

void reculer(int pas)
{
  int i;
  for (i = 1; i < pas; i++)
  {
    digitalWrite(dir, 1);
    digitalWrite(dir2, 1);
    
    digitalWrite(sleep, 1);
    digitalWrite(istep, 1);
    digitalWrite(sleep2, 1);
    digitalWrite(istep2, 1);

    delayMicroseconds(1000);
    digitalWrite(istep, 0);
    digitalWrite(istep2, 0);

    delayMicroseconds(1000);
  }
}


 void calculangle(float angle)
{
  angle=angle/360;
  Serial.print("angle = ");
 Serial.println(angle);
 perimetreroue=pi*diametreroue;
  Serial.print("perimetre roue = ");
 Serial.println(perimetreroue);
 perimetresol=pi*diametrentreroue;
  Serial.print("perimetre sol = ");
 Serial.println(perimetresol);
 tourentier=perimetresol/perimetreroue;
  Serial.print("tour entier = ");
 Serial.println(tourentier);
 

 pas=tourentier*nbrdepas*angle;
  Serial.print("pas = ");
 Serial.println(pas);
 
}


