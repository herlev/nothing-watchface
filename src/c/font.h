#pragma once

#include <pebble.h>
#include <stdint.h>

#define GLYPH(w, ...) {.width = (w), .data = __VA_ARGS__}

typedef struct {
  uint8_t width;
  uint8_t data[7][5];
} Glyph;

typedef enum {
  F0,
  F1,
  F2,
  F3,
  F4,
  F5,
  F6,
  F7,
  F8,
  F9,
  FCOLON,
} FontChar;

static Glyph ndot55[] = {
  [F0] = GLYPH(5, {
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0},
  }),
  [F1] = GLYPH(2, {
    {0, 1},
    {1, 1},
    {0, 1},
    {0, 1},
    {0, 1},
  }),
  [F2] = GLYPH(5, {
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {0, 0, 1, 1, 0},
    {0, 1, 0, 0, 0},
    {1, 1, 1, 1, 1},
  }),
  [F3] = GLYPH(5, {
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {0, 0, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0},
  }),
  [F4] = GLYPH(4, {
    {0, 0, 1, 0},
    {0, 1, 1, 0},
    {1, 0, 1, 0},
    {1, 1, 1, 1},
    {0, 0, 1, 0},
    {0, 0, 1, 0},
  }),
  [F5] = GLYPH(5, {
    {1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0},
    {1, 1, 1, 1, 0},
    {0, 0, 0, 0, 1},
    {1, 1, 1, 1, 0},
  }),
  [F6] = GLYPH(5, {
    {0, 0, 1, 1, 0},
    {0, 1, 0, 0, 0},
    {1, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0},
  }),
  [F7] = GLYPH(5, {
    {1, 1, 1, 1, 1},
    {0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0},
  }),
  [F8] = GLYPH(5, {
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0},
  }),
  [F9] = GLYPH(5, {
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 1},
    {0, 0, 0, 1, 0},
    {0, 1, 1, 0, 0},
  }),
  [FCOLON] = GLYPH(1, {
    {0},
    {1},
    {0},
    {1},
    {0},
   }),
};

static Glyph ndot57[] = {
  [F0] = GLYPH(5, {
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0},
  }),
  // Not the same as the official ndot57 font, but monospace looks more
  // balanced when used with the weekday indicator
  [F1] = GLYPH(5, {
    {0, 1, 1, 0, 0},
    {1, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1},
  }),
  // [F1] = GLYPH(3, {
  //   {0, 1, 0},
  //   {1, 1, 0},
  //   {0, 1, 0},
  //   {0, 1, 0},
  //   {0, 1, 0},
  //   {0, 1, 0},
  //   {1, 1, 1},
  // }),

  [F2] = GLYPH(5, {
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 1, 0, 0, 0},
    {1, 1, 1, 1, 1},
  }),

  [F3] = GLYPH(5, {
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {0, 0, 0, 0, 1},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0},
  }),

  [F4] = GLYPH(5, {
    {0, 0, 0, 1, 0},
    {0, 0, 1, 1, 0},
    {0, 1, 0, 1, 0},
    {1, 0, 0, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0},
  }),

  [F5] = GLYPH(5, {
    {1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0},
    {1, 0, 0, 0, 0},
    {1, 1, 1, 1, 0},
    {0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0},
  }),

  [F6] = GLYPH(5, {
    {0, 0, 1, 1, 1},
    {0, 1, 0, 0, 0},
    {1, 0, 0, 0, 0},
    {1, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0},
  }),

  [F7] = GLYPH(5, {
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0},
  }),
  [F8] = GLYPH(5, {
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0},
  }),
  [F9] = GLYPH(5, {
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 1},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 1, 0},
    {0, 1, 1, 0, 0},
  }),
  [FCOLON] = GLYPH(1, {
    {0},
    {0},
    {1},
    {0},
    {1},
    {0},
    {0},
   }),
};

typedef struct {
  int8_t dot_spacing;
  uint8_t dot_width;
  Glyph *glyphs;
} NdotFont;

static NdotFont font1 = {
    .dot_spacing = 0,
    .dot_width = 4,
    .glyphs = ndot57,
};

inline uint8_t font_get_glyph_default_width(NdotFont *font) {
  uint8_t num_dots_h = 5;
  return num_dots_h * font->dot_width + (num_dots_h - 1) * font->dot_spacing;
}

inline uint8_t font_get_glyph_width(NdotFont *font, FontChar c) {
  uint8_t num_dots_h = font->glyphs[c].width;
  return num_dots_h * font->dot_width + (num_dots_h - 1) * font->dot_spacing;
}

inline uint8_t font_get_glyph_height(NdotFont *font) {
  uint8_t num_dots_v = 7;
  return num_dots_v * font->dot_width + (num_dots_v - 1) * font->dot_spacing;
}

inline uint8_t font_draw_char(
    GContext *ctx, NdotFont *font, uint8_t x, uint8_t y, FontChar c
) {
  Glyph *g = &font->glyphs[c];
  uint8_t w = font->dot_width;
  uint8_t x_start = x;

  for (int row = 0; row < 7; row++) {
    for (int col = 0; col < g->width; col++) {
      if (g->data[row][col] == 1) {
        graphics_fill_rect(ctx, GRect(x, y, w, w), w / 2 - 1, 0b1111);
      }
      x += w + font->dot_spacing;
    }
    x = x_start;
    y += w + font->dot_spacing;
  }
  return font_get_glyph_width(font, c);
}

inline void draw_time_center(GContext *ctx, NdotFont *font, uint8_t h, uint8_t m) {
  if (h > 99 || m > 99) {
    return;
  }
  FontChar h0 = h / 10;
  FontChar h1 = h % 10;
  FontChar m0 = m / 10;
  FontChar m1 = m % 10;
  uint8_t y = PBL_DISPLAY_HEIGHT / 2 - font_get_glyph_height(font) / 2 + 1;
  uint8_t space = font->dot_width + 2 * font->dot_spacing;
  uint8_t x_center = PBL_DISPLAY_WIDTH / 2;
  uint8_t x_colon = x_center - font_get_glyph_width(font, FCOLON) / 2 + 1;
  font_draw_char(ctx, font, x_colon, y, FCOLON);
  uint8_t h1x = x_colon - space - font_get_glyph_width(font, h1);
  font_draw_char(ctx, font, h1x, y, h1);
  uint8_t h0x = h1x - space - font_get_glyph_width(font, h0);
  font_draw_char(ctx, font, h0x, y, h0);
  uint8_t m0x = x_colon + space + font_get_glyph_width(font, FCOLON);
  font_draw_char(ctx, font, m0x, y, m0);
  uint8_t m1x = m0x + space + font_get_glyph_width(font, m0);
  font_draw_char(ctx, font, m1x, y, m1);
}

inline void draw_cross_center(GContext *ctx) {
  uint8_t W = PBL_DISPLAY_WIDTH;
  uint8_t H = PBL_DISPLAY_HEIGHT;
  graphics_context_set_antialiased(ctx, false);
  graphics_context_set_fill_color(ctx, GColorDarkGray);
  graphics_fill_rect(ctx, GRect(W / 2, 0, 2, H), 0, 0);
  graphics_fill_rect(ctx, GRect(0, H / 2, W, 2), 0, 0);
}
