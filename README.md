# workflow

workflow is a CLI tool that helps you with coding. All you need to do is make a `main.lua` file and put it in `~/.config/workflow/lua/your_command/main.lua` and you can run it by typing `workflow your_command`. Ths little program gives some Lua functions that make your job very easy. There is also a config file that can be used by every script. If you want to make a command read [the guide to making commands](COMMANDS.md). You can see every Markdown file by typing `workflow docs file`, make sure the name is in lowercase and has no extension. This program is in an early state and everything might change (it already did 2 times).

Thanks for checking out this repo!

## Installation

Clone the repository:

```bash
git clone https://github.com/therealmaksim4/workflow
```

Enter the repository:

```bash
cd workflow
```

Run the [install script](install.sh):

```bash
bash install.sh
```

## Updating

Enter the repository:

```bash
cd workflow
```

Update the repository:

```bash
git pull
```

Run the [install script](install.sh):

```bash
bash install.sh
```

## Configuration

There is a config.lua file that is made after installing. Make sure that file is up to date with all of the new options otherwise it won't work. For reference look at the [example_config.lua file](example_config.lua) to see all of the options. If this is your first time installing the config.lua is made from the [example_config.lua file](example_configlua).
