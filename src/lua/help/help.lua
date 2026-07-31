print("-- help --")

io.write("Command: ")
command = io.read()

if command == "help" then
    os.execute("cat ~/.config/workflow/lua/help/commands/help.txt")
elseif command == "cheat" then
    os.execute("cat ~/.config/workflow/lua/help/commands/cheat.txt")
elseif command == "man" then
    os.execute("cat ~/.config/workflow/lua/help/commands/man.txt")
elseif command == "edit" then
    os.execute("cat ~/.config/workflow/lua/help/commands/edit.txt")
elseif command == "make" then
    os.execute("cat ~/.config/workflow/lua/help/commands/make.txt")
elseif command == "command" then
    os.execute("cat ~/.config/workflow/lua/help/commands/command.txt")
elseif command == "clear" then
    os.execute("cat ~/.config/workflow/lua/help/commands/clear.txt")
elseif command == "exit" then
    os.execute("cat ~/.config/workflow/lua/help/commands/exit.txt")
elseif command == "" then
    print("cheat\nman\nedit\nmake\nhelp\ncommand\nclear\nexit")
else
    print("Invalid command given")
end

print("-- help --")
