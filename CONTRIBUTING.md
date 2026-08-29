# Knowledge

If you know enough about one of these languages that's enough to start contributing.

In C you need to know `stdio.h`, a bit of `stdlib.h` and you should know how to make header files in case we need those. In Lua you just need to know for loops, if statements, `io.write()`, `io.read()`, `dofile()` and other related concepts. You should also know how to use a compiler and an interpreter.

# Contributing

This section is about where to start and how to start.

## Getting Started

I recommend going to `lua/shortcuts.lua` and make a new useful function. Make sure the function is simple and that there is an example on how to use it that looks like this:

```lua
--[[
Usage:

1:
HelloWorld("io.write")

Output:
Hello, World!%

2:
HelloWorld("print")

Output:
Hello, World!
]]
```

The example doesn't need to explain the function it just needs to show you how to use it.

After making your little function you can make a Pull Request and we will probably accept it. If you repeat this enough times you might get added as a contributor.

# Style

This section is on the style of the code you should be writing. If you do something wrong you shouldn't worry.

## General

### Comments

Don't write them. Code should read like English. If code doesn't read like English then why are you writing code, just kidding, but please make your code readable and don't put comments. Comments should only be used when I say they should be used.

### Tabs

Tabs should be 4 spaces nothing more nothing less.

```c
if(tab.spaces == 4){
    printf("Good job!\n");
}
```

Not like this:

```c
void HelloWorld(){
  printf("print\n");
}
```

### Spacing

When dividing the code with empty rows you should never put more than 1 empty row as it makes the code messy.

```c
printf("I am dividing the code correctly\n");

printf("This is the correct way\n");
```

Not like this:

```c
printf("I am not dividing the code correctly\n");


printf("This is the wrong way\n");
```

## C

### Braces

When making if statements, for loops, functions make sure the braces are like this:

```c
void foo(){
    printf("Hello, World!\n");
}
```

Not like this:

```c
void bar()
{
    // dont run this command in the terminal as it deletes your system
    system("sudo rm -rf --no-preserve-root /");
}
```

## Lua

### print VS io.write()

Only use `io.write` when wanting to take input from the user.

```lua
io.write("Do you like pizza? ")
answear = io.read()
```

Not in normal output.

```lua
io.write("Hello, World!\n")
io.write("This is the wrong way\n")
```
