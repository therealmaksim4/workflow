dofile(os.getenv("HOME") .. "/.config/workflow/config.lua")

global.on_command_start()

if global.show_command_name == true then
    print("-- help --")
end

commands = {
    help = "List every command and it's function",
    cheat = "Open up cheat sheets (check out https://github.com/chubin/cheat.sh because that's where the sheets come from)",
    man = "Open up manual pages for core utils",
    command = "Run a shell command",
    edit = "Edit a file",
    make = "Create a file",
}

print("workflow v0.2.0\n")

for key, value in pairs(commands) do
    print(key .. " " .. help.seperator .. " " .. value)
end

if global.show_command_name == true then
    print("-- help --")
end

global.on_command_end()
