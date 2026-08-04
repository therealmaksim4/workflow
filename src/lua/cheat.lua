dofile(os.getenv("HOME") .. "/.config/workflow/config.lua")

global.on_command_start()

if global.show_command_name == true then
    print("-- cheat --")
end

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

if global.show_command_name == true then
    print("-- cheat --")
end

global.on_command_end()
