#ifndef ZEROUI_CANVAS_H
#define ZEROUI_CANVAS_H

#include "zeroui_common.h"
#include "zeroui_canvas_sdl.h"
//#include <iostream>

//void (*pf)(int);

#ifdef __cplusplus
extern "C" {
#endif
/*
typedef struct _zeroui_canvas_t zeroui_canvas_t;
struct _zeroui_canvas_t{
    void *userdata;
    void (*init)(zeroui_canvas_t *self);
    void (*set_draw_color)(zeroui_canvas_t *self, zeroui_rgba_t color);
    void (*draw_rect)(zeroui_canvas_t *self, zeroui_int_t x, zeroui_int_t y, zeroui_int_t w, zeroui_int_t h);
    void (*fill_rect)(zeroui_canvas_t *self, zeroui_int_t x, zeroui_int_t y, zeroui_int_t w, zeroui_int_t h);
    void (*destroy)(zeroui_canvas_t *self);
    void (*flush)(zeroui_canvas_t *self);
    void (*clear)(zeroui_canvas_t *self);
};
*/

void zeroui_canvas_init(zeroui_canvas_t *self);
void zeroui_canvas_set_draw_color(zeroui_canvas_t *self, zeroui_rgba_t color);
void zeroui_canvas_draw_rect(zeroui_canvas_t *self, zeroui_int_t x, zeroui_int_t y, zeroui_int_t w, zeroui_int_t h);
void zeroui_canvas_fill_rect(zeroui_canvas_t *self, zeroui_int_t x, zeroui_int_t y, zeroui_int_t w, zeroui_int_t h);
void zeroui_canvas_destroy(zeroui_canvas_t *self);
void zeroui_canvas_flush(zeroui_canvas_t *self);
void zeroui_canvas_clear(zeroui_canvas_t *self);
void zeroui_canvas_draw_point(zeroui_canvas_t *self, zeroui_int_t x, zeroui_int_t y);
void zeroui_canvas_clip_rect(zeroui_canvas_t *canvas, zeroui_int_t x, zeroui_int_t y, zeroui_int_t w, zeroui_int_t h);
void zeroui_canvas_unclip_rect(zeroui_canvas_t *canvas);

//void zeroui_init_canvas(zeroui_canvas_t *canvas);

#ifdef __cplusplus
}
#endif

/*
class ZeroUI{
    private:
        Canvas *canvas;
    public:
        ZeroUI();
        void setCanvas(Canvas *canvas);
           
};
*/

#endif