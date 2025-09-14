#pragma once
#include "font.h"
#include <pebble.h>
#include <stdint.h>

void draw_weekday_indicator_center(
    GContext *ctx, uint8_t weekday, uint8_t y, NdotFont *font, GColor8 color,
    GColor8 active_color
) {
  uint8_t w = font->dot_width;
  uint8_t x_center = PBL_DISPLAY_WIDTH / 2 - w / 2 + 1;
  uint8_t spacing = (w + font->dot_spacing) * 4;
  for (int i = 0; i < 7; i++) {
    graphics_context_set_fill_color(ctx, i == weekday ? active_color : color);
    graphics_fill_rect(
        ctx, GRect(x_center + (-3 + i) * spacing, y, w, w), w / 2 - 1, 0b1111
    );
  }
}
