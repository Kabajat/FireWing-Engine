#include "../fw/fw.h"

fw_win_t win;

int main(int32_t argc, char const *argv[]) {
    fw_win_init(
        &win,
        "Hello FireWing",
        800,
        600,
        0);

    while (fw_is_running(win)) {
        fw_poll_events();
        fw_swap_buffers(win);
    }
    
    fw_kill();
    
    return 0;
}