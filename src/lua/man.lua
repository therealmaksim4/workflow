dofile(os.getenv("HOME") .. "/.config/workflow/config.lua")
dofile("/usr/src/workflow/src/lua/special/check_command_name_color.lua")

global.on_command_start()

check_command_name_color("man")

io.write("Page: ")
page = io.read()

os.execute("man " .. page)

check_command_name_color("man")

global.on_command_end()
