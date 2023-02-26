/*
RGT Steering Controller
The Arduino will act as a USB keyboard and when you press the buttons it will send the 'A' or 'D' keyboard signals. 

*** PULL Up Version ***


BOM:
- Arduino Pro Micro 
- Switch qty: 2 (any contact normally open will work)

*/

#include <Keyboard.h>



const int buttonLeftPin = 5;  
const int buttonRightPin = 7;  
 


void setup() {
  pinMode(buttonLeftPin, INPUT_PULLUP);
  pinMode(buttonRightPin, INPUT_PULLUP);

   Keyboard.begin();
   Keyboard.releaseAll();
}

void loop() {

if(digitalRead(buttonLeftPin) != HIGH){
      Keyboard.write('A');
    }
    else if (digitalRead(buttonRightPin) != HIGH){
      Keyboard.write('D');
    }

    delay(150);
}
