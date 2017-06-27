/*Diese Schaltung l�sst sich zu Beginn durch pin7 und pin6 in eine Zeit oder Sensorschaltung starten.

In der Sensorschaltung zeigt die LSA f�r die Hauptra�e gr�n und f�r die Nebenstra�e rot.
Sobalt der eingebaute PullUp Taster gedrueckt wird, bekommt die Nebenstra�e eine Gr�nphase,
waehrend die Hauptstra�e rot bekommt.
Zeitschaltung ist das gleiche ohne Druecker.
Schaltung am Arudino getestet			

15.05.17
VERSION 3    versucht nun im laufenden Sensorschaltungs- oder Zeitschaltungsbetrieb ohne druecken des RESET Tasters
den jeweiligen Betriebsmodus zu �ndern. Aus der Sensorschaltung kann bereits in der Gr�nstandphase 
(f�r die Hauptstr.) in den Zeitschaltungsmodus gewechselt werden. Andersherum fehlt die bislang die M�glichkeit,
Prozesse parallel ablaufen lassen zu k�nnen.
*/


void setup() {

//Hauptstra�e
pinMode(10,OUTPUT);//Rot1
pinMode(11,OUTPUT);//Gelb1
pinMode(12,OUTPUT);//Gruen1
//Nebenstra�e
pinMode(2, OUTPUT);//Rot2
pinMode(3, OUTPUT);//Gelb2
pinMode(4, OUTPUT);//Gruen2
//Sensoren
pinMode(8, INPUT_PULLUP);//Druecker
pinMode(7, INPUT_PULLUP);//Schalter Zeitschaltung
pinMode(6, INPUT_PULLUP);//Schalter Sensorschaltung
}

//Funktionen
void schalteHauptRot();
void schalteNebenGruen();
void schalteNebenRot();
void schalteHauptGruen();
void sensorschaltung();
void zeitschaltung();
int gruenzeit = 5000;
int gelbphasenzeit = 2000;

//HAUPTPROGRAMM
void loop() {

	if (digitalRead(7) == LOW) { zeitschaltung(); }
	if (digitalRead(6) == LOW) { sensorschaltung(); }
}


//Schaltungen
void sensorschaltung() {
	bool druecker;
	if (digitalRead(8) == HIGH) { druecker == false; }
	if (digitalRead(8) == LOW) { druecker == true; }

	while (druecker == false)
	{
		digitalWrite(12, HIGH);//Hautpstra�e hat gruen1
		digitalWrite(2, HIGH);//Nebenstra�e hat rot2
		if (digitalRead(7) == LOW) {
			zeitschaltung();
		}
		if (digitalRead(8) == LOW) {
			schalteHauptRot();
			schalteNebenGruen();
			schalteNebenRot();
			schalteHauptGruen();
		}

	}
}
void zeitschaltung() {
	
	while (true) {
		if (digitalRead(6) == LOW) { sensorschaltung(); }
		schalteHauptRot();
		schalteNebenGruen();
		schalteNebenRot();
		schalteHauptGruen();
		delay(gruenzeit);
	}
}


void schalteHauptRot() {
	digitalWrite(12, LOW); digitalWrite(11, HIGH);
	delay(gelbphasenzeit);
	digitalWrite(11, LOW); digitalWrite(10, HIGH);

}
void schalteNebenGruen() {
	delay(2800);
	digitalWrite(3, HIGH);
	delay(gelbphasenzeit);
	digitalWrite(2, LOW); digitalWrite(3, LOW); digitalWrite(4, HIGH);

}
void schalteNebenRot() {
	delay(gruenzeit);
	digitalWrite(4, LOW); digitalWrite(3, HIGH);
	delay(gelbphasenzeit);
	digitalWrite(3, LOW); digitalWrite(2, HIGH);
}
void schalteHauptGruen() {
	delay(3000);
	digitalWrite(11, HIGH);
	delay(gelbphasenzeit);
	digitalWrite(10, LOW); digitalWrite(11, LOW); digitalWrite(12, HIGH);
}