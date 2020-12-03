#include <SPI.h>
#include <AccelStepper.h>


AccelStepper stepper(1,2,3);
AccelStepper stepper2(1,4,5);
AccelStepper stepper3(1,6,7);
AccelStepper stepper4(1,8,9);
AccelStepper stepper5(1,10,11);
AccelStepper stepper6(1,12,13);


char receivedChar;
boolean newData = false;


char dest;
int stepDest = 0;
int stepDest2 = 0;
int stepDest3 = 0;
int stepDest4 = 0;
int stepDest5 = 0;
int stepDest6 = 0;
int maxspeed = 2000;
int accel = 200;

unsigned long curMillis;

unsigned long prevReplyToPCmillis = 0;
unsigned long replyToPCinterval = 1000;


void setup() {
  Serial.begin(115200);

  delay(500);
  stepper.setCurrentPosition(0);
  stepper2.setCurrentPosition(0);
  stepper3.setCurrentPosition(0);
  stepper4.setCurrentPosition(0);
  stepper5.setCurrentPosition(0);
  stepper6.setCurrentPosition(0);

}

void loop() {

  curMillis = millis();
 
  recvOneChar();
  //showNewData();
  
  updateSpeedAndAccel();
  updateStepperPos();
  
  //replyToPC(); //unread replies cause trouble i.e full buffer

  moveStepper();



  
  
}

void recvOneChar() {
  if (Serial.available() > 0) {
    delay(20);
    receivedChar = Serial.read();
    newData = true;
    parseInc();
  }
}

void showNewData() {
  if (newData == true) {
    Serial.print("Received: ");
    Serial.println(receivedChar);
    newData = false;
    parseInc();
  }
}

void parseInc() {

  
  char dest = receivedChar;
  
  if (dest == 'w') {
    stepDest += 300;
  }

  else if (dest == 's') {
    stepDest -= 300;
  }
  
  else if (dest == 'y') {
    stepDest2 += 300;
  }
  
  else if (dest == 'h') {
    stepDest2 -= 300;
  }

  else if (dest == 'd') {
    stepDest3 += 300;
  }
  
  else if (dest == 'e') {
    stepDest3 -= 300;
  }

  else if (dest == 'f') {
    stepDest4 += 300;
  }

    else if (dest == 'r') {
     stepDest4 -= 300;

  }

    else if (dest == 't') {
    stepDest5 += 300;
  }

    else if (dest == 'g') {
    stepDest5 -= 300;
  }
  
    else if (dest == 'a') {
    stepDest6 -= 300;
  }

    else if (dest == 'q') {
    stepDest6 += 300;
  }

    while (Serial.available() > 0) {
    Serial.read();
   }

}

void zeroSteppers() {
  stepper.setCurrentPosition(0);
  stepper2.setCurrentPosition(0);
  stepper3.setCurrentPosition(0);
  stepper4.setCurrentPosition(0);
  stepper5.setCurrentPosition(0);
  stepper6.setCurrentPosition(0);

  stepDest = 0;
  stepDest2 = 0;
  stepDest3 = 0;
  stepDest4 = 0;
  stepDest5 = 0;
  stepDest6 = 0;
  
  //Serial.println("Zeroed in ZeroSteppers");
  delay(2000);
  //Serial.println("Zeroed in ZeroSteppers after wait");
}



void updateSpeedAndAccel() {
  stepper.setMaxSpeed(maxspeed);
  stepper.setAcceleration(accel);

  stepper2.setMaxSpeed(maxspeed);
  stepper2.setAcceleration(accel);

  stepper3.setMaxSpeed(maxspeed);
  stepper3.setAcceleration(accel);

  stepper4.setMaxSpeed(maxspeed);
  stepper4.setAcceleration(accel);

  stepper5.setMaxSpeed(maxspeed);
  stepper5.setAcceleration(accel);

  stepper6.setMaxSpeed(maxspeed);
  stepper6.setAcceleration(accel);
}


void updateStepperPos() {

  stepper.moveTo(stepDest);
  stepper2.moveTo(stepDest2);
  stepper3.moveTo(stepDest3);
  stepper4.moveTo(stepDest4);
  stepper5.moveTo(stepDest5);
  stepper6.moveTo(stepDest6);
  

}



void moveStepper() {
  stepper.run();
  stepper2.run();
  stepper3.run();
  stepper4.run();
  stepper5.run();
  stepper6.run();

  }
  
  
