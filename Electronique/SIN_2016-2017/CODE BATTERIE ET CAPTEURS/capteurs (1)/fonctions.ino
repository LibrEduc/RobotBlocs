void lecturecapteur(){
  etatcapteur1 = digitalRead( capteur1 );
  etatcapteur1 = not( etatcapteur1 );
  Serial.println(etatcapteur1);

  etatcapteur2 = digitalRead( capteur2 );
  etatcapteur2 = not( etatcapteur2 );
    Serial.println(etatcapteur2);

  
    etatcapteur3 = digitalRead( capteur3 );
  etatcapteur3 = not( etatcapteur3 );
    Serial.println(etatcapteur3);

  
    etatcapteur4 = digitalRead( capteur4 );
  etatcapteur4 = not( etatcapteur4 );
    Serial.println(etatcapteur4);

  
  if((etatcapteur1==0)&&(etatcapteur2==0)&&(etatcapteur3==0)&&(etatcapteur4==0)){
  Serial.println("forme 1");
  }
  if((etatcapteur1==0)&&(etatcapteur2==0)&&(etatcapteur3==0)&&(etatcapteur4==1)){
  Serial.println("forme 2");
  }
  if((etatcapteur1==0)&&(etatcapteur2==0)&&(etatcapteur3==1)&&(etatcapteur4==0)){
  Serial.println("forme 3");
  }
  if((etatcapteur1==0)&&(etatcapteur2==0)&&(etatcapteur3==1)&&(etatcapteur4==1)){
  Serial.println("forme 4");
  }
  if((etatcapteur1==0)&&(etatcapteur2==1)&&(etatcapteur3==0)&&(etatcapteur4==0)){
  Serial.println("forme 5");
  }
  if((etatcapteur1==0)&&(etatcapteur2==1)&&(etatcapteur3==0)&&(etatcapteur4==1)){
  Serial.println("forme 6");
  }
  if((etatcapteur1==0)&&(etatcapteur2==1)&&(etatcapteur3==1)&&(etatcapteur4==0)){
  Serial.println("forme 7");
  }
  if((etatcapteur1==0)&&(etatcapteur2==1)&&(etatcapteur3==1)&&(etatcapteur4==1)){
  Serial.println("forme 8");
  }
  if((etatcapteur1==1)&&(etatcapteur2==0)&&(etatcapteur3==0)&&(etatcapteur4==0)){
  Serial.println("forme 9");
  }
  if((etatcapteur1==1)&&(etatcapteur2==0)&&(etatcapteur3==0)&&(etatcapteur4==1)){
  Serial.println("forme 10");
  }
  if((etatcapteur1==1)&&(etatcapteur2==0)&&(etatcapteur3==1)&&(etatcapteur4==0)){
  Serial.println("forme 11");
  }
  if((etatcapteur1==1)&&(etatcapteur2==0)&&(etatcapteur3==1)&&(etatcapteur4==1)){
  Serial.println("forme 12");
  }
  if((etatcapteur1==1)&&(etatcapteur2==1)&&(etatcapteur3==0)&&(etatcapteur4==0)){
  Serial.println("forme 13");
  }
  if((etatcapteur1==1)&&(etatcapteur2==1)&&(etatcapteur3==0)&&(etatcapteur4==1)){
  Serial.println("forme 14");
  }
  if((etatcapteur1==1)&&(etatcapteur2==1)&&(etatcapteur3==1)&&(etatcapteur4==0)){
  Serial.println("forme 15");
  }
  if((etatcapteur1==1)&&(etatcapteur2==1)&&(etatcapteur3==1)&&(etatcapteur4==1)){
  Serial.println("forme 16");
  }
}
