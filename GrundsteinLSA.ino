/*
 Name:		GrundsteinLSA_janis_Test.ino
 Created:	10.05.2017 21:20:40
 Author:	Janis
*/

// the loop function runs over and over again until power down or reset


	void setup() {
		//Hauptstra�e
		pinMode(5, OUTPUT);//Rot
		pinMode(6, OUTPUT);//Gr�n
		pinMode(7, OUTPUT);//Gelb
		//Nebenstra�e
		pinMode(11, OUTPUT);//Rot
		pinMode(12, OUTPUT);//Gelb
		pinMode(13, OUTPUT);//Gr�n

    pinMode(22,INPUT);
	}

	void hptstr() {
		digitalWrite(5, HIGH);		//Schaltet Rot
		delay(5000);
		digitalWrite(6, HIGH);		//Schaltet Gelb
		delay(700);
		digitalWrite(5, LOW);		//deaktiviert Rot
		digitalWrite(6, LOW);		//deaktiviert Gelb
		digitalWrite(7, HIGH);		//Schaltet Gr�n
		delay(21000);
		digitalWrite(6, HIGH);	//Schaltet Gelb
		digitalWrite(7, LOW);	//deaktiviert Gr�n
		delay(2500);
		digitalWrite(5, HIGH);	//Schalte Rot
		digitalWrite(6, LOW);	//deaktiviere Gelb
	}
	void nbnstr() {
		digitalWrite(11, HIGH); 
		delay(1000);
		digitalWrite(12, HIGH);		
		delay(700);
		digitalWrite(11, LOW);		//deaktiviert Rot
		digitalWrite(12, LOW);		//deaktiviert Gelb
		digitalWrite(13, HIGH);		//Schaltet Gr�n
		delay(7000);
		digitalWrite(12, HIGH);	//Schaltet Gelb
		digitalWrite(13, LOW);	//deaktiviert Gr�n
		delay(2500);
		digitalWrite(11, HIGH);	//Schalte Rot
		digitalWrite(12, LOW);	//deaktiviere Gelb
	}
	void loop() {
  if (digitalRead(22) == HIGH)
  {
		nbnstr();
  }
  else 
  {
    hptstr();
    nbnstr();
  }
	}
