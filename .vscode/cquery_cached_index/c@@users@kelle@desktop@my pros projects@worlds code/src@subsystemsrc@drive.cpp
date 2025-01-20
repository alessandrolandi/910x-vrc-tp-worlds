#include "main.h"

//SENSORS
pros::ADIGyro gyro(GYRO_PORT, 0.91);

//CONTROL FUNCTIONS
void setDrive(int left, int right) {
  driveLeftBack = left;
  driveRightBack = right;
  driveLeftFront = left;
  driveRightFront = right;
}

void tareDrive() {
  driveLeftFront.tare_position();
  driveLeftBack.tare_position();
  driveRightFront.tare_position();
  driveRightBack.tare_position();
}

double avgEncoderUnits() {
  return (fabs(driveLeftBack.get_position()) + fabs(driveLeftBack.get_position()) + fabs(driveRightFront.get_position()) +
  fabs(driveRightBack.get_position())) / 4;
}

//AUTONOMOUS FUNCTIONS
void translate(int units, int speed, bool resetGyro) {
  int reverse = abs(units) / units;
  if(resetGyro)
    gyro.reset();
  tareDrive();
  while(fabs(avgEncoderUnits()) < abs(units)) {
    setDrive(reverse * speed - gyro.get_value(), reverse * speed + gyro.get_value());
    pros::delay(5);
  }
  setDrive(reverse * -10, reverse * -10);
  pros::delay(75);
  setDrive(0, 0);
}

void translateAcc(int units, int maxSpeed, bool resetGyro) {
  int reverse = abs(units) / units;
  int accelUnits = 150;
  int decelUnits = 400;
  if(resetGyro)
    gyro.reset();
  tareDrive();
  int unitsTraveled, unitsLeft, baseVoltage, prevTraveled = 0, rampUp = 0;
  if(abs(units) >= accelUnits + decelUnits) {
    while(avgEncoderUnits() < abs(units)) {
      unitsTraveled = (int) avgEncoderUnits();
      unitsLeft = abs(units) - unitsTraveled;
      if(unitsTraveled < accelUnits)
        baseVoltage = (maxSpeed - 10) * sin(1.5708 * unitsTraveled / accelUnits) + 10;
      else if(unitsLeft < decelUnits)
        baseVoltage = (maxSpeed - 10) * sin(1.5708 * unitsLeft / decelUnits) + 10;
      else
        baseVoltage = maxSpeed;
      if(abs(unitsTraveled - prevTraveled) < 5)
        rampUp += 5;
      else
        rampUp = 0;
      baseVoltage += rampUp;
      pros::lcd::set_text(0, std::to_string(rampUp));
      pros::lcd::set_text(1, std::to_string(avgEncoderUnits()));
      setDrive(baseVoltage * reverse - gyro.get_value() * 0.5, baseVoltage * reverse + gyro.get_value() * 0.5);
      prevTraveled = unitsTraveled;
      pros::delay(5);
    }
    //setDrive(-5 * reverse, -5 * reverse);
    //pros::delay(50);
  }
  else {
    while(avgEncoderUnits() < abs(units)) {
      unitsTraveled = (int) avgEncoderUnits();
      unitsLeft = abs(units) - unitsTraveled;
      if(unitsTraveled < units * accelUnits / (accelUnits + decelUnits))
        baseVoltage = (maxSpeed - 10) * sin(1.5708 * unitsTraveled / accelUnits) + 10;
      else if(unitsLeft < units * decelUnits / (accelUnits + decelUnits))
        baseVoltage = (maxSpeed - 10) * sin(1.5708 * unitsLeft / decelUnits) + 10;
      setDrive(baseVoltage * reverse - gyro.get_value(), baseVoltage * reverse + gyro.get_value());
      pros::delay(5);
    }
    setDrive(-10 * reverse, -10 * reverse);
    pros::delay(50);
  }
  setDrive(0, 0);
}

void translateTime(int millis, int voltage, bool useGyro) {
  setDrive(voltage - (useGyro * gyro.get_value()), voltage + (useGyro * gyro.get_value()));
  pros::delay(millis);
}

void rotate(int degrees10, int maxSpeed) {
  int reverse = abs(degrees10) / degrees10;
  gyro.reset();
  while(fabs(gyro.get_value()) < abs(degrees10) - 100)
    setDrive(maxSpeed * reverse, -maxSpeed * reverse);
  setDrive(-10 * reverse, 10 * reverse);
  pros::delay(100);
  while(fabs(gyro.get_value()) > abs(degrees10) + 5 || fabs(gyro.get_value()) < abs(degrees10) - 5) {
    if(fabs(gyro.get_value()) > abs(degrees10) + 5)
      setDrive(0.5 * -maxSpeed * reverse, 0.5 * maxSpeed * reverse);
    else
      setDrive(0.5 * maxSpeed * reverse, 0.5 * -maxSpeed * reverse);
  }
  setDrive(5 * reverse, -5 * reverse);
  pros::delay(50);
  setDrive(0, 0);
}

void pidRotation(){

}

//USER CONTROL FUNCTIONS
void assignDrive() {
  int l = controllerAnalog(LEFT_JOYSTICK);
  int r = controllerAnalog(RIGHT_JOYSTICK);
  setDrive(abs(l) > 10 ? l : 0, abs(r) > 10 ? r : 0);
}
