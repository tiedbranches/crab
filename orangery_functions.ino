


void updateSpeedAndAccel() {
  stepper.setMaxSpeed(maxspeed);
  stepper.setAcceleration(accel);

}


void updateStepperPos() {

  stepper.moveTo(stepDest);

}



void moveStepper() {
  stepper.moveTo(5000);
  stepper.run();

  }

void moveStepper2() {
  stepper.moveTo(0);
  stepper.run();

  }

void moveStepperBack() {
  stepper.moveTo(0);
  stepper.run();

  }
