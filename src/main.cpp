#include <iostream>

int main(int argc, char *argv[]){
    if(argc == 2 && argv[1] == "help"){
        std::cout << "workflow v0.0.2" << std::endl << std::endl;
        std::cout << "help - Display this help command" << std::endl;
        std::cout << "cheat - Pull up cheatsheets" << std::endl;
        std::cout << "man - Pull up man pages" << std::endl;
        std::cout << std::endl << "The git repo: \"https://github.com/therealmaksim4/workflow\"" << std::endl;

        return 0;
    }

    else if(argc == 2 && argv[1] == "cheat"){
        system("lua ~/.config/workflow/lua/cheat.lua");

        return 0;
    }

    else if(argc == 2 && argv[1] == "man"){
        system("lua ~/.config/workflow/lua/man.lua");

        return 0;
    }

    else if(argc > 2){
        std::cout << "Too much arguments given" << std::endl;

        return 1;
    }
    
    else if(argc == 1){
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
    }

    return 0;
}
