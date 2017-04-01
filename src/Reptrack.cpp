#include "Reptrack.h"

/**
  * Default Constructor
  */
Reptrack::Reptrack()
{
    okay=true;
    menu_option=0;
}

/**
  * Main Intro
  */
void Reptrack::main_intro()
{
    Cobra c1([&]{load_data();});             // load data from files
    Cobra c2([&]{intro(std::cout);});        // display introduction
    c1.join();
    c2.join();
}

/**
  * Main Menu
  */
void Reptrack::main_menu()
{
    Cobra c1([&]{menu(std::cout);});         // display user interface
    c1.join();
    Cobra c2([&]{selection();});             // act on user input
    Cobra c3([&]{tooltime.sleep(100);});     // pause to conserve cpu power
    c2.join();
    c3.join();
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
// PRIVATE FUNCTIONS
/**
  * Program Intro
  */
void Reptrack::intro(std::ostream& out)
{
    out<<"\nWELCOME TO REPTRACK\n";
    out<<"\n"<<date<<"\n";
}

/**
  * Program Start Menu Function
  */
void Reptrack::menu(std::ostream& out)
{
    char input;
    out<<"MAIN MENU CHOICES: \n";
    out<<"    1) GROUP MENU \n";
    out<<"    2) CONFIG MENU \n";
    out<<"    3) QUIT \n";
    out<<"\nCHOICE ? : ";
    std::cin >> input;
    menu_option = input;
    std::cin.ignore(100, '\n');
}

/**
  * Main menu Selection
  */
void Reptrack::selection()
{
    tooltime.clear_screen(std::cout, 100);
    if(menu_option == '1')
    {
        while(okay == true)
        {
            Cobra c1([&]{group_menu(std::cout);});
            c1.join();
            Cobra c2([&]{group_selection();});             
            Cobra c3([&]{tooltime.sleep(100);});     
            c2.join();
            c3.join();
        }
        okay = true;
    }
    if(menu_option == '2')
    {
        okay = true;
    }
    if(menu_option == '3') okay = false;
}

/**
  * Snake Menu Function
  */
void Reptrack::group_menu(std::ostream& out)
{
    char input;
    out<<"CHOICES: \n";
    out<<"    1) ADD NEW GROUP \n";
    out<<"    2) REMOVE GROUP \n";
    out<<"    3) VIEW GROUPS \n";
    out<<"    4) MODIFYGROUP \n";
    out<<"    5) BACK \n";
    out<<"\nCHOICE??: ";
    std::cin >> input;
    menu_option = input;
    std::cin.ignore(100, '\n');
}

/**
  * Snake menu Selection
  */
void Reptrack::group_selection()
{
    tooltime.clear_screen(std::cout, 100);
    if(menu_option == '1')
    {
        std::string input;
        std::cout<<"Group Name??: ";
        std::cin >> input;
        std::cin.ignore(100,'\n');

        Group* viper = new Group(input);
        groups.push_back(*viper);
        viper = nullptr;

        std::ofstream group_publisher;
        group_publisher.open("/home/tim/code/reptrack/data/group_data.txt");
        Cobra c1([&]{publish_groups(group_publisher);});
        c1.join();
        group_publisher.close();
    }
    if(menu_option == '2')
    {

    }
    if(menu_option == '3')
    {
        Cobra c1([&]{publish_groups(std::cout);});
        c1.join();
    }
    if(menu_option == '4')
    {

    }
    if(menu_option == '5') okay = false;
}

/**
  * load data from files
  */
void Reptrack::load_data()
{
    std::ifstream group_data;
    group_data.open("/home/tim/code/reptrack/data/group_data.txt");
    Cobra c1([&]{gather_groups(group_data);});
    c1.join();
    group_data.close();
}

/**
  * gather groups from data file
  */
void Reptrack::gather_groups(std::ifstream& in)
{
    char* line_checker;
    in.getline(line_checker, 200, '\n');
    
    std::string line_string;
    for(int i=0;i<line_string.length();i++)
    {
        line_string += line_checker[i];
    }

    if(line_string == tooltime.print_line('#', 100))
    {
        Group group;

        while(in >> group)
        {
            Group* viper = new Group(group);
            groups.push_back(*viper);
            viper = nullptr;
        }
    }
}

/**
  * publish snakes to data file
  */
void Reptrack::publish_groups(std::ostream& out)
{
    tooltime.blank_line(out);
    tooltime.print_line('#', 100, out);
    tooltime.blank_line(out);    

    std::list<Group>::iterator group_iterator;
    group_iterator = groups.begin();

    while(group_iterator!=groups.end())
    {   
        out << *group_iterator;
        group_iterator++;
    }

    tooltime.blank_line(out);
    tooltime.print_line('#', 100, out);
    tooltime.blank_line(out);    
}

