#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <chrono>
#include <ctime>
#include <utility>
#include "TimsTools.h"

using namespace std::rel_ops;

typedef std::chrono::time_point<std::chrono::system_clock> time_point;

class Date
{
    private:
        /**
         * wrapper for a time stamp
         */
        time_point time;
        std::time_t time_stamp;

    public:
        TimsTools tooltime;

        /**
         * Default Constructor
         */
        Date();

        /**
         * Time Constructor
         */
        Date(std::chrono::time_point<std::chrono::system_clock> Time);

        /**
         * Copy Constructor
         */
        Date(const Date& other);

        /**
         * Destructor
         */
        ~Date(){}

        /**
         * Assignment Operator
         */
        Date& operator=(const Date& other);

        /**
         * Subtraction Operator
         */
         std::chrono::duration<long int, std::ratio<1l, 1000000000l> > operator-(const Date& other);

        /**
         * Less-than Operator
         */
        bool operator<(const Date& other)const;

        /**
         * Equivalence Operator
         */
        bool operator==(const Date& other)const;

        /**
         * set time
         */
        void set_time(time_point Time){time = Time;}

        /**
         * 
         */
        void set_time_by_string(std::string time_string);

        /**
         * Display Function
         */
        void display(std::ostream& out) const;

        /**
         * File print Function
         */
        void file_print(std::ostream& out, char tag) const;
};

/**
 * Insertion Stream Operator 
 */
inline std::ostream& operator<<(std::ostream &out, Date& printer)
{
    printer.display(out);
    
    return out;
}

/**
 *  Stream Operator 
 */
inline std::istream& operator>>(std::istream &in, Date& receiver)
{    
    std::string time_string;

    in >> time_string;

    receiver.set_time_by_string(time_string);

    return in;
}


#endif //DATE_H_INCLUDED
