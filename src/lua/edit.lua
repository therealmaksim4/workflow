dofile(os.getenv("HOME") .. "/.config/workflow/config.lua")

on_command_start()

if global.show_command_name == true then
    print("-- edit --")
end

io.write("Text Editor: ")
editor = io.read()

io.write("Filepath: ")
filepath = io.read()

os.execute(editor .. " " .. filepath)

if global.show_command_name == true then
    print("-- edit --")
end
