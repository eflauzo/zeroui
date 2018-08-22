#ifndef ZEROUI_STYLE_H
#define ZEROUI_STYLE_H

#include "zeroui_color.h"
#include "zeroui_common.h"

#ifdef __cplusplus
extern "C" {
#endif



typedef struct zeroui_control_style_t_ zeroui_control_style_t; 
struct zeroui_control_style_t_ {
    zeroui_rgba_t border_color;
    zeroui_rgba_t control_face;
    zeroui_rgba_t control_background;
    zeroui_int_t border_width;
    zeroui_int_t margin;
};

typedef struct zeroui_style_t_ zeroui_style_t; 
struct zeroui_style_t_{
    zeroui_rgba_t backgroud_color;
    zeroui_int_t gap;

    zeroui_control_style_t *regular;
    zeroui_control_style_t *focus;
    zeroui_control_style_t *input_focus;
    
};




#ifdef __cplusplus
}
#endif

#endif