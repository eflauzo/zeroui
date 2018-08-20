#include "zeroui_canvas_sdl.h"
//#include "zeroui_canvas.h"
//#include <SDL2/SDL.h>

//#include <iostream>

//void (*pf)(int);

//typedef zeroio_int int16_t;

// void *userdata;
// void (*init)(zeroui_canvas_t *self);
// void (*rect)(zeroui_canvas_t *self, zeroui_int_t x, zeroui_int_t y, zeroui_int_t w, zeroui_int_t h);
// void (*cleanup)(zeroui_canvas_t *self);

// struct sdl_userdata {
//     SDL_Window *window;
//     SDL_Renderer *renderer;
// };


void zeroui_canvas_init(zeroui_canvas_t *canvas){
    
    //canvas = 
    //struct sdl_userdata *userdata = malloc(sizeof(struct sdl_userdata));
    //canvas = (void*)userdata;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(255, 255, 0, &canvas->window, &canvas->renderer);

}

void zeroui_canvas_destroy(zeroui_canvas_t *canvas){
    //struct sdl_userdata *userdata = (struct sdl_userdata *)(canvas);

    SDL_DestroyRenderer(canvas->renderer);
    SDL_DestroyWindow(canvas->window);
    SDL_Quit();
    
    //free(canvas);
}

void zeroui_canvas_clear(zeroui_canvas_t *canvas) {
    SDL_RenderClear(canvas->renderer);
}


void zeroui_canvas_flush(zeroui_canvas_t *canvas) {
    SDL_RenderPresent(canvas->renderer);
}



void zeroui_canvas_draw_rect(zeroui_canvas_t *canvas, zeroui_int_t x, zeroui_int_t y, zeroui_int_t w, zeroui_int_t h) {
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = w;
    r.h = h;
    SDL_RenderDrawRect(canvas->renderer, &r );
}

void zeroui_canvas_fill_rect(zeroui_canvas_t *canvas, zeroui_int_t x, zeroui_int_t y, zeroui_int_t w, zeroui_int_t h) {
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = w;
    r.h = h;
    SDL_RenderFillRect(canvas->renderer, &r );
}

void zeroui_canvas_set_draw_color(zeroui_canvas_t *canvas, zeroui_rgba_t color) {
    SDL_SetRenderDrawColor(canvas->renderer, color.r, color.g, color.b, color.a);
}


void zeroui_canvas_draw_point(zeroui_canvas_t *canvas, zeroui_int_t x, zeroui_int_t y) {
    SDL_RenderDrawPoint(canvas->renderer, x, y);
}

void zeroui_canvas_clip_rect(zeroui_canvas_t *canvas, zeroui_int_t x, zeroui_int_t y, zeroui_int_t w, zeroui_int_t h) {
    //printf("-->\n");
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = w;
    r.h = h;
    int rx = SDL_RenderSetClipRect(canvas->renderer, &r );
    if (rx!=0){
        printf("Oppps!\n");
        printf("%s",SDL_GetError());
        printf("---\n");
    }else{
        //printf("Success!\n");
    }
}

void zeroui_canvas_unclip_rect(zeroui_canvas_t *canvas){
int rx = SDL_RenderSetClipRect(canvas->renderer, NULL );
    if (rx!=0){
        printf("Oppps!\n");
        printf("%s",SDL_GetError());
        printf("---\n");
    }else{
        //printf("Success!\n");
    }
}
/*
class ZeroUI{
    private:
        Canvas *canvas;
    public:
        ZeroUI();
        void setCanvas(Canvas *canvas);
           
};
*/
