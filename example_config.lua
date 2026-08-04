global = {
    show_command_name = true, -- Shows the name of the command being ran
}

function global.on_command_start() -- When running a command this function will be ran at the start
    -- Empty
end

function global.on_command_end() -- When running a command this function will be ran at the end
    -- Empty
end

cheat = {
    type_full_url = false, -- If true "URL: (language/query or util~query)". Enabling this means you get more freedom.
}

help = {
    seperator = "-", -- What seperates the command and the description
}

command = {
    show_command_name = true, -- Shows the name of the shell command being ran
}

edit = {
    editor = {
        default_editor = "nano",
        use_default_editor = false, -- If false the edit command will ask you to give it an editor, otherwise it will use the default editor above
    },
}
