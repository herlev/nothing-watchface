#include "font.h"
#include "weekday_indicator.h"
#include <pebble.h>

static Window *main_window;
static TextLayer *date_layer;
static Layer *canvas_layer;

static const char *months[] = {
    "JAN", "FEB", "MAR", "APR", "MAY", "JUN",
    "JUL", "AUG", "SEP", "OCT", "NOV", "DEC",
};

static void update_time() {
  time_t temp = time(NULL);
  struct tm *tick_time = localtime(&temp);

  static char date_buf[20];

  snprintf(
      date_buf, sizeof(date_buf), "%s %d", months[tick_time->tm_mon],
      tick_time->tm_mday
  );
  text_layer_set_text(date_layer, date_buf);
  layer_mark_dirty(canvas_layer);
}

static void canvas_update_proc(Layer *layer, GContext *ctx) {
  graphics_context_set_antialiased(ctx, true);
  GRect bounds = layer_get_bounds(layer);
  time_t temp = time(NULL);
  struct tm *tick_time = localtime(&temp);
  uint8_t weekday = (tick_time->tm_wday + 7 - 1) % 7;
  // draw_cross_center(ctx);
  graphics_context_set_fill_color(ctx, GColorWhite);
  draw_time_center(ctx, &font1, tick_time->tm_hour, tick_time->tm_min);
  draw_weekday_indicator_center(
      ctx, weekday, 150, &font1, GColorDarkGray, GColorRed
  );
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_time();
}

static void main_window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  canvas_layer = layer_create(bounds);
  layer_set_update_proc(canvas_layer, canvas_update_proc);

  date_layer = text_layer_create(GRect(0, 8, bounds.size.w, 18));
  text_layer_set_font(
      date_layer, fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD)
  );
  text_layer_set_background_color(date_layer, GColorClear);
  text_layer_set_text_color(date_layer, GColorDarkGray);
  text_layer_set_text_alignment(date_layer, GTextAlignmentCenter);

  layer_add_child(window_layer, text_layer_get_layer(date_layer));
  layer_add_child(window_layer, canvas_layer);
}

static void main_window_unload(Window *window) {
  layer_destroy(canvas_layer);
  text_layer_destroy(date_layer);
}

static void init() {
  main_window = window_create();
  window_set_window_handlers(
      main_window, (WindowHandlers){
                       .load = main_window_load,
                       .unload = main_window_unload,
                   }
  );
  window_set_background_color(main_window, GColorBlack);

  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
  window_stack_push(main_window, true);
  update_time();
}

static void deinit() {
  window_destroy(main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
