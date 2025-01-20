#include "main.h"

//CONTROL FUNCTIONS

/*
Sets the voltage of the two flywheel motors
@param voltage: voltage to set the motors to
*/
void setFlywheel(int voltage);

/*
Checks the status of the flywheel toggle and returns whether or not it is engaged
@return: the value of flywheelToggle, either true or false
*/
bool getFlywheelStatus();

float SteveControlLoop(int basepwm, int desiredrpm, double Kp);
extern bool backshot;

extern int autonError;
extern int autonpwm;
extern float autonkp;

extern void sniperAutonReg(void * ignore);
//AUTONOMOUS FUNCTIONS

//USER CONTROL FUNCTIONS

/*
Checks for action on the controller's 'A' button to turn the flywheel toggle either on or off
*/
void assignFlywheel();
