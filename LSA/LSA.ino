//Sensor (Taster) gesteuerte Schaltung einer LSA die sowohl als Berufsverkehrschaltung als auch als Nachtschaltung verwendet werden kann.
//Es werden alle Verkehrsteilnehmer berücksichtigt. Diese Schaltung lässt sich zu Beginn durch pin18 und pin19 in eine Zeit oder Sensorschaltung starten.
//Die Hauptstraße hat immer Green und sowohl Nebenstraße als auch Abbieger immer Rot, bis entweder ein auto auf dem Abbiegestreifen,
//ein Auto in der Nebenstraße steht, oder ein Fußgaenger bzw. Radfahrer den Knopf betätigt.

//  Autor: Hendric Schüttenberg
//  Erstellt am: 23.05.2017 12:04
//  Update am: 06.06.2017 durch Janis Kinzinger

#define TEST
#include "testDefinitionen.h"	//Einbinden der Tests
#include "LEDschaltungen.h"		//Auslagern der Funktionsdefinitionen für die LED Schaltungen in Header-Datei
#include "arduSetup.h"			//Auslagern des Setups der Pins für LED´s und Taster in Header-Datei

void setup();

//Lichtschaltfunktionen
void sensorschaltung() {
	Led schalte;	//Objektinstanzierung für die Klasse Led zum späteren aufrufen der Funktionen
	{
		do {
			schalte.standard();			//Standard: hauptstraße gruen, rest rot
			//Nebenstraße
			switch (digitalRead(20))
			{
			case HIGH:
				schalte.hptaufRot();	//Objekt schalte, Mehtode der Klasse Led; Aufruf der Funktion, die die Hauptstraße auf Rot schaltet
				schalte.nbnstr();
				schalte.hptaufGreen();
				break;

			case LOW:
				schalte.standard();		//Hauptstraße gruen, Rest rot
				break;
			}
			//Hauptstraßenabbieger
			switch (digitalRead(21))
			{
			case HIGH:
				schalte.hptaufRot();
				schalte.lksabgr();
				schalte.hptaufGreen();
				break;

			case LOW:
				schalte.standard();
				break;
			}
			//Straßenbahn
			switch (digitalRead(22))
			{
			case HIGH:
				schalte.hptaufRot();
				schalte.strbhn();
				schalte.hptaufGreen();
				break;

			case LOW:
				schalte.standard();
				break;
			}
			}
		while (digitalRead(26 == HIGH));		//Solange der Taster für Sensorschaltung aktiv (high) ist, wird sensorschaltung ausgeführt (Relais für Taster vorrrausgesetzt)
	}

}
void zeitschaltung() {
	Led schalte;		//Objektinstanzierung für die Klasse Led zum späteren aufrufen der Funktionen
	schalte.standard();
	do {									//Es wurde Zeitschaltung ausgewahlt, also wird zeitschaltung mindestens einmal durchlaufen
		schalte.hptaufRot();
		schalte.nbnstr();
		schalte.hptaufGreen();
		schalte.lksabgr();
		schalte.hptaufRot();
		schalte.strbhn();
		schalte.hptaufGreen();
	} 
	while (digitalRead(25 == HIGH));		//Solange der Taster für Zeitschaltung aktiv (high) ist, wird zeitschaltung ausgeführt
}

//Sensorschaltng bzw. Tasterschaltung
void loop()
{
	if (digitalRead(25) == HIGH) { zeitschaltung(); }			//Wenn Taster 25 gedrueckt wird, führe Zeitschaltung aus
	if (digitalRead(26) == HIGH) { sensorschaltung(); }			//Wenn Taster 26 gedrueckt wird, führe Sensorschaltung aus
																//Wird kein Taster gedrueckt, passiert nichts
}

