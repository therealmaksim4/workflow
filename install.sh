#!/bin/bash

printf "Making the .config directory... "

cd

mkdir ~/.config/workflow
mkdir ~/.config/src

echo "Done!"
printf "Copying the source code into the .config directory... "

cp -r ~/workflow/src .config/workflow/src

rm -rf ~/.config/workflow/src/main.cpp

echo "Done!"
printf "Building and installing the files... "

cd ~/workflow

cmake -S . -B build
cmake --build build
sudo cmake --install build

echo "Done!"
