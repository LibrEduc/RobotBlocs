/*
  Créé l'année scolaire 2016/2017,
  par les élèves de SIN du LYCEE EUGENE LIVET :
  Pierre NICOLAS, Hugo DENIER, Martin POREE et Sullivan LETOUZIC
*/

// COMPTER LE NOMBRE DE BLOCS DANS LA SEQUENCE
void action1realise0() {
  while (action1realise == 0) {
    sortie.write("1Z"); // ON DEMANDE S'IL Y A UN BLOC A COTE
    temps = millis();
    Serial.println("Envoie de la lettre Z = y a t'il un bloc ?");

    while ((!sortie.available()) && (action1realise == 0) ) {
      if ((millis() - temps) >= 500) { // TEMPS ECOULE ; PAS DE REPONSE ; RESET DE LA CARTE
        asm("jmp 0x00");
      }
      if (sortie.read() == 'Y') { // IL Y A UNE REPONSE ET DONC UN BLOC
        Serial.println("Lecture de la lettre Y = il y a un bloc");
        action1realise = 1;
      }
    }
  }
}
//==================================================================================================================================================================
// RECUPERER LES FONCTIONS DES BLOCS
void action2realise0() {
  while (action2realise == 0) {
    if (sortie.available()) // ATTENTE DE RECEVOIR QQCHOSE
    {
      qe = sortie.read(); // LECTURE DE CE QUE JE RECOIS
      Serial.println(qe);
      tableau2[x] = qe; // ET STOCKAGE DANS UN TABLEAU
      x++;

      if (qe == 'Z') // SI ON RECOIT Z CELA SIGNIFIE QUE L'ONT A TOUT RECU
      {
        Serial.println("On a reçu la lettre Z = fin de la transmission");
        sortie.write('Y');
        delay(100);
        i = x;
        action2realise = 1;
      }
    }
  }
}
//==================================================================================================================================================================
// ENVOYER AU ROBOT LES FONCTIONS DES BLOCS
void action2realise1() {
  while (action2realise == 1) {
    radio.write(&("Z"), sizeof("Z")); // ON ENVOIE Z POUR VERIFIER LA CONNEXION AVEC LE ROBOT
    while (recu == 0) {
      radio.openReadingPipe(0, rxAddr);
      radio.startListening();

      if (radio.available()) // SI ON RECOIT Y ALORS LA CONNEXION FONCTIONNE
      {
        radio.read(&text, sizeof(text));
        Serial.println(text);
        if (text == 'Y') {
          Serial.println("On recoit Y");
          recu = 1;
        }
      }
    }

    while (envoi == 0) { // ENVOIE DES FONCTIONS AU ROBOT
      Serial.println("On envoit les fonctions"); //lire le texte dans moniteur série
      radio.setRetries(15, 15);
      radio.openWritingPipe(rxAddr);
      radio.stopListening();

      for (int x = i - 2; x >= 0; x--) { // DEROULEMENT DU TABLEAU
        Serial.println(tableau2[x]);
        radio.write(&tableau2[x], sizeof(tableau2[x]));
      }

      radio.write(&("Z"), sizeof("Z")); // ENVOIT DE Z POUR TERMINER LA LIAISON

      Serial.println("Redemarrage dans 5secondes");
      delay(5000);
      asm("jmp 0x00");
    }
  }
}
//==================================================================================================================================================================
// LA LECTURE DE LA BATTERIE SE FAIT A L'AIDE D'UN PONT DIVISEUR DE TENSION 
void lecturedebatterie() {
  lecturebatterie = analogRead(batterie);
  voltage = 0.0098 * lecturebatterie;
  Serial.println("La batterie est a :");
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
  }
}
//==================================================================================================================================================================
