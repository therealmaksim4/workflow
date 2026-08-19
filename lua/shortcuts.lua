--[[
    Usage:
    players = prompt("Amount of players playing")
    number = prompt("What's your favorite number")
]]
function prompt(string)
    io.write(string .. ": ")
    retval = io.read()

    return retval
end

--[[
    Usage:
    error_msg("x should be an integer", 1)
]]
function error_msg(message, status_code)
    io.stderr:write("workflow: " .. message)

    os.exit(status_code)
end
