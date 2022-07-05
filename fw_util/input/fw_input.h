#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdint.h>
#include <stdbool.h>

#include "../win/fw_win.h"

#ifndef FW_API
#define FW_API extern
#endif

#define FW_KEY_UNKNOWN            -1

#define FW_KEY_SPACE              32
#define FW_KEY_APOSTROPHE         39
#define FW_KEY_COMMA              44
#define FW_KEY_MINUS              45
#define FW_KEY_PERIOD             46
#define FW_KEY_SLASH              47
#define FW_KEY_0                  48
#define FW_KEY_1                  49
#define FW_KEY_2                  50
#define FW_KEY_3                  51
#define FW_KEY_4                  52
#define FW_KEY_5                  53
#define FW_KEY_6                  54
#define FW_KEY_7                  55
#define FW_KEY_8                  56
#define FW_KEY_9                  57
#define FW_KEY_SEMICOLON          59
#define FW_KEY_EQUAL              61
#define FW_KEY_A                  65
#define FW_KEY_B                  66
#define FW_KEY_C                  67
#define FW_KEY_D                  68
#define FW_KEY_E                  69
#define FW_KEY_F                  70
#define FW_KEY_G                  71
#define FW_KEY_H                  72
#define FW_KEY_I                  73
#define FW_KEY_J                  74
#define FW_KEY_K                  75
#define FW_KEY_L                  76
#define FW_KEY_M                  77
#define FW_KEY_N                  78
#define FW_KEY_O                  79
#define FW_KEY_P                  80
#define FW_KEY_Q                  81
#define FW_KEY_R                  82
#define FW_KEY_S                  83
#define FW_KEY_T                  84
#define FW_KEY_U                  85
#define FW_KEY_V                  86
#define FW_KEY_W                  87
#define FW_KEY_X                  88
#define FW_KEY_Y                  89
#define FW_KEY_Z                  90
#define FW_KEY_LEFT_BRACKET       91
#define FW_KEY_BACKSLASH          92
#define FW_KEY_RIGHT_BRACKET      93
#define FW_KEY_GRAVE_ACCENT       96
#define FW_KEY_WORLD_1            161
#define FW_KEY_WORLD_2            162

#define FW_KEY_ESCAPE             256
#define FW_KEY_ENTER              257
#define FW_KEY_TAB                258
#define FW_KEY_BACKSPACE          259
#define FW_KEY_INSERT             260
#define FW_KEY_DELETE             261
#define FW_KEY_RIGHT              262
#define FW_KEY_LEFT               263
#define FW_KEY_DOWN               264
#define FW_KEY_UP                 265
#define FW_KEY_PAGE_UP            266
#define FW_KEY_PAGE_DOWN          267
#define FW_KEY_HOME               268
#define FW_KEY_END                269
#define FW_KEY_CAPS_LOCK          280
#define FW_KEY_SCROLL_LOCK        281
#define FW_KEY_NUM_LOCK           282
#define FW_KEY_PRINT_SCREEN       283
#define FW_KEY_PAUSE              284
#define FW_KEY_F1                 290
#define FW_KEY_F2                 291
#define FW_KEY_F3                 292
#define FW_KEY_F4                 293
#define FW_KEY_F5                 294
#define FW_KEY_F6                 295
#define FW_KEY_F7                 296
#define FW_KEY_F8                 297
#define FW_KEY_F9                 298
#define FW_KEY_F10                299
#define FW_KEY_F11                300
#define FW_KEY_F12                301
#define FW_KEY_F13                302
#define FW_KEY_F14                303
#define FW_KEY_F15                304
#define FW_KEY_F16                305
#define FW_KEY_F17                306
#define FW_KEY_F18                307
#define FW_KEY_F19                308
#define FW_KEY_F20                309
#define FW_KEY_F21                310
#define FW_KEY_F22                311
#define FW_KEY_F23                312
#define FW_KEY_F24                313
#define FW_KEY_F25                314
#define FW_KEY_KP_0               320
#define FW_KEY_KP_1               321
#define FW_KEY_KP_2               322
#define FW_KEY_KP_3               323
#define FW_KEY_KP_4               324
#define FW_KEY_KP_5               325
#define FW_KEY_KP_6               326
#define FW_KEY_KP_7               327
#define FW_KEY_KP_8               328
#define FW_KEY_KP_9               329
#define FW_KEY_KP_DECIMAL         330
#define FW_KEY_KP_DIVIDE          331
#define FW_KEY_KP_MULTIPLY        332
#define FW_KEY_KP_SUBTRACT        333
#define FW_KEY_KP_ADD             334
#define FW_KEY_KP_ENTER           335
#define FW_KEY_KP_EQUAL           336
#define FW_KEY_LEFT_SHIFT         340
#define FW_KEY_LEFT_CONTROL       341
#define FW_KEY_LEFT_ALT           342
#define FW_KEY_LEFT_SUPER         343
#define FW_KEY_RIGHT_SHIFT        344
#define FW_KEY_RIGHT_CONTROL      345
#define FW_KEY_RIGHT_ALT          346
#define FW_KEY_RIGHT_SUPER        347
#define FW_KEY_MENU               348

#define FW_KEY_LAST               FW_KEY_MENU

#define FW_MOD_SHIFT           0x0001

#define FW_MOD_CONTROL         0x0002

#define FW_MOD_ALT             0x0004

#define FW_MOD_SUPER           0x0008

#define FW_MOD_CAPS_LOCK       0x0010

#define FW_MOD_NUM_LOCK        0x0020

#define FW_MOUSE_BUTTON_1         0
#define FW_MOUSE_BUTTON_2         1
#define FW_MOUSE_BUTTON_3         2
#define FW_MOUSE_BUTTON_4         3
#define FW_MOUSE_BUTTON_5         4
#define FW_MOUSE_BUTTON_6         5
#define FW_MOUSE_BUTTON_7         6
#define FW_MOUSE_BUTTON_8         7
#define FW_MOUSE_BUTTON_LAST      FW_MOUSE_BUTTON_8
#define FW_MOUSE_BUTTON_LEFT      FW_MOUSE_BUTTON_1
#define FW_MOUSE_BUTTON_RIGHT     FW_MOUSE_BUTTON_2
#define FW_MOUSE_BUTTON_MIDDLE    FW_MOUSE_BUTTON_3

#define FW_JOYSTICK_1             0
#define FW_JOYSTICK_2             1
#define FW_JOYSTICK_3             2
#define FW_JOYSTICK_4             3
#define FW_JOYSTICK_5             4
#define FW_JOYSTICK_6             5
#define FW_JOYSTICK_7             6
#define FW_JOYSTICK_8             7
#define FW_JOYSTICK_9             8
#define FW_JOYSTICK_10            9
#define FW_JOYSTICK_11            10
#define FW_JOYSTICK_12            11
#define FW_JOYSTICK_13            12
#define FW_JOYSTICK_14            13
#define FW_JOYSTICK_15            14
#define FW_JOYSTICK_16            15
#define FW_JOYSTICK_LAST          FW_JOYSTICK_16

#define FW_GAMEPAD_BUTTON_A               0
#define FW_GAMEPAD_BUTTON_B               1
#define FW_GAMEPAD_BUTTON_X               2
#define FW_GAMEPAD_BUTTON_Y               3
#define FW_GAMEPAD_BUTTON_LEFT_BUMPER     4
#define FW_GAMEPAD_BUTTON_RIGHT_BUMPER    5
#define FW_GAMEPAD_BUTTON_BACK            6
#define FW_GAMEPAD_BUTTON_START           7
#define FW_GAMEPAD_BUTTON_GUIDE           8
#define FW_GAMEPAD_BUTTON_LEFT_THUMB      9
#define FW_GAMEPAD_BUTTON_RIGHT_THUMB     10
#define FW_GAMEPAD_BUTTON_DPAD_UP         11
#define FW_GAMEPAD_BUTTON_DPAD_RIGHT      12
#define FW_GAMEPAD_BUTTON_DPAD_DOWN       13
#define FW_GAMEPAD_BUTTON_DPAD_LEFT       14
#define FW_GAMEPAD_BUTTON_LAST            FW_GAMEPAD_BUTTON_DPAD_LEFT

#define FW_GAMEPAD_BUTTON_CROSS       FW_GAMEPAD_BUTTON_A
#define FW_GAMEPAD_BUTTON_CIRCLE      FW_GAMEPAD_BUTTON_B
#define FW_GAMEPAD_BUTTON_SQUARE      FW_GAMEPAD_BUTTON_X
#define FW_GAMEPAD_BUTTON_TRIANGLE    FW_GAMEPAD_BUTTON_Y

#define FW_GAMEPAD_AXIS_LEFT_X        0
#define FW_GAMEPAD_AXIS_LEFT_Y        1
#define FW_GAMEPAD_AXIS_RIGHT_X       2
#define FW_GAMEPAD_AXIS_RIGHT_Y       3
#define FW_GAMEPAD_AXIS_LEFT_TRIGGER  4
#define FW_GAMEPAD_AXIS_RIGHT_TRIGGER 5
#define FW_GAMEPAD_AXIS_LAST          FW_GAMEPAD_AXIS_RIGHT_TRIGGER

FW_API bool fw_is_key_down(fw_win_t *win, int32_t key);
FW_API bool fw_is_mouse_down(fw_win_t *win, int32_t button);

FW_API bool fw_is_key_up(fw_win_t *win, int32_t key);
FW_API bool fw_is_mouse_up(fw_win_t *win, int32_t button);

FW_API fw_vec2i_t fw_get_mouse_position(fw_win_t *win);
