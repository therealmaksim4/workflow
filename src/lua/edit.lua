print("-- edit --")

io.write("Text Editor: ")
editor = io.read()

io.write("Filepath: ")
filepath = io.read()

os.execute(editor .. " " .. filepath)

print("-- edit --")
