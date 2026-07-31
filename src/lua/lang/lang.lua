print("-- lang --")

io.write("Language: ")
language = io.read()

if language == "lua" then
    os.execute("cat ~/.config/workflow/lua/lang/languages/lua.txt")
elseif language == "c" then
    os.execute("cat ~/.config/workflow/lua/lang/languages/c.txt")
elseif language == "cpp" then
    os.execute("cat ~/.config/workflow/lua/lang/languages/cpp.txt")
elseif language == "python" then
    os.execute("cat ~/.config/workflow/lua/lang/languages/python.txt")
else
    print("Invalid language given")
end

print("-- lang --")
