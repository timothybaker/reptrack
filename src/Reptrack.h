#ifndef REPTRACK_H_INCLUDED
#define REPTRACK_H_INCLUDED

#include <thread>
#include <list>
#include <iostream>
#include <fstream>
#include "Date.h"
#include "Group.h"
#include "TimsTools.h"

typedef std::thread Cobra;
typedef TimsTools ToolTime;

class Reptrack
{
    private:
        bool okay;
        char menu_option;
        Date date;
        ToolTime tooltime;
        std::list<Group> groups;

        /**
          * gather snakes from data file
          */
        void gather_groups(std::ifstream& in);

        /**
         * Program Intro
         */
        void intro(std::ostream& out);

        /**
         * Program Start Menu Function
         */
        void menu(std::ostream& out);

        /**
          * menu selection
          */
        void selection();

        /**
         * Snake Menu Function
         */
        void group_menu(std::ostream& out);

        /**
          * Snake menu selection
          */
        void group_selection();

        /**
         * load data from files
         */
        void load_data();

        /**
          * publish snakes to file
          */
        void publish_groups(std::ostream& out);
        
    public:
        /**
         * Default Constructor
         */
        Reptrack();

        /**
         * Deconsructor
         */
        ~Reptrack(){};

        /**
         * reptrack flagger
         */
        bool ok()const{return okay;}

        /**
         * Main Intro
         */
        void main_intro();

        /**
         * Main Menu
         */
        void main_menu();
};

#endif //REPTRACK_H_INCLUDED
