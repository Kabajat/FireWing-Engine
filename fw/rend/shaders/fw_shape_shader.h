#pragma once

static const char *fw_shape_shp_vert =
"#version 330\n"
"layout(location = 0) in vec2 position;\n"
"uniform mat4 proj_mat;\n"
"uniform mat4 model_mat;\n"
"uniform mat4 tex_mat;\n"
"void main() {\n"
"    gl_Position = proj_mat * model_mat * vec4(position, 0.0, 1.0);\n"
"}\0";

static const char *fw_shape_shp_frag =
"#version 330\n"
"out vec4 out_color;\n"
"uniform vec4 color;\n"
"uniform float br;\n"

"void main() {\n"
"    out_color = color + vec4(br, br, br, 0.0);\n"
"}\0";