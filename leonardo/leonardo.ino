/*
* By Daniel Tam (daniel@danieltam.net)
* Fixed by bbben
============ NOTES ============
This will create a SDVX Controller using an Arduino Leonardo. 
You will hook up one wire of the button to the Arduino pin and the other to Arduino's ground. When pushed, the button should go to ground.
You will need to download the encoder library and use it in your project for this to work (ww.circuitsathome.com/mcu/reading-rotary-encoder-on-arduino)
===============================
*/

#include <Mouse.h>
#include <Keyboard.h>

// buttons
#define BT_A 4
#define BT_B 5
#define BT_C 6
#define BT_D 7
#define FX_L 8
#define FX_R 9
#define BT_ST 10

// encoders 0 1 2 3 only. dont change
#include <Encoder.h>
Encoder enc1(2, 3);
Encoder enc2(0, 1);

float knob1 = 0;
float knob2 = 0;
float old_knob1 = 0;
float old_knob2 = 0;

void setup()
{ 
  // set pins to read
  pinMode(BT_A, INPUT_PULLUP);
  pinMode(BT_B, INPUT_PULLUP);
  pinMode(BT_C, INPUT_PULLUP);
  pinMode(BT_D, INPUT_PULLUP);
  pinMode(FX_L, INPUT_PULLUP);
  pinMode(FX_R, INPUT_PULLUP);
  pinMode(BT_ST, INPUT_PULLUP);
  
  Mouse.begin();
  Keyboard.begin();
}

void loop()
{
  // read encoders
  knob1 = (float)enc1.read();
  knob2 = (float)enc2.read();
  Mouse.move(0, knob1-old_knob1);
  Mouse.move(knob2-old_knob2, 0);
  old_knob2 = knob2;
  old_knob1 = knob1;
  
  
  // read the buttons for low, if it's low, output a keyboard press  
  if(digitalRead(BT_A) == LOW)
  {
    Keyboard.press('a');
  }
  else
  {
    Keyboard.release('a');
  }
  
  if(digitalRead(BT_B) == LOW)
  {
    Keyboard.press('b');
  }
  else
  {
    Keyboard.release('b');
  }
  
  if(digitalRead(BT_C) == LOW)
  {
    Keyboard.press('c');
  }
  else
  {
    Keyboard.release('c');
  }
  
  if(digitalRead(BT_D) == LOW)
  {
    Keyboard.press('d');
  }
  else
  {
    Keyboard.release('d');
  }
  
  if(digitalRead(FX_L) == LOW)
  {
    Keyboard.press('z');
  }
  else
  {
    Keyboard.release('z');
  }
  
  if(digitalRead(FX_R) == LOW)
  {
    Keyboard.press('x');
  }
  else
  {
    Keyboard.release('x');
  }
  
  if(digitalRead(BT_ST) == LOW)
  {
    Keyboard.press('n');
  }
  else
  {
    Keyboard.release('n');
  }
}
