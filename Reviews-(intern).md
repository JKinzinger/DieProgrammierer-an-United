## Review 1
### Name des Reviewers

Janis Kinzinger
### Name des Entwicklers

Hendric Schüttenberg, Michel Brandes, Yannik Schäkel, Janis Kinzinger
### Dateien

LSA/LSA.ino
### git-Revision (git log)

Lates Commit for all Data:
eeaacb0fd2ab588d5088d5a73c0f11236b33f3c0
### Untersuchte Funktionalität

Syntax, Kommentation, allgemeine Funktionalität und Effektivität
### Reviewergebnisse
**Codierungsstandards:**  
Allgemein wurden die Codierungsstandards größtenteils eingehalten. Das Setup wurde in eine Headerdatei ausgelagert,
was den Code ein wenig übersichtlicher macht. Die `void loop()`(83) Funktion wurde an das Ende gestellt. 
Für eine bessere Verständlichkeit könnte man die zwei Funktionen, die darin aufgerufen werden, erst nach der `loop`-Funktion definieren.
Die Einrückungen sind im ganzen Code sinnvoll gesetzt, jedoch die `do while()`(21) Schleife könnte noch kürzer ausfallen, da ihre Länge sehr unübersichlich ist.
Die Benennungen der Funktionen, die die LEDs schalten ist sinnvoll, da hieraus abgeleitet werden kann, welche Ampel gechaltet wird.

**Kommentare:**  
Mit Kommentaren wurde in diesem Code ein wenig sparsam umgegangen. Beispielhaft ist in (24) in keiner Weise erläutert, was die `switch` Anweisung bewirkt. 
Durch das darüberstehende `Nebenstraße`(23) ist jedenfalls nicht ersichtlich, dass der Tasterstatus abgefragt wird.
Die Sensor- und zschaltung bleiben somit weitgehend unverständlich in ihren Abläufen.

**Logik:**  
Alle `switch-Case` Anweisungen werden ordnungsgemäß mit einem `break;` beendet. Ein `default` case ist nicht nötig, da die Taster nur zwei Stellungen haben.

**Fehlerbehandlung:**  
Fehler werden in sofert behandelt, alsdass die jeweilige Schleife oder Anweisung durchlaufen wird und anschließend wieder im loop neu Abgefragt wird.
Außer Tasterbetätigung werden vom Programm keine anderen Eingaben erwartet, die Fehler verursachen könnten.

**Codeentscheidungen:**  
Für die Abfrage der Taster wurden jeweils `switch-Case` Anweisungen verwendet, in denen jeweils beide Fälle des Tasters (HIGH und LOW) berücksichtigt werden. 
Hier kann man durch eine `if Schleife` eine kürzere Abfrage des Tasters gestalten, ohne jedes mal den `schalte.Standard()` aufrufen zu müssen. Die `break;` Befehle würden ebenfalls wegfallen.
Als unnötig könnte man die Klasse Led bzw. die Objektinstanziierung des Objektes `schalte`ansehen, da keine weiteren Objekte benötigt werden und so die Attribute für jedes Objekt nicht einzeln gebraucht werden.

## Review 2
### Name des Reviewers

Michel Brandes
### Name des Entwicklers

Entwicklergruppe "Die Programmierer"
### Dateien
Proto5.ino (main)  
LEDschaltungen.h
### git-Revision (git log)

Lates Commit for all Data:
eeaacb0fd2ab588d5088d5a73c0f11236b33f3c0
### Untersuchte Funktionalität

Funktionalität, Aufbau und Struktur des Codes
### Reviewergebnisse

**Codierungsstandards:**  
Die Codestruktur ist soweit logisch, Einrückungen wurden korrekt verwendet um den Code übersichtlicher zu machen. 
Die Funkionen zeitschaltung und sensorschaltung wurden aus dem loop ausgelagert, damit diese getrennt betrachtet werden können.
Dies ist sinnvoll da die Funktionen, abhängig von der Stellung eines Kippschalters, nur einzeln aufgrufen werden.
Die aufgerufene Funktion durchläuft dann meist mehrere loops bevor die andere Funktion verwendet wird. 

**Kommentare:**  
Die Kommentare sind an einigen stellen etwas sparsam verteilt, aufgrund der einleuchtenden Benennung von Funktionen und Variablen ist der Code dennoch größtenteils verständlich. 
Bei der Einbindung des Ultraschallsensors könnten die Kommentare der Übersichtlichkeit halber knapper ausfallen und mehr auf den Ablauf im Code eingehen als auf die genaue Funktion des Sensors.

**Logik:**  
Es sind soweit keine Logikfehler zu erkennen

**Fehlerbehandlung:**  
Fehler können nur in der Anwendung des Programms mit dem Arduino ermittelt werden,
mögliche Fehlerquellen können hierbei Taster und Sensoren sein.

**Codeentscheidungen:**  
Der Übersichtlichkeit halber könnten einige Funktionen aus dem Hauptprogramm in Headerdateien ausgelagert werden.
Als Beispiel hierfür kann die Funktion der Messung der Entfernung mit dem Ultraschallsensor dienen, diese könnte ohne weiteres ausgelagert werden.


## Review 3
### Name des Reviewers

Yannik Schäkel
### Name des Entwicklers

Hendric Schüttenberg, Michel Brandes, Janis Kinzinger, Yannik Schäkel
### Dateien

Proto 7
### git-Revision (git log)

