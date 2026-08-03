dofile(os.getenv("HOME") .. "/.config/workflow/config.lua")

on_command_start()

if global.show_command_name == true then
    print("-- man --")
end

io.write("Page: ")
page = io.read()

os.execute("man " .. page)

if global.show_command_name == true then
    print("-- man --")
end
