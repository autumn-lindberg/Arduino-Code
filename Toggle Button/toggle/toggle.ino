//www.elegoo.com
//2016.12.08

int ledPin = 5;
int buttonPin = 9;

int on = 0;

unsigned long lastTimePressed = millis();
int debounceDelay = 200;

void setup() 
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  
  digitalWrite(ledPin, LOW);
}

void loop() 
{
  // if it's past the alotted debounce time
  if (millis() - lastTimePressed > debounceDelay) {
    // do stuff
    if (digitalRead(buttonPin) == LOW) {
      // start a new timer
      lastTimePressed = millis();
      on = 1 - on;
      digitalWrite(ledPin, on);
    }
  }
}