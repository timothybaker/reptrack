#include "Reptrack.h"

int main(int argc, char** argv)
{
    Reptrack reptrack;  

    reptrack.main_intro();                             // declare reptracker

    while(reptrack.ok())
    {
        reptrack.main_menu();                          // ask for user input
    }

    return 0;
}


