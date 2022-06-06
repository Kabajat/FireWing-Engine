set APPLICATION_NAME=FireWingApplication
set GAME_DIR=src/*.c

set FW_DIR=fw/win/*.c fw/app/*.c fw/rend/*.c fw/input/*.c

gcc -w %GAME_DIR% %FW_DIR% -o bin/win/64/%APPLICATION_NAME%.exe -I./winex/include -L./winex/64/lib -lglfw3dll -lopengl32 -lglu32 -lgdi32 -lglew32 -luser32 -lkernel32