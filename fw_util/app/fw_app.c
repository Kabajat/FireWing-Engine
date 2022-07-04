#include "fw_app.h"

FW_API bool fw_is_running(fw_win_t *win) { return !glfwWindowShouldClose(win); }

FW_API void fw_swap_buffers(fw_win_t *win) { glfwSwapBuffers(win); }

FW_API void fw_poll_events() { glfwPollEvents(); }

FW_API void fw_kill() { glfwTerminate(); exit(0); }