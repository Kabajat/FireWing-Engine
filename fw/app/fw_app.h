#pragma once

#ifndef FW_API
#define FW_API extern
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "../win/fw_win.h"

FW_API bool fw_is_running(fw_win_t win);

FW_API void fw_swap_buffers(fw_win_t win);

FW_API void fw_poll_events();

FW_API void fw_kill();