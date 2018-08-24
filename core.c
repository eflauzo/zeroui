#include <emscripten.h>
#include <emscripten/html5.h>

//#include <cstdlib>
#include "zeroui.h"

zeroui_control_t *container;
zeroui_context_t *ctx;
//zeroui_context_t ctx;

void mainloop(void *arg)
{      
    zeroui_context_t *ctx = (zeroui_context_t *)arg;
    zeroui_select_bf_reset(&ctx->select_bf);

    zeroui_canvas_set_draw_color(ctx->canvas, ctx->style->backgroud_color);
    zeroui_canvas_clear(ctx->canvas);
    container->visualize(ctx, container, 20, 20, 100, 40);
    zeroui_canvas_flush(ctx->canvas);


    /*
    zeroui_canvas_t *canvas = (zeroui_canvas_t *)arg;
    
    zeroui_canvas_clip_rect(canvas, 30,5,100,2500);
    zeroui_canvas_clear(canvas);

    
    
    zeroui_rgba_t black = {.r=0,.g=0,.b=0,.a=255};
    zeroui_canvas_set_draw_color(canvas, black);
    zeroui_canvas_clear(canvas);
    zeroui_rgba_t red = {.r=255,.g=0,.b=0,.a=255};
    zeroui_canvas_set_draw_color(canvas, red);
    zeroui_canvas_fill_rect(canvas, 20,20,90,40);
    

    zeroui_monospace_font_t font;
    
    zeroui_rgba_t orange = {.r=255,.g=255,.b=0,.a=255};
    zeroui_canvas_set_draw_color(canvas, orange);
    
    
    zeroui_monospace_draw_string(canvas, &font, 120, 120, "Hello XXXX World\0");
    
    //zeroui_canvas_clear(canvas);
    //zeroui_canvas_unclip_rect(canvas);
    zeroui_canvas_flush(canvas);
    */
}

//EM_BOOL key_callback(int eventType, const EmscriptenKeyboardEvent *e, void *userData)
//EMSCRIPTEN_RESULT emscripten_set_keypress_callback(const char *target, void *userData, EM_BOOL useCapture, em_key_callback_func callback)
EM_BOOL key_callback(int eventType, const EmscriptenKeyboardEvent *e, void *userData)
{
    printf("You pressed key %lu\n", e->which);
    if (ctx->input_focus != NULL){
        if (ctx->input_focus->on_key_down != NULL){
            ctx->input_focus->on_key_down(ctx->input_focus, ctx, e->which);
        }
    }
    return 0;
}

EM_BOOL mouse_callback(int eventType, const EmscriptenMouseEvent *e, void *userData)
{   
    printf("MOUSE    %ld   %ld\n",e->canvasX, e->canvasY);
    void* ptr = zeroui_select_bf_pick(&ctx->select_bf, e->canvasX, e->canvasY);
    if (ptr!=NULL){
        printf("Something ...\n");
        zeroui_control_t *ctrl = (zeroui_control_t *)ptr;
        if (ctrl->selectable){
            ctx->input_focus = ctrl;
        }

    }

    /*
  printf("%s, screen: (%ld,%ld), client: (%ld,%ld),%s%s%s%s button: %hu, buttons: %hu, movement: (%ld,%ld), canvas: (%ld,%ld), target: (%ld, %ld)\n",
    emscripten_event_type_to_string(eventType), e->screenX, e->screenY, e->clientX, e->clientY,
    e->ctrlKey ? " CTRL" : "", e->shiftKey ? " SHIFT" : "", e->altKey ? " ALT" : "", e->metaKey ? " META" : "", 
    e->button, e->buttons, e->movementX, e->movementY, e->canvasX, e->canvasY, e->targetX, e->targetY);
    */
    /*
  if (e->screenX != 0 && e->screenY != 0 && e->clientX != 0 && e->clientY != 0 && e->canvasX != 0 && e->canvasY != 0 && e->targetX != 0 && e->targetY != 0)
  {
    if (eventType == EMSCRIPTEN_EVENT_CLICK) gotClick = 1;
    if (eventType == EMSCRIPTEN_EVENT_MOUSEDOWN && e->buttons != 0) gotMouseDown = 1;
    if (eventType == EMSCRIPTEN_EVENT_DBLCLICK) gotDblClick = 1;
    if (eventType == EMSCRIPTEN_EVENT_MOUSEUP) gotMouseUp = 1;
    if (eventType == EMSCRIPTEN_EVENT_MOUSEMOVE && (e->movementX != 0 || e->movementY != 0)) gotMouseMove = 1;
  }

  if (eventType == EMSCRIPTEN_EVENT_CLICK && e->screenX == -500000)
  {
    printf("ERROR! Received an event to a callback that should have been unregistered!\n");
    gotClick = 0;
    report_result(1);
  }

  instruction();
  */
  return 0;
}

void btn1_on_click(zeroui_control_t *ctrl, zeroui_context_t *ctx){

}
    

