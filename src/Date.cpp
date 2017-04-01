#include "Date.h"

/**
 * Default Constructor
 */
Date::Date()
{
    time = std::chrono::system_clock::now();
    time_stamp = std::chrono::system_clock::to_time_t(time);
}

/**
  * Time Constructor
  */
Date::Date(std::chrono::time_point<std::chrono::system_clock> Time)
{
    time = Time;
    time_stamp = std::chrono::system_clock::to_time_t(time);
}

/**
 * Copy Constructor
 */
Date::Date(const Date& other)
{
    this->time = other.time;
}

/**
 * Assignment Operator
 */
Date& Date::operator=(const Date& other)
{
    if(*this == other) return *this;
    this->time = other.time;
    return *this;
}

/**
 * Subtraction Operator
 */
 std::chrono::duration<long int, std::ratio<1l, 1000000000l> > Date::operator-(const Date& other)
{
    return (this->time - other.time);
}

/**
 * Less-than Operator
 */
bool Date::operator<(const Date& other)const
{
    if(this->time < other.time) return true;
    return false;
}

/**
  * Equivalence Operator
  */
bool Date::operator==(const Date& other)const
{
    if(this->time == other.time) return true;
    return false;
}

/**
 * Display Function
 */
void Date::display(std::ostream& out) const
{
    out<<std::ctime(&time_stamp);
}

/**
  * File print Function
  */
void Date::file_print(std::ostream& out, char tag) const
{  
    out << std::ctime(&time_stamp) << "\n";

    std::string printer;
    for(int i=0;i<500;i++)
    {
        printer += tag;
    }

    out << printer << "\n";
}

/**
  * 
  */
void Date::set_time_by_string(std::string time_string)
{
    
}