Latest Commit for all Data: 9f980446af44bdc9b144dfceb34a82e0838e2f91
### Untersuchte Funktionalität

Struktur, Funktionalität, Kommentierung
### Review Ergebnisse
**Codierungsstandards:**  
Die Struktur des Codes ist im ganzen logisch aufgebaut. Durch Einrückungen an den dafür vorgesehenen Stellen werden Funktionen und Anweisungsblöcke gut sichtbar voneinander getrennt und so übersichtlicher dargestellt.

Variablen wurden definiert und im Code keine Eingänge direkt verwendet.


**Kommentare:**  
Kommentare wurden an wichtigen Stellen eingebracht, z.B. zur Erläuterung von Funktionen oder Variablen.
Es könnten jedoch noch mehr Kommentare eingefügt werden um den Code für Außenstehende verständlicher zu machen.
In der „if-else“ Funktion der „Void Led::rotgreenrot“ ist eine Redundanz der Kommentare vorhanden, welche nach einer Erweiterung wahrscheinlich übersehen wurden und noch entfernt werden müssen.

**Logik:**  
Logikfehler sind nicht erkennbar, da alle „switch-case“ und „if-else“ Bedingungen in sich stimmig sind und keine Fehler aufrufen können.
Durch „break;“ in allen „switch-case“ Fällen ist ein „default“ zum Beenden nicht nötig, da der Schalter nur zwei Positionen hat.

**Fehlerbehandlung:**  
Da der Hauptcode im Loop läuft, tritt ein Fehler, möglicherweise verursacht durch einen Hardwarefehler nur einmal kurzfristig auf und wird im nächsten Durchlauf nicht wieder auftreten.
Hardwarefehler wie z.B. ein gelöstes Kabel oder ein defekter Taster müssen manuell ermittelt werden.

**Codeentscheidungen:**  
Um die Übersichtlichkeit des Codes zu währen, haben wir einige Funktionen in Header Dateien ausgelagert. 
Dadurch wurde der Hauptcode kompakter und leichter verständlich.

# Review 4
### Name des Reviewers

Hendric Schüttenberg
### Name des Entwicklers

Hendric Schüttenberg, Michel Brandes, Yannik Schäkel, Janis Kinzinger
### Dateien

Proto8/Proto8.ino
### git-Revision (git log)

Latest Commit for all Data:
11e9ef5f90e27bfe23d4731687709a22415d5d38 
### Untersuchte Funktionalität

Syntax, Kommentation, allgemeine Funktionalität und Effektivität
### Reviewergebnisse
**Codierungsstandards:**  
Allgemein wurden die Codierungsstandards eingehalten. Das Setup des Programms wurde in einer Headerdatei ausgelagert, was den Code übersichtlich gestaltet. Die `void loop()` (28) wurde in diesem Prototypen an den Anfang des Codes gesetzt, welches direkt erkenntlich macht, welche Hauptfunktionen in der Schleife abgearbeitet werden. Gefolgt wird die Schleife von den zwei Hauptfunktionen `void zeitschaltung()` (46) und `void sensorschaltung()` (82). Die Einrückung des Codes sind sinnvoll gesetzt und verständlich. Die Serielle Ausgabe der Funktionsnamen ist sinnvoll gewählt, da so nachverfolgt werden kann, welche Funktionen der Arduino in dem gewünschten Moment abarbeitet. Ebenfalls gut gewählt ist die Objektinstanzierung innerhalb der Hauptfunktionen, da so ersichtlich ist, welche Ampel geschaltet wird und welchen Pin die jeweiligen LEDs belegen, ohne das in die `Setup.h` gewechselt werden muss.   
                              
**Kommentare:**                                                      
Die Kommentierung ist in ausreichendem Maße vorhanden. Es ist klar, was in den Funktionen aufgerufen wird. Auf Wiederholungen wurde geachtet, und mit einem wie z.B. in (103) mit `//siehe Zeile(58)` abgekürzt um dopplungen zu vermeiden und den Code unübersichtlich wirken zu lassen.    
                                           
**Logik:**                                                      
Alle `switch-Case` Anweisungen wurden mit einem `break;` beendet. ein default; wird nicht benötigt, da die Taster lediglich zwei Stellungen haben entweder `HIGH` oder `LOW`. Für die Taster in der Sensorschaltungen wurden die `switch-Case` Anweisungen durch `if Schleife` getauscht, das Programm läuft so durchgehend in der Standard- Funktion bis ein Taster gedrückt wird. Ein weiteres Abfragen ob der Taster nun `LOW` ist wird nicht benötigt. Dies resultiert in einer schnelleren Reaktion des Programms auf Eingaben mithilfe der Taster.
                                   
**Fehlerbehandlung:**                                                     
Es kommt vermehrt vor, dass ein Fragezeichen an statt des gewünschten Sonderzeichens in den Kommentaren auftaucht, dies kann durch einfaches umschreiben in `ue`, `ae`, `oe` bzw. `ss` geändert werden (Fragezeichen Problem).    
         
**Codeentscheidungen:**                                                  
Um eine noch öftere Abfrage der Starßenbahn in der Sensorsteuerung zu erhalten, könnte for dem z.B. `lksabgr.aufGruen();` (112) noch ein weitere `if Schleife` enthalten sein, um die Straßenbahn sowohl vor, als auch nach der Schaltung von Linksabbieger bsw. Nebenstraße zu  erhalten.