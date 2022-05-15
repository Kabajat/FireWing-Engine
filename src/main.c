#include "../fw/fw.h"

#include <windows.h>

fw_win_t win;
fw_rend_t rend;

fw_tex_t tex0;
fw_spr_t spr0;

const char *get_exe_path() {
    char *path = (char *)malloc(MAX_PATH);
    GetModuleFileName(NULL, path, MAX_PATH);
    char *ptr = strrchr(path, '\\');
    *ptr = '\0';
    return path;
}

int main(int32_t argc, char const *argv[]) {
    fw_win_init(
        &win,
        "Hello FireWing",
        1280,
        720,
        0);

    fw_rend_init(&rend, win, 1280 / 4, 720 / 4);

    char buf[MAX_PATH];
    printf("%s\n", get_exe_path());
    sprintf(buf, "%s\\resources\\test_sprite.png", get_exe_path());

    fw_texture_init(&tex0, buf, FW_RGBA8, FW_RGBA);
    spr0 = FW_NEW_SPRITE(&tex0, 0, 0, tex0.width, tex0.height);

    while (fw_is_running(win)) {
        fw_poll_events();

        fw_rend_set_view(&rend, FW_NEW_RECT(0, 0, 1, 1));

        fw_rend_begin(&rend);
        fw_rend_push_sprite(&rend, FW_NEW_TRANSFORM(0, 0, tex0.width, tex0.height, 0.5f, 0.5f, 45.0f), spr0, FW_COLOR_WHITE);
        fw_rend_end(&rend);

        fw_swap_buffers(win);
    }
    
    fw_kill();
    
    return 0;
}