//www.elegoo.com
//2016.12.08

#include "pitches.h"
 
int pin = 8;
int numNotes = 29;

struct Note {
  unsigned int frequency;
  unsigned long duration;

  Note(int frequency, int duration) {
    this->frequency = frequency;
    this->duration = duration;
  }

  void play() {
    tone(pin, this->frequency);
    delay(this->duration);
  }
};

// notes in the melody:
Note melody[] = {
  Note(NOTE_C5, 375),
  Note(0, 5),
  Note(NOTE_C5, 250),
  Note(NOTE_D5, 500),
  Note(NOTE_C5, 500),
  Note(NOTE_F5, 500),
  Note(NOTE_E5, 1000),
  
  Note(NOTE_C5, 375),
  Note(0, 5),
  Note(NOTE_C5, 250),
  Note(NOTE_D5, 500),
  Note(NOTE_C5, 500),
  Note(NOTE_G5, 500),
  Note(NOTE_F5, 1000),

  Note(NOTE_C5, 375),
  Note(0, 5),
  Note(NOTE_C5, 250),
  Note(NOTE_C6, 500),
  Note(NOTE_A5, 500),
  Note(NOTE_F5, 500),
  Note(NOTE_E5, 500),
  Note(NOTE_D5, 1000),

  Note(NOTE_B5, 375),
  Note(0, 5),
  Note(NOTE_B5, 250),
  Note(NOTE_A5, 500),
  Note(NOTE_F5, 500),
  Note(NOTE_G5, 500),
  Note(NOTE_F5, 1000),

};
 
void setup() {
 Serial.begin(9600);
}
 
void loop() {  
  for (int thisNote = 0; thisNote < numNotes; thisNote++) {

    melody[thisNote].play();
     
  }
  noTone(8);
  delay(2000);
   
}
