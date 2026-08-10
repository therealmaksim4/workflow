#include <iostream>

int main(int argc, char *argv[]){
    if(argc != 1){
        std::cerr << "workflow doesn't accept arguments" << std::endl;

        return 1;
    }

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

        else if(cmd == "c"){
            system("luajit /usr/src/workflow/src/lua/special/edit_config.lua");
        }

        else if(cmd == "rc"){
            system("rm -rf ~/.config/workflow/config.lua");
            system("cp -r ~/workflow/example_config.lua ~/.config/workflow/config.lua");
        }

        else if(cmd == "q"){
            running = false;
        }

        else{
            std::cerr << "\033[31m" << cmd << ": command not found" << "\033[0m" << std::endl;
        }
    }

    system("clear");

    return 0;
}
