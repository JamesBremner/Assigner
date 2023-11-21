#include "assigner.h"
#include "cTask.h"
#include "cAgent.h"
#include "cAssign.h"
#include "cSlot.h"

bool unitTest()
{
    std::string utname, result, expected;

    utname = "1";
    readstring(
        "a Carol 1 A cleaner\n"
        "a Bob 1 B cleaner\n"
        "a Alice 1 A cleaner\n"
        "t 202311011000 cleaner cleaner\n");

    result = specText();

    expected =
        "a Carol 1 A cleaner\n"
        "a Bob 1 B cleaner\n"
        "a Alice 1 A cleaner\n"
        "t 202311011000 cleaner cleaner";
    if( expected != result )
        throw std::runtime_error(utname + " unit test failed");

    return true;
}
