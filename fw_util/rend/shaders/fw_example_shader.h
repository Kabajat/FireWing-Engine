#pragma once

static const char *fw_example_shader_vert =
"#version 330\n"
"layout(location = 0) in vec2 position;\n"
"layout(location = 1) in vec3 color;\n"
"out vec3 v_color;\n"
"void main() {\n"
"    v_color = color;\n"
"    gl_Position = vec4(position, 1.0, 1.0);\n"
"}\0";

static const char *fw_example_shader_frag =
"#version 330\n"
"out vec4 out_color;\n"
"in vec3 v_color;\n"
"void main() {\n"
"    out_color = vec4(v_color, 1.0);\n"
"}\0";