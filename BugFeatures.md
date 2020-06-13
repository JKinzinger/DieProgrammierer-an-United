# Bug01:
**Autor:** Janis Kinzinger  
**Datum:** 30.05.17 11:00  
**Modul:** Datei LSA.ino, Modul Sensorschaltung   
**Beschreibung:**   
Innerhalb der Sensorschaltung wurde bei dem Implementieren der Taster für die Umschaltung auf Zeit- oder Sensorschaltung nichts verändert. Bei Auswahl der Sensorschaltung durch den Taster 26 wird diese gestartet, sodass die LED´s leuchten, jedoch wird nichtmehr auf die dazugehörigen Eingaben durch die Taster 20,21 und 22 reagiert, welche zuvor fehlerfrei funktionierten. Die LED´s ändern ihren Leutstatus also nach Betätigen der Taster nicht.  
**Reproduzierbarkeit:**   
Starten des Arduinos mit LSA.ino (Stand: 30.05.17 11:00 Git log: c5f49d95a07917555c62620bf24f83e51b2f2e17) und Auswahl der Sensorschaltung mit Betätigen des Tasters 26.

### Buguntersuchung01:
**Autor:** Michel Brandes  
**Datum:** 19.06.17 18:00  
**Modul:** Datei LSA.ino, Modul Sensorschaltung und Zeitschaltung (commit c5f49d95a07917555c62620bf24f83e51b2f2e17)  
**Beschreibung:**  
Beim Versuch den Bug01 zu reproduzieren zeigte sich dieser in einer anderen Form;
Die Schaltung befindet sich anders als im Bug01 beschrieben vom Programmstart an permanent in der Zeitschaltung, ein Wechseln auf die Sensorschaltung durch den Taster 26 verlief erfolglos. Durch die Isolierung der beiden Schaltungsfunktionen zeigte sich dass diese einzeln reibungsfrei funktionieren, der Fehler ist also vermutlich im Funktionsaufruf im Hauptprogramm oder auf dem Schaltbrett zu finden.  
**Lösungsansatz:**  
Eine Überprüfung des Schaltbrettes sollte Fehler in der Verkabelung ausschließen. Wenn diese keinen Fehler liefert mu⁫ss der Fehler im Hauptprogramm liegen, eine Veränderung des Funktionsaufrufes von Sensor- und Zeitschaltung durch z.B. einen Kippschalter wird hierbei in Betracht gezogen.
### Buguntersuchung01 Ergänzung:
**Autor:** Janis Kinzinger  
**Datum:** 21.06.17 14:00  
**Modul:** Datei LSA.ino, Modul Sensorschaltung und Zeitschaltung  
**Beschreibung:**  
Mögliche Lösung des oben Beschriebenen Problems: Die Funktion Sensorschaltung beinhaltetete keinen Befehl, der einen loop auslöste. Dadurch war das Betätigen der Taster für die Sensorschaltung in der Durchführungszeit unmöglich, da diese sehr kurz war. Durch eine ergänzte do-while Schleife, die den Taster für die Sensorschaltung mit einbezieht, sollte es nun möglich sein, die Taster zu Betätigen und so die entsprechenden Schaltfunktionen für die Verkehrsteilnehmer auszuführen.

# Bug02:  
**Autor:** Hendric Schüttenberg                      
**Datum:** 21.06.2017 14:50                         
**Modul:** Datei LSA.ino, LSA  Commit:dcb286220de886ee9b6426851a8dfaf4236aa95a                     
**Beschreibung:**                   
Die jeweilige wahl der Schltung (Sensor/Zeit) kann nun getätigt werden, jedoch ist ein umschlalten nach wahl der Schaltung nicht mehr möglich. Taster der Sensorschaltung funktionieren einwandfrei, auch die Zeitschaltung läuft normal durch. Das Program reagiert lediglich nach der Wahl der Schaltung nicht mehr auf Eingaben durch Taster Pin 25 oder Pin 26.  
**Reproduzierbarkeit:**   
Starten des Arduinos mit LSA.ino (Stand: 21.06.2017 14:50) und Auswahl der gewünschten Schaltung mit Betätigen des Tasters 25 oder 26.

