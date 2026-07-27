print("-- command --")

io.write("Command: ")
command = io.read()

print("-- " .. command .. " --")

os.execute(command)

print("-- " .. command .. " --")
print("-- command --")
