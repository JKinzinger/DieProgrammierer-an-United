/*Diese Schaltung zeigt für die Hauptraße grün und für die Nebenstraße rot.
Sobalt der eingebaute PullUp Taster gedrueckt wird, bekommt die Nebenstraße eine Grünphase,
waehrend die Hauptstraße rot bekommt.
Schaltung am Arudino getestet			*/

void setup() {

//hauptstraße
pinMode(10,OUTPUT);//Rot1
pinMode(11,OUTPUT);//Gelb1
pinMode(12,OUTPUT);//Gruen1
//nebenstraße
pinMode(8, INPUT_PULLUP);//Druecker
pinMode(2, OUTPUT);//Rot2
pinMode(3, OUTPUT);//Gelb2
pinMode(4, OUTPUT);//Gruen2
}

//Funktionen
void schaltehauptrot();
void schaltenebengruen();
void schaltenebenrot();
void schaltehauptgruen();
int nebengruenzeit = 5000;
int gelbphasenzeit = 2000;

void loop() {
	bool druecker;
	if (digitalRead(8) == HIGH) { druecker == false; }
	if (digitalRead(8) == LOW) { druecker == true; }

	while (druecker == false)
	{
		digitalWrite(12, HIGH);//Hautpstraße hat gruen1
		digitalWrite(2, HIGH);//Nebenstraße hat rot2

		if (digitalRead(8) == LOW) {
			schaltehauptrot();
			schaltenebengruen();
			schaltenebenrot();
			schaltehauptgruen();
		}

	}
	
	
	
	
}

void schaltehauptrot() {
	digitalWrite(12, LOW); digitalWrite(11, HIGH);
	delay(gelbphasenzeit);
	digitalWrite(11, LOW); digitalWrite(10, HIGH);

}
void schaltenebengruen() {
	delay(2800);
	digitalWrite(3, HIGH);
	delay(gelbphasenzeit);
	digitalWrite(2, LOW); digitalWrite(3, LOW); digitalWrite(4, HIGH);

}
void schaltenebenrot() {
	delay(nebengruenzeit);
	digitalWrite(4, LOW); digitalWrite(3, HIGH);
	delay(gelbphasenzeit);
	digitalWrite(3, LOW); digitalWrite(2, HIGH);
}
void schaltehauptgruen() {
	delay(3000);
	digitalWrite(11, HIGH);
	delay(gelbphasenzeit);
	digitalWrite(10, LOW); digitalWrite(11, LOW); digitalWrite(12, HIGH);
}