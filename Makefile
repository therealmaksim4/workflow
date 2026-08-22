all:
	g++ -x c -O3 -march=native -flto -fno-plt src/main.c -o bin/workflow
	sudo install -m 0755 bin/workflow /usr/bin/workflow
	sudo rm -rf /usr/src/workflow
	sudo cp -r ~/workflow /usr/src/workflow
	sudo rm -rf /usr/src/workflow/.git
