--[[
Usage:
Let's pretend script.rb prints "Hello, World!"

1:
run_ruby("~/.config/workflow/my_command/script.rb", "r")

-- This runs the script

2:
output = run_ruby("~/.config/workflow/my_command/script.rb", "c")

-- This returns the output of the script
]]
function run_ruby(filepath, option)
    if option == "r" then
        os.execute("ruby " .. filepath)
    elseif option == "c" then
        handle = io.popen("ruby " .. filepath)
        output = handle:read("*all")

        return output
    else
        io.stderr:write("Invalid option given\n")
    end
end
