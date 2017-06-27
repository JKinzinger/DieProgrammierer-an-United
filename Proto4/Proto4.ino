//Sensor (Taster) gesteuerte Schaltung einer LSA die sowohl als Berufsverkehrschaltung als auch als Nachtschaltung verwendet werden kann.
//Es werden alle Verkehrsteilnehmer berücksichtigt. Diese Schaltung lässt sich zu Beginn durch pin18 und pin19 in eine Zeit oder Sensorschaltung starten.
//Die Hauptstraße hat immer Green und sowohl Nebenstraße als auch Abbieger immer Rot, bis entweder ein auto auf dem Abbiegestreifen,
//ein Auto in der Nebenstraße steht, oder ein Fußgaenger bzw. Radfahrer den Knopf betätigt.

//  Autor: Hendric Schüttenberg
//  Erstellt am: 23.05.2017 12:04
//  Update am: 27.06.2017 durch Hendric Schüttenberg


#define TEST
#include "testDefinitionen.h"	//Einbinden der Tests
#include "LEDschaltungen.h"		//Auslagern der Funktionsdefinitionen für die LED Schaltungen in Header-Datei
#include "arduSetup.h"			//Auslagern des Setups der Pins für LED´s und Taster in Header-Datei

void setup();

                               //S E N S O R S C H A L T U N G

void sensorschaltung() 
{
	Led schalte;	//Objektinstanzierung für die Klasse Led zum späteren aufrufen der Funktionen
	{
			schalte.standard();			//Standard: hauptstraße gruen, rest rot
			
		                                            	//N E B E N S T R A ß E
                                                 
			switch (digitalRead(20))
			{
  			case HIGH:
  				schalte.hptaufRot();	//Objekt schalte, Mehtode der Klasse Led; Aufruf der Funktion, die die Hauptstraße auf Rot schaltet
             if (digitalRead(22)==HIGH)   //breche Nebenstraßenschaltung ab damit Straßebbahnschaltung gestartet werden kann
                {break;}
  				schalte.nbnstr();
             if (digitalRead(22)==HIGH)   //breche Nebenstraßenschaltung ab damit Straßebbahnschaltung gestartet werden kann
                {break;}
  				schalte.hptaufGreen();
  				break;
  
  			case LOW:
  				schalte.standard();		//Hauptstraße gruen, Rest rot
  				break;
			}
			
			                                           //H A U P T S T R A ß E N A B B I E G E R
                                                 
			switch (digitalRead(21))
			{
  			case HIGH:
  				schalte.hptaufRot();
             if (digitalRead(22)==HIGH)   //breche Hauptstraßenabbiegerschaltung ab damit Straßebbahnschaltung gestartet werden kann
                {break;}
  				schalte.lksabgr();
             if (digitalRead(22)==HIGH)   //breche Hauptstraßenabbiegerschaltung ab damit Straßebbahnschaltung gestartet werden kann
                {break;}
  				schalte.hptaufGreen();
  				break;
  
  			case LOW:
  				schalte.standard();
  				break;
			}
			
		                                              //S T R A ß E N B A H N
                                                 
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
}

                                //Z E I T S C H A L T U N G
                                
void zeitschaltung() 
{
	Led schalte;		//Objektinstanzierung für die Klasse Led zum späteren aufrufen der Funktionen
	  schalte.standard();
		schalte.hptaufRot();
        if(digitalRead(22)==HIGH)
        {
          schalte.strbhn();
        }
		schalte.nbnstr();
        if(digitalRead(22)==HIGH)
        {
          schalte.strbhn();
        }
		schalte.hptaufGreen();
    schalte.hptaufRot();
       if(digitalRead(22)==HIGH)
        {
          schalte.strbhn();
        }
		schalte.lksabgr();
        if(digitalRead(22)==HIGH)
        {
          schalte.strbhn();
        }
    schalte.hptaufGreen(); 
}



           //U M S C H A L T U N G    T A S T E R   BZW.   S E N S O R

void loop()
{
	switch(digitalRead(25))
	{ 
	  case HIGH:
    zeitschaltung();
    break;
    
    case LOW:
    sensorschaltung();
    break;
  }			//Wenn Taster 25 auf ON steht, wird Zeitschaltung ausgefürht, wenn OFF Sensorschaltung
}

