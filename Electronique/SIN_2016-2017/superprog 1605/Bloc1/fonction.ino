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
    //Serial.println("action1realise 0");
    if ((millis() - temps) <= 500) {
      //Serial.println("Temps inferieur a deux secondes");

      sortie.begin(57600);
      if (!sortie.available()) {
        sortie.write(tableau[0] + 1);
        sortie.write('Z');
        Serial.println("Envoie de la lettre Z = y a t'il un autre bloc ?");
        delay(100);
      }
      else {
        if (sortie.read() == 'Y') {
          Serial.println("Lecture de la lettre Y = il y a un bloc");
          transmettrefonction();
        }
      }
    }
    else {
      Serial.println("Pas de reponse : pas d'autre bloc apres moi");
      envoyerfonction();
      Serial.println("Redemarrage du bloc dans 5 secondes ...");
      delay(5000);
      asm("jmp 0x00");
    } // alors il n'y a pas d'autres cartes
  }
}

void envoyerfonction() {
    liresafonction();
  while (action2realise == 0) {
    
    //Serial.println("ok");
    entree.begin(57600);
    if ((!entree.available())&&(cbon==0)) {
      Serial.print("Envoie de ma fonction : ");
      Serial.println(fonction);
      entree.write(fonction);
      entree.write('Z');
cbon==1;

      //delay(100);
          //Serial.println("a");

    }
    else {
      if (entree.read() == 'Y') {
        //Serial.println("CAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAMARCCHEEEEEEEEEEEEEEEEEE");
        action2realise = 1;
      }
    }
        //Serial.println("terminé");

  }
}

void transmettrefonction() {
  while (action3realise == 0) {
    //Serial.println("action3realise 0");
    //liresafonction();
    while (action4realise == 0) {
      //Serial.println("action4realise 0");
      sortie.begin(57600);
      if (sortie.available())                       //:Si on reçoit quelque chose alors :
      {
        Serial.print("On recoit quelque chose : ");
        qe = sortie.read();                            //Lecture de ce que je reçoit
        Serial.println(qe);
        tableau2[x] = qe;                                  //Stockage de ce que je reçoit dans un tableau en fonction de i
        x++;                                             //Incrémentation de i pour stocker la prochaine donnée éventuelle dans le tableau
        if (qe == 'Z')                                       //;Si on reçoit A, cela signifie que l'on a reçu la totalité des données
        {
          Serial.println("On a recu la lettre Z = fin de la reception");
          sortie.write('Y');                                   //On envoie Z pour signifier que l'on a bien compris le message
          i = x;  
          h=i-1;
//On sauvegarde la valeur de i dans z
          action4realise = 1;
        }                                                    //;
      }
      /* else{          Serial.println("On recoit rien");
        }*/
    }
    while (action4realise == 1) {
      //Serial.println("action4realise 1");
      liresafonction();
      entree.begin(57600);
      for (x = 0; x < i - 1; x++) {                      //-Pour i allant de 0 à z(= à i) on va lire le tableau (afin de potentiellement le renvoyer
        char cas = tableau2[x];
        //Serial.println("Envoie de ma fonction");
        entree.write(cas);
        delay(100);



        //delay(100);
        Serial.print("Envoie du caractere du bloc ");
        Serial.print(h);
        Serial.print(" : ");
        Serial.println(cas);
        h=h-1;
      }
      Serial.print("Envoie de ma fonction : ");
      Serial.println(fonction);
      entree.write(fonction);
      //entree.write("H");
      entree.write('Z');
      //delay(50);

      while (!entree.available()) {
        Serial.println("attente de la confirmation Y");
      }
      if (entree.read() == 'Y') {
        //Serial.println("bug");
        reboot();
        action4realise = 2;
      }
    }
  }
}



void liresafonction() {
  Serial.println("Etat des capteurs :");
  etatcapteur1 = digitalRead( capteur1 );
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


void reboot() {
  Serial.println("Redemarrage du bloc dans 5 secondes ...");
  delay(5000); asm("jmp 0x00");
}