### Buguntersuchung02: 
**Autor:** Hendric Schüttenberg                                                    
**Datum:** 27.06.2017 13:20                                                                
**Modul:** Datei LSA.ino, LSA    commit:87237c5448518f715d710b42e544cf9d120fce76                                                            
**Beschreibung:**                                                                   
Das ändern der Tasterabfrage, auf eine doppelte Abfrage, wenn `Taster26` `LOW`soll case HIGH: zeitschaltung() und `case LOW: sensorschaltung()` sowie `Taster25 HIGH` `case HIGH: sensorschaltung()` und `case LOW: zeitschaltung()`, bringt keine Veränderung.

### Buguntersuchung02 Ergänzung:
**Autor:** Hendric Schüttenberg            
**Datum:** 27.06.2017 14:15         
**Modul:** Datei LSA.ino, LSA                        
**Beschreibung:**                       
Durch Austauschen des Druckknopfes, durch einen zwei-Wege Schalters, wurde der Bug02 behoben.

# Bug03:
**Autor:** Michel Brandes   
**Datum:** 27.06.2017 19:50   
**Modul:** Datei LSA.ino, Proto4 (commit 74493c0146c04eb5c9816726bbdb640cf9d9cb98)    
**Beschreibung:**   
Wenn in der Sensorschaltung die Taster Pin 20 oder Pin 21 betätigt werden und somit der Schaltvorgang für die entsprechenden LEDs eingeleitet wird sollte die Betätigung von Taster Pin 22 jenen Schaltvorgang schnellstmöglich beenden um so die Priorität der Straßenbahn zu ermöglichen. Dieser Mechanismus funktioniert soweit auch. Dabei tritt allerdings der unerwünschte Nebeneffekt auf, dass die gelbe LED Pin 7 kurzzeitig aktiviert und danach wieder deaktiviert wird bevor die blaue LED Pin 8 Deaktiviert wird.  
**Reproduzierbarkeit:**  
Starten des Arduinos mit LSA.ino (Stand: 27.06.2017 15:00), Betätigen von Schalter Pin 20 oder Schalter Pin 21, danach betätigen Schalter Pin 22.  
  
### Buguntersuchung03:
**Autor:** Michel Brandes  
**Datum:** 28.06.2017 18:00  
**Modul:** Datei LSA.ino, Proto4 (commit 74493c0146c04eb5c9816726bbdb640cf9d9cb98)  
**Beschreibung:**  
Der Bug tritt auf da die Funktion nach betätigung des Tasters 22 einen break ausführt und den Loop von vorne beginnt. Bevor es dabei, wie gewünscht, Pin Taster 22 abfragt, um gegebenenfalls die Straßenbahnschaltung zu aktivieren, wird erst die Funktion schalte.standard aufgerufen. Diese ist verantwortlich für das kurzzeitige aktivieren der der gelben LED Pin 7.
Durch das aktivieren der Straßenbahnschaltung mit einer if-else Schleife anstatt der neustartung des loops durch einen break konnte der Bug gelöst werden.

# Bug04:
**Autor:** Yannik Schäkel   
**Datum:** 12.07.2017 20:00   
**Modul:** Datei LSA.ino, (commit 2e77627aa063d1828e474ac02ab2598ca0b03ea8)    
**Beschreibung:**   
Würde der Photowiderstand einen sehr niedrigen Wert ausgeben, würde die Formel zur Berechnung der adaptiven Helligkeitsanpassung ein sehr geringes Ergebnis ausrechnen. Dieses würde dazu führe, dass die LEDs mit einer so niedrigen Spannung versorgt werden, dass sie nicht leuchten würden.   
**Reproduzierbarkeit:**  
Starten des Arduinos mit LSA.ino (Stand: 11.07.17) Den Raum so sehr abdunkeln und den Photowiderstand vollkommen bedecken, dass der Analogeingang einen sehr kleinen Wert einliest.
  
### Buguntersuchung04:
**Autor:** Yannik Schäkel  
**Datum:** 12.07.2017 21:00  
**Modul:** Datei LSA.ino, (commit 2e77627aa063d1828e474ac02ab2598ca0b03ea8)  
**Beschreibung:**  
Die Helligkeitsanpassung der LSA würde durch einen niedrigen Eingangswert auf A0 ein minimal kleines Ergebnis errechnen und so die LEDs mit minimaler Spannung beschalten, dass diese nicht leuchten würden.

Kann durch eine if-else Schaltung mit minimal Wert unterbunden werden.