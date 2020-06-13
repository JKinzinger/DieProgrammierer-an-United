
## Review 1
### Name des Reviewers

Janis Kinzinger
### Name des Entwicklers

Nerea Meinicke, Gruppe "Mensch ist der United"
### Dateien

Temperatur.ino
### git-Revision (git log)

Lates Commit for all Data:
7c92d5e5cf29aecbc08f903093364b6d5e508e87
### Untersuchte Funktionalität

Syntax, Kommentation, allgemeine Funktionalität und Effektivität
### Reviewergebnisse
**Codierungsstandards:**  
Generell ist der Code durch die weit ausgerückten Kommentare sehr Breit, was die Darstellung auf manchen Displays schwierig gestalten könnte.
Besser wäre hier die Anordnung der Kommentare über den dazugehörigen Code-Zeilen, wodurch eine spätere Umformatierung leichter fallen würde.
Ausrückungen durch Tabulatoren sind der Verwendung von vielen Leerzeichen ebenfalls vorzuziehen.

Die Variable `int taster=12`(6) könnte nach Coderichtlinien als Konstante in `TASTER_PIN` umbenannt werden.
Die Benennung der Variable `char X_buffer[4]`(30) ist nicht nachvollziehbar. Auch die Benennung des Pins A0(1) in `TMP36` wird nicht näher erläutert. Ansonsten wurden gute Bezeichnungen verwendet.

Die Verständlichkeit des setups `void setup()`(14) ist schwierig, da keine Kommentare verfasst wurden und somit weder der Befehl `Serial.begin(9600)`(16) unnachvollziehbar bleibt.

Einrückungen wurden sinnvoll gesetzt, jedoch in (76) und Folgende nicht durchgängig eingehalten.

**Kommentare:**  
Die Kommentierung fällt ausgesprochen umfangreich aus. Fast jede Zeile besitzt ein eigenes Kommentar.
Hier gilt es zu bedenken, ob nicht einiges weggelassen werden könnte wie z.B. `char X_buffer[4];   //Max. Zahl "9999"`(30), da bei diesem Beispiel eine Temperatur von 9999°C unrealistisch scheint.
Auch gut sind die als Blöcke eingeschobenen Erklärungen der Funktion des Gesamten Programms.

**Logik:**  
Statt der Bedingung des else if Befehls(80) `temperatur <= wunschtemp` müsste nur < verwendet werden, da bei erreichter Wunschtemperatur die Heizung nicht weiter auf kleinerer Stufe laufen müsste, wie auch in nebenstehendem Kommentar beschrieben. Schleifen weisen korrekte Ablaufanzahlen auf und Bedingungen wurden richtig gewählt.
  

**Fehlerbehandlung:**  
Wenn die Wunschtemperatur vom Benutzer auf 0 Grad Celsius gesetzt wird, bleibt das Programm in der while Schleife(35) und fragt die Wunschtemperatur erneut ab. Ein Hinweis die Temperatur nicht gleich Null zu setzen würde das Problem lösen. Für weitere nicht vorhergesehene Eingaben wie Textzeichen sind keine besonderen Fehlermeldungen vorgesehen, sodass das Programm damit evtl. nicht umgehen kann und abstürzt.

**Codeentscheidungen:**  
Im Allgemeinen wurde der Programmtext sinnvoll und schlank gehalten.
Eine `while` Schleife(41) mit vorangehendem initialisieren von `i` am Anfang der Funktion `void leseWunschTemp()`(29) ist für diesen Fall 
unübersichtlich, da das i an keiner weiteren Stelle benötigt wird. Besser ist es hier eine `for` Schleife zu verwenden.
Bei Variable `int tasterstatus`(7) ist bool als Datentyp sinnvoller, da nur HIGH und LOW gespeichert werden.

## Review 2
### Name des Reviewers

Hendric Schüttenberg
### Name des Entwicklers

Niklas Holz, Gruppe "Mensch ist der United"
### Dateien

RFID.ino 
Bewegungssensor.h
### git-Revision (git log)

Last commit for all Data:
7c92d5e5cf29aecbc08f903093364b6d5e508e87
### Untersuchte FunktionalitÃ¤t

Ansteuerung des RFID – Kits und Bewegungsmelders
### Reviewergebnisse

**Codierungsstandards:**

***RFID.ino:***
Der Code nimmt grundsätzlich durch seine ausschweifenden Kommentare eine stattliche breite ein, besser wäre es in diesem Fall, die Kommentare über die zu beschreibende Codezeile zu schreiben, der Code erhält zwar mehr Zeilen, jedoch lässt sich so der Kommentar genau zuordnen. Des Weiteren lässt sich so der Code auf jedem Bildschirm (Notebook, Desktop) einwandfrei lesen. 
Die Kommentierung des Codes ist verständlich und ist umfangreich vorhanden.
Für einer klarere Darstellung, dass die RFID- Karte nicht angenommen wurde, wäre zusätzlich eine rote LED sinnvoll, welche nur Aufleuchtet, wenn `Serial.printIn(„NICHT BERECHTIGT“)` (87) ausgibt. Somit würde auch das Aufblinken der `grünen LED` in (77) wegfallen und könnte durch ein einmaliges aufblinken für 1-2sec ersetzt werden.
Einrückungen wurden sinnvoll gesetzt.
 
