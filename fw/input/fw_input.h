#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdint.h>
#include <stdbool.h>

#include "../win/fw_win.h"

#ifndef FW_API
#define FW_API extern
#endif

FW_API bool fw_is_key_down(fw_win_t win, int32_t key);
FW_API bool fw_is_mouse_down(fw_win_t win, int32_t button);

FW_API void fw_get_mouse_position(fw_win_t win, int32_t *x, int32_t *y);