commands = %x(ls -1 ~/.config/workflow/lua)

if commands == ""
  $stderr.puts("workflow: no commands in ~/.config/workflow/lua")
else
  print(commands)
end
