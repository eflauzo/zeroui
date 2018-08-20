#ifndef ZEROUI_TYPOGRAPH_H
#define ZEROUI_TYPOGRAPH_H

#include "zeroui_common.h"
#include "zeroui_canvas.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct zeroui_font_t_ zeroui_font_t; 
struct zeroui_font_t_ {

};

typedef struct zeroui_monospace_font_t_ zeroui_monospace_font_t; 
struct zeroui_monospace_font_t_ {

};


zeroui_int_t zeroui_monospace_get_char_w(zeroui_monospace_font_t *font);
zeroui_int_t zeroui_monospace_get_char_h(zeroui_monospace_font_t *font);
zeroui_int_t zeroui_monospace_get_str_w(zeroui_monospace_font_t *font, char *str);
zeroui_int_t zeroui_monospace_get_str_h(zeroui_monospace_font_t *font, char *str);
void zeroui_monospace_draw_char(zeroui_canvas_t *canvas, zeroui_monospace_font_t *font, zeroui_int_t x, zeroui_int_t y, char ch);
void zeroui_monospace_draw_string(zeroui_canvas_t *canvas, zeroui_monospace_font_t *font, zeroui_int_t x, zeroui_int_t y, char *str);

#ifdef __cplusplus
}
#endif

//typedef uint8_t zeroui_color_t;

#endif