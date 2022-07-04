#include "../fw_util/fw.h"

fw_win_t *win;

int32_t main(int32_t argc, char const *argv[]) {
    win = fw_win_init(
        "Hello FireWing",
        1280,
        720,
        0);

    while (fw_is_running(win)) {
        fw_poll_events();
        fw_swap_buffers(win);
    }

    fw_win_destroy(win);
    fw_kill();
    
    return 0;
}