#include "Group.h"

Group::Group()
{
    group_name ="default_group";
}

Group::Group(std::string Group_Name)
{
    group_name = Group_Name;
}

/**
  * add dates from input file
  */
void Group::add_feed_date(Date* date)
{
    feed_dates.push_back(*date);
}

/**
  * add dates from input file
  */
void Group::add_clean_date(Date* date)
{
    clean_dates.push_back(*date);
}

/**
  * add dates from input file
  */
void Group::add_water_date(Date* date)
{
    water_dates.push_back(*date);
}

void Group::display(std::ostream& out)
{
    out << group_name << "\n";
    
    std::list<Date>::iterator date_iterator;

    date_iterator = water_dates.begin();
    while(date_iterator != water_dates.end())
    {
        out << *date_iterator ;
        date_iterator++;
    }
    tooltime.print_line('$', 100, out);  

    date_iterator = feed_dates.begin();
    while(date_iterator != feed_dates.end())
    {
        out << *date_iterator ;
        date_iterator++;
    }
    tooltime.print_line('@', 100, out);

    date_iterator = clean_dates.begin();
    while(date_iterator != clean_dates.end())
    {
        out << *date_iterator ;
        date_iterator++;
    }
    tooltime.print_line('!', 100, out);
    
}
