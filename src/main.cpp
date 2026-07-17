#include <iostream>

int main(){
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
