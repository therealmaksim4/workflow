dofile(os.getenv("HOME") .. "/.config/workflow/config.lua")

os.execute(edit.editor.default_editor .. " ~/.config/workflow/config.lua")
