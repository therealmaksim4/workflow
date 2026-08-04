dofile(os.getenv("HOME") .. "/.config/workflow/config.lua")

global.on_command_start()

if global.show_command_name == true then
    print("-- edit --")
end

if edit.editor.use_default_editor == false then
    io.write("Text Editor: ")
    editor = io.read()
elseif edit.editor.use_default_editor == true then
    editor = edit.editor.default_editor
end

io.write("Filepath: ")
filepath = io.read()

os.execute(editor .. " " .. filepath)

if global.show_command_name == true then
    print("-- edit --")
end

global.on_command_end()
