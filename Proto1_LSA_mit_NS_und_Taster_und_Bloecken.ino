
int tasterstatus=0;


void setup() {
  //Hauptstraße
  pinMode(5,OUTPUT); //Rot
  pinMode(6,OUTPUT); //Gelb
  pinMode(7,OUTPUT); //Grün

  //Nebenstraße
  pinMode(11,OUTPUT); //Rot
  pinMode(12,OUTPUT); //Gelb
  pinMode(13,OUTPUT); //Grün
  
  //Sensoren
  pinMode(22,INPUT);

}





void loop() {
  tasterstatus=digitalRead(22);
  if (tasterstatus == HIGH) //Wenn Taster gedrückt, wird Nebenstraße grün
  {
    digitalWrite(11, HIGH); 
    delay(5000);
    digitalWrite(12, HIGH);   
    delay(700);
    digitalWrite(11, LOW);    //deaktiviert Rot
    digitalWrite(12, LOW);    //deaktiviert Gelb
    digitalWrite(13, HIGH);   //Schaltet Grün
    delay(7000);
    digitalWrite(12, HIGH); //Schaltet Gelb
    digitalWrite(13, LOW);  //deaktiviert Grün
    delay(2500);
    digitalWrite(11, HIGH); //Schalte Rot
    digitalWrite(12, LOW); //deaktiviere Gelb 
  }
   
  else  
  {
    loop(); //Normale Ampelschaltung
    {
     digitalWrite(5, HIGH);    //Schaltet Rot
      delay(5000);
      digitalWrite(6, HIGH);    //Schaltet Gelb
      delay(700);
      digitalWrite(5, LOW);   //deaktiviert Rot
      digitalWrite(6, LOW);   //deaktiviert Gelb
      digitalWrite(7, HIGH);    //Schaltet Grün
      delay(21000);
      digitalWrite(6, HIGH);  //Schaltet Gelb
      digitalWrite(7, LOW); //deaktiviert Grün
      delay(2500);
      digitalWrite(5, HIGH);  //Schalte Rot
      digitalWrite(6, LOW); //deaktiviere Gelb
     digitalWrite(11, HIGH); 
    delay(5000);
    digitalWrite(12, HIGH);		//schaltet Gelb  
    delay(700);
    digitalWrite(11, LOW);    //deaktiviert Rot
    digitalWrite(12, LOW);    //deaktiviert Gelb
    digitalWrite(13, HIGH);   //Schaltet Grün
    delay(7000);
    digitalWrite(12, HIGH); //Schaltet Gelb
    digitalWrite(13, LOW);  //deaktiviert Grün
    delay(2500);
    digitalWrite(11, HIGH); //Schalte Rot
    digitalWrite(12, LOW); //deaktiviere Gelb
    }
}
}
