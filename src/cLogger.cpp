#include <Windows.h>
#include <iostream>
#include <fstream>
#include "allocator.h"

#define LOGGING true

    cLogger::cLogger()
    : flog(LOGGING)
    {
        if( ! flog )
            return;
        ofs.open("a2tLog.txt");
        headline();
    }

void cLogger::headline()
{
    if (!ofs.is_open())
        throw std::runtime_error("21 Cannot open log file");

    auto start = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(start);

#define INFO_BUFFER_SIZE 32767
    char computer[INFO_BUFFER_SIZE];
    char user[INFO_BUFFER_SIZE];
    long unsigned int bufCharCount = INFO_BUFFER_SIZE;

    // Get and display the name of the computer.
    GetComputerName(computer, &bufCharCount);

    bufCharCount = INFO_BUFFER_SIZE;
    GetUserName( user, &bufCharCount );

    ofs
        << "Agents2Tasks by " << user
        << " on " << computer
        << " at " << std::ctime(&time)
        << "\n";

}
