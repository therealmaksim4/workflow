#include <iostream>

int main(int argc, char *argv[]){
    system("clear");

    bool running = true;
    std::string cmd;

    while(running){
        std::cin >> cmd;

        if(cmd == "cheat"){
            system("lua ~/.config/workflow/lua/cheat.lua");
        }

        else if(cmd == "man"){
            system("lua ~/.config/workflow/lua/man.lua");
        }

        else if(cmd == "edit"){
            system("lua ~/.config/workflow/lua/edit.lua");
        }

        else if(cmd == "make"){
            system("lua ~/.config/workflow/lua/make.lua");
        }

        else if(cmd == "help"){
            system("lua ~/.config/workflow/lua/help/help.lua");
        }

        else if(cmd == "command"){
            system("lua ~/.config/workflow/lua/command.lua");
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
