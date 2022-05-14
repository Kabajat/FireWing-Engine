#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cglm/cglm.h>
#include <cglm/mat4.h>

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

#define FW_NEW_SPRITE(tex, x, y, w, h) (fw_spr_t){ tex, x, y, w, h }

#define __FW_REND_MAX_GL_OBJECTS 3

typedef struct fw_rend_t {
    fw_win_t win;

    bool in_frame;

    GLuint fbo;
    GLuint fbo_tex;

    GLuint vaos[__FW_REND_MAX_GL_OBJECTS];
    GLuint vbos[__FW_REND_MAX_GL_OBJECTS];
    GLuint ebos[__FW_REND_MAX_GL_OBJECTS];

    GLuint post_processing_shp;
    GLuint example_shp;
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

FW_API void fw_rend_init(fw_rend_t *rend, fw_win_t win, int32_t res_width, int32_t res_height);

FW_API void fw_rend_set_resolution(fw_rend_t *rend, int32_t width, int32_t height);

FW_API void fw_rend_set_view(fw_rend_t *rend, fw_rect_t rect);

FW_API void fw_rend_begin(fw_rend_t *rend);
FW_API void fw_rend_end(fw_rend_t *rend);

FW_API void fw_texture_init(fw_tex_t *tex, const char* file_name, int32_t internal_format, int32_t format);

FW_API void fw_rend_push_example(fw_rend_t *rend);
FW_API void fw_rend_push_sprite(fw_rend_t *rend, fw_transf_t transf, fw_spr_t spr, fw_color_t color);