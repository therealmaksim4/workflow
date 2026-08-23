all:
	g++ -x c -O3 -march=native -flto -fno-plt src/main.c -o bin/workflow
	luac -o bin/check_command_name_color.luac lua/check_command_name_color.lua
	luac -o bin/shortcuts.luac lua/shortcuts.lua
	luac -o bin/run_ruby.luac lua/run_ruby.lua
	sudo install -m 0755 bin/workflow /usr/bin/workflow
	sudo rm -rf /usr/src/workflow
	sudo cp -r ~/workflow /usr/src/workflow
	sudo rm -rf /usr/src/workflow/.git
