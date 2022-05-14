#include "../fw/fw.h"

fw_win_t win;
fw_rend_t rend;

int main(int32_t argc, char const *argv[]) {
    fw_win_init(
        &win,
        "Hello FireWing",
        800,
        600,
        0);

    fw_rend_init(&rend, win, 200, 160);

    while (fw_is_running(win)) {
        fw_poll_events();
        fw_swap_buffers(win);
    }
    
    fw_kill();
    
    return 0;
}