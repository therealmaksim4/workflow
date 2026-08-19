# How to write your own commands

When writing your commands you need to `dofile()` this file:

```lua
dofile(os.getenv("HOME") .. "/.config/workflow/config.lua")
```

After those two you need to put `global.on_command_start()` after the `dofile()` and `global.on_command_end()` at the end of your file. This will show the name of the command if the config file has that setting on. You should also try to make your own settings if you are going to distribute your command. in workflow/lua there a lua files you can `dofile()` that help you by giving you functions that simplify the process of making a command.

Here is a simple example of a command:

```lua
dofile(os.getenv("HOME") .. "/.config/workflow/config.lua")
dofile("/usr/src/workflow/lua/check_command_name_color.lua")

global.on_command_start()

check_command_name_color("cheat")

if cheat.type_full_url == true then
    io.write("URL: ")
    url = io.read()
    
    os.execute("curl cht.sh/" .. url)
elseif cheat.type_full_url == false then
    io.write("Language: ")
    language = io.read()

    io.write("Query: ")
    query = io.read()

    os.execute("curl cht.sh/" .. language .. "/" .. query)
end

check_command_name_color("cheat")

global.on_command_end()
```
