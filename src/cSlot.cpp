#include "Agents2Tasks.h"

std::vector<cSlot *> cSlot::theSlots;

cSlot::cSlot(const std::vector<std::string> &vtoken)
    : myName(vtoken[1])
{
    for (int k = 2; k < vtoken.size(); k++)
    {
        cTask *pt = cTask::find(vtoken[k]);
        if (!pt)
        {
            pt = cTask::add(vtoken[k]);
        }
        myTasks.push_back(pt);
    }
}

bool cSlot::hasFamily(int family) const
{
    return (myFamily.find(family) != myFamily.end());
}

std::string cSlot::text() const
{
    std::stringstream ss;

    ss
        << "t " << myName;
    for (cTask *pt : myTasks)
        ss << " " << pt->name();

    return ss.str();
}

bool cSlot::isSane()
{

    if (!theSlots.size())
        throw std::runtime_error("22 No timeslots specified");

    /* Convert timeslot names to 64 bit integers so that their order can be checked

    While pointers to integers, or to anything else, are 64 bits long, the integers themselves are 32 bits long on 64 bit compilers.

    If 64 bit integers are required, then they have to be explicitly declared using long long or int64.

    For some discussion on this https://stackoverflow.com/q/17489857/16582
    */
    long long prev = -1;

    for (auto *slot : theSlots)
    {
        long long t = atoll(slot->name().c_str());
        if (!t)
            throw std::runtime_error("10 "
                                     "Timeslot badly formatted " +
                                     slot->name());
        if (std::to_string(t) != slot->name())
            throw std::runtime_error("17 "
                                     "timeslot overflow");
        if (prev == -1)
        {
            prev = t;
            continue;
        }
        if (prev >= t)
            throw std::runtime_error("11 "
                                     "Timeslots out of order at " +
                                     slot->name());
    }

    return true;
}