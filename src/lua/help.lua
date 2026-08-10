dofile(os.getenv("HOME") .. "/.config/workflow/config.lua")
dofile("/usr/src/workflow/src/lua/special/check_command_name_color.lua")

global.on_command_start()

check_command_name_color("help")

commands = {
    help = "List every command and it's function",
    cheat = "Open up cheat sheets (check out https://github.com/chubin/cheat.sh because that's where the sheets come from)",
    man = "Open up manual pages for core utils",
    command = "Run a shell command",
    edit = "Edit a file",
    make = "Create a file",
    clear = "Clear the screen",
}

mini_commands = {
    q = "Exit workflow",
    c = "Edit the config.lua file",
    rc = "Reset your config to default settings",
    p = "Execute previous command",
}

print("workflow v0.2.0\nNormal Commands:\n")

for key, value in pairs(commands) do
    print(key .. " " .. help.seperator .. " " .. value)
end

print("\nMini Commands:\n")

for key, value in pairs(mini_commands) do
    print(key .. " " .. help.seperator .. " " .. value)
end

check_command_name_color("help")

global.on_command_end()
