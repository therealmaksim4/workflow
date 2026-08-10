dofile(os.getenv("HOME") .. "/.config/workflow/config.lua")
dofile("/usr/src/workflow/src/lua/special/check_command_name_color.lua")

global.on_command_start()

check_command_name_color("make")

io.write("Filepath: ")
filename = io.read()

os.execute("touch " .. filename)

check_command_name_color("make")

global.on_command_end()
