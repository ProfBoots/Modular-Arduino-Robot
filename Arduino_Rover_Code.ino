#include <Dabble.h>
// dabble by STEMpedia

/*Your bluetooth module 
    wiring is as follows: Vcc goes to 5v, GND goes to GND, Tx goes to 
    D2, and RX goes to D3. 
*/
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

int speedPin = 9;
int dirPin1 = 5;
int dirPin2 = 4;

int speedPin2 = 11;
int dirPin3 = 7;
int dirPin4 = 6;

void setup() {
pinMode(speedPin, OUTPUT);
pinMode(speedPin, OUTPUT);

  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(dirPin3, OUTPUT);
  pinMode(dirPin4, OUTPUT);
  Serial.begin(250000);
  Dabble.begin(9600);
  
  
  // put your setup code here, to run once:

}

void loop() {
  Dabble.processInput(); { //Crucial in Grabbing and processing our Bluetooth inputs

  if(GamePad.isUpPressed())
  {
        Serial.println("Forward");
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, HIGH);
    digitalWrite(dirPin3, LOW);
    digitalWrite(dirPin4, HIGH);
  }
  else if(GamePad.isDownPressed())
  {
        Serial.println("Reverse");
    digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, LOW);
    digitalWrite(dirPin3, HIGH);
    digitalWrite(dirPin4, LOW);
  }
       else if(GamePad.isRightPressed())
  {
        Serial.println("Left");
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, HIGH);
    digitalWrite(dirPin3, HIGH);
    digitalWrite(dirPin4, LOW);
  }
    else if(GamePad.isLeftPressed())
  {
         Serial.println("RIGHT");
    digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, LOW);
    digitalWrite(dirPin3, LOW);
    digitalWrite(dirPin4, HIGH);

  }
 
  else
  {
         Serial.println("Stop");
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, LOW);
    digitalWrite(dirPin3, LOW);
    digitalWrite(dirPin4, LOW);
  }
}
}
