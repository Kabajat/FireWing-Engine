#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#ifndef FW_API
#define FW_API extern
#endif

FW_API void fw_shader_init(GLuint *program, const char *vertex_source, const char *fragment_source);