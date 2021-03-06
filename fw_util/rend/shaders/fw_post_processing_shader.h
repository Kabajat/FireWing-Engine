#pragma once

static const char *fw_post_processing_shp_vert =
"#version 330\n"
"layout(location = 0) in vec2 position;\n"
"layout(location = 1) in vec2 texcoord;\n"
"out vec2 v_texcoord;\n"
"void main() {\n"
"    v_texcoord = texcoord;\n"
"    gl_Position = vec4(position, 0.0, 1.0);\n"
"}\0";

static const char *fw_post_processing_shp_frag =
"#version 330\n"
"out vec4 out_color;\n"
"in vec2 v_texcoord;\n"
"uniform sampler2D tex_sampler;\n"
"void main() {\n"
"    out_color = texture(tex_sampler, v_texcoord);\n"
"}\0";