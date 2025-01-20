#include "main.h"

//SENSORS
pros::ADIDigitalIn limitSwitch('h');

//IMPORTANT VARIABLES
bool loadOverride = false;
enum intakeModes {
  INTAKE_MODE_STILL = 0,
  INTAKE_MODE_INTAKE = 1,
  INTAKE_MODE_OUTTAKE = 2,
  INTAKE_MODE_LOAD = 3,
  INTAKE_MODE_FIRE = 4
};
int intakeMode = INTAKE_MODE_STILL;

//CONTROL FUNCTIONS
void setIntake(int voltage) {
  intake = voltage;
}

void setIntakeMode(int mode) {
  intakeMode = mode;
}

void load() {
  if(pros::competition::is_autonomous()) {
    int t = pros::millis();
    while(true) {
      setIntake(-50);
      if(pros::millis() - t > 1000 || limitSwitch.get_value() || loadOverride)
        break;
      pros::delay(5);
    }
  }
  else {
    int t = pros::millis();
    while(true) {
      setIntake(-40);
      if(pros::millis() - t > 3000 || limitSwitch.get_value() || loadOverride || anyIntakeButtonPressed())
        break;
      pros::delay(5);
    }
  }
  loadOverride = false;
  setIntake(0);
}

void fire() {
  if(pros::competition::is_autonomous()) {
    int t = pros::millis();
    while(true) {
      setIntake(-127);
      if(pros::millis() - t > 1000 || limitSwitch.get_value())
        break;
      pros::delay(5);
    }
    t = pros::millis();
    while(true) {
      setIntake(-127);
      if(pros::millis() - t > 1000 || !limitSwitch.get_value())
        break;
      pros::delay(5);
    }
  }
  else {
    int t = pros::millis();
    while(true) {
      setIntake(-127);
      if(pros::millis() - t > 1000 || limitSwitch.get_value() /*|| anyIntakeButtonPressed()*/)
        break;
      pros::delay(5);
    }
    t = pros::millis();
    while(true) {
      setIntake(-127);
      if(pros::millis() - t > 1000 || !limitSwitch.get_value() /*|| anyIntakeButtonPressed()*/)
        break;
      pros::delay(5);
    }
  }
  setIntake(0);
}
void backdoubleShot() {
  loadOverride = true;
  fire();
  setFlywheel(127);
  //setFlywheel(90);
  pros::delay(50);
  fire();
  //loadOverride = true;
}

