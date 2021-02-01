void interruption() {
  if (etatbouton == 1) {
    erreur();
    loop();
  }
  else {
    etatbouton = 1;
    temps = millis();
  }
  while (digitalRead(pinbouton) == 1);
}

void erreur() {
  //asm("jmp 0x00");
  //etatbouton = 0;
  action1realise = 0;
  action2realise = 0;
  x = 0;
  n = 0;
  i = 0;
      temps = millis();

}

void communicationradio() {}
