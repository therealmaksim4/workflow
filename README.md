# workflow v0.1.1

Enhance your coding.

## Installation

Arch:

Clone the repository:

`git clone https://github.com/therealmaksim4/workflow`

Enter the repository:

`cd workflow`

Make the package using makepkg:

`makepkg -si`

Other distros:

Clone the repository:

`git clone https://github.com/therealmaksim4/workflow`

Enter the repository:

`cd workflow`

Run the install script:

`bash install.sh`

## How to use

There are a few commands as of the latest version:

`cheat` - Find cheatsheets for what you need

`man` - Man pages for what you need

`bash` - Run one line of bash

`clear` - Clear the screen

`exit` - Exit workflow

You can also execute multiple commands in one line by doing `cheat bash clear` which would open up cheatsheets, execute a bash command and clear the terminal.

## Configuration

You can edit the source code directly after installing (You only can't edit the main.cpp file but you don't even need to do it). Make sure to back up your source config files as we delete past source config files!

## What's new?

We switched from bash to lua for simplicity and ease of configuration! Lua is much simpler, it's better for writing small reusable scripts and it's really fast.