void doubleShot() {
  doubleShotting = true;
  loadOverride = true;
  fire();
  pros::delay(15);
  //setIntake(10);
  //pros::delay(50);
  //setIntakeMode(INTAKE_MODE_LOAD);
  flywheelTop = -90;
  flywheelBottom = -90;
  pros::delay(30);
  flywheelTop = 20;
  flywheelBottom = 20;
  //loadOverride = true;
    pros::delay(5);
  fire();
    pros::delay(5);
  flywheelTop = 110;
	flywheelBottom = 110;
  doubleShotting = false;
  /*
  loadOverride = true;
  setFlywheel(FLYWHEEL_SPEED);*/
}
/*
void doubleShot() {
     while(!limitSwitch.get_value() && (abs(controller.get_analog(ANALOG_LEFT_Y)) < 30 && abs(controller.get_analog(ANALOG_RIGHT_Y)) < 30)) {
         intake = -127;
     }
     while(limitSwitch.get_value() && (abs(controller.get_analog(ANALOG_LEFT_Y)) < 30 && abs(controller.get_analog(ANALOG_RIGHT_Y)) < 30)) {
         intake = -127;
     }
		 if ((abs(controller.get_analog(ANALOG_LEFT_Y)) < 30 && abs(controller.get_analog(ANALOG_RIGHT_Y)) < 30)){
			 intake.set_brake_mode(MOTOR_BRAKE_HOLD);
			 intake = 0;
			 pros::delay(50);
			 flywheelTop = -100;
		   flywheelBottom =  -100;
			 pros::delay(50);
			 flywheelTop = 35;
			 flywheelBottom = 35;
			 pros::delay(10);
		 }
     while(!limitSwitch.get_value() && (abs(controller.get_analog(ANALOG_LEFT_Y)) < 30 && abs(controller.get_analog(ANALOG_RIGHT_Y)) < 30)) {
         intake = -127;
     }
     while(limitSwitch.get_value() && (abs(controller.get_analog(ANALOG_LEFT_Y)) < 30 && abs(controller.get_analog(ANALOG_RIGHT_Y)) < 30)) {
         intake = -127;
     }
     intake = 0;
     flywheelTop = FLYWHEEL_SPEED;
     flywheelBottom = FLYWHEEL_SPEED;
 }

void doubleShot() {
  fire();
  pros::delay(500);
  //setIntakeMode(INTAKE_MODE_LOAD);
  pros::delay(20);
  setFlywheel(-90);
  pros::delay(90);
  setFlywheel(60);
  //loadOverride = true;
  fire();
  pros::delay(500);
  setFlywheel(FLYWHEEL_SPEED);
}
*/
//AUTONOMOUS FUNCTIONS
void intakeModeControlFnc(void * ignore) {
  intake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  while(true) {
    switch(intakeMode) {
      case INTAKE_MODE_STILL:
        break;
      case INTAKE_MODE_INTAKE:
        _intake();
        setIntakeMode(INTAKE_MODE_STILL);
        break;
      case INTAKE_MODE_OUTTAKE:
        outtake();
        setIntakeMode(INTAKE_MODE_STILL);
        break;
      case INTAKE_MODE_LOAD:
        load();
        setIntakeMode(INTAKE_MODE_STILL);
        break;
      case INTAKE_MODE_FIRE:
        fire();
        load();
        setIntakeMode(INTAKE_MODE_STILL);
        break;
    }
    pros::delay(20);
  }
}

//COMPETITION FUNCTIONS
void assignIntake() {
  if(controllerDigital(INTAKE_BUTTON)) {
    int t = pros::millis();
    while(pros::millis() - t < 200 && controllerDigital(INTAKE_BUTTON)) {
      assignDrive();
      assignScraper();
      assignFlywheel();
      pros::delay(5);
    }
    if(!controllerDigital(INTAKE_BUTTON)){

      if(backshot){
        backdoubleShot();
      }
      else{
        doubleShot();
      }
    }
    else{
      setIntakeMode(INTAKE_MODE_INTAKE);
    }


/*    else {
      t = pros::millis();
      while(pros::millis() - t < 200 && !controllerDigital(INTAKE_BUTTON)) {
        assignDrive();
        pros::delay(5);
      }
      if(controllerDigital(INTAKE_BUTTON)) {
        if(getFlywheelStatus())
          doubleShot();
      }
        setIntakeMode(INTAKE_MODE_LOAD);
    }*/
    while(intakeMode != INTAKE_MODE_STILL) {
      assignDrive();
      assignScraper();
      assignFlywheel();
      pros::delay(5);
    }
    setIntakeMode(INTAKE_MODE_LOAD);
    pros::delay(5);
  }
  else if(controllerDigital(OUTTAKE_BUTTON)) {
      loadOverride = true;
      setIntakeMode(INTAKE_MODE_FIRE);
      while(intakeMode != INTAKE_MODE_STILL) {
        assignDrive();
        assignScraper();
        assignFlywheel();
        pros::delay(5);
      }
      setIntakeMode(INTAKE_MODE_LOAD);
  }
  while(intakeMode != INTAKE_MODE_STILL) {
    assignDrive();
    assignScraper();
    assignFlywheel();
    pros::delay(5);
  }
  }


void _intake() {
  while(controllerDigital(INTAKE_BUTTON)) {
    setIntake(127);
    pros::delay(5);
  }
  setIntake(0);
}

void outtake() {
  while(controllerDigital(OUTTAKE_BUTTON)) {
    setIntake(-84);
    pros::delay(5);
  }
  setIntake(0);
}
