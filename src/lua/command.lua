dofile(os.getenv("HOME") .. "/.config/workflow/config.lua")

on_command_start()

if global.show_command_name == true then
    print("-- command --")
end

io.write("Command: ")
command = io.read()

if command.show_command_name == true then
    print("-- " .. command .. " --")
end

os.execute(command)

if command.show_command_name == true then
    print("-- " .. command .. " --")
end

if global.show_command_name == true then
    print("-- command --")
end
