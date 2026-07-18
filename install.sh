#!/bin/bash

printf "Making the config directory... "

cd

mkdir ~/.config/workflow > /dev/null 2>&1
mkdir ~/.config/src > /dev/null 2>&1

echo "Done!"
printf "Removing past source config files... "

rm -rf ~/.config/workflow/src/

echo "Done!"
printf "Copying the source code into the config directory... "

cp -r ~/workflow/src .config/workflow/src

rm -rf ~/.config/workflow/src/main.cpp

echo "Done!"
printf "Building and installing the files... "

cd ~/workflow

cmake -S . -B build > /dev/null 2>&1
cmake --build build > /dev/null 2>&1
sudo cmake --install build > /dev/null 2>&1

echo "Done!"
