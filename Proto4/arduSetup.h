void setup() {
					//Hauptstra�e
pinMode(5, OUTPUT);//Rot
pinMode(6, OUTPUT);//Gelb
pinMode(7, OUTPUT);//Grün

				   //Nebenstra�e
pinMode(11, OUTPUT);//Rot
pinMode(12, OUTPUT);//Gelb
pinMode(13, OUTPUT);//Gr�n

					//Abbieger Hauptstraße
pinMode(2, OUTPUT);//Rot
pinMode(3, OUTPUT);//Gelb
pinMode(4, OUTPUT);//Grün

				   //Straßenbahn
pinMode(9, OUTPUT); //Weiß (Fahren)
pinMode(8, OUTPUT); //Blau (Stehen)

					 //Taster
pinMode(20, INPUT_PULLUP); //Taster 1 Nebenstraße
pinMode(21, INPUT_PULLUP); //Taster 2 Hauptstraßenabbieger
pinMode(22, INPUT_PULLUP); //Taster 3 Straßenbahn
pinMode(25, INPUT_PULLUP);//Schalter Zeitschaltung			Relais für Funktionsweise benötigt bzw. andere Tasterverschaltung
pinMode(26, INPUT_PULLUP);//Schalter Sensorschaltung		Ralais für Funktionsweise benötigt bzw. andere Tasterverschaltung

}
