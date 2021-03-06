// Scratchboard emulation
// by Kevin Osborn
// http://baldwisdom.com
// Feel free to use this code in any way you wish! (Though if you want to link
// to my blog, that would be cool)
// This is scratchboard use of a sparkfun midi shield which has 2 pots and 3 buttons.
#include <ScratchSensors.h>
#define BUTTON1   2
#define BUTTON2   3
#define BUTTON3   4
#define POT1      A0
#define POT2      A1

ScratchSensors Scratchboard;

void setup()
{
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  digitalWrite(BUTTON1, HIGH);
  digitalWrite(BUTTON2, HIGH);
  digitalWrite(BUTTON3, HIGH); 
  pinMode(POT1, INPUT);
  pinMode(POT2, INPUT);
  
  Scratchboard.init();
}

void loop()
{
  Scratchboard.Values[RESISTA] = analogRead(POT1);
  Scratchboard.Values[RESISTB] = analogRead(POT2);
  Scratchboard.Values[BUTTON] = digitalRead(BUTTON1)?1023:0;
 
  Scratchboard.report(); 

}

  


