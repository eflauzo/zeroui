#ifndef ZEROUI_CONTROLS_H
#define ZEROUI_CONTROLS_H

#include "zeroui_common.h"
#include "zeroui_canvas.h"
#include "zeroui_typograph.h"
#include "zeroui_list.h"
#include "zeroui_select_bf.h"

#ifdef __cplusplus
extern "C" {
#endif



typedef struct zeroui_style_t_ zeroui_style_t; 
struct zeroui_style_t_ {
    zeroui_rgba_t backgroud_color;
    zeroui_rgba_t border_color;
    zeroui_rgba_t control_face;
    zeroui_rgba_t control_background;
    zeroui_int_t border_width;
    zeroui_int_t margin;
};

typedef struct zeroui_context_t_ zeroui_context_t; 
struct zeroui_context_t_ {
    zeroui_canvas_t *canvas;
    zeroui_style_t *style;
    zeroui_select_bf_t select_bf;
};

typedef struct zeroui_layout_t_ zeroui_layout_t;
struct zeroui_layout_t_{
    zeroui_list_t controls;
    void (*output)(zeroui_layout_t *layout, zeroui_context_t *ctx, zeroui_int_t x, zeroui_int_t y, zeroui_int_t w, zeroui_int_t h);
    void (*measure)(zeroui_layout_t *layout, zeroui_context_t *ctx, zeroui_int_t *w, zeroui_int_t *h);
};





// typedef struct zeroui_visualizer_t_ zeroui_visualizer_t; 
// struct zeroui_visualizer_t_ {
    
// };


typedef struct zeroui_control_t_ zeroui_control_t; 
struct zeroui_control_t_ {
    //zeroui_visualizer_t visualizer;
    void *attrib;
    zeroui_layout_t *contains;
    void (*visualize)(zeroui_context_t *ctx, zeroui_control_t *ctrl, zeroui_int_t x, zeroui_int_t y, zeroui_int_t w, zeroui_int_t h);
    void (*measure)(zeroui_context_t *ctx, zeroui_control_t *ctrl, zeroui_int_t *w, zeroui_int_t *h);
};





typedef struct zeroui_button_attrib_t_ zeroui_button_attrib_t;
struct zeroui_button_attrib_t_ {
    char* text;
    zeroui_monospace_font_t *font;
    void (*on_click)(zeroui_control_t *ctrl, zeroui_context_t *ctx);
};

typedef struct zeroui_container_attrib_t_ zeroui_container_attrib_t;
struct zeroui_container_attrib_t_ {
    zeroui_int_t w;
    zeroui_int_t h;
};

void zeroui_button_attrib_init(zeroui_button_attrib_t *attrib);
void zeroui_control_init_button(zeroui_context_t *ctx, zeroui_control_t* control, zeroui_button_attrib_t *attrib);
void zeroui_control_init_container(zeroui_context_t *ctx, zeroui_control_t* control, zeroui_container_attrib_t *attrib);




void zeroui_style_init_monochrome_light(zeroui_style_t *style);
void zeroui_style_init_monochrome_dark(zeroui_style_t *style);
void zeroui_context_init(zeroui_context_t *ctx, zeroui_canvas_t *canvas, zeroui_style_t *style);


void zeroui_layout_init_horizontal(zeroui_layout_t *layout);
void zeroui_layout_init_vertical(zeroui_layout_t *layout);

//visualize()

#ifdef __cplusplus
}
#endif

#endif