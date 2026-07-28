#!/bin/bash

printf "Making the config directory... "

cd

mkdir -p ~/.config/workflow 1>/dev/null

echo "Done!"
printf "Removing past config files... "

rm -rf ~/.config/workflow/lua 1>/dev/null

echo "Done!"
printf "Copying the lua source code into the config directory... "

cp -r ~/workflow/src/lua ~/.config/workflow/lua

echo "Done!"
printf "Building and installing the files... "

cd ~/workflow

rm -rf build
mkdir build

cmake -S . -B build 1>/dev/null
cmake --build build 1>/dev/null
sudo cmake --install build 1>/dev/null

echo "Done!"
