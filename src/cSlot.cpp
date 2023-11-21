#include "assigner.h"
#include "cTask.h"
#include "cAgent.h"
#include "cAssign.h"
#include "cSlot.h"

std::vector<cSlot *> cSlot::theSlots;

cSlot::cSlot(const std::vector<std::string> &vtoken)
    : myName(vtoken[1])
{
    for (int k = 2; k < vtoken.size(); k++)
        myTasks.push_back(cTask::find(vtoken[k]));
}

std::string cSlot::text()
{
    std::stringstream ss;

    ss
        << "t " << myName;
     for ( cTask* pt : myTasks)
        ss << " " <<  pt->name();

    return ss.str();
}