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

    auto va = cAgent::getAll();
    if( va.size() != 3 )
        throw std::runtime_error(utname + " unit test failed");

    // auto vt = cTask::getAll();
    // if( vt.size() != 1 )
    //     throw std::runtime_error(utname + " unit test failed");

    auto vs = cSlot::getAll();
    if( vs.size() != 1 )
        throw std::runtime_error(utname + " unit test failed");


    return true;
}
