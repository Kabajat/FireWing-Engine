#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef FW_API
#define FW_API extern
#endif

#define FW_USE_CORE_PROFILE 0x00032001
#define FW_RESIZABLE GLFW_RESIZABLE

typedef GLFWwindow fw_win_t;
typedef uint32_t fw_win_flags_t;

FW_API fw_win_t *fw_win_init(const char *title, int32_t width, int32_t height, fw_win_flags_t flags);

FW_API void fw_win_destroy(fw_win_t *win);

FW_API void fw_win_set_size(fw_win_t *win, int width, int height);

FW_API void fw_win_set_position(fw_win_t *win, int x, int y);

FW_API void fw_win_set_title(fw_win_t *win, const char *title);

FW_API void fw_win_get_size(fw_win_t *win, int *width, int *height);

FW_API void fw_win_get_position(fw_win_t *win, int *x, int *y);

FW_API void fw_win_set_aspect_ratio(fw_win_t *win, int numer, int denom);