#include "fw_rend.h"

#include "shaders/fw_example_shader.h"
#include "shaders/fw_sprite_shader.h"
#include "shaders/fw_post_processing_shader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void __fw_framebuffer_init(fw_rend_t *rend) {
    GLuint fbo;
    glGenFramebuffers(1, &fbo);

    GLuint fbo_tex;
    glGenTextures(1, &fbo_tex);
    glBindTexture(GL_TEXTURE_2D, fbo_tex);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, rend->res_width, rend->res_height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);

    glBindFramebuffer(GL_FRAMEBUFFER, fbo);  
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, fbo_tex, 0);  

    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    rend->fbo = fbo;
    rend->fbo_tex = fbo_tex;
}

void __fw_set_proj(fw_rend_t *rend, fw_rect_t viewport) {
    glm_ortho(-rend->res_width * 0.5f, rend->res_width * 0.5f, rend->res_height * 0.5f, -rend->res_height * 0.5f, -1.0f, 1.0f, rend->proj_mat);
    glm_translate(rend->proj_mat, (vec3) { viewport.x, viewport.h, 0.0f });
    glm_scale(rend->proj_mat, (vec3) { viewport.w, viewport.h, 1.0f });

    glUseProgram(rend->sprite_shp);
    glUniformMatrix4fv(glGetUniformLocation(rend->sprite_shp, "proj_mat"), 1, GL_FALSE, (GLfloat*)rend->proj_mat);

    glUseProgram(0);
}

void __fw_set_model(fw_rend_t *rend, fw_transf_t transf) {
    glm_mat4_identity(rend->model_mat);
    glm_translate(rend->model_mat, (vec3) { transf.x, transf.y, 0.0f });

    glm_rotate(rend->model_mat, transf.angle / FW_RAD2DEG, (vec3) { 0.0f, 0.0f, 1.0f });
    glm_translate(rend->model_mat, (vec3) { -transf.pivot_x * transf.w, -transf.pivot_y * transf.h, 0.0f });

    glm_scale(rend->model_mat, (vec3) { transf.w, transf.h, 1.0f });

    glUseProgram(rend->sprite_shp);
    glUniformMatrix4fv(glGetUniformLocation(rend->sprite_shp, "model_mat"), 1, GL_FALSE, (GLfloat*)rend->model_mat);

    glUseProgram(0);
}

void __fw_set_tex(fw_rend_t *rend, fw_spr_t spr) {
    glm_mat4_identity(rend->tex_mat);
    glm_translate(rend->tex_mat, (vec3) { spr.x / (float)spr.tex->width, spr.y / (float)spr.tex->height, 0.0f });
    glm_scale(rend->tex_mat, (vec3) { spr.width / (float)spr.tex->width, spr.height / (float)spr.tex->height, 1.0f });

    glUseProgram(rend->sprite_shp);
    glUniformMatrix4fv(glGetUniformLocation(rend->sprite_shp, "tex_mat"), 1, GL_FALSE, (GLfloat*)rend->tex_mat);

    glUseProgram(0);
}

