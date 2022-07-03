#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cglm/cglm.h>
#include <cglm/mat4.h>

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "../win/fw_win.h"
#include "../math/fw_math.h"
#include "fw_shader.h"

#ifndef FW_API
#define FW_API extern
#endif

#define FW_RGB GL_RGB
#define FW_RGB4 GL_RGB4
#define FW_RGB8 GL_RGB8
#define FW_RGB16 GL_RGB16

#define FW_RGBA GL_RGBA
#define FW_RGBA4 GL_RGBA4
#define FW_RGBA8 GL_RGBA8

#define FW_BORDER_SCREEN (fw_rect_t) { 0.0f, 1.0f, 1.0f, 0.0f }
#define FW_BORDER_CENTER (fw_rect_t) { -0.5f, 0.5f, 0.5f, -0.5f }

#define FW_NEW_SPRITE(tex, x, y, w, h) (fw_spr_t){ tex, x, y, w, h }

#define __FW_REND_MAX_GL_OBJECTS 4

typedef struct fw_rend_t {
    fw_win_t *win;

    bool in_frame;

    GLuint fbo;
    GLuint fbo_tex;

    GLuint vaos[__FW_REND_MAX_GL_OBJECTS];
    GLuint vbos[__FW_REND_MAX_GL_OBJECTS];
    GLuint ebos[__FW_REND_MAX_GL_OBJECTS];

    GLuint post_processing_shp;
    GLuint example_shp;
    GLuint shape_shp;
    GLuint sprite_shp;

    int32_t res_width;
    int32_t res_height;

    int32_t win_width;
    int32_t win_height;

    mat4 proj_mat;
    mat4 model_mat;
    mat4 tex_mat;
}fw_rend_t;

typedef struct fw_tex_t {
    GLuint id;
    int32_t width;
    int32_t height;
}fw_tex_t;

typedef struct fw_spr_t {
    fw_tex_t *tex;

    int32_t x, y;
    int32_t width, height;
}fw_spr_t;

FW_API fw_rend_t *fw_rend_init(fw_win_t *win, int32_t res_width, int32_t res_height);
FW_API void fw_rend_destroy(fw_rend_t *rend);

FW_API void fw_rend_set_background_color(fw_rend_t* rend, fw_color_t color);
FW_API void fw_rend_set_resolution(fw_rend_t *rend, int32_t width, int32_t height);
FW_API void fw_rend_set_view(fw_rend_t *rend, fw_rect_t rect, fw_rect_t border);

FW_API void fw_rend_begin(fw_rend_t *rend);
FW_API void fw_rend_end(fw_rend_t *rend);

FW_API fw_tex_t fw_texture_init(const char* file_name, int32_t internal_format, int32_t format);

FW_API void fw_rend_push_example(fw_rend_t *rend);
FW_API void fw_rend_push_rect(fw_rend_t *rend, fw_transf_t transf, fw_color_t color);
FW_API void fw_rend_push_sprite(fw_rend_t *rend, fw_transf_t transf, fw_spr_t spr, fw_color_t color);

FW_API void fw_rend_push_lines(fw_rend_t *rend, fw_vec2_t *points, size_t points_size, fw_color_t color, float width, bool connect_lines);
