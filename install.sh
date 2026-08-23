#!/bin/bash

errors=0
warnings=0

sudo printf ""

read -p "Would you like to automatically install dependencies? (gcc, lua, ruby (ruby might need to be installed manually on some systems)) [y/n] " dependencies

if [[ $dependencies == "y" ]]; then
    echo -e "\e[0;34m#\e[0;0m Installing dependencies:"

    if command -v apt > /dev/null 2>&1; then
        sudo apt install gcc lua ruby-full
    elif command -v dnf > /dev/null 2>&1; then
        sudo dnf install gcc lua
    elif command -v yum > /dev/null 2>&1; then
        sudo yum install gcc lua ruby
    elif command -v zypper > /dev/null 2>&1; then
        sudo zypper install gcc lua
    elif command -v pacman > /dev/null 2>&1; then
        sudo pacman -S gcc lua ruby
    elif command -v apk > /dev/null 2>&1; then
        sudo apk add gcc lua
    elif command -v xbps-install > /dev/null 2>&1; then
        sudo xbps-install gcc lua
    else
        echo "\e[0;31mError: Package manager not found, dependencies will need to be manually installed\e[0;0m"

        ((errors++))
    fi
elif [[ $dependencies == "n" ]]; then
    echo -e "\e[0;33mWarning: Dependencies will need to be installed manually\e[0;0m"

    ((warnings++))
else
    echo -e "\e[0;33mWarning: Invalid answear given, dependencies will need to be manually installed\e[0;0m"

    ((warnings++))
fi

echo -e "\e[0;34m#\e[0;0m Making the config directory:"

cd

if [ -e ~/.config/workflow ]; then
    echo -e "\e[0;33mWarning: Directory already exists\e[0;0m"

    ((warnings++))
else
    echo "  mkdir -p ~/.config/workflow"

    mkdir -p ~/.config/workflow > /dev/null 2>&1
fi

echo -e "\e[0;34m#\e[0;0m Making the lua directory:"

if [ -e ~/.config/workflow/lua ]; then
    echo -e "\e[0;33mWarning: Directory already exists\e[0;0m"

    ((warnings++))
else
    echo "  mkdir -p ~/.config/workflow/lua"

    mkdir -p ~/.config/workflow/lua > /dev/null 2>&1
fi

echo -e "\e[0;34m#\e[0;0m Making config.lua:"

if [ -e ~/.config/workflow/config.lua ]; then
    echo -e "\e[0;33mWarning: File already exists\e[0;0m"

    ((warnings++))
else
    echo "  cp -r ~/workflow/example_config.lua ~/.config/workflow/config.lua"

    cp -r ~/workflow/example_config.lua ~/.config/workflow/config.lua
fi

echo -e "\e[0;34m#\e[0;0m Compiling and installing the files:"

cd ~/workflow

make | sed 's/^/  /'

echo -e "\n\e[0;31mNumber of errors: $errors\e[0;0m"
echo -e "\e[0;33mNumber of warnings: $warnings\e[0;0m"
