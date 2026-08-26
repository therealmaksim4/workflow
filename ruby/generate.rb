require("fileutils")

command_name = ARGV[0]
home_dir = ENV["HOME"]

FileUtils.mkdir("#{home_dir}/.config/workflow/lua/#{command_name}")
FileUtils.touch("#{home_dir}/.config/workflow/lua/#{command_name}/main.lua")

content = %Q(dofile("/usr/src/workflow/bin/all.luac")

global.on_command_start()

check_command_name_color("#{command_name}")

-- Your code goes here

check_command_name_color("#{command_name}")

global.on_command_end())

File.write("#{home_dir}/.config/workflow/lua/#{command_name}/main.lua", content)
