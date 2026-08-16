# Knowledge

In C you need to know stdio.h, a bit of stdlib.h and you should know how to make header files incase we need those. In Lua you just need to know for loops, if statements, `io.write()`, `io.read()`, `dofile()` and other related concepts. You should also know how to use a compiler and an interpreter.

# Contributing

You can begin contributing by writing a new command that is useful. Be unique, but don't make commands that no one will ever use. Don't vibecode as AI ruins your creativity. You should also use workflow while contributing to see if it's a good tool and to see what can be improved. The source code is organised well so it's easy to start contributing.

# Style

This section is on the style of the code you should be writing. If you do something wrong you shouldn't worry.

## General

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

Only use io.write when wanting to take input from the user.

```lua
io.write("Do you like pizza? ")
answear = io.read()
```

Not in normal output.

```lua
io.write("Hello, World!\n")
io.write("This is the wrong way\n")
```
