#ifndef TIMSTOOLS_H_INCLUDED
#define TIMSTOOLS_H_INCLUDED

#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#include <ctime>
#include <utility>

typedef std::chrono::time_point<std::chrono::system_clock> time_point;

class TimsTools
{
    private:
        time_point time;

    public:
        TimsTools(){};
        ~TimsTools(){};
        void sleep(int milliseconds);
        void clear_screen(std::ostream& out, int lines);
        void blank_line(std::ostream& out);
        void print_line(char filler, int length, std::ostream& out);
        std::string print_line(char filler, int length);
        std::time_t time_stamp();
};

#endif //TIMSTOOLS_H_INCLUDED