int main()
{
    //zeroui_init_canvas(&canvas);

    zeroui_canvas_t canvas;
    zeroui_canvas_init(&canvas);

    //zeroui_style_t style;
    //zeroui_style_init_monochrome_dark(&style);

    
    //zeroui_context_init(ctx, &canvas, &style);


zeroui_control_style_t zeroui_control_style_monochrome_light = {
    .border_color = ZEROUI_COLOR_BLACK,
    .control_face = ZEROUI_COLOR_BLACK,
    .control_background = ZEROUI_COLOR_WHITE,
    .border_width = 1,
    .margin = 1,
    .control_font = &zeroui_font_regular
};

zeroui_control_style_t zeroui_control_style_monochrome_dark = {
    .border_color = ZEROUI_COLOR_WHITE,
    .control_face = ZEROUI_COLOR_WHITE,
    .control_background = ZEROUI_COLOR_BLACK,
    .border_width = 1,   
    .margin = 1,
    .control_font = &zeroui_font_regular
};


zeroui_style_t monozeroui_style_monochrome_dark = {
    .backgroud_color = ZEROUI_COLOR_BLACK,
    .gap = 1,
    .regular = &zeroui_control_style_monochrome_dark,
    .focus = &zeroui_control_style_monochrome_dark,
    .input_focus = &zeroui_control_style_monochrome_light
};



    zeroui_mempool_t mempool;
    ctx = zeroui_context_create(&mempool, &canvas, &monozeroui_style_monochrome_dark);

    //zeroui_control_t btn;
    //zeroui_container_attrib_t attrib_container;
    //attrib_container.w = 200;
    //attrib_container.h = 200;
    //zeroui_context_t *ctx = 
    //zeroui_control_init_container(ctx, &container, &attrib_container);




    /*
    zeroui_control_t btn1;
    zeroui_button_attrib_t attrib_btn1;
    zeroui_button_attrib_init(&attrib_btn1);
    attrib_btn1.text = "btn1";
    attrib_btn1.font = &regular;
    attrib_btn1.on_click = &btn1_on_click;
    zeroui_control_init_button(ctx, &btn1, &attrib_btn1);
    */
    zeroui_control_t *btn1 = zeroui_new_button(ctx, "Hello There");
    zeroui_control_t *btn2 = zeroui_new_button(ctx, "Hello There2");
    zeroui_control_t *btn3 = zeroui_new_button(ctx, "Hello There3");

    /*
    zeroui_control_t btn2;
    zeroui_button_attrib_t attrib_btn2;
    zeroui_button_attrib_init(&attrib_btn2);
    attrib_btn2.text = " This is 2 \0";
    attrib_btn2.font = &regular;
    zeroui_control_init_button(ctx, &btn2, &attrib_btn2);

    zeroui_control_t btn3;
    zeroui_button_attrib_t attrib_btn3;
    zeroui_button_attrib_init(&attrib_btn3);
    attrib_btn3.text = " I am 3 \0";
    attrib_btn3.font = &regular;
    zeroui_control_init_button(ctx, &btn3, &attrib_btn3);
    */

   /*
    zeroui_control_t edt;
    zeroui_edit_attrib_t attrib_edt;
    zeroui_edit_attrib_init(&attrib_edt);
    //attrib_btn3.text = " I am 3 \0";
    attrib_btn3.font = &regular;
    zeroui_control_init_edit(ctx, &edt, &attrib_edt);
    */


    zeroui_control_t *edt = zeroui_new_edit(ctx);

    //zeroui_control_t second_col;
    //zeroui_container_attrib_t second_col_attrib_container;
    //zeroui_control_init_container(ctx, &second_col, &second_col_attrib_container);

    
    zeroui_layout_t *v_layout = zeroui_new_vertical_layout(ctx);
    zeroui_control_t *second_col = zeroui_new_container(ctx, v_layout);
    //zeroui_layout_init_vertical(&v_layout);
    //second_col.contains = &v_layout;
    zeroui_list_append(&v_layout->controls, btn2);
    zeroui_list_append(&v_layout->controls, btn3);
    zeroui_list_append(&v_layout->controls, edt);

    //zeroui_layout_t layout;
    //zeroui_layout_init_horizontal(&layout);
    //container.contains = &layout;
    zeroui_layout_t *h_layout = zeroui_new_horizontal_layout(ctx);
    container = zeroui_new_container(ctx, h_layout);
    zeroui_list_append(&h_layout->controls, btn1);
    zeroui_list_append(&h_layout->controls, second_col);
    
    
    const int simulate_infinite_loop = 1; // call the function repeatedly
    const int fps = 10; // call the function as fast as the browser wants to render (typically 60fps)

    emscripten_set_keydown_callback(0, 0, 1, key_callback);
    emscripten_set_click_callback(0, 0, 1, mouse_callback);
    emscripten_set_main_loop_arg(mainloop, ctx, fps, simulate_infinite_loop);
    emscripten_set_click_callback(0, 0, 1, mouse_callback);
    
    zeroui_canvas_destroy(&canvas);

    return 0;
}
