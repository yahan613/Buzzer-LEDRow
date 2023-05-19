#include "pitches.h"
byte previousState=1, presentState=1, songNumber=10;
const int buttonPin = 2;     // the number of the pushbutton pin
int songLen[2] = {23, 14};
int thisNote = 0;

// notes in the melody:

int melody3[] = { //Merry have a little sheep
  NOTE_B5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_A5, NOTE_A5, NOTE_A5,
  NOTE_B5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_B5, NOTE_B5,
  NOTE_A5, NOTE_A5,NOTE_B5, NOTE_A5, NOTE_G5
};
int melody2[] = { //Harry Potter
  NOTE_B5, NOTE_E6, NOTE_G6, NOTE_FS6, NOTE_E6, NOTE_B6, NOTE_A6, NOTE_FS6, NOTE_E6, NOTE_G6, NOTE_FS6, NOTE_DS6, NOTE_F6, NOTE_B5
};//si mi sol fa# mi si la fa# mi sol fa# do fa si
int melody1[] = { //the Last of Us
  NOTE_G6, NOTE_E6, NOTE_A6, NOTE_FS6, NOTE_G6, 0, NOTE_G6, NOTE_E6, NOTE_A6, NOTE_FS6, NOTE_B6, 0, NOTE_G6,
  NOTE_E6, NOTE_A6, NOTE_FS6, NOTE_G6, 0, NOTE_AS6, NOTE_A6, NOTE_G6, NOTE_E6, NOTE_E6
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations3[] = {
  4, 4, 4, 4, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 2
};
int noteDurations2[] = {
  4, 2, 8, 8, 2, 4, 1, 1, 2, 8, 8, 2, 4, 1   
};
int noteDurations1[] = {
  3, 3, 3, 3, 1, 6, 3, 3, 3, 3, 1, 6, 3, 3, 3, 3, 1, 6, 3, 3, 3, 3, 1
};

int ledPin[10] = {
  4, 7, A4, A5, A3, A2, A1, A0, 12, 13
};
//si do mi fa fa# sol la sib si 0
void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  for(int thisLED = 0; thisLED < 10; thisLED++)
  {
    pinMode(ledPin[thisLED], OUTPUT);
  }
}

void loop() {
  checkButton();

  if(songNumber==10){
    for (thisNote = 0; thisNote < songLen[0]; thisNote++) {

      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations1[thisNote];
      tone(8, melody1[thisNote], noteDuration);
      checkButton();
      
      int led; 
      if(melody1[thisNote] == NOTE_B5) { led = ledPin[0]; Serial.println(led);}       //si
      else if(melody1[thisNote] == NOTE_DS6) { led = ledPin[1]; Serial.println(led);}  //dob
      else if(melody1[thisNote] == NOTE_E6) { led = ledPin[3]; Serial.println(led);}  //mi
      else if(melody1[thisNote] == NOTE_F6) { led = ledPin[4]; Serial.println(led);}  //fa
      else if(melody1[thisNote] == NOTE_FS6) { led = ledPin[5]; Serial.println(led);} //fa#
      else if(melody1[thisNote] == NOTE_G6) { led = ledPin[6]; Serial.println(led);}  //sol
      else if(melody1[thisNote] == NOTE_A6) { led = ledPin[7]; Serial.println(led);}  //la
      else if(melody1[thisNote] == NOTE_AS6) { led = ledPin[8]; Serial.println(led);} //sib
      else if(melody1[thisNote] == NOTE_B6) { led = ledPin[9]; Serial.println(led);}  //si
      else if(melody1[thisNote] == 0) { led = ledPin[2]; Serial.println(led);}        //0
      digitalWrite(led, HIGH);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(8);
      checkButton();
      digitalWrite(led, LOW);
    }
  checkButton();
  }
  
  if(songNumber==11){
    checkButton();
    for (thisNote = 0; thisNote < songLen[1]; thisNote++) {

      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations2[thisNote];
      tone(8, melody2[thisNote], noteDuration);
      checkButton();

      int led; 
      if(melody2[thisNote] == NOTE_B5) { led = ledPin[0]; Serial.println(led);}       //si
      else if(melody2[thisNote] == NOTE_DS6) { led = ledPin[1]; Serial.println(led);}  //dob
      else if(melody2[thisNote] == NOTE_E6) { led = ledPin[3]; Serial.println(led);}  //mi
      else if(melody2[thisNote] == NOTE_F6) { led = ledPin[4]; Serial.println(led);}  //fa
      else if(melody2[thisNote] == NOTE_FS6) { led = ledPin[5]; Serial.println(led);} //fa#
      else if(melody2[thisNote] == NOTE_G6) { led = ledPin[6]; Serial.println(led);}  //sol
      else if(melody2[thisNote] == NOTE_A6) { led = ledPin[7]; Serial.println(led);}  //la
      else if(melody2[thisNote] == NOTE_AS6) { led = ledPin[8]; Serial.println(led);} //sib
      else if(melody2[thisNote] == NOTE_B6) { led = ledPin[9]; Serial.println(led);}  //si
      else if(melody2[thisNote] == 0) { led = ledPin[2]; Serial.println(led);}        //0
      digitalWrite(led, HIGH);      

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(8);
      checkButton();     
      digitalWrite(led, LOW);
    }
    checkButton();
   }

}

void checkButton()
{
  for(int i = 0; i < 10; i++)
  {
    presentState = digitalRead(buttonPin);
    delay(2);
  }
  presentState = digitalRead(buttonPin);
  Serial.println(presentState);
  if(presentState==0){
    songNumber=21-songNumber;
    Serial.println(songNumber);
    if(songNumber == 10) {
      thisNote = songLen[1]; 
      Serial.println(thisNote); 
      delay(300);
      }
    else if(songNumber == 11) {
      thisNote = songLen[0]; 
      Serial.println(thisNote); 
      delay(300);
      }

  } else {
    previousState = presentState;
  }
  delay(10);
  previousState = presentState;
}
