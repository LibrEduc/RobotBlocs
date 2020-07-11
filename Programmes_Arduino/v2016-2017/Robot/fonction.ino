/*
  Créé l'année scolaire 2016/2017,
  par les élèves de SIN du LYCEE EUGENE LIVET :
  Pierre NICOLAS, Hugo DENIER, Martin POREE et Sullivan LETOUZIC
*/

// AVANCE TOUT DROIT SELON LE NOMBRE DE PAS DEMANDE
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
//==================================================================================================================================================================
// ETEINT LES MOTEURS POUR ECONOMISER DE L'ENERGIE
void arret()
{
  digitalWrite(sleep, 0);
  digitalWrite(sleep2, 0);
}
//==================================================================================================================================================================
// TOURNER A GAUCHE SELON LE NOMBRE DE PAS DEMANDE
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
}//==================================================================================================================================================================
// TOURNER A DROITE SELON LE NOMBRE DE PAS DEMANDE
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
//==================================================================================================================================================================
// RECULE TOUT DROIT SELON LE NOMBRE DE PAS DEMANDE
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
//==================================================================================================================================================================
// CONVERTIT UN ANGLE EN NOMBRE DE PAS
void calculangle(float angle)
{
  angle = angle / 360;
  Serial.print("angle = ");
  Serial.println(angle);
  perimetreroue = pi * diametreroue;
  Serial.print("perimetre roue = ");
  Serial.println(perimetreroue);
  perimetresol = pi * diametrentreroue;
  Serial.print("perimetre sol = ");
  Serial.println(perimetresol);
  tourentier = perimetresol / perimetreroue;
  Serial.print("tour entier = ");
  Serial.println(tourentier);
  pas = tourentier * nbrdepas * angle;
  Serial.print("pas = ");
  Serial.println(pas);
}
//==================================================================================================================================================================
// GERE LA MUSIQUE
void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}
//==================================================================================================================================================================
// LEVE LE CRAYON AVEC UN SERVOMOTEUR
void levercrayon() {
  servo.write(150);
  }
//==================================================================================================================================================================
// BAISSE LE CRAYON AVEC UN SERVOMOTEUR
void baissercrayon() {*
servo.write(180); // FAIRE LES AJUSTEMENTS
}
