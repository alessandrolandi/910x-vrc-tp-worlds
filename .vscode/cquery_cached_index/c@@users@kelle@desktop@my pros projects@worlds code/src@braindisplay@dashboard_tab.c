#include "main.h"
#include <stdint.h>
#include "display/lv_conf.h"
#include "display/lv_draw/lv_draw.h"


void dashboard_tab_init(lv_obj_t* tab_dashboard) {
lv_obj_t* status_area = lv_cont_create(tab_dashboard, NULL);
 lv_cont_set_style(status_area, &style_status_area);
 lv_cont_set_fit(status_area, true, true);
 lv_obj_align(status_area, NULL, LV_ALIGN_IN_TOP_RIGHT, -128, 64);
 lv_cont_set_layout(status_area, LV_LAYOUT_COL_M);
}
