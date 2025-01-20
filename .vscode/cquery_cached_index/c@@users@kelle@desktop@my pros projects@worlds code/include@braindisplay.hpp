#include "main.h"

extern const lv_img_t debuglogo;
extern const uint8_t debuglogo_pixel_map;
extern const uint8_t skylinelogo_pixel_map;
extern const lv_img_t skylinelogo;


  // init
  void dashboard_create();
  void dashboard_tab_init(lv_obj_t* tab_dashboard);
  void auto_tab_init(lv_obj_t* tab_auto);
  void settings_tab_init(lv_obj_t* tab_settings);
  void dashboard_styles_init();

  // colors
  static const lv_color_t color_gold = LV_COLOR_HEX(0xBFA373);
  static const lv_color_t color_blue = LV_COLOR_HEX(0x0E192B);
  static const lv_color_t color_blue_sel = LV_COLOR_HEX(0x2E394B);
  static const lv_color_t color_grey = LV_COLOR_HEX(0xC9C7C8);

  // important objects
  extern lv_obj_t* brain_battery_pct;

  // styles
  extern lv_style_t style_container;
  extern lv_style_t style_list;
  extern lv_style_t style_list_border;
  extern lv_style_t style_btn_inline;
  extern lv_style_t style_btn_inline_prs;
  extern lv_style_t style_btn_standard;
  extern lv_style_t style_highlight;
  extern lv_style_t style_grey;
  extern lv_style_t style_toggle_bg;
  extern lv_style_t style_toggle_accent;
  extern lv_style_t style_toggle_knob;
  extern lv_style_t style_status_area;
  extern lv_style_t style_status;
  extern lv_style_t style_status_title;

  // animations
  lv_anim_t dashboard_anim_logo(lv_obj_t* b);
  lv_anim_t dashboard_anim_status(lv_obj_t* b);
  lv_anim_t logo_fade(lv_obj_t* b);
