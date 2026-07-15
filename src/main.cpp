#include <iostream>

int main(){
    system("clear");

    bool running = true;
    std::string cmd;

    while(running){
        std::cin >> cmd;

        if(cmd == "cheat"){
            system("bash ~/workflow/src/cheatsheets/cheatsheets.sh");
        }

        else if(cmd == "man"){
            system("bash ~/workflow/src/manpages/manpages.sh");
        }

        else if(cmd == "clear"){
            system("clear");
        }

        else if(cmd == "exit"){
            running = false;
        }
    }

    return 0;
}
