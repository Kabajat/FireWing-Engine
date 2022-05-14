#pragma once

#include <stdint.h>

#define FW_PI 3.14159265358979323846
#define FW_RAD2DEG 57.2957795130823208768

#define FW_NEW_VEC2(x, y) (fw_vec2_t){ x, y }
#define FW_NEW_VEC2I(x, y) (fw_vec2i_t){ x, y }

#define FW_NEW_RECT(x, y, w, h) (fw_rect_t){ x, y, w, h }
#define FW_NEW_RECTI(x, y, w, h) (fw_recti_t){ x, y, w, h }

#define FW_NEW_TRANSFORM(x, y, sx, sy, px, py, ang) (fw_transf_t){ x, y, sx, sy, px, py, ang }

#define FW_NEW_COLOR_RGB(r, g, b) (fw_color_t){ r, g, b, 255 }
#define FW_NEW_COLOR_RGBA(r, g, b, a) (fw_color_t){ r, g, b, a }
#define FW_NEW_COLOR(r, g, b, a, br) (fw_color_t){ r, g, b, a, br }

#define FW_COLOR_WHITE (fw_color_t){ 255, 255, 255, 255, 0 }
#define FW_COLOR_BLACK (fw_color_t){ 0, 0, 0, 255, 0 }

typedef struct fw_vec2_t {
    float x;
    float y;
}fw_vec2_t;

typedef struct fw_vec2i_t {
    int32_t x;
    int32_t y;
}fw_vec2i_t;

typedef struct fw_rect_t {
    float x, y;
    float w, h;
}fw_rect_t;

typedef struct fw_recti_t {
    int32_t x, y;
    int32_t w, h;
}fw_recti_t;

typedef struct fw_transf_t {
    float x, y;
    float w, h;
    float pivot_x, pivot_y;
    float angle;
}fw_transf_t;

typedef struct fw_color_t {
    uint8_t r, g, b, a;
    uint8_t br;
}fw_color_t;