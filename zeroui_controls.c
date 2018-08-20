#include "zeroui_controls.h"


//void button_control()

void output_subelements(zeroui_context_t *ctx, zeroui_control_t *control, zeroui_int_t x, zeroui_int_t y, zeroui_int_t w, zeroui_int_t h){
    if (control->contains != NULL){
        control->contains->output(control->contains, ctx, x, y, w, h);
    }
};


void measure_subelements(zeroui_context_t *ctx, zeroui_control_t *control, zeroui_int_t *w, zeroui_int_t *h){
    if (control->contains != NULL){
        control->contains->measure(control->contains, ctx, w, h);
    }
};

void visualize_button(zeroui_context_t *ctx, zeroui_control_t *control, zeroui_int_t x, zeroui_int_t y, zeroui_int_t w, zeroui_int_t h){
    zeroui_button_attrib_t *attrib = (zeroui_button_attrib_t *)control->attrib;
    zeroui_canvas_set_draw_color(ctx->canvas, ctx->style->control_background);
    zeroui_canvas_fill_rect(ctx->canvas,x,y,w,h);
    zeroui_canvas_set_draw_color(ctx->canvas, ctx->style->control_face);
    zeroui_canvas_draw_rect(ctx->canvas,x,y,w,h);
    zeroui_int_t offset = ctx->style->border_width + ctx->style->margin;
    zeroui_monospace_draw_string(ctx->canvas, attrib->font, x+offset, y+offset, attrib->text);
    output_subelements(ctx, control, x, y, w, h);
    if (attrib->on_click != NULL){
        zeroui_select_bf_register(
            &(ctx->select_bf), 
            x, 
            y, 
            w,
            h, control);
    }
}

void measure_button(zeroui_context_t *ctx, zeroui_control_t *control, zeroui_int_t *w, zeroui_int_t *h){
    zeroui_button_attrib_t *attrib = (zeroui_button_attrib_t *)control->attrib;
    zeroui_int_t text_w = zeroui_monospace_get_str_w(attrib->font, attrib->text);
    zeroui_int_t text_h = zeroui_monospace_get_str_h(attrib->font, attrib->text);
    *w = text_w + (ctx->style->border_width * 2) + (ctx->style->margin * 2);
    *h = text_h + (ctx->style->border_width * 2) + (ctx->style->margin * 2);
}

void visualize_container(zeroui_context_t *ctx, zeroui_control_t *control, zeroui_int_t x, zeroui_int_t y, zeroui_int_t w, zeroui_int_t h){
    // zeroui_button_attrib_t *attrib = (zeroui_button_attrib_t *)control->attrib;
    // zeroui_canvas_set_draw_color(ctx->canvas, ctx->style->control_background);
    // zeroui_canvas_fill_rect(ctx->canvas,x,y,w,h);
    // zeroui_canvas_set_draw_color(ctx->canvas, ctx->style->control_face);
    // zeroui_canvas_draw_rect(ctx->canvas,x,y,w,h);
    // zeroui_int_t offset = ctx->style->border_width + ctx->style->margin;
    // zeroui_monospace_draw_string(ctx->canvas, attrib->font, x+offset, y+offset, attrib->text);
    output_subelements(ctx, control, x, y, w, h);
}

void measure_container(zeroui_context_t *ctx, zeroui_control_t *control, zeroui_int_t *w, zeroui_int_t *h){
    zeroui_container_attrib_t *attrib = (zeroui_container_attrib_t *)control->attrib;
    //zeroui_int_t text_w = zeroui_monospace_get_str_w(attrib->font, attrib->text);
    //zeroui_int_t text_h = zeroui_monospace_get_str_h(attrib->font, attrib->text);
    //*w = text_w + (ctx->style->border_width * 2) + (ctx->style->margin * 2);
    //*h = text_h + (ctx->style->border_width * 2) + (ctx->style->margin * 2);
    //*w = attrib->w;
    //*h = attrib->h;

    measure_subelements(ctx, control, w, h);
}

void zeroui_button_attrib_init(zeroui_button_attrib_t *attrib){
    attrib->font = NULL;
    attrib->text = " ??? ";
    attrib->on_click = NULL;
}

void zeroui_control_init_button(zeroui_context_t *ctx, zeroui_control_t *control, zeroui_button_attrib_t *attrib){
    //zeroui_control_t *result = malloc(sizeof(zeroui_control_t));
    //zeroui_control_t *butt = malloc(sizeof(zeroui_control_t));
    control->attrib = attrib;
    control->measure = &measure_button;
    control->visualize = &visualize_button;
    control->contains = NULL;
}



void zeroui_control_init_container(zeroui_context_t *ctx, zeroui_control_t* control, zeroui_container_attrib_t *attrib){
    control->attrib = attrib;
    control->measure = &measure_container;
    control->visualize = &visualize_container; 
    control->contains = NULL;   
}




void zeroui_style_init_monochrome_light(zeroui_style_t *style){
    zero_rgba_set(&style->backgroud_color, 255,255,255,255);
    zero_rgba_set(&style->border_color, 0,0,0,255);
    zero_rgba_set(&style->control_face, 0,0,0,255);
    zero_rgba_set(&style->control_background, 255,255,255,255);
    style->border_width = 1;
    style->margin = 1;
 }

