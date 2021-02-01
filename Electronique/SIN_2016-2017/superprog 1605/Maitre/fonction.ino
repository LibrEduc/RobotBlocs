void action1realise0() {
  while (action1realise == 0) {                                                              //b Réalisation de l'action 1 qui consiste à compter le nombre de block
    //Serial.println("Action1realise 0");
    sortie.write("1Z");
    sortie.begin(57600);
    temps = millis();
    Serial.println("Envoie de la lettre Z = y a t'il un bloc ?");

    while ((!sortie.available()) && (action1realise == 0) ) {                                                                //d-0 Si l'on ne reçoit rien alors on écrit 1Z 1=block maitre et Z=STOP
      //Serial.println("Lecture");
      if ((millis() - temps) >= 500) {
        asm("jmp 0x00");
      }
      if (sortie.read() == 'Y') {
        Serial.println("Lecture de la lettre Y = il y a un bloc");
        action1realise = 1;
      }
    }                                                                  //c-1
  }
}
//==================================================================================================================================================================
void action2realise0() {
  while (action2realise == 0) {                                  //!Permet de n'envoyer qu'une seule fois l'information à partir du moment ou la communication est faite
    //Serial.println("Action2realise 0");
    sortie.begin(57600);

    if (sortie.available())                       //:Si on reçoit quelque chose alors :
    {
      qe = sortie.read();                            //Lecture de ce que je reçoit
      Serial.println(qe);

      tableau2[x] = qe;                                  //Stockage de ce que je reçoit dans un tableau en fonction de i
      x++;
      //Serial.print("On recoit quelque chose : ");

      //Incrémentation de i pour stocker la prochaine donnée éventuelle dans le tableau

      if (qe == 'Z')                                       //;Si on reçoit A, cela signifie que l'on a reçu la totalité des données
      {
        Serial.println("On a reçu la lettre Z = fin de la transmission");
        sortie.begin(57600);
        sortie.write('Y');                                   //On envoie Z pour signifier que l'on a bien compris le message
        delay(100);
        i = x;                                                 //On sauvegarde la valeur de i dans z
        action2realise = 1;
      }                                                    //;
    }
    else {
      //Serial.println("Non, on ne recoit rien");
    }
  }
}
//==================================================================================================================================================================
void action2realise1() {
  while (action2realise == 1) {
    radio.write(&("Z"), sizeof("Z"));
    while (recu == 0) {
      radio.openReadingPipe(0, rxAddr);
      radio.startListening();
      Serial.println("onnerecoitrien"); //lire le texte dans moniteur série

      if (radio.available())  // Si on reçoit quelques choses
      {
        radio.read(&text, sizeof(text));
        Serial.println(text); //lire le texte dans moniteur série
        if (text == 'Y') {
          Serial.println("onrecoitY"); //lire le texte dans moniteur série
          recu = 1;
        }
      }
    }

    while (envoi == 0) {
      // BOUCLE D'ECRITURE DES FORMES

      Serial.println("onecritlesformes"); //lire le texte dans moniteur série

      radio.setRetries(15, 15);
      radio.openWritingPipe(rxAddr);
      radio.stopListening();

      for (int x = i-2; x >= 0; x--) {                      //-Pour i allant de 0 à z(= à i) on va lire le tableau (afin de potentiellement le renvoyer*
        Serial.println(tableau2[x]);
        radio.write(&tableau2[x], sizeof(tableau2[x]));
      }

      // radio.write(&("Z"), sizeof("Z");
      radio.write(&("Z"), sizeof("Z"));

      Serial.println("redemarrage dans 5secondes"); //lire le texte dans moniteur série
      delay(5000);
      asm("jmp 0x00");
    }
  }
  /*
    radio.begin();
    radio.setRetries(15, 15);
    radio.openWritingPipe(rxAddr);
    radio.stopListening();
    Serial.println("Les fonctions reçus sont : ");

    for (x = 0; x < i - 1; x++) {                      //-Pour i allant de 0 à z(= à i) on va lire le tableau (afin de potentiellement le renvoyer
    Serial.println(tableau2[x]);
    //Serial.println("ouep");
    radio.write(&tableau2[x], sizeof(tableau2[x]));
         // Serial.println("ouepp");

    }      //-

    //Serial.println("stop");
    Serial.println("Redemarrage du bloc dans 5 secondes ...");
    delay(5000);
    asm("jmp 0x00");
    }*/
}
//==================================================================================================================================================================
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
void ledRVBpwm(int pwmRouge, int pwmVert, int pwmBleu) {
  analogWrite(ledRouge, pwmRouge);
  analogWrite(ledVert, pwmVert);
  analogWrite(ledBleu, pwmBleu);
}
//==================================================================================================================================================================
