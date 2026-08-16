dofile(os.getenv("HOME") .. "/.config/workflow/config.lua")
dofile("/usr/src/workflow/lua/special/check_command_name_color.lua")

global.on_command_start()

check_command_name_color("help")

commands = {
    help = "List every command and it's function",
    cheat = "Open up cheat sheets (check out https://github.com/chubin/cheat.sh because that's where the sheets come from)",
}

print("workflow v0.2.0\n")

for key, value in pairs(commands) do
    print(key .. " " .. help.seperator .. " " .. value)
end

check_command_name_color("help")

global.on_command_end()
