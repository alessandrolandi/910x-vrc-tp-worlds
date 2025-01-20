#include "main.h"

//CONTROLLER DEFINES AND FUNCTIONS
extern pros::Controller controller;
#define LEFT_JOYSTICK pros::E_CONTROLLER_ANALOG_LEFT_Y
#define RIGHT_JOYSTICK pros::E_CONTROLLER_ANALOG_RIGHT_Y
#define INTAKE_BUTTON pros::E_CONTROLLER_DIGITAL_L2
#define OUTTAKE_BUTTON pros::E_CONTROLLER_DIGITAL_L1
#define SCRAPER_UP_BUTTON pros::E_CONTROLLER_DIGITAL_R2
#define SCRAPER_DOWN_BUTTON pros::E_CONTROLLER_DIGITAL_R1
#define FLYWHEEL_TOGGLE_BUTTON pros::E_CONTROLLER_DIGITAL_A
std::int32_t controllerDigital(pros::controller_digital_e_t channel);
std::int32_t controllerAnalog(pros::controller_analog_e_t channel);
bool anyIntakeButtonPressed();

//MOTORS
extern pros::Motor driveLeftBack;
extern pros::Motor driveLeftFront;
extern pros::Motor driveRightBack;
extern pros::Motor driveRightFront;
extern pros::Motor flywheelTop;
extern pros::Motor flywheelBottom;
extern pros::Motor intake;
extern pros::Motor scraper;
extern pros::ADIGyro gyro;
extern pros::ADIDigitalIn limitSwitch;
extern bool doubleShotting;
//AUTONS
void redFlags();
void redCaps();
void blueFlags();
void blueCaps();
void blueSnipe();
void redSnipe();
void skills();
void blue1ball();
void run();
void debugScreen();
void continuous();
//MISC
#define FLYWHEEL_SPEED 127
#define GYRO_PORT 'F'
