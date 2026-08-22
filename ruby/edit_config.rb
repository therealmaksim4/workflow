editor = ARGV[0]
home_dir = ENV["HOME"]

system("#{editor} #{home_dir}/.config/workflow/config.lua")
