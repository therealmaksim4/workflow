#!/bin/bash

echo "Making the config directory..."

cd

mkdir -p ~/.config/workflow > /dev/null 2>&1

echo "Removing past config files..."

rm -rf ~/.config/workflow/lua > /dev/null 2>&1

echo "Copying the lua source code into the config directory..."

cp -r ~/workflow/src/lua ~/.config/workflow/lua

echo "Making config.lua..."

if [ -e ~/.config/workflow/config.lua ]; then
    echo "File already exists!"
else
    cp -r ~/workflow/example_config.lua ~/.config/workflow/config.lua
fi

echo "Building and installing the files..."

cd ~/workflow

mkdir build > /dev/null 2>&1

cmake -S . -B build 1>/dev/null
cmake --build build 1>/dev/null
sudo cmake --install build 1>/dev/null

rm -rf build > /dev/null 2>&1
