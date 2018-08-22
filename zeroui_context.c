#include "zeroui_context.h"
//#include "zeroui_controls.h"

 zeroui_context_t * zeroui_context_create(zeroui_mempool_t *mempool, zeroui_canvas_t *canvas, zeroui_style_t *style) {
    zeroui_context_t *ctx = zeroui_mempool_alloc(mempool, sizeof(zeroui_context_t));
    ctx->canvas = canvas;
    ctx->mempool = mempool;
    ctx->style = style;
    
     //ctx->select_bf.itemcount = 0;
     zeroui_select_bf_reset(&ctx->select_bf);
     ctx->input_focus = NULL;
     ctx->focus = NULL;

    return ctx;
 }

