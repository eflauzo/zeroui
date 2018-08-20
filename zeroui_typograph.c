#include "zeroui_typograph.h"
#include "font8x8_basic.h"

zeroui_int_t zeroui_monospace_get_char_w(zeroui_monospace_font_t *font){
    return 8;
}

zeroui_int_t zeroui_monospace_get_char_h(zeroui_monospace_font_t *font){
    return 8;
}

zeroui_int_t zeroui_monospace_get_str_w(zeroui_monospace_font_t *font, char *str){
    return strlen(str) * zeroui_monospace_get_char_w(font);
}
zeroui_int_t zeroui_monospace_get_str_h(zeroui_monospace_font_t *font, char *str){
    return zeroui_monospace_get_char_h(font);
}

void zeroui_monospace_draw_char(zeroui_canvas_t *canvas, zeroui_monospace_font_t *font, zeroui_int_t x, zeroui_int_t y, char ch){
    // TODO: add assert
    char *rows = font8x8_basic[ch];
    for (int row=0; row<8; row++){
        //char rows[row];
        for (int col=0; col<8; col++){
            char need_a_mark = (0x01 << col) & rows[row];
            if (need_a_mark){
                zeroui_canvas_draw_point(canvas, x + col, y + row);
            }
        }
    }
}

void zeroui_monospace_draw_string(zeroui_canvas_t *canvas, zeroui_monospace_font_t *font, zeroui_int_t x, zeroui_int_t y, char *str){
    char *ch_i = str;
    zeroui_int_t char_w = zeroui_monospace_get_char_w(font);
    zeroui_int_t xi = x;
    while (*ch_i != 0){
        zeroui_monospace_draw_char(
            canvas, 
            font, 
            xi, 
            y, 
            *ch_i
        );
        xi += char_w;
        ch_i++;
    } 
}
