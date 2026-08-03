dofile(os.getenv("HOME") .. "/.config/workflow/config.lua")

on_command_start()

if global.show_command_name == true then
    print("-- make --")
end

io.write("Filepath: ")
filename = io.read()

os.execute("touch " .. filename)

if global.show_command_name == true then
    print("-- make --")
end