***Bewegungsmelder.h:***
Genau wie in RFID.ino gilt das einfügen der Kommentare über dem Code sinnvoller ist.
Die Kommentierung des Codes ist verständlich und ist umfangreich vorhanden.
Die Wahl des Namens der Funktion `motionsensor` (6) ist ungünstig gewählt, da dies ebenfalls der Name der Klasse ist, der Name Sensor würde in diesem Fall ausreichen.
Einrückungen wurden sinnvoll gesetzt.

**Kommentare:**  
Die Kommentierung fällt wie bereits in den Codestandards erklärt recht umfangreich aus. Weitere Anmerkung müssen nicht getätigt werden.

**Logik:**  
Es befinden sich keine Logikfehler im Code, der Code ist sehr gut verständlich.

**Fehlerbehandlung:**
Es sind keine Fehler ersichtlich.

**Codeentscheidungen:**  
Der Code ist sehr schlank gehalten und ist gut verständlich. Lediglich eine bessere Visualisierung der Erkennung der RFID- Karte wäre angebracht um dieses nicht falsch zu deuten.

## Review 3
### Name des Reviewers

Michel Brandes
### Name des Entwicklers

Jannik Hansen, Gruppe "Mensch ist der United"
### Dateien

### git-Revision (git log)

7c92d5e5cf29aecbc08f903093364b6d5e508e87
### Untersuchte Funktionalität

Funktionalität, Aufbau und Struktur des Codes
### Reviewergebnisse

**Codierungsstandards:**  
Der Code ist durch die korrekte Verwendung von Einrückungen und Absätzen sehr übersichtlich und gut lesbar.

**Kommentare:**  
Die Beregnungsfunktion.ino ist angemessen kommentiert was ungemein zum Verständnis des Codes beiträgt, Variablen und Funktionen sind zweckmäßig benannt.
Die setup_Rain.h ist deutlich minimalistischer kommentiert, dank gelungen benannten Variablen sind ihr Aufbau und ihre Funktion dennoch ohne Probleme verständlich.

**Logik:**  
Im Code befinden sich soweit keine Logikfehler.

**Fehlerbehandlung:**  
Fehler können einzig und allein in der Interaktion mit dem Arduino entstehen und müssen durch Tests mit eben jenem ausgeschlossen werden.

**Codeentscheidungen:**  
Da der Code gut aufgebaut und kommentiert ist besteht kein akuter Änderungsbedarf, einzig die Klasse PT2D scheint mit dem Inhalt von nur 3 Objekten überflüssig, dies wurde aber bereits erkannt und in einem Kommentar festgehalten.


## Review 4
### Name des Reviewers

Yannik Schäkel
### Name des Entwicklers

Nerea Meinicke, Gruppe "Mensch ist der United"  
### Dateien

Temperatur.ino
### git-Revision (git log)

Last commit for all Data:
7c92d5e5cf29aecbc08f903093364b6d5e508e87

### Untersuchte Funktionalität
Codeaufbau, Kommentierung und Funktionalität des Codes

### Reviewergebnisse

**Codierungsstandards:**
Durch Einrückung und Absätzen wurde der Code übersichtlich gestaltet. If-else Anweisungen sind somit einfacher lesbar. Der Code ist dazu systematisch aufgebaut, am Anfang die Deklaration der Variablen, folgend die Void Setup und die Void Loop.  

**Kommentare:**  
Durch eine Vielzahl an Kommentaren, kann man überall nachlesen was an dieser Stelle passieren soll. Zwischendurch wird auch für die Void Setup oder Void Loop in einem größerem Block genauer erklärt was hier geschieht. 
Jedoch hätte man die Kommentare in einer Tabulator-Ordnung bringen können. so stehen viele versetzt übereinander.
Dafür sind die Kommentare schmal gehalten, was zu Folge hat das man nicht viel nach rechts oder links scrollen muss.  

**Logik:**  
Man kann gut nachvollziehen was sich der Entwickler im Code gedacht hat. Logikfehler sind soweit nicht zu erkennen.   

**Fehlerbehandlung:**
Fehler sind nicht zu erkennen. Fehler die z.B. durch den Arduino verursacht werden, müssen manuell gesucht und behoben werden.  

**Codeentscheidungen:**  
Durch die Struktur ist der Code verständlich aufgebaut, auch für fremde Leser. Durch Wahl einfacher Variablen wird der Code nicht künstlich verkompliziert und durch den Schlanken Aufbau das lesen vereinfacht.
