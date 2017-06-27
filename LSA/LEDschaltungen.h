#ifndef LEDSCHALTUNGEN.H	// Falls LEDschaltungen.h nicht vorhanden ist,...
#define LEDSCHALTUNGEN.H	// fuege LEDschaltungen.h und den Inhalt dieses Headers hinzu
							// Damit wird verhindert, dass dieser Header zweimal
							// hinzugefuegt wird.

class Led
{
public:
	void rotgreenrot(int pinRot, int pinGelb, int pinGreen);
	void nbnstr();
	void lksabgr();
	void strbhn();
	void hptaufRot();
	void hptaufGreen();
	//Hauptstraﬂe gruen, der Rest hat rot:
	void standard();

private:
	int gruenphase = 2000;
	int gelbphase = 1500;
	int verzoegerungNachDrueken = 2000;
	int zeitZwischenSchaltungen = 2000;

};

void Led::rotgreenrot(int pinRot, int pinGelb, int pinGreen) {
	digitalWrite(pinRot, HIGH); //Schaltet Rot
	delay(verzoegerungNachDrueken);
	digitalWrite(pinGelb, HIGH);  //Schaltet Gelb
	delay(gelbphase);
	digitalWrite(pinRot, LOW), digitalWrite(pinGelb, LOW), digitalWrite(pinGreen, HIGH);   //deaktiviert Rot und Gelb //Schaltet Green
	delay(gruenphase);
	digitalWrite(pinGelb, HIGH), digitalWrite(pinGreen, LOW);  //Schaltet Gelb //deaktiviert Green
	delay(gelbphase);
	digitalWrite(pinRot, HIGH), digitalWrite(pinGelb, LOW);  //Schaltet Rot //deaktiviert Gelb
}

void Led::nbnstr()
{
	rotgreenrot(11, 12, 13);
}

void Led::lksabgr()
{
	rotgreenrot(2, 3, 4);
}

void Led::strbhn()
{
	digitalWrite(8, HIGH); //Schaltet Blau
	delay(3000);
	digitalWrite(9, HIGH), digitalWrite(8, LOW); //Schaltet Weiﬂ //deaktiviert Blau
	delay(5000);
	digitalWrite(8, HIGH), digitalWrite(9, LOW); //Schaltet Blau //deaktiviert Weiﬂ
}

void Led::hptaufRot()
{
	delay(zeitZwischenSchaltungen);
	digitalWrite(7, HIGH); //Green Hauptstraﬂe
	delay(gruenphase);
	digitalWrite(6, HIGH), digitalWrite(7, LOW); //Schaltet Gelb //deaktiviert Green
	delay(gelbphase);
	digitalWrite(5, HIGH), digitalWrite(6, LOW); //Schaltet Rot //deaktiviert Gelb
}

void Led::hptaufGreen()
{
	delay(zeitZwischenSchaltungen);
	digitalWrite(6, HIGH);    //Schaltet Gelb
	delay(gelbphase);
	digitalWrite(5, LOW), digitalWrite(6, LOW), digitalWrite(7, HIGH);    //deaktiviert Rot und Gelb //Schaltet Green

}

//Hauptstraﬂe gruen, der Rest hat rot:
void Led::standard() {
	digitalWrite(2, HIGH);
	digitalWrite(11, HIGH);
	digitalWrite(7, HIGH);
	digitalWrite(8, HIGH);
}



#endif // Schliesst die ifndef Abfrage ab siehe Zeile 1