#include <Keyboard.h> // The main library for sending keystrokes. //https://www.arduino.cc/reference/en/language/functions/usb/keyboard/
//#include "Mouse.h"
#include <Keypad.h>  //https://playground.arduino.cc/Code/Keypad/

#define encoder0PinA 3   //2
#define encoder0PinB 2    //3
#define encoder0Btn 8
int encoder0Pos = 0;


const byte ROWS = 3; 
const byte COLS = 3; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
};

byte rowPins[ROWS] = {10,16,14}; 
byte colPins[COLS] = {15,18,19}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  pinMode(encoder0PinA, INPUT_PULLUP);
  pinMode(encoder0PinB, INPUT_PULLUP);
  pinMode(encoder0Btn, INPUT_PULLUP);
  attachInterrupt(0, doEncoder, CHANGE);
}

int valRotary,lastValRotary;
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println(customKey);
    if(customKey == '1'){
    	Keyboard.write('p');
      
    }else if(customKey == '2'){
        Keyboard.write('0');
      
    }else if(customKey == '3'){
        Keyboard.write('9');
            
    }else if(customKey == '4'){
        Keyboard.write('['); 
      
    }else if(customKey == '5'){
		Keyboard.write(']');
            
    }else if(customKey == '6'){
		Keyboard.write('o');
      
    }else if(customKey == '7'){
		Keyboard.write('m');
      
    }else if(customKey == '8'){
		Keyboard.write('r');
    }

    
  }


//code for encoder

  int btn = digitalRead(encoder0Btn);
  if(valRotary>lastValRotary){
	Keyboard.write('3');
    }
  if(valRotary<lastValRotary)  {
	Keyboard.write('4');
    }
  lastValRotary = valRotary;
  delay(50);
}
void doEncoder()
{
  if (digitalRead(encoder0PinA) == digitalRead(encoder0PinB))
  {
  encoder0Pos++;
  }
  else
  {
  encoder0Pos--;
  }
  valRotary = encoder0Pos/2.5;
}
