#ifndef ZEROUI_CONTEXT_H
#define ZEROUI_CONTEXT_H

#include "zeroui_common.h"
#include "zeroui_canvas.h"
#include "zeroui_mempool.h"
#include "zeroui_style.h"
//#include "zeroui_controls.h"
#include "zeroui_select_bf.h"

//#include 
//#include "zeroui_typograph.h"
//#include "zeroui_list.h"
//#include "zeroui_select_bf.h"

#ifdef __cplusplus
extern "C" {
#endif

//typedef struct zeroui_control_t_ zeroui_control_t; 

typedef struct zeroui_control_t_ zeroui_control_t; 


typedef struct zeroui_context_t_ zeroui_context_t; 
struct zeroui_context_t_ {
    zeroui_canvas_t *canvas;
    zeroui_style_t *style;
    zeroui_control_t *focus;
    zeroui_control_t *input_focus;
    zeroui_control_t *root_control;
    zeroui_mempool_t *mempool;
    zeroui_select_bf_t select_bf;
};

zeroui_context_t * zeroui_context_create(zeroui_mempool_t *mempool, zeroui_canvas_t *canvas, zeroui_style_t *style);


#ifdef __cplusplus
}
#endif

#endif