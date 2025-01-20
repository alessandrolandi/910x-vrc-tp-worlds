#include "main.h"
#include <stdint.h>
#include "display/lv_conf.h"
#include "display/lv_draw/lv_draw.h"


void dashboard_create() {

    // tab view
    lv_obj_t* tab_view = lv_tabview_create(lv_scr_act(), NULL);
    lv_tabview_set_style(tab_view, LV_TABVIEW_STYLE_BG, &style_container);
    lv_tabview_set_style(tab_view, LV_TABVIEW_STYLE_INDIC, &style_highlight);
    lv_tabview_set_style(tab_view, LV_TABVIEW_STYLE_BTN_BG, &style_btn_inline);
    lv_tabview_set_style(tab_view, LV_TABVIEW_STYLE_BTN_PR, &style_btn_inline_prs);
    lv_tabview_set_style(tab_view, LV_TABVIEW_STYLE_BTN_REL, &style_btn_inline);
    lv_tabview_set_style(tab_view, LV_TABVIEW_STYLE_BTN_TGL_PR, &style_btn_inline_prs);
    lv_tabview_set_style(tab_view, LV_TABVIEW_STYLE_BTN_TGL_REL, &style_btn_inline);

    // dashboard tab
    lv_obj_t* tab_dashboard = lv_tabview_add_tab(tab_view, "DASHBOARD");
    lv_page_set_scrl_fit(tab_dashboard, false, false);
    lv_page_set_scrl_height(tab_dashboard, (lv_coord_t) (lv_obj_get_height(tab_dashboard) - 16));
    dashboard_tab_init(tab_dashboard);

    // auto tab
    lv_obj_t* tab_auto = lv_tabview_add_tab(tab_view, "AUTONOMOUS");
    lv_page_set_scrl_fit(tab_auto, false, false);
    lv_page_set_scrl_height(tab_auto, (lv_coord_t) (lv_obj_get_height(tab_auto) - 16));
    auto_tab_init(tab_auto);


    // settings tab
    lv_obj_t* tab_settings = lv_tabview_add_tab(tab_view, "SETTINGS");
    lv_page_set_scrl_fit(tab_settings, false, false);
    lv_page_set_scrl_height(tab_settings, (lv_coord_t) (lv_obj_get_height(tab_settings) - 16));
    settings_tab_init(tab_settings);


  }
