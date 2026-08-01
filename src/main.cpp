#include <iostream>

int main(int argc, char *argv[]){
    system("clear");

    bool running = true;
    std::string cmd;

    while(running){
        std::cin >> cmd;

        if(cmd == "cheat"){
            system("luajit ~/.config/workflow/lua/cheat.lua");
        }

        else if(cmd == "man"){
            system("luajit ~/.config/workflow/lua/man.lua");
        }

        else if(cmd == "edit"){
            system("luajit ~/.config/workflow/lua/edit.lua");
        }

        else if(cmd == "make"){
            system("luajit ~/.config/workflow/lua/make.lua");
        }

        else if(cmd == "help"){
            system("luajit ~/.config/workflow/lua/help.lua");
        }

        else if(cmd == "command"){
            system("luajit ~/.config/workflow/lua/command.lua");
        }

        else if(cmd == "lang"){
            system("luajit ~/.config/workflow/lua/lang/lang.lua");
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
