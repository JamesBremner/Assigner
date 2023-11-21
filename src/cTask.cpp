#include "assigner.h"
#include "cTask.h"
#include "cAgent.h"
#include "cAssign.h"
#include "cSlot.h"

cTask *cTask::find(const std::string &name)
{
    auto it = std::find_if(
        theTasks.begin(), theTasks.end(),
        [&](cTask *pt)
        {
            return (pt->name() == name);
        });
    if (it == theTasks.end())
        return 0;
    return *it;
}

cTask *cTask::add(const std::string &name)
{
    if (find(name))
        throw std::runtime_error("25 Duplicate task name");
    theTasks.push_back(
        new cTask(name));
    return theTasks.back();
}