print("-- cheat --")

io.write("Language: ")
language = io.read()

io.write("Query: ")
query = io.read()

os.execute("curl cht.sh/" .. language .. "/" .. query)

print("-- cheat --")
