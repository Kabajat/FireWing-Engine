gcc -w src/*.c fw_util/win/*.c fw_util/app/*.c fw_util/rend/*.c fw_util/input/*.c -o bin/linux/FireWingApplication -I./fw_impl -lglfw -lGLEW -lGL -lm
