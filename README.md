# workflow

Enhance your workflow.

## Installation

### Dependencies

Arch:

`sudo pacman -S cmake git`

Debian:

`sudo apt install cmake git`
#
### How to install

Make sure to install the dependencies before installing this repository!

Clone the repository:

`git clone therealmaksim4/workflow`

Enter the repository:

`cd workflow`

Set up the CMake:

`cmake -S . -B build/`

Build the files:

`cmake --build build/`

Install the files (this won't work without sudo):

`sudo cmake --install build/`

You should be done! Type `workflow` into the terminal and it should be over!

## How to use

There are a few commands as of version 0.0.11:

`cheat` - Find cheatsheets for what you need

`man` - Man pages for what you need

`bash` - Run one line of bash

`clear` - Clear the screen

`exit` - Exit workflow