void zeroui_style_init_monochrome_dark(zeroui_style_t *style){
    zero_rgba_set(&style->backgroud_color, 0,0,0,255);
    zero_rgba_set(&style->border_color, 255,255,255,255);
    zero_rgba_set(&style->control_face, 255,255,255,255);
    zero_rgba_set(&style->control_background, 0,0,0,255);
    style->border_width = 1;
    style->margin = 1;
 }



 void zeroui_context_init(zeroui_context_t *ctx, zeroui_canvas_t *canvas, zeroui_style_t *style){
     ctx->canvas = canvas;
     ctx->style = style;
 }


void horizontal_output(zeroui_layout_t *layout, zeroui_context_t *ctx, zeroui_int_t x, zeroui_int_t y, zeroui_int_t w, zeroui_int_t h){
    zeroui_int_t max_h = 0;
    zeroui_list_element_t *elm_i = layout->controls.head->next;
    while (elm_i != NULL){
        zeroui_control_t *control = (zeroui_control_t *)elm_i->data;
        zeroui_int_t control_w;
        zeroui_int_t control_h;
        
        control->measure(ctx, control, &control_w, &control_h);
        if (control_h > max_h){
            max_h = control_h;
        } 
        elm_i = elm_i->next;
    }

    // visualizing
    zeroui_int_t x_offset = 0;
    elm_i = layout->controls.head->next;
    while (elm_i != NULL){
        zeroui_control_t *control = (zeroui_control_t *)elm_i->data;
        zeroui_int_t control_w;
        zeroui_int_t control_h;
        
        control->measure(ctx, control, &control_w, &control_h);
        control->visualize(ctx, control, x+x_offset+ctx->style->margin, y, control_w, max_h);

        x_offset += control_w + ctx->style->margin;
        elm_i = elm_i->next;
    }
}

void horizontal_measure(zeroui_layout_t *layout, zeroui_context_t *ctx, zeroui_int_t *w, zeroui_int_t *h){
    zeroui_int_t max_h = 0;
    zeroui_int_t total_w = 0;
    zeroui_list_element_t *elm_i = layout->controls.head->next;
    while (elm_i != NULL){
        zeroui_control_t *control = (zeroui_control_t *)elm_i->data;
        zeroui_int_t control_w;
        zeroui_int_t control_h;
        
        control->measure(ctx, control, &control_w, &control_h);
        if (control_h > max_h){
            max_h = control_h;
        } 
        total_w += control_w + ctx->style->margin;
        elm_i = elm_i->next;
    }
    *w = total_w;
    *h = max_h;
}

void vertical_output(zeroui_layout_t *layout, zeroui_context_t *ctx, zeroui_int_t x, zeroui_int_t y, zeroui_int_t w, zeroui_int_t h){
    zeroui_int_t max_w = 0;
    zeroui_list_element_t *elm_i = layout->controls.head->next;
    while (elm_i != NULL){
        zeroui_control_t *control = (zeroui_control_t *)elm_i->data;
        zeroui_int_t control_w;
        zeroui_int_t control_h;
        
        control->measure(ctx, control, &control_w, &control_h);
        if (control_w > max_w){
            max_w = control_w;
        } 
        elm_i = elm_i->next;
    }

    // visualizing
    zeroui_int_t y_offset = 0;
    elm_i = layout->controls.head->next;
    while (elm_i != NULL){
        zeroui_control_t *control = (zeroui_control_t *)elm_i->data;
        zeroui_int_t control_w;
        zeroui_int_t control_h;
        
        control->measure(ctx, control, &control_w, &control_h);
        control->visualize(ctx, control, x, y+y_offset+ctx->style->margin, max_w, control_h);

        y_offset += control_h;
        elm_i = elm_i->next;
    }
}

void vertical_measure(zeroui_layout_t *layout, zeroui_context_t *ctx, zeroui_int_t *w, zeroui_int_t *h){
    zeroui_int_t total_h = 0;
    zeroui_int_t max_w = 0;
    zeroui_list_element_t *elm_i = layout->controls.head->next;
    while (elm_i != NULL){
        zeroui_control_t *control = (zeroui_control_t *)elm_i->data;
        zeroui_int_t control_w;
        zeroui_int_t control_h;
        
        control->measure(ctx, control, &control_w, &control_h);
        if (control_w > max_w){
            max_w = control_w;
        } 
        total_h += control_h + ctx->style->margin;
        elm_i = elm_i->next;
    }
    *w = max_w;
    *h = total_h;
}

 void zeroui_layout_init_horizontal(zeroui_layout_t *layout){
     zeroui_list_init(&layout->controls);
     layout->output = &horizontal_output;
     layout->measure = &horizontal_measure;
 }

 void zeroui_layout_init_vertical(zeroui_layout_t *layout){
     zeroui_list_init(&layout->controls);
     layout->output = &vertical_output;
     layout->measure = &vertical_measure;
 }