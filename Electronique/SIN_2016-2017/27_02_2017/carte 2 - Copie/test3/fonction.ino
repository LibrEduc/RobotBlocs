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
    Serial.println("action1realise 0");
    if ((millis() - temps) <= 500) {
      Serial.println("Temps inferieur a deux secondes");

      sortie.begin(57600);
      if (!sortie.available()) {
        sortie.write(tableau[0] + 1);
        sortie.write('Z');
        Serial.println("Ecriture du nombre de carte +Z");
        delay(100);
      }
      else {
        if (sortie.read() == 'Y') {
          Serial.println("Lecture de la lettre Y");
          transmettrefonction();
        }
      }
    }
    else {
      Serial.println("Aucune autre carte detectee");
      envoyerfonction();
      Serial.println("REBOOT DANS 5SECONDES");
      delay(5000);
      asm("jmp 0x00");
    } // alors il n'y a pas d'autres cartes
  }
}

void envoyerfonction() {
  while (action2realise == 0) {
    liresafonction();
    entree.begin(57600);
    if (!entree.available()) {
      Serial.println("On envoie fonction + Z");
      entree.write(fonction);
      entree.write('Z');
      delay(100);
    }
    else {
      if (entree.read() == 'D') {
        Serial.println("On recoit Y = fin de journee");
        action2realise = 1;
      }
    }
  }
}

void transmettrefonction() {
  while (action3realise == 0) {
    Serial.println("action3realise 0");
    liresafonction();
    while (action4realise == 0) {
      Serial.println("action4realise 0");
      sortie.begin(57600);
      if (sortie.available())                       //:Si on reçoit quelque chose alors :
      {
        Serial.println("On reçoit des trucs");
        qe = sortie.read();                            //Lecture de ce que je reçoit
        //Serial.print(qe);
        tableau2[x] = qe;                                  //Stockage de ce que je reçoit dans un tableau en fonction de i
        x++;                                             //Incrémentation de i pour stocker la prochaine donnée éventuelle dans le tableau
        if (qe == 'Z')                                       //;Si on reçoit A, cela signifie que l'on a reçu la totalité des données
        {
          Serial.println("Z a ete lu, on envoie Y");
          sortie.write('Y');                                   //On envoie Z pour signifier que l'on a bien compris le message
          i = x;                                                 //On sauvegarde la valeur de i dans z
          action4realise = 1;
        }                                                    //;
      }
      else{          Serial.println("On recoit rien");
}
    }
    while (action4realise == 1) {
      Serial.println("action4realise 1");
      entree.begin(57600);
      for (x = 0; x < i; x++) {                        //-Pour i allant de 0 à z(= à i) on va lire le tableau (afin de potentiellement le renvoyer
        entree.write(tableau2[x]);
        delay(100);
        Serial.println("renvoie des caracteres");

      }
      entree.write(fonction);
      entree.write('Z');

      while (!entree.available()) {
        Serial.println("attente de la confirmation Y");
      }
      if (entree.read() == 'Y') {
        action3realise = 1;
      }
    }
  }
}



void liresafonction() {
  fonction = 'V';
  Serial.println("Ma fonction est D");

}
