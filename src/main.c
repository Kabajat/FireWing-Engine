#include "../fw/fw.h"

fw_win_t win;
fw_rend_t rend;

int main(int32_t argc, char const *argv[]) {
    fw_win_init(
        &win,
        "Hello FireWing",
        1280,
        720,
        0);

    fw_rend_init(&rend, win, 1280 / 3, 720 / 3);

    while (fw_is_running(win)) {
        fw_poll_events();
        fw_rend_begin(&rend);
        fw_rend_push_rect(&rend, FW_NEW_TRANSFORM(0, 0, 50, 50, 0.5f, 0.5f, 0.0f), FW_COLOR_WHITE);
        fw_rend_end(&rend);
        fw_swap_buffers(win);
    }

    fw_kill();
    
    return 0;
}