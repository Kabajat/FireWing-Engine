# FireWing-Engine
FireWing is a set of tools built with OpenGL to help the creation of pixel art games in C/C++.

<img src="https://github.com/Kabajat/FireWing-Engine/blob/master/logo.png" width="400"/>

## Requirements
MinGW, GCC

## How to use?

First you need to clone the git repo and open it.

### Setting up the application name and source directory
If you're on Windows open the ``build.bat`` file.

```bat
set APPLICATION_NAME= <your application name>
set GAME_DIR= <your application source directories>
```

The first variable is for your application executable name.
The second variable is for the source files for your application.

You can change these two to your specific needs.

### Setting the main application and game loop

When you open the ``main.c`` in the ``src`` folder you are greeted with a pre-written application setup:

```c
#include "../fw_util/fw.h"

fw_win_t *win;

int main(int32_t argc, char const *argv[]) {
    win = fw_win_init(
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
```

Now let's break this structure into small parts.

First in your ```int main()``` you need to declare a new ```fw_win_t``` struct and initialize it with the ```fw_win_init``` function.
The structure of this function is ```fw_win_init(WINDOW_STRUCT, WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HIEGHT, WINDOW_FLAGS)```

Then we need to create the main game loop width the following:
 ```c
while (fw_is_running(win)) {
    fw_poll_events();
    fw_swap_buffers(win);
}
```

```fw_is_running``` checks if the window is currently running.
```fw_poll_events``` updates the user input every frame
```fw_swap_buffers``` shows the next frame to the window

At the end we need to call ```fw_kill()``` otherwise the application wouldn't be able to close.

### Rendering

To draw things to the screen we need a ```c
fw_rent_t```.
You can initialize it by doing ```c
fw_rent_t *rend = fw_rend_init(WINDOW_STRUCT, RESOLUTION_WIDTH, RESOLUTION_HEIGHT);```
