all:
	g++ -O3 -Iinclude src/main.c src/commands.c -o bin/workflow
	sudo install -m 0755 bin/workflow /usr/bin/workflow
	sudo rm -rf /usr/src/workflow
	sudo cp -r ~/workflow /usr/src/workflow
	sudo rm -rf /usr/src/workflow/.git
