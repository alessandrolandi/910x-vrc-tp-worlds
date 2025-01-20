#include "main.h"

//CONTROL FUNCTIONS

/*
Sets the voltage of the scraper motor
@param voltage: the voltage to set the scraper motor to
*/
void setScraper(int voltage);

//AUTONOMOUS FUNCTIONS

/*
Moves the scraper to a designated position on the scraper motor's integrated encoder
@param pos: the unit value to move the scraper motor to, in raw counts
@param maxSpeed: the maximum allowable speed that the motor will move at until it reaches the designated position
@param finish: whether or not to pause all other code until the movement is complete, set to false by default
*/
void moveScraperTo(int pos, int maxSpeed, bool finish = false);

//USER CONTROL FUNCTIONS

/*
Checks for action on the right bumpers and shifts position either one step up or down
*/
void assignScraper();
