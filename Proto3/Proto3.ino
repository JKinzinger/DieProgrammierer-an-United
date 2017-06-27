

class Gruen
{
  int ledPin;
  long OnTime;
  long OffTime;

  int ledState;
  unsigned long previousMillis;

 public:
  Gruen(int pin, long on, long off)
  {
    ledPin = pin;
    pinMode (ledPin, OUTPUT);

    OnTime = on;
    OffTime = off;

    ledState = LOW;
    previousMillis = 0;
  }

 void Update()
  {
    // check to see if it's time to change the state of the LED
    unsigned long currentMillis = millis();
     
    if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
    {
      ledState = LOW;  // Turn it off
      previousMillis = currentMillis;  // Remember the time
      digitalWrite(ledPin, ledState);  // Update the actual LED
    }
    else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
    {
      ledState = HIGH;  // turn it on
      previousMillis = currentMillis;   // Remember the time
      digitalWrite(ledPin, ledState);   // Update the actual LED
    }
  }
};

class Gelb
{
  int ledPin;
  long OnTime;
  long OffTime;

  int ledState;
  unsigned long previousMillis;

 public:
  Gelb(int pin, long on, long off)
  {
    ledPin = pin;
    pinMode (ledPin, OUTPUT);

    OnTime = on;
    OffTime = off;

    ledState = LOW;
    previousMillis = 0;
  }

 void Update()
  {
    // check to see if it's time to change the state of the LED
    unsigned long currentMillis = millis();
     
    if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
    {
      ledState = LOW;  // Turn it off
      previousMillis = currentMillis;  // Remember the time
      digitalWrite(ledPin, ledState);  // Update the actual LED
    }
    else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
    {
      ledState = HIGH;  // turn it on
      previousMillis = currentMillis;   // Remember the time
      digitalWrite(ledPin, ledState);   // Update the actual LED
    }
  }
};



class Rot
{
  // Class Member Variables
  // These are initialized at startup
  int ledPin;      // the number of the LED pin
  long OnTime;     // milliseconds of on-time
  long OffTime;    // milliseconds of off-time

  // These maintain the current state
  int ledState;                 // ledState used to set the LED
  unsigned long previousMillis;   // will store last time LED was updated

  // Constructor - creates a Flasher 
  // and initializes the member variables and state
  public:
  Rot(int pin, long on, long off)
  {
  ledPin = pin;
  pinMode(ledPin, OUTPUT);     
    
  OnTime = on;
  OffTime = off;
  
  ledState = LOW; 
  previousMillis = 0;
  }

  void Update()
  {
    // check to see if it's time to change the state of the LED
    unsigned long currentMillis = millis();
     
    if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
    {
      ledState = LOW;  // Turn it off
      previousMillis = currentMillis;  // Remember the time
      digitalWrite(ledPin, ledState);  // Update the actual LED
    }
    else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
    {
      ledState = HIGH;  // turn it on
      previousMillis = currentMillis;   // Remember the time
      digitalWrite(ledPin, ledState);   // Update the actual LED
    }
  }
};

int haupt = 21000;
int neben = 7000;
int abbieger = 5000;

Rot led1(2, 3700, 21000);
Rot led2(3, 3700, 9500);
Gelb led3(4, 700, haupt);
Gelb led4(5, 700, neben);
Gelb led5(6,700, abbieger);
Gruen led6(7, haupt, 6200);
Gruen led7 (8, neben, 6200);
Gruen led8(9, abbieger, 6200);
Gelb led9(4, 2500, 3000);
Gelb led10(5, 2500,3000);
Gelb led11(6, 2500,3000);
Rot led12(10, 3700, 7500);

void setup()
{
}

void loop()
{
  led1.Update();
  led3.Update();
  led6.Update();
  led9.Update();

 // led2.Update();
 // led4.Update();
 // led7.Update();
 // led10.Update();

 // led12.Update();
 // led5.Update();
 // led8.Update();
 // led11.Update();
}
