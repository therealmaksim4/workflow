commands = %x(ls -1 ~/.config/workflow/lua)

if commands == ""
  $stderr.print("workflow: no commands in ~/.config/workflow/lua\n")
else
  print(commands)
end
