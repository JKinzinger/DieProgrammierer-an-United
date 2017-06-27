#ifndef TESTDEFINITIONEN_H
#define TESTDEFINITIONEN_H

#ifdef TEST

#include "test.h"
#include "registration.h"




void testJanis(){ // Name frei waehlbar
  // Die folgende Zeile sorgt dafuer, dass die Testfunktion 
  // identifizierbar ist 
  bool testResult = false;

  // Eigene Testimplementierung
  

  // testResult kann bei einem erfolgreichen Test 
  // auf true gesetzt werden
  
  
  APITest::printTestResult(testResult, "Umschaltung Sensor-/Zeitschaltung", "Janis Kinzinger",
  "A04 Eine Umstellung von einer festen Zeitschaltung auf eine sensorgesteuerte Schaltung soll moeglich sein.", "testDefinitionen.h");
}


void runTests(){
  APITest::printTestStartHeader(); // Nicht modifizieren
  
  // Hier sollen die eigenen Tests hinzugefuegt werden
  testJanis();
  
  APITest::printTestEndFooter(); // Nicht modifizieren
}
#endif //TEST

#ifdef TEST  // Nicht modifizieren
  #define RUNTEST runTests();
#else
  #define RUNTEST
#endif


#endif //TESTDEFINITIONEN_H
