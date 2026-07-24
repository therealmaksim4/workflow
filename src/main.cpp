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
        system("bash ~/.config/workflow/src/cheatsheets/cheatsheets.sh");

        return 0;
    }

    else if(argc == 2 && argv[1] == "man"){
        system("bash ~/.config/workflow/src/manpages/manpages.sh");

        return 0;
    }

    else if(argc > 2){
        std::cout << "Too much arguments given" << std::endl;

        return 1;
    }

    system("clear");

    bool running = true;
    std::string cmd;

    while(running){
        std::cin >> cmd;

        if(cmd == "cheat"){
            system("bash ~/.config/workflow/src/cheatsheets/cheatsheets.sh");
        }

        else if(cmd == "man"){
            system("bash ~/.config/workflow/src/manpages/manpages.sh");
        }

        else if(cmd == "bash"){
            system("bash ~/.config/workflow/src/bash/bash.sh");
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
