set APPLICATION_NAME=FireWingApplication
set GAME_DIR=src/*.c

set FW_DIR=fw_util/win/*.c fw_util/app/*.c fw_util/rend/*.c fw_util/input/*.c

gcc -w %GAME_DIR% %FW_DIR% -o bin/win32/32/%APPLICATION_NAME%.exe -I./fw_impl -I./include -L./lib/32 -lglfw3dll -lopengl32 -lglu32 -lgdi32 -lglew32 -luser32 -lkernel32