// Scratchboard emulation library by Kevin Osborn
//https://github.com/osbock/ScratchSensors
//http://baldwisdom.com
#include <ScratchSensors.h>
ScratchSensors Scratchboard;

#include <Esplora.h>
int x_ofset = 0;
int x_value = 0;
int y_ofset = 0;
int y_value = 0;

void setup()
{
  //Initialize serial and wait for port to open:
  Serial.begin(9600); 
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  x_ofset = Esplora.readJoystickX();
  delay(100);
  y_ofset = Esplora.readJoystickY();
  delay(100);
  //Initialize the Scratchboard library
  Scratchboard.init();
}

void loop()
{
  Scratchboard.Values[SLIDER] = Esplora.readSlider();
  Scratchboard.Values[LIGHT] = Esplora.readLightSensor();
  Scratchboard.Values[SOUND] = Esplora.readMicrophone();
  Scratchboard.Values[BUTTON] = Esplora.readButton(SWITCH_DOWN) == HIGH?1023:0;
  
  //Map the resistance A and B to accelerometer
  Scratchboard.Values[RESISTA] = Esplora.readAccelerometer(X_AXIS);
  Scratchboard.Values[RESISTB] = Esplora.readAccelerometer(Y_AXIS);
  
  //Map the resistance C and D to the joystick
  //Check to see if the X axis is nearly at the centre if so report zero.
  x_value = Esplora.readJoystickX()-x_ofset;
  if(x_value == 1 or x_value == -1){
    Scratchboard.Values[RESISTC] = 0;
  }else{
    Scratchboard.Values[RESISTC] = x_value;
  }
  //Check to see if the Y axis is nearly at the centre if so report zero.
  y_value = Esplora.readJoystickY()-y_ofset;
  if(y_value == 1 or y_value == -1){
    Scratchboard.Values[RESISTD] = 0;
  }else{
    Scratchboard.Values[RESISTD] = y_value;
  }
  //Send the reading to Scratch
  Scratchboard.report(); 
}

  


