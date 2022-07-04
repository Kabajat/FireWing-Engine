#pragma once

static const char *fw_sprite_shp_vert =
"#version 330\n"
"layout(location = 0) in vec2 position;\n"
"layout(location = 1) in vec2 texcoord;\n"
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
"uniform vec4 color;\n"
"uniform float br;\n"
"void main() {\n"
"   vec4 p = texture( tex_sampler, v_texcoord);\n"

"    if (p.a == 0.0)\n"
"        discard;\n"

"    out_color = p * color + vec4(br, br, br, 0.0);\n"
"}\0";