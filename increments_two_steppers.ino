#include <SPI.h>
#include <AccelStepper.h>

AccelStepper stepper(1,3,2);
AccelStepper stepper2(1,5,4);
AccelStepper stepper3(1,7,6);
AccelStepper stepper4(1,9,8);
AccelStepper stepper5(1,11,10);


const byte buffSize = 40;
char inputBuffer[buffSize];
const char startMarker = '<';
const char endMarker = '>';
const char incMarker = '.';
const char commMarker = ')';
const char testMarker = 'a';
byte bytesRecvd = 0;
boolean readInProgress = false;
boolean newDataFromPC = false;

char messageFromPC[buffSize] = {0};
char dest;
int stepDest = 0;
int stepDest2 = 0;
int stepDest3 = 0;
int stepDest4 = 0;
int stepDest5 = 0;
int maxspeed = 2000;
int accel = 1000;

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

}

void loop() {

  curMillis = millis();
 
  getDataFromPC();
  
  updateSpeedAndAccel();
  updateStepperPos();
  
  //replyToPC(); //unread replies cause trouble i.e full buffer

  moveStepper();
  //moveStepper();
  //moveStepper();
  //moveStepper();
  //moveStepper();
  
  
}
