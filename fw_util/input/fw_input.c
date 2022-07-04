#include "fw_input.h"

FW_API bool fw_is_key_down(fw_win_t *win, int32_t key) { return glfwGetKey(win, key) == GLFW_PRESS; }
FW_API bool fw_is_mouse_down(fw_win_t *win, int32_t button) { return glfwGetMouseButton(win, button) == GLFW_PRESS; }

FW_API bool fw_is_key_up(fw_win_t *win, int32_t key) { return glfwGetKey(win, key) == GLFW_RELEASE; }
FW_API bool fw_is_mouse_up(fw_win_t *win, int32_t button) { return glfwGetMouseButton(win, button) == GLFW_RELEASE; }

FW_API void fw_get_mouse_position(fw_win_t *win, int32_t *x, int32_t *y)
{
    double x_, y_;
    glfwGetCursorPos(win, &x_, &y_);
    *x = (int32_t)x_;
    *y = (int32_t)y_;
}
