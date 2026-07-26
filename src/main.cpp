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

        else if(cmd == "bash"){
            system("lua ~/.config/workflow/lua/bash.lua");
        }

        else if(cmd == "clear"){
            system("clear");
        }

        else if(cmd == "exit"){
            running = false;
        }

        else{
            std::cout << "Invalid command." << std::endl;
        }
    }

    return 0;
}
