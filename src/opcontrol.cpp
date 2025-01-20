#include "main.h"
//#include "subsystemSrc/drow.c"
//#include "display/lv_conf.h"
//#include "display/lvgl.h"
void opcontrol() {
	flywheelTop = 110;
	flywheelBottom = 110;
	/*
	LV_IMG_DECLARE(debuglogo);
  lv_obj_t * imgDebugLogo = lv_img_create(lv_scr_act(), NULL);
  lv_img_set_src(imgDebugLogo, &debuglogo);
  LV_IMG_DECLARE(skylineLogo);
	lv_obj_t * imgSkyline = lv_img_create(lv_scr_act(), NULL);
	lv_obj_align(imgSkyline, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 40);
	lv_img_set_src(imgSkyline, &skylinelogo);*/
	
		debugScreen();		
		while(true) {
			continuous();
		/*pros::lcd::print(1, "intake watts %f", intake.get_power());
			pros::lcd::print(2, "topFlywheel Motor watts %f", flywheelTop.get_power());
			pros::lcd::print(3, "bottomFlywheel Motor watts %f", flywheelBottom.get_power());
			pros::lcd::print(4, "gyro %f", gyro.get_value());
			pros::lcd::print(5, "flywheelrpm top %f",flywheelTop.get_actual_velocity());
			pros::lcd::print(6, "flywheelrpm bottom %f",flywheelBottom.get_actual_velocity());
			pros::lcd::print(7, "limitSwitch %D",limitSwitch.get_value());*/
		assignDrive();
		assignScraper();
		assignIntake();
		assignFlywheel();
		pros::delay(20);
	}
}
