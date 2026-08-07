#include <iostream>

int main(int argc, char *argv[]){
    system("clear");

    bool running = true;
    std::string cmd;

    while(running){
        std::cin >> cmd;

        if(cmd == "cheat"){
            system("luajit /usr/src/workflow/src/lua/cheat.lua");
        }

        else if(cmd == "man"){
            system("luajit /usr/src/workflow/src/lua/man.lua");
        }

        else if(cmd == "edit"){
            system("luajit /usr/src/workflow/src/lua/edit.lua");
        }

        else if(cmd == "make"){
            system("luajit /usr/src/workflow/src/lua/make.lua");
        }

        else if(cmd == "help"){
            system("luajit /usr/src/workflow/src/lua/help.lua");
        }

        else if(cmd == "command"){
            system("luajit /usr/src/workflow/src/lua/command.lua");
        }

        else if(cmd == "clear"){
            system("clear");
        }

        else if(cmd == "exit"){
            system("clear");
            running = false;
        }

        else{
            std::cout << "Invalid command" << std::endl;
        }
    }

    return 0;
}
