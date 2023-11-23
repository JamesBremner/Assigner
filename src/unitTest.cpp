#include "Agents2Tasks.h"

bool unitTest()
{
    std::string utname, result, expected;

    utname = "1";
    readstring(
        "a Carol 1 A cleaner\n"
        "a Bob 1 B cleaner\n"
        "a Alice 1 C cleaner\n"
        "t 202311011000 cleaner cleaner\n");

    result = specText();

    expected =
        "a Carol 1 A cleaner\n"
        "a Bob 1 B cleaner\n"
        "a Alice 1 C cleaner\n"
        "t 202311011000 cleaner cleaner\n";
    if (expected != result)
        throw std::runtime_error(utname + " unit test failed");

    utname = "2";

    Agents2Tasks();

    result = cAssign::text(cSlot::getAll()[0]);
    expected =
        "A 202311011000 Carol to cleaner\n"
        "A 202311011000 Bob to cleaner\n";
    if (expected != result)
    {
        std::cout << result;
        throw std::runtime_error(utname + " unit test failed");
    }

    /////////////////////////////////

    utname = "even workload";
    readstring(
        "a Carol 1 C cleaner\n"
        "a Bob 1 B cleaner\n"
        "a Alice 1 A cleaner\n"
        "t 202311011000 cleaner cleaner\n"
        "t 202311011200 cleaner\n");

    Agents2Tasks();

    // Alice gets job in 2nd timeslot because she has the least workload
    result = cAssign::text(cSlot::getAll()[1]);
    expected =
        "A 202311011200 Alice to cleaner\n";
    if (expected != result)
        throw std::runtime_error(utname + " unit test failed");

    /////////////////////////////////////////////

    utname = "prefer family";
    readstring(

        "a Carol 1 A cleaner\n"
        "a Bob 1 B cleaner\n"
        "a Alice 1 A cleaner\n"
        "t 202311011000 cleaner cleaner\n");

    // give Alice a history of heavy workload
    cAgent::getAll()[2]->setPreviousTasks(10);

    Agents2Tasks();
    result = cAssign::text(cSlot::getAll()[0]);

    // Carol and Alice gets the task because
    // although Alice has a greater previous workload than Bob
    // the family group gets priority over workload
    // https://github.com/JamesBremner/Agents2Tasks/issues/21#issuecomment-1813504598

    expected = "A 202311011000 Carol to cleaner\nA 202311011000 Alice to cleaner\n";
    if (expected != result)
        throw std::runtime_error(utname + " unit test failed");

    ///////////////////////////////////////////////

    utname = "agent blocking";
    readstring(
        "a Alice 1 smith teacher cleaner\n"
        "t 202311010830 teacher cleaner\n"
        "t 202311020830 teacher cleaner\n"
        "t 202311030830 teacher cleaner\n");

    Agents2Tasks();

    result = cAssign::text(cSlot::getAll()[0]);
    expected =
        "A 202311010830 Alice to teacher\n";
    if (expected != result)
        throw std::runtime_error(utname + " unit test failed");

    // blocked from all tasks
    result = cAssign::text(cSlot::getAll()[1]);
    expected = "";
    if (expected != result)
        throw std::runtime_error(utname + " unit test failed");

    // block expired
    result = cAssign::text(cSlot::getAll()[2]);
    expected =
        "A 202311030830 Alice to teacher\n";
    if (expected != result)
        throw std::runtime_error(utname + " unit test failed");

    ///////////////////////////////////////

    utname = "Group Agent";
    readstring(
        "a Alice 1 A Cleaner\n"
        "a Bob 1 B Cleaner\n"
        "a Carol 1 C Cleaner Acolyte\n"
        "g Cleaner Alice Bob Carol\n"
        "t 202311181000 Cleaner\n");

    Agents2Tasks();

    result = cAssign::text(cSlot::getAll()[0]);
    expected = "A 202311181000 Alice_group to Cleaner\nA 202311181000 Alice in Alice_group to Cleaner\nA 202311181000 Bob in Alice_group to Cleaner\nA 202311181000 Carol in Alice_group to Cleaner\n";

    if (expected != result)
        throw std::runtime_error(utname + " unit test failed");

    return true;
}
