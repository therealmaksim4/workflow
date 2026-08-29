all:
	gcc -O3 -march=native -Iinclude src/* -o bin/workflow
	luac -o bin/all.luac lua/all.lua
	luac -o bin/check_command_name_color.luac lua/check_command_name_color.lua
	luac -o bin/shortcuts.luac lua/shortcuts.lua
	sudo install -m 0755 bin/workflow /usr/bin/workflow
	sudo rm -rf /usr/src/workflow
	sudo cp -r ~/workflow /usr/src/workflow
	sudo rm -rf /usr/src/workflow/.git
