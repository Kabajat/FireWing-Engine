#include "fw_win.h"

FW_API fw_win_t *fw_win_init(const char *title, int32_t width, int32_t height, fw_win_flags_t flags)
{
    if (!glfwInit()) {
        printf("Failed to initialize GLFW\n");
        exit(-1);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

    glfwWindowHint(GLFW_RESIZABLE, (flags & GLFW_RESIZABLE) ? GL_TRUE : GL_FALSE);
    
    fw_win_t *win = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!win) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(win);
    
    glfwSwapInterval(GLFW_TRUE);

    if (glewInit() != GLEW_OK) {
        printf("Failed to initialize GLEW\n");
        glfwTerminate();
        exit(-1);
    }

    glViewport(0, 0, width, height);

    return win;
}

FW_API void fw_win_destroy(fw_win_t *win) { glfwDestroyWindow(win); }

FW_API void fw_win_set_size(fw_win_t *win, int width, int height) { glfwSetWindowSize(win, width, height); }

FW_API void fw_win_set_position(fw_win_t *win, int x, int y) { glfwSetWindowPos(win, x, y); }

FW_API void fw_win_set_title(fw_win_t *win, const char *title) { glfwSetWindowTitle(win, title); }

FW_API void fw_win_get_size(fw_win_t *win, int *width, int *height) { glfwGetWindowSize(win, width, height); }

FW_API void fw_win_get_position(fw_win_t *win, int *x, int *y) { glfwGetWindowPos(win, x, y); }

FW_API void fw_win_set_aspect_ratio(fw_win_t *win, int numer, int denom) { glfwSetWindowAspectRatio(win, numer, denom); }
