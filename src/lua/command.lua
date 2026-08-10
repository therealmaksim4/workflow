dofile(os.getenv("HOME") .. "/.config/workflow/config.lua")
dofile("/usr/src/workflow/src/lua/special/check_command_name_color.lua")

global.on_command_start()

check_command_name_color("command")

io.write("Command: ")
command = io.read()

check_command_name_color(command)

os.execute(command)

check_command_name_color(command)
check_command_name_color("command")

global.on_command_end()
