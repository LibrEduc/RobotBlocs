/*
  Créé l'année scolaire 2016/2017,
  par les élèves de SIN du LYCEE EUGENE LIVET :
  Pierre NICOLAS, Hugo DENIER, Martin POREE et Sullivan LETOUZIC
*/

// FAIRE UN CARRE
void carre()
{
  calculangle(90);
  droite(pas);
  baissercrayon();
  toutdroit(800);
  gauche(pas);
  toutdroit(1600);
  gauche(pas);
  toutdroit(1600);
  gauche(pas);
  toutdroit(1600);
  gauche(pas);
  toutdroit(800);
  levercrayon();
  gauche(pas);
  toutdroit(2400);
  arret();
  delay(1000);
}
//==================================================================================================================================================================
// FAIRE UN TRIANGLE
void triangle()
{
  calculangle(90);
  droite(pas);
  baissercrayon();
  toutdroit(800);
  calculangle(120);
  gauche(pas);
  toutdroit(1600);
  gauche(pas);
  toutdroit(1600);
  gauche(pas);
  toutdroit(800);
  calculangle(90);
  levercrayon();
  gauche(pas);
  toutdroit(2200);
  arret();
  delay(1000);
}
//==================================================================================================================================================================
// FAIRE LA MELODIE
void melodie()
{
  int length = 15; // NOMBRE DE NOTES
  char notes[] = "ccggaagffeeddc ";
  int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
  int tempo = 300;
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
      playNote(notes[i], beats[i] * tempo);
    }
    delay(tempo / 2);
  }
  delay(1000);
}
//==================================================================================================================================================================
// FAIRE UN TRAIT VERS L'AVANT
void avant()
{
  baissercrayon();
  toutdroit(1600);
  levercrayon();
  toutdroit(800);
  arret();
  delay(1000);
}
//==================================================================================================================================================================
// FAIRE UN TRAIT HORIZONTAL
void gauchedroite()
{
  calculangle(90);
  droite(pas);
  toutdroit(800);
  calculangle(180);
  gauche(pas);
  baissercrayon();
  toutdroit(1600);
  levercrayon();
  gauche(pas);
  toutdroit(800);
  calculangle(90);
  gauche(pas);
  toutdroit(800);
  arret();
  delay(1000);
}
//==================================================================================================================================================================
// FAIRE UN HEXAGONE
void hexagone()
{
  calculangle(90);
  droite(pas);
  baissercrayon();
  toutdroit(400);
  calculangle(60);
  gauche(pas);
  toutdroit(800);
  gauche(pas);
  toutdroit(800);
  gauche(pas);
  toutdroit(800);
  gauche(pas);
  toutdroit(800);
  gauche(pas);
  toutdroit(800);
  gauche(pas);
  toutdroit(400);
  calculangle(90);
  levercrayon();
  gauche(pas);
  toutdroit(2400); // a recalculer
  arret();
  delay(1000);
}
//==================================================================================================================================================================
// FAIRE UN RECTANGLE
void rectangle()
{
  calculangle(90);
  droite(pas);
  baissercrayon();
  toutdroit(800);
  gauche(pas);
  toutdroit(800);
  gauche(pas);
  toutdroit(1600);
  gauche(pas);
  toutdroit(800);
  gauche(pas);
  toutdroit(800);
  levercrayon();
  gauche(pas);
  toutdroit(1600);
  arret();
  delay(1000);
}
//==================================================================================================================================================================
// FAIRE UN LOSANGE
void losange()
{
  calculangle(65);
  droite(pas);
  baissercrayon();
  toutdroit(800);
  calculangle(130);
  gauche(pas);
  toutdroit(800);
  calculangle(50);
  gauche(pas);
  toutdroit(800);
  calculangle(130);
  gauche(pas);
  toutdroit(800);
  levercrayon();
  calculangle(50);
  gauche(pas);
  toutdroit(2400);
  arret();
  delay(1000);
}
//==================================================================================================================================================================

