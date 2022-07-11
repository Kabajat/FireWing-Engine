#include "fw_input.h"

FW_API bool fw_is_key_down(fw_win_t *win, int32_t key)
{
    return glfwGetKey(win, key) == GLFW_PRESS;
}

FW_API bool fw_is_mouse_down(fw_win_t *win, int32_t button)
{
    return glfwGetMouseButton(win, button) == GLFW_PRESS;
}

FW_API bool fw_is_key_up(fw_win_t *win, int32_t key)
{
    return glfwGetKey(win, key) == GLFW_RELEASE;
}

FW_API bool fw_is_mouse_up(fw_win_t *win, int32_t button)
{
    return glfwGetMouseButton(win, button) == GLFW_RELEASE;
}

FW_API fw_vec2i_t fw_get_mouse_position(fw_win_t *win)
{
    double x, y;
    glfwGetCursorPos(win, &x, &y);
    return (fw_vec2i_t) { (int32_t)x, (int32_t)y };
}
