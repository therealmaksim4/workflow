dofile(os.getenv("HOME") .. "/.config/workflow/config.lua")

function check_command_name_color(command_name)
    if global.show_command_name == true then
        if global.colors.use_colors == false then
            print("-- " .. command_name .. " --")
        elseif global.colors.use_colors == true then
            if global.colors.main_color == "red" then
                print("\27[31m-- " .. command_name .. " --\27[0m")
            elseif global.colors.main_color == "green" then
                print("\27[32m-- " .. command_name .. " --\27[0m")
            elseif global.colors.main_color == "yellow" then
                print("\27[33m-- " .. command_name .. " --\27[0m")
            elseif global.colors.main_color == "blue" then
                print("\27[34m-- " .. command_name .. " --\27[0m")
            elseif global.colors.main_color == "magenta" then
                print("\27[35m-- " .. command_name .. " --\27[0m")
            elseif global.colors.main_color == "cyan" then
                print("\27[36m-- " .. command_name .. " --\27[0m")
            elseif global.colors.main_color == "black" then
                print("\27[30m-- " .. command_name .. " --\27[0m")
            elseif global.colors.main_color == "white" then
                print("\27[37m-- " .. command_name .. " --\27[0m")
            else
                print("-- " .. command_name .. " --")
            end
        end
    end
end
