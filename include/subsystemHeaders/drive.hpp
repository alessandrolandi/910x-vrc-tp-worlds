#include "main.h"

//CONTROL FUNCTIONS

/*
Sets the voltage of the four drive motors.
@param left: voltage of the left motors
@param right: voltage of the right motors
*/
void setDrive(int left, int right);

/*
Resets the integrated motor encoders on the four drive motors
*/
void tareDrive();

/*
Calculates the average of the four integrated motor encoders on the four drive motors
@return: POSITIVE average drive encoder value
*/
double avgEncoderUnits();


extern const lv_img_t debuglogo;
extern const uint8_t debuglogo_pixel_map;
extern const uint8_t skylinelogo_pixel_map;
extern const lv_img_t skylinelogo;
//AUTONOMOUS FUNCTIONS

/*
Moves the drivebase a certain number of units at a certain speed, as if on a grid
@param units: the amount of units to move (positive moves forward, negative moves backward)
@param speed: the voltage the motors will be set to as the drivebase Moves
@param resetGyro: whether or not to reset the gyroscope before performing the action (default set to true)
*/
void translate(int units, int speed, bool resetGyro = true);

/*
Moves the drivebase a certain number of units at variable speed using trigonometric acceleration and deceleration
@param units: the amount of units to move (positive moves forward, negative moves backward)
@param maxSpeed: the peak speed of the function (if less than the combined accel/decel units, will not reach this speed)
@param resetGyro: whether or not the reset the gyroscope before performing the action (default set to true)
*/
void translateAcc(int units, int maxSpeed, bool resetGyro = true);

/*
Moves the drivebase forward for a certain amount of time at a certain speed
@param millis: the amount of time, in milliseconds, to move forward
@param votlage: the exact voltage to set the motors to during this motion
@param useGyro: whether or not to use the gyroscope to stabilize the drive when moving
*/
void translateTime(int millis, int voltage, bool useGyro = false);

/*
Rotates the drivebase a certain number of units, at a certain speed (for most of the turn)
@param degrees10: the amount of units, in degrees * 10, to rotate the drivebase
@parm maxSpeed: the peak speed of the turn, used until it gets within 100 units of the turn
*/
void rotate(int degrees10, int maxSpeed);

//USER CONTROL FUNCTIONS

/*
Checks the controller's joysticks and assigns the designated values to the four drive motors
*/
void assignDrive();
