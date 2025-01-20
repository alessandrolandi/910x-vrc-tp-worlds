#include "main.h"
#include <stdint.h>
#include "display/lv_conf.h"
#include "display/lv_draw/lv_draw.h"

  lv_style_t style_container;
  lv_style_t style_list;
  lv_style_t style_list_border;
  lv_style_t style_highlight;
  lv_style_t style_grey;
  lv_style_t style_toggle_bg;
  lv_style_t style_toggle_accent;
  lv_style_t style_toggle_knob;
  lv_style_t style_btn_inline;
  lv_style_t style_btn_inline_prs;
  lv_style_t style_btn_standard;
  lv_style_t style_status_area;
  lv_style_t style_status;
  lv_style_t style_status_title;

  void dashboard_styles_init() {

    // container style
    lv_style_copy(&style_container, &lv_style_plain);
    style_container.body.border.color = color_gold;
    style_container.body.border.width = 16;
    style_container.body.border.part = LV_BORDER_BOTTOM;
    style_container.body.padding.hor = 0;
    style_container.body.padding.inner = 24;
    style_container.text.color = color_blue;
    style_container.line.color = color_grey;
    style_container.line.width = 4;
    style_container.line.opa = 255;
    //style_container.line.rounded = false;

    // list style
    lv_style_copy(&style_list, &style_container);
    style_list.body.border.width = 0;

    // list style (with bottom border)
    lv_style_copy(&style_list_border, &style_list);
    style_list_border.body.border.color = color_grey;
    style_list_border.body.border.width = 2;
    style_list_border.body.border.part = LV_BORDER_TOP | LV_BORDER_BOTTOM;

    // inline button style
    lv_style_copy(&style_btn_inline, &style_container);
    style_btn_inline.body.main_color = color_blue;
    style_btn_inline.body.grad_color = style_btn_inline.body.main_color;
    style_btn_inline.body.border.width = 0;
    style_container.body.padding.inner = 0;
    style_btn_inline.text.color = LV_COLOR_WHITE;
    style_btn_inline.text.opa = 255;

    // inline button style (pressed)
    lv_style_copy(&style_btn_inline_prs, &style_btn_inline);
    style_btn_inline_prs.body.main_color = color_blue_sel;
    style_btn_inline_prs.body.grad_color = style_btn_inline_prs.body.main_color;

    // standard button style
    lv_style_copy(&style_btn_standard, &style_btn_inline);
    style_btn_standard.body.radius = 32;

    // highlighted object style
    lv_style_copy(&style_highlight, &lv_style_plain_color);
    style_highlight.body.main_color = color_gold;
    style_highlight.body.grad_color = style_highlight.body.main_color;
    style_highlight.body.padding.hor = 12;
    style_highlight.body.padding.ver = 12;

    // grey style
    lv_style_copy(&style_grey, &style_highlight);
    style_grey.body.main_color = color_grey;
    style_grey.body.grad_color = style_grey.body.main_color;
    style_grey.line.color = color_grey;
    style_grey.line.width = 4;
    style_grey.line.opa = 255;
  //  style_grey.line.rounded = false;

    // toggle background color
    lv_style_copy(&style_toggle_bg, &style_grey);
    style_toggle_bg.body.padding.ver = 0;
    style_toggle_bg.body.padding.hor = 0;
    style_toggle_bg.body.padding.inner = 0;
    style_toggle_bg.body.radius = LV_RADIUS_CIRCLE;

    // toggle accent color
    lv_style_copy(&style_toggle_accent, &style_highlight);
    style_toggle_accent.body.padding.ver = 0;
    style_toggle_accent.body.padding.hor = 0;
    style_toggle_accent.body.padding.inner = 0;
    style_toggle_accent.body.radius = LV_RADIUS_CIRCLE;

    // toggle knob style
    lv_style_copy(&style_toggle_knob, &style_container);
    style_toggle_knob.body.main_color = color_blue;
    style_toggle_knob.body.grad_color = style_toggle_knob.body.main_color;
    style_toggle_knob.body.border.width = 0;
    style_toggle_knob.body.radius = LV_RADIUS_CIRCLE;

    // status area style
    lv_style_copy(&style_status_area, &lv_style_plain);
    style_status_area.body.padding.inner = 32;

    // status style
    lv_style_copy(&style_status, &style_container);
    style_status.body.border.color = color_grey;
    style_status.body.border.width = 4;
    style_status.body.border.part = LV_BORDER_FULL;
    style_status.text.font = &lv_font_dejavu_20;

    // status title style
    lv_style_copy(&style_status_title, &style_status);
    style_status_title.body.border.width = 0;
    style_status_title.body.padding.hor = 8;
    style_status_title.text.color = color_grey;
    style_status_title.text.font = &lv_font_dejavu_20;

  }
