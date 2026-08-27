--[[
Usage:

1:
players = prompt("Amount of players playing")

Output:
Amount of players playing: 8

2:
number = prompt("What's your favorite number")

Output:
What's your favorite number: 4
]]
function prompt(string)
    io.write(string .. ": ")
    retval = io.read()

    return retval
end

--[[
Usage:
error_msg("x should be an integer", "example_command", 1)

Output:
workflow: example_command: x should be an integer
]]
function error_msg(message, command, status_code)
    io.stderr:write("workflow: " .. command .. ": " .. message)

    os.exit(status_code)
end
