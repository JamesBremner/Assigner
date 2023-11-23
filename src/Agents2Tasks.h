#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <chrono>

typedef std::chrono::system_clock::time_point timepoint_t;

class cSlot;

void readfile(
    const std::string &fname);

void readstring(
    const std::string &sin);

bool unitTest();

std::string specText();

void writefile( const std::string& fname );

#include "cTask.h"
#include "cAgent.h"
#include "cAssign.h"
#include "cSlot.h"

