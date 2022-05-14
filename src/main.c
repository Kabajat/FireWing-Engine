#include <stdio.h>
#include "../fw/fw.h"

#define GLT_IMPLEMENTATION
#include <GL/gltext.h>

/*
    Dear future me, I can't even begin to express how sorry I am. :(
    The code below is a mess, and I'm not even sure if it's even working.
    I don't even know if I'm even using it.
    My hatred to OpenGL is so deep that I can't even begin to express it. It burns with the
    fire if a hundred suns. I'm so sorry!

    OpenGL is a mess.
    I can't even find a single function that works.
    I can't even find a single function that compiles.
    
    The problems with the .jpeg image format a inevitable.
    Stb_image.h is a mess.
    Loading a jpeg image with openGL is like throwing rocks at an altistic kid.
    .JPEG is not my favorite image format.

    UPDATE: I'm not sure what I'm doing wrong.
    FIX: ?
*/

fw_win_t win;
fw_rend_t rend;

fw_tex_t tex0;
fw_spr_t spr0;

int main(int32_t argc, char const *argv[]) {
    int32_t win_width = 4 * 75;
    int32_t win_height = 3 * 75;

    fw_win_init(
        &win,
        "Hello FireWing",
        win_width * 3,
        win_height * 3,
        0);

    fw_win_set_aspect_ratio(win, win_width, win_height);
    fw_rend_init(&rend, win, win_width, win_height);

    fw_texture_init(&tex0, "C:\\Users\\kiko\\Downloads\\FireWing Engine\\bin\\win32\\resources\\test_sprite.png", FW_RGBA8, FW_RGBA);
    spr0 = FW_NEW_SPRITE(&tex0, 0, 0, tex0.width, tex0.height);
      
    int i;

    while (fw_is_running(win)) {
        fw_poll_events();

        fw_rend_set_view(&rend, FW_NEW_RECT(0, 0, 1.0f, 1.0f));

        fw_rend_begin(&rend);

        //fw_rend_push_example(&rend);
        i+=1;
        fw_rend_push_sprite(&rend, FW_NEW_TRANSFORM(0, 0, 19, 29, 0.5f, 0.5f, i), spr0);
        fw_rend_end(&rend);

        fw_swap_buffers(win);
    }
    
    fw_kill();
    
    return 0;
}