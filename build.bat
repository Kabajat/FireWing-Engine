set APPLICATION_NAME=FireWingApplication
set GAME_DIR=src/*.c

set FW_DIR=fw/win/*.c fw/app/*.c fw/rend/*.c fw/input/*.c

gcc -w %GAME_DIR% %FW_DIR% -o bin/win32/%APPLICATION_NAME%.exe -I./win32/include -L./win32/lib -lglfw3dll -lopengl32 -lglu32 -lgdi32 -lglew32 -luser32 -lkernel32