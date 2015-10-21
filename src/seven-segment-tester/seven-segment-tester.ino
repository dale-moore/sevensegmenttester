/****************************************************************************
Copyright (c) 2015 

    Dale Moore
    www.duckysoftware.com
    dale.moor3@gmail.com

Permission is hereby granted, free of charge, to any person obtaining 
a copy of this software and associated documentation files (the "Software"), 
to deal in the Software without restriction, including without limitation 
the rights to use, copy, modify, merge, publish, distribute, sublicense, 
and/or sell copies of the Software, and to permit persons to whom the 
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included 
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL 
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR 
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR 
OTHER DEALINGS IN THE SOFTWARE.
****************************************************************************/



// Identify the Arduino OUTPUT PINS 
const int APIN = 2;
const int BPIN = 3;
const int CPIN = 4;
const int DPIN = 5;
const int EPIN = 6;
const int FPIN = 7;
const int GPIN = 8;

// Identify the PIN to start with
int pinIndex = GPIN;

const int ALL=0;
const int SINGLE=1;
int mode=SINGLE;



void setup() {
  pinMode(APIN, OUTPUT);
  pinMode(BPIN, OUTPUT);
  pinMode(CPIN, OUTPUT);
  pinMode(DPIN, OUTPUT);
  pinMode(EPIN, OUTPUT);
  pinMode(FPIN, OUTPUT);
  pinMode(GPIN, OUTPUT);  
}
  
void loop() {  
  if (mode==SINGLE) {  
    getNextLed();
    turnOnLed(pinIndex);
    delay(500);
    turnOffLed(pinIndex);
    if (pinIndex==GPIN) {
      mode = ALL;
    }
  }
  else {
    turnOnAllLeds();    
    delay(1000);
    turnOffAllLeds();
    mode = SINGLE;
  }
}

int getNextLed() { 
  if (pinIndex == APIN)
    pinIndex = BPIN;
  else if (pinIndex == BPIN)
    pinIndex = CPIN;
  else if (pinIndex == CPIN)
    pinIndex = DPIN;
  else if (pinIndex == DPIN)
    pinIndex = EPIN;
  else if (pinIndex == EPIN)
    pinIndex = FPIN;
  else if (pinIndex == FPIN)
    pinIndex = GPIN;
  else if (pinIndex == GPIN) 
    pinIndex = APIN;      
}

void turnOffAllLeds() {
  turnOffLed(APIN);  
  turnOffLed(BPIN);
  turnOffLed(CPIN);
  turnOffLed(DPIN);
  turnOffLed(EPIN);
  turnOffLed(GPIN);
  turnOffLed(FPIN);
}

void turnOnAllLeds() {
  turnOnLed(APIN);  
  turnOnLed(BPIN);
  turnOnLed(CPIN);
  turnOnLed(DPIN);
  turnOnLed(EPIN);
  turnOnLed(GPIN);
  turnOnLed(FPIN);
}

void turnOffLed(int aPin) {
  digitalWrite(aPin, LOW);
}

void turnOnLed(int aPin) {
  digitalWrite(aPin, HIGH);
}
