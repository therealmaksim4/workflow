dofile(os.getenv("HOME") .. "/.config/workflow/config.lua")
dofile("/usr/src/workflow/lua/special/check_command_name_color.lua")

global.on_command_start()

check_command_name_color("cheat")

if cheat.type_full_url == true then
    io.write("URL: ")
    url = io.read()
    
    os.execute("curl cht.sh/" .. url)
elseif cheat.type_full_url == false then
    io.write("Language: ")
    language = io.read()

    io.write("Query: ")
    query = io.read()

    os.execute("curl cht.sh/" .. language .. "/" .. query)
end

check_command_name_color("cheat")

global.on_command_end()
