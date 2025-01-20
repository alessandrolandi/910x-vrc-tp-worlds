#include "main.h"

//VARIABLES
int scraperPositions[] = {0, 1225, 1345};
int scraperPos = 0;

//CONTROL FUNCTIONS
void setScraper(int voltage) {
  scraper = voltage;
}

//AUTONOMOUS FUNCTIONS
void moveScraperTo(int pos, int maxSpeed, bool finish) {
  scraper.move_absolute(pos, maxSpeed);
  if(finish) {
    while(fabs(pos - scraper.get_position()) > 10)
      pros::delay(5);
  }
}

//USER CONTROL FUNCTIONS
void assignScraper() {
  if(controllerDigital(SCRAPER_UP_BUTTON) && scraperPos > 0) {
    scraperPos -= scraperPos == 2 ? 2 : 1;
    moveScraperTo(scraperPositions[scraperPos], 200);
    while(controllerDigital(SCRAPER_UP_BUTTON)) {
      assignDrive();
      pros::delay(5);
    }
  }
  else if(controllerDigital(SCRAPER_DOWN_BUTTON) && scraperPos < 2) {
    scraperPos++;
    moveScraperTo(scraperPositions[scraperPos], 200);
    while(controllerDigital(SCRAPER_DOWN_BUTTON)) {
      assignDrive();
      pros::delay(5);
    }
  }
  //scraper = 127 * (controllerDigital(SCRAPER_DOWN_BUTTON) - controllerDigital(SCRAPER_UP_BUTTON));
}


struct Pid
{
    double errorTotal;
    double errorZone;
    double error;
    const double kP,kI,kD;
    double errorLast;
};

int PID(Pid * pid, double setPoint, double Sensor){
  // Calculate error
  pid->error = setPoint - Sensor;
  pid->errorTotal += pid->error;
  pid->errorLast = pid->error;

    // Find proportional term
  double pTerm = pid->error * pid->kP;
    // Find integral term
  double iTerm = pid->kI * pid->errorTotal;
    // Find derivative term
  double dTerm = pid->kD * (pid->error - pid->errorLast);
  if (pid->error < pid->errorZone) {
    pid->errorTotal += pid->error;
  } else {
    pid->errorTotal = 0;
  }
    // Compute output
  double power = pTerm + iTerm + dTerm;

    // return val
  return power;
}