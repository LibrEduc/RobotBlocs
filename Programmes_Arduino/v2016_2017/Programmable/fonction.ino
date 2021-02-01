/*
  Créé l'année scolaire 2016/2017,
  par les élèves de SIN du LYCEE EUGENE LIVET :
  Pierre NICOLAS, Hugo DENIER, Martin POREE et Sullivan LETOUZIC
*/

// SAVOIR SI UN BLOC EST A COTE DE NOUS
void transmission() {
  while (action1realise == 0) {
    if ((millis() - temps) <= 500) {
      sortie.begin(57600);
      if (!sortie.available()) { // ON ENVOIE Z POUR SAVOIR SI UN BLOC EST LA
        sortie.write(tableau[0] + 1);
        sortie.write('Z');
        Serial.println("Envoie de la lettre Z = y a t'il un autre bloc ?");
        delay(100);
      }
      else { // ON RECOIT Y DONC UN BLOC EST PRESENT
        if (sortie.read() == 'Y') {
          Serial.println("Lecture de la lettre Y = il y a un bloc");
          transmettrefonction(); // TRANSFERER LES FONCTIONS VERS LE BLOC MAITRE
        }
      }
    }
    else { // PAS DE REPONSE DONC PAS DE BLOC APRES NOUS
      Serial.println("Pas de reponse : pas d'autre bloc apres moi");
      envoyerfonction(); // ON ENVOIE SA FONCTION
      reboot(); // REDEMARRARE DE LA CARTE
    }
  }
}
//==================================================================================================================================================================
// ENVOYER SA FONCTION 
void envoyerfonction() {
  liresafonction(); // LIRE LE COUVERCLE
  while (action2realise == 0) {
    entree.begin(57600);
    if ((!entree.available()) && (envoi == 0)) { // ON ENVOIE SA FONCTION
      Serial.print("Envoie de ma fonction : ");
      Serial.println(fonction);
      entree.write(fonction);
      entree.write('Z');
      envoi == 1;
    }
    else { // ON ATTEND L'ACCUSE DE RECEPTION
      if (entree.read() == 'Y') {
        action2realise = 1;
      }
    }
  }
}
//==================================================================================================================================================================
// LIRE LES FONCTIONS DES AUTRES BLOCS ET Y AJOUTER SA FONCTION
void transmettrefonction() {
  while (action3realise == 0) {
    while (action4realise == 0) {
      sortie.begin(57600);
      if (sortie.available()) // ON RECOIT QQCHOSE
      {
        Serial.print("On recoit quelque chose : ");
        qe = sortie.read(); // LECTURE DE CE QUE JE RECOIS
        Serial.println(qe);
        tableau2[x] = qe; // STOCKAGE DE CE QUE JE RECOIS
        x++;                                             
        if (qe == 'Z') // SI ON A RECU Z ALORS RECEPTION TERMINEE
        {
          Serial.println("On a recu la lettre Z = fin de la reception");
          sortie.write('Y'); // ON VALIDE LA RECEPTION
          i = x;
          h = i - 1;
          action4realise = 1;
        }                                                  
      }
    }
    while (action4realise == 1) {
      liresafonction(); // ON LIT LA FONCTION DU COUVERCLE
      entree.begin(57600);
      for (x = 0; x < i - 1; x++) { // ON RENVOIT CE QU'ON VIENT DE RECEVOIR
        char cas = tableau2[x];
        entree.write(cas);
        delay(100);
        Serial.print("Envoie du caractere du bloc ");
        Serial.print(h);
        Serial.print(" : ");
        Serial.println(cas);
        h = h - 1;
      }
      Serial.print("Envoie de ma fonction : ");
      Serial.println(fonction); 
      entree.write(fonction); // ET ON ENVOIE NOTRE FONCTION
      entree.write('Z'); // ON VALIDE L'ENVOIE
      
      while (!entree.available()) {
        Serial.println("attente de la confirmation Y");
      }
      if (entree.read() == 'Y') { // ON RECOIT L'ACCUSE DE RECEPTION
        reboot();
        action4realise = 2;
      }
    }
  }
}
//==================================================================================================================================================================
// ON LIT LA FONCTION PORTEE PAR LE COUVERCLE
void liresafonction() {
  Serial.println("Etat des capteurs :");
  etatcapteur1 = digitalRead( capteur1 ); // ON LIT LE CAPTEUR POUR SAVOIR S'IL CAPTE OU NON UN AIMANT
  etatcapteur1 = not( etatcapteur1 );
  Serial.print("Capteur 1 : ");
  Serial.println(etatcapteur1);

  etatcapteur2 = digitalRead( capteur2 );
  etatcapteur2 = not( etatcapteur2 );
  Serial.print("Capteur 2 : ");
  Serial.println(etatcapteur2);

  etatcapteur3 = digitalRead( capteur3 );
  etatcapteur3 = not( etatcapteur3 );
  Serial.print("Capteur 3 : ");
  Serial.println(etatcapteur3);

  etatcapteur4 = digitalRead( capteur4 );
  etatcapteur4 = not( etatcapteur4 );
  Serial.print("Capteur 4 : ");
  Serial.println(etatcapteur4);

  Serial.print("Cela correspond à la forme : ");
  // ON INTERPRETE LES DONNEES
  if ((etatcapteur1 == 0) && (etatcapteur2 == 0) && (etatcapteur3 == 0) && (etatcapteur4 == 0)) { 
    fonction = 'A';
    Serial.print("forme 1 ");
  }
  else {
    if ((etatcapteur1 == 0) && (etatcapteur2 == 0) && (etatcapteur3 == 0) && (etatcapteur4 == 1)) {
      Serial.print("forme 2 ");
      fonction = 'B';
    }
    else {
      if ((etatcapteur1 == 0) && (etatcapteur2 == 0) && (etatcapteur3 == 1) && (etatcapteur4 == 0)) {
        Serial.print("forme 3 ");
        fonction = 'C';
      }
      else {
        if ((etatcapteur1 == 0) && (etatcapteur2 == 0) && (etatcapteur3 == 1) && (etatcapteur4 == 1)) {
          Serial.print("forme 4 ");
          fonction = 'D';
        }
        else {
          if ((etatcapteur1 == 0) && (etatcapteur2 == 1) && (etatcapteur3 == 0) && (etatcapteur4 == 0)) {
            Serial.print("forme 5 ");
            fonction = 'E';
          }
          else {
            if ((etatcapteur1 == 0) && (etatcapteur2 == 1) && (etatcapteur3 == 0) && (etatcapteur4 == 1)) {
              Serial.print("forme 6 ");
              fonction = 'F';
            }
            else {
              if ((etatcapteur1 == 0) && (etatcapteur2 == 1) && (etatcapteur3 == 1) && (etatcapteur4 == 0)) {
                Serial.print("forme 7 ");
                fonction = 'G';
              }
              else {
                if ((etatcapteur1 == 0) && (etatcapteur2 == 1) && (etatcapteur3 == 1) && (etatcapteur4 == 1)) {
                  Serial.print("forme 8 ");
                  Serial.println("lol");

                  fonction = 'H';
                }
                else {
                  if ((etatcapteur1 == 1) && (etatcapteur2 == 0) && (etatcapteur3 == 0) && (etatcapteur4 == 0)) {
                    Serial.print("forme 9 ");
                    fonction = 'I';
                  }
                  else {
                    if ((etatcapteur1 == 1) && (etatcapteur2 == 0) && (etatcapteur3 == 0) && (etatcapteur4 == 1)) {
                      Serial.print("forme 10 ");
                      fonction = 'J';
                    }
                    else {
                      if ((etatcapteur1 == 1) && (etatcapteur2 == 0) && (etatcapteur3 == 1) && (etatcapteur4 == 0)) {
                        Serial.print("forme 11 ");
                        fonction = 'K';
                      }
                      else {
                        if ((etatcapteur1 == 1) && (etatcapteur2 == 0) && (etatcapteur3 == 1) && (etatcapteur4 == 1)) {
                          Serial.print("forme 12 ");
                          fonction = 'L';
                        }
                        else {
                          if ((etatcapteur1 == 1) && (etatcapteur2 == 1) && (etatcapteur3 == 0) && (etatcapteur4 == 0)) {
                            Serial.print("forme 13 ");
                            fonction = 'M';
                          }
                          else {
                            if ((etatcapteur1 == 1) && (etatcapteur2 == 1) && (etatcapteur3 == 0) && (etatcapteur4 == 1)) {
                              Serial.print("forme 14 ");
                              fonction = 'N';
                            }
                            else {
                              if ((etatcapteur1 == 1) && (etatcapteur2 == 1) && (etatcapteur3 == 1) && (etatcapteur4 == 0)) {
                                Serial.print("forme 15 ");
                                fonction = 'O';
                              }
                              else {
                                if ((etatcapteur1 == 1) && (etatcapteur2 == 1) && (etatcapteur3 == 1) && (etatcapteur4 == 1)) {
                                  Serial.print("forme 16 ");


                                  fonction = 'P';
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  Serial.print("et donc a la lettre : ");
  Serial.println(fonction);
}
//==================================================================================================================================================================
// REDEMARRARE DE LA CARTE
void reboot() {
  Serial.println("Redemarrage du bloc dans 5 secondes ...");
  delay(5000); asm("jmp 0x00");
}
//==================================================================================================================================================================
