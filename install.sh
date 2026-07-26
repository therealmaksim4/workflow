#!/bin/bash

printf "Making the config directory... "

cd

mkdir -p ~/.config/workflow > /dev/null 2>&1

echo "Done!"
printf "Removing past config files... "

rm -rf ~/.config/workflow/lua > /dev/null 2>&1

echo "Done!"
printf "Copying the lua source code into the config directory... "

cp -r ~/workflow/src/lua ~/.config/workflow/lua

echo "Done!"
printf "Building and installing the files... "

cd ~/workflow

cmake -S . -B build > /dev/null 2>&1
cmake --build build > /dev/null 2>&1
sudo cmake --install build > /dev/null 2>&1

echo "Done!"
