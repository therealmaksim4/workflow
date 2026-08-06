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
    echo -e "\e[0;31mFile already exists!\e[0;0m"
else
    cp -r ~/workflow/example_config.lua ~/.config/workflow/config.lua
fi

echo "Building and installing the files..."

cd ~/workflow

make 1>/dev/null
