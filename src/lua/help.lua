print("-- help --")

commands = {
    help = "List every command and it's function",
    cheat = "Open up cheat sheets (check out https://github.com/chubin/cheat.sh because that's where the sheets come from)",
    man = "Open up manual pages for core utils",
    command = "Run a shell command",
    edit = "Edit a file",
    make = "Create a file",
    lang = "Info about a programming language",
}

print("workflow v0.1.7\n")

for key, value in pairs(commands) do
    print(key .. " - " .. value)
end

print("-- help --")
