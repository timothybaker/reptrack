#ifndef GROUP_H_INCLUDED
#define GROUP_H_INCLUDED

#include <list>
#include <iostream>
#include "Date.h"  
#include "TimsTools.h"

using namespace std::rel_ops;

class Group
{
    protected:
        std::string     group_name;
        std::list<Date> clean_dates;
        std::list<Date> feed_dates;
        std::list<Date> water_dates;

    public:
        TimsTools       tooltime;

        /**
         * Default Constructor
         */
        Group();

        /**
         * Command Constructor
         */
        Group(std::string Group_Name);

        /**
         * Deconsructor
         */
        ~Group(){}

        /**
          * set group name
          */
        void set_group_name(std::string Group_Name){group_name=Group_Name;}

        /**
          * add dates from input file
          */
        void add_feed_date(Date* date);

        /**
          * add dates from input file
          */
        void add_clean_date(Date* date);

        /**
          * add dates from input file
          */
        void add_water_date(Date* date);

        /**
         * Assignment Operator
         */
        Group& operator=(const Group& other){}

        /**
         * Less-than Operator
         */
        bool operator<(const Group& other)const{}

        /**
         * Equivalence Operator
         */
        bool operator==(const Group& other)const{}

        /**
         * Display Function
         */
        void display(std::ostream& out);
};

/**
 * Insertion Stream Operator 
 */
inline std::ostream& operator<<(std::ostream &out, Group& printer)
{
    printer.display(out);
    
    return out;
}

/**
 *  Stream Operator 
 */
inline std::istream& operator>>(std::istream &in, Group& receiver)
{
    char* input;
    in.getline(input, 500, '\n');
    std::string input_to_string;

        receiver.set_group_name(input);
        
        Date water_date;
        while( in >> water_date)
        {
            Date* date = new Date(water_date);
            receiver.add_water_date(date);
            date = nullptr;
        }

        Date feed_date;
        while( in >> feed_date)
        {
            Date* date = new Date(feed_date);
            receiver.add_feed_date(date);
            date = nullptr;
        }
    
        Date clean_date;
        while(in >> clean_date)
        {
            Date* date = new Date(clean_date);
            receiver.add_clean_date(date);
            date = nullptr;
        }
    

    return in;
}

#endif //GROUP_H_INCLUDED




