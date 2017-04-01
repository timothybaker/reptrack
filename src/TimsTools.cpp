#include "TimsTools.h"

void TimsTools::sleep(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void TimsTools::clear_screen(std::ostream& out, int lines)
{
    out << std::string(lines, '\n');
}

void TimsTools::print_line(char filler, int length, std::ostream& out)
{
    std::string printer;
    for(int i=0;i<length;i++)
    {
        printer += filler;
    }
    out << printer << "\n";
}

std::string TimsTools::print_line(char filler, int length)
{
    std::string printer;
    for(int i=0;i<length;i++)
    {
        printer += filler;
    }

    return printer;
}

void TimsTools::blank_line(std::ostream& out)
{
    print_line(' ', 100, out);
}

std::time_t TimsTools::time_stamp()
{
    time = std::chrono::system_clock::now();
    std::time_t stamp;
    stamp = std::chrono::system_clock::to_time_t(time);

    return stamp;

}
