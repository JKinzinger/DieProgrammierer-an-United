#ifndef REGISTRATION_H // Falls REGISTRATION_H nicht vorhanden ist,...
#define REGISTRATION_H // fuege REGISTRATION_H und den Inhalt dieses Headers hinzu
                       // Damit wird verhindert, dass dieser Header zweimal
                       // hinzugefuegt wird.

char registeredTag[4];

int deletePerson(const char * strin, int str_size){

  if(str_size == 4)
  {
    if(strncmp(registeredTag, strin, 4) == 0)  //Wenn registeredTag == strin...
    {
      registeredTag[0] = '\0'; //registeredTag mit Nullen ueberschreiben
      registeredTag[1] = '\0';
      registeredTag[2] = '\0';
      registeredTag[3] = '\0';

      Serial.print("Tag removed");
      Serial.println();

      return 1;
    }
  }

  return 0;
}

void registerPerson(const char * strin, int str_size){

  if(str_size == 4) // Pruefung ob es nur 4 Byte sind
  {
    if(deletePerson(strin, str_size))
    {
      return;
    }
    
    strncpy(registeredTag, strin, 4); //String von 'strin' wird 'registeredTag' zugewiesen
    Serial.print("Tag registered");
    Serial.println();
  }
}

#endif // Schiesst die ifndef Abfrage ab siehe Zeile 1