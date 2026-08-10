dofile(os.getenv("HOME") .. "/.config/workflow/config.lua")
dofile("/usr/src/workflow/src/lua/special/check_command_name_color.lua")

global.on_command_start()

check_command_name_color("edit")

if edit.editor.use_default_editor == false then
    io.write("Text Editor: ")
    editor = io.read()
elseif edit.editor.use_default_editor == true then
    editor = edit.editor.default_editor
end

io.write("Filepath: ")
filepath = io.read()

os.execute(editor .. " " .. filepath)

check_command_name_color("edit")

global.on_command_end()