FW_API void fw_texture_init(fw_tex_t *tex, const char* file_name, int32_t internal_format, int32_t format) {
    GLuint tex_id;
    glGenTextures(1, &tex_id);
    glBindTexture(GL_TEXTURE_2D, tex_id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    int width, height, nrChannels;
    unsigned char *data = stbi_load(file_name, &width, &height, &nrChannels, 0);

    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, internal_format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
        printf("Failed to load texture\n");
    
    stbi_image_free(data);

    tex->id = tex_id;
    tex->width = width;
    tex->height = height;
}

FW_API void fw_rend_init(fw_rend_t *rend, fw_win_t win, int32_t res_width, int32_t res_height) {
    rend->win = win;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glGenVertexArrays(__FW_REND_MAX_GL_OBJECTS, rend->vaos);
    glGenBuffers(__FW_REND_MAX_GL_OBJECTS, rend->vbos);
    glGenBuffers(__FW_REND_MAX_GL_OBJECTS, rend->ebos);

    rend->res_width = res_width;
    rend->res_height = res_height;

    rend->win_width = 800;
    rend->win_height = 600;

    rend->in_frame = false;

    float frame_vertices[] = {
        -1.0f, -1.0f, 0.0f, 0.0f,
        1.0f, -1.0f, 1.0f, 0.0f,
        -1.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f
    };

    float example_vertices[] = {
        -0.5f, -0.5f, 1.0f, 0.5f, 0.5f,
        0.0f, 0.5f, 0.5f, 1.0f, 0.5f,
        0.5f, -0.5f, 0.5f, 1.0f, 1.0f
    };

    float sprite_vertices[] = {
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 1.0f
    };

    uint32_t triangle_indices[] = {
        0, 1, 2
    };

    uint32_t frame_indices[] = {
        0, 1, 2,
        2, 3, 1,
    };

    uint32_t rect_indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    __fw_framebuffer_init(rend);

    fw_shader_init(&rend->post_processing_shp, fw_post_processing_shp_vert, fw_post_processing_shp_frag);
    fw_shader_init(&rend->example_shp, fw_example_shader_vert, fw_example_shader_frag);
    fw_shader_init(&rend->sprite_shp, fw_sprite_shp_vert, fw_sprite_shp_frag);

    glBindVertexArray(rend->vaos[0]);
    glBindBuffer(GL_ARRAY_BUFFER, rend->vbos[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(frame_vertices), frame_vertices, GL_STREAM_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rend->ebos[0]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(frame_indices), frame_indices, GL_STREAM_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);

    glBindVertexArray(rend->vaos[1]);
    glBindBuffer(GL_ARRAY_BUFFER, rend->vbos[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(example_vertices), example_vertices, GL_STREAM_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rend->ebos[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(triangle_indices), triangle_indices, GL_STREAM_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);

    glBindVertexArray(rend->vaos[2]);
    glBindBuffer(GL_ARRAY_BUFFER, rend->vbos[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(sprite_vertices), sprite_vertices, GL_STREAM_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rend->ebos[2]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(rect_indices), rect_indices, GL_STREAM_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);
}

FW_API void fw_rend_set_resolution(fw_rend_t *rend, int32_t width, int32_t height) {
    rend->res_width = width;
    rend->res_height = height;

    glBindTexture(GL_TEXTURE_2D, rend->fbo_tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, rend->res_width, rend->res_height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    glBindTexture(GL_TEXTURE_2D, 0);
}

FW_API void fw_rend_set_view(fw_rend_t *rend, fw_rect_t rect) { __fw_set_proj(rend, rect); }

FW_API void fw_rend_begin(fw_rend_t *rend) {
    if (rend->in_frame)
        return;

    rend->in_frame = true;
    
    glfwGetWindowSize(rend->win, &rend->win_width, &rend->win_height);

    glBindFramebuffer(GL_FRAMEBUFFER, rend->fbo);
    glClear(GL_COLOR_BUFFER_BIT);

    glViewport(0, 0, rend->res_width, rend->res_height);
}

FW_API void fw_rend_end(fw_rend_t *rend) {
    if (!rend->in_frame)
        return;

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glViewport(0, 0, rend->win_width, rend->win_height);

    glBindTexture(GL_TEXTURE_2D, rend->fbo_tex);

    glUseProgram(rend->post_processing_shp);
    glBindVertexArray(rend->vaos[0]);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

    glLoadIdentity();

    rend->in_frame = false;
}

FW_API void fw_rend_push_example(fw_rend_t *rend) {
    if (!rend->in_frame)
        return;
    
    glUseProgram(rend->example_shp);
    glBindVertexArray(rend->vaos[1]);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

FW_API void fw_rend_push_sprite(fw_rend_t *rend, fw_transf_t transf, fw_spr_t spr, fw_color_t color) {
    if (!rend->in_frame)
        return;

    __fw_set_model(rend, transf);
    __fw_set_tex(rend, spr);

    glUseProgram(rend->sprite_shp);

    glUniform4f(glGetUniformLocation(rend->sprite_shp, "color"), color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f);
    glUniform1f(glGetUniformLocation(rend->sprite_shp, "br"), color.br / 255.0f);

    glBindTexture(GL_TEXTURE_2D, spr.tex->id);
    glBindVertexArray(rend->vaos[2]);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}