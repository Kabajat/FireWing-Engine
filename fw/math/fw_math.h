#pragma once

#include <stdint.h>

#define FW_PI 3.14159265358979323846
#define FW_RAD2DEG 57.2957795130823208768

#define FW_NEW_VEC2(x, y) (fw_vec2_t){ x, y }
#define FW_NEW_VEC2I(x, y) (fw_vec2i_t){ x, y }

#define FW_NEW_RECT(x, y, w, h) (fw_rect_t){ x, y, w, h }
#define FW_NEW_RECTI(x, y, w, h) (fw_recti_t){ x, y, w, h }

#define FW_NEW_TRANSFORM(x, y, sx, sy, px, py, ang) (fw_transf_t){ x, y, sx, sy, px, py, ang }

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