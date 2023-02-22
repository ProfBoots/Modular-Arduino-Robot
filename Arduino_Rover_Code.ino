#include <Dabble.h>
#include <PWMServo.h>

/*Your bluetooth module 
    wiring is as follows: Vcc goes to 5v, GND goes to GND, Tx goes to 
    D2, and RX goes to D3. 
*/
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE


int dirPin1 = 5;
int dirPin2 = 4;

int dirPin3 = 7;
int dirPin4 = 6;

int dirPin5 = A0;
int dirPin6 = A1;

PWMServo claw;
PWMServo upperArm;

int armPos = 90;
int clawPos = 130;

void setup() {
    claw.attach(10);
  upperArm.attach(9);
  upperArm.write(armPos);
  claw.write(clawPos);

  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(dirPin3, OUTPUT);
  pinMode(dirPin4, OUTPUT);

  pinMode(dirPin5, OUTPUT);
  pinMode(dirPin6, OUTPUT);


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

  if(GamePad.isCrossPressed() && armPos < 270)
  {
    armPos++;
    upperArm.write(armPos);
    delay(10);
  }
   else if(GamePad.isTrianglePressed() && armPos > 0)
  {
    armPos--;
    upperArm.write(armPos);
    delay(10);
  }
  else if(GamePad.isSelectPressed() && clawPos < 180)
  {
    clawPos++;
    claw.write(clawPos);
    delay(10);
  }
  else if(GamePad.isStartPressed() && clawPos > 0)
  {
    clawPos--;
    claw.write(clawPos);
    delay(10);
  }
  else{
    claw.write(clawPos);
    upperArm.write(armPos);
  }
  if(GamePad.isSquarePressed())
  {
            Serial.println("Arm Up");
    digitalWrite(dirPin5, HIGH);
    digitalWrite(dirPin6, LOW);
  }
   else if(GamePad.isCirclePressed())
  {
            Serial.println("Arm Down");
    digitalWrite(dirPin5, LOW);
    digitalWrite(dirPin6, HIGH);
  }
  else{
        digitalWrite(dirPin5, LOW);
    digitalWrite(dirPin6, LOW);
  }
}
}
