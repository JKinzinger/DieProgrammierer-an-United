# Feature01:  
**Autor:** Michel Brandes  
**Datum:** 05.07.2017    
**Modul:** Proto8, Datei LEDschaltung.h Stand 05.07.2017    
**Name des Features:** Led::messungAbstand  
**Funktion für den Arduino:**  
Um eine automatische Aktivierung der Straßenbahnschaltung zu ermöglichen sollte ein automatischer Sensor integriert werden der diese jederzeit aktivieren kann. Die Wahl viel hierbei auf einen Abstandssensor der die Distanz zu Objekten messen kann und einen Wert ausgibt der dann, in Form einer if-else Funktion, zur Aktivierung der Funktion strbhn genutzt werden kann.                                              
**Code:**  
Um die Messung des Ultraschallsensors an das Hauptprogramm weiterzugeben werden in der Funktion zuerst zwei Variablen, abstand und abstand_in_cm, definiert. Die Variable abstand wird hierbei durch die Messung des Sensors definiert. Dazu wird zuerst der Trigger Pin 34 auf LOW geschaltet damit der Sensor sicher kein Signal ausgibt. Nach einem Delay von 2ms wird Pin 34 wieder auf HIGH geschaltet, somit wird ein Ultraschallsignal vom Trigger des Sensors ausgegeben. Nachdem einem weiteren Delay von 5ms wird der Pin 34 erneut auf LOW geschaltet und die Variable abstand wird als Ausgabe des Echopins Pin 35 definiert. Der Ausgabewert ist hierbei die vom Sensor gemessene Zeit zwischen Ausgabe des Signals von Pin 34 bis zum Eingang des Signals in Pin 35 in ms. Durch die Multiplikation mit einem Faktor wird der aus der Variable abstand die Variable abstand_in_cm berechnet. Wie der Name vermuten lässt handelt es sich hierbei um den errechneten Abstand des Sensors zum Objekt in cm, die Umrechnung dient hierbei der Veranschaulichung und der Vereinfachung. Die Variable abstand_in_cm wird zuletzt mit return an das Hauptprogramm übergeben.

# Feature02:  
**Autor:** Hendric Schüttenberg                                                 
**Datum:** 10.07.2017                                                                         
**Modul:** LSA/LSA.ino Stand: 10.07.2017 22:53                                                                     
**Name des Features:** void sensorschaltung()                                                                
**Funktion für den Arduino:**                                                                         
Die Sensorschaltung ist die Manuell schaltbare Funktion unseres Programms. Hierbei hat der User zugriff auf zwei verschiedene Taster, welche entweder Nebenstraße oder Abbieger eine Grünphase ermöglicht, oder einen Abstandssensor welcher die Grünphase für die Straßenbahn ermöglicht                                                         
**Code:**  
Um die Funktionen ablaufen zu lassen, wird mithilfe von `Led::standard();` (93) eine Standardfunktion iniziiert. Hierbei ist die Hauptstraße immer Grün und Straßenbahn, Abbieger und Nebenstraße immer Rot bzw. Blau. Die Unterfunktionen der Sensorsteuerung sind nach `Nebenstraße` (95), `Abbieger` (107) und `Straßenbahn` (119) aufgeteilt. Diese Unterfunktionen sind `if Schleifen`, die mit einem Taster iniziiert werden können. Ist der Taster `HIGH` so werden die in der `if Schleife` genannten Opperationen durchgeführt. Hierbei wird immer nach gleichen Schema ein Objekt der Klasse `Led` mithilfe der Methoden `aufRot` und `aufGruen` geschaltet um so das gewünschte Signalbild zu erhalten. Die Straßenbahn ist hierbei ein Sonderfall. Sie wird immer abgefragt, wenn alle Ampel Rot sind, ob der Mindestabstand unterschritten wurde. Ist dem so, so wird die Straßenbahn auf `Fahren` geschaltet, alle anderen Signale bleiben Rot. Erst nachdem die Straßenbahnfunktion bearbeitet wurde, kehrt die vorher aufgerufenen Schleife zu der Funktion `Led::standard` zurück.


# Feature03:  
**Autor:** Yannik Schäkel  
**Datum:** 11.07.2017  
**Modul:** LSA  
**Name des Features:** Led::setHelligkeit() 
**Funktion für den Arduino:**  
Über einen Fotowiderstand wird die Helligkeit der Umgebung "gemessen"und in das Programm eingespeist. Nach Berechnung und Abgleich der Werte, wird über die PWM Ausgänge die LEDs beschaltet.  
**Code:**  
Für den reibungslosen Ablauf, werden drei Variablen mit zwei Unterschiedlichen Datentypen angelegt.
Der Fotosensor speist die Werte über den Eingang A0 ein, welcher als Variable (int Eingang) definiert ist.
Diese Variable (Eingang) wird in void Led::setHelligkeit() verwendet und mit analogRead(Eingang) eingelesen und in der Variable (float messung) gespeichert.
Die Variable (messung) wird in einer einfachen Rechenformel verwendet, um eine Stufenlose Anpassung der Helligkeit der LEDs an die Umgebungshelligkeit zu erreichen.
Das Ergebnis der Berechnung wird in der dritten Variable (float helligkeit) abgelegt, mit (Serial.print) an den Serial Monitor ausgegeben und mit analogWrite in der jeweiligen Funktion, werden durch die PWM Ausgänge die LEDs geschaltet.

# Feature04:  
**Autor:** Janis Kinzinger  
**Datum:** 11.07.2017  
**Modul:** LSA, Datei LEDschaltungen.h   
**Name des Features:** Variabilität der Gelb- und Grünphasen      
**Funktion für den Arduino:**    
Durch verändertes Verkehrsaufkommen an der gesteuerten Kreuzung, ist es sinnvoll, die Grün- und Gelbphasen bestimmter Straßen speziell anzupassen. Dieses Feature ermöglicht das Verändern der Grünphase für eine höhere oder niedrigere Zahl der Verkehrsteilnehmer, die pro Phase die Ampel passieren können. Ebenfalls ermöglicht das Feature die Anpassung der Gelbzeiten, um die Unfallgefahr durch zu kurze Gelbphasen bei bestimmten Ampeln zu verringern.  
**Code:**    
Funktionalität erreicht dieses Feature durch private Attribute der Klasse Led. Diese sind als integer Datentyp initialisiert und haben die Zeit der jewiligen Phase in Millisekunden als Wert. In den entsprechenden Schaltungsfunktionen für die LEDs werden dann diese Attribute in die Delay-Befehle eingesetzt, sodass keine Umstrukturierung des Codes und Suchen nach den Werten nötig ist. Die Attribute sind Objektgebunden und somit für jede Straße einzeln aufrufbar und veränderlich. Der Wert der Grünphase ist Standardmäßig auf 2000  und der Wert der Gelbphase auf 1500 Millisekunden gesetzt. Durch die ebenfalls Objektgebundenen Setter-Funktionen `void setGruenphase(int)` und `void setGelbphase(int)` können die Werte der Gelb- und Grünphase der entsprechenden Strasse abweichend vom Standard gesetzt werden.