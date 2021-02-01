void interruption() {
  erreur();
  etatbouton = 1;
  temps = millis();
}

void erreur() {
  etatbouton = 0;
  action1realise = 0;
  tableau[99];
  n = 0;
}

void communicationradio() {}

void transmission() {
  while (action1realise == 0) {
    if ((millis() - temps) <= 2000) {
      sortie.begin(57600);
      if (!sortie.available()) {
        sortie.write(tableau[0]+1);
        sortie.write('Z');
        Serial.println("ecriture");
        delay(100);
      }
      else {
        if (sortie.read() == 'Y') {
          Serial.println("CAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAMARCCHEEEEEEEEEEEEEEEEEE");
          action1realise = 1;
        }
      }
    }
    else{Serial.println("pas d autre carte detecte");} // alors il n'y a pas d'autres cartes
        Serial.println(tableau[0]);

  }}
