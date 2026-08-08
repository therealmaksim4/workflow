all:
	g++ -O3 -march=native -funroll-loops -fprefetch-loop-arrays -flto src/main.cpp -o workflow
	sudo install -m 0755 workflow /usr/bin/workflow
	rm -rf workflow
	sudo rm -rf /usr/src/workflow
	sudo cp -r ~/workflow /usr/src/workflow
	sudo rm -rf /usr/src/workflow/.git
