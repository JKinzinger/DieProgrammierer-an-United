void setup() {
pinMode(7,OUTPUT);

pinMode(8,OUTPUT);

pinMode(5,OUTPUT);

}

void loop() {
 digitalWrite(7,HIGH);  //Schaltet Rot
 delay(5000);
 digitalWrite(5,HIGH);  //Schaltet Gelb
 delay(700);
 digitalWrite(7,LOW); //deaktiviert Rot
 digitalWrite(5,LOW);//deaktiviert Gelb
 digitalWrite(8,HIGH);    //Schaltet Grün
 delay(7000);
 digitalWrite(5,HIGH);  //Schaltet Gelb
 digitalWrite(8,LOW);  //deaktiviert Grün
 delay(2500);
 digitalWrite(7,HIGH); //Schalte Rot
 digitalWrite(5,LOW);  //deaktiviere Gelb
}