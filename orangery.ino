#include <SPI.h>
#include <AccelStepper.h>

AccelStepper stepper(1,3,2);

int stepDest = 0;
int maxspeed = 5000;
int accel = 5000;

unsigned long curMillis;
unsigned long firstMillis;
unsigned long secondMillis;
unsigned long loopMillis;

unsigned long prevReplyToPCmillis = 0;
unsigned long replyToPCinterval = 1000;

bool firstLoopLast;
bool secondLoopLast;


void setup() {
  Serial.begin(115200);

  stepper.setMaxSpeed(maxspeed);
  stepper.setAcceleration(accel);
  stepper.moveTo(stepDest);


}

void loop() {

  curMillis = millis();
 
  if (millis()<4000) {
    moveStepper();
    firstMillis=millis();
    Serial.print("firstMillis: ");
    Serial.println(firstMillis);
    firstLoopLast=true;
  }

  else if ((millis() >= 4000) && (curMillis < 8001)) {
    moveStepperBack();
    secondMillis=millis();
    Serial.print("secondMillis: ");
    Serial.println(secondMillis);
    firstLoopLast=false;
  }

  else if (((millis() - firstMillis) >= 4000) && firstLoopLast == false) {
    loopMillis=millis();
    
    while ((millis() - loopMillis) < 4000) {
      moveStepper();
      Serial.print("First loop: ");
      Serial.println(millis() - loopMillis);
      firstLoopLast=true;
    
    }
  }

  else if (((millis() - secondMillis) >= 4000) && firstLoopLast==true) {
    loopMillis = millis();

    while ((millis() - loopMillis) < 4000) {
      moveStepperBack();
      Serial.print("Second loop: ");
       Serial.println(millis() - loopMillis);
       firstLoopLast=false;
    }
  }
  

  
  
}
