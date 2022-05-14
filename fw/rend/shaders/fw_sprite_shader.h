#pragma once

static const char *fw_sprite_shp_vert =
"#version 330\n"
"layout(location = 0) in vec2 position;"
"layout(location = 1) in vec2 texcoord;"
"out vec2 v_texcoord;\n"
"uniform mat4 proj_mat;\n"
"uniform mat4 model_mat;\n"
"uniform mat4 tex_mat;\n"
"void main() {\n"
"    v_texcoord = vec4(tex_mat * vec4(texcoord, 0.0, 1.0)).xy;\n"
"    gl_Position = proj_mat * model_mat * vec4(position, 0.0, 1.0);\n"
"}\0";

static const char *fw_sprite_shp_frag =
"#version 330\n"
"out vec4 out_color;\n"
"in vec2 v_texcoord;\n"
"uniform sampler2D tex_sampler;\n"
"void main() {\n"
"    out_color = texture(tex_sampler, v_texcoord);\n"
"}\0";