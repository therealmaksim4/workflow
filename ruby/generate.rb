require("fileutils")

command_name = ARGV[0]

FileUtils.mkdir("#{ENV["HOME"]}/.config/workflow/lua/#{command_name}")
FileUtils.touch("#{ENV["HOME"]}/.config/workflow/lua/#{command_name}/main.lua")

content = %Q(dofile(os.getenv("HOME") .. "/.config/workflow/config.lua")
dofile("/usr/src/workflow/lua/check_command_name_color.lua")

global.on_command_start()

check_command_name_color("#{command_name}")

-- Your code goes here

check_command_name_color("#{command_name}")

global.on_command_end())

File.write("#{ENV["HOME"]}/.config/workflow/lua/#{command_name}/main.lua", content)
