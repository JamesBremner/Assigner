#include "assigner.h"
#include "cTask.h"
#include "cAgent.h"
#include "cAssign.h"
#include "cSlot.h"

std::vector<cAgent *> cAgent::theAgents;
std::vector<std::string> cAgent::vFamily;

cAgent::cAgent(const std::vector<std::string> &vtoken)
    : myName(vtoken[1]),
    myAssigned( false )
{
    // parse family

    auto it = std::find(
        vFamily.begin(), vFamily.end(), vtoken[3]);
    if (it == vFamily.end())
    {
        // new family
        vFamily.push_back(vtoken[3]);
        myFamily = vFamily.size() - 1;
    }
    else
    {
        // member of an existing family
        myFamily = it - vFamily.begin();
    }

    // parse tasks

    for (int k = 4; k < vtoken.size(); k++)
    {
        cTask *pt = cTask::find(vtoken[k]);
        if (!pt)
            cTask::add(vtoken[k]);

        myTasks.push_back(
            std::make_pair(
                cTask::find(vtoken[k]),
                atof(vtoken[2].c_str())));
    }
}


std::string cAgent::text() const
{
    std::stringstream ss;

    ss
        << "a " << myName
        << " " << myTasks[0].second
        << " " << vFamily[myFamily];

    for (auto &tp : myTasks)
    {
        ss << " " << tp.first->name();
    }
    ss << "\n";

    return ss.str();
}

void cAgent::add(const std::vector<std::string> &vtoken)
{
    if (std::find_if(
            theAgents.begin(), theAgents.end(),
            [&](cAgent *pa)
            {
                return pa->name() == vtoken[1];
            }) != theAgents.end())
        throw std::runtime_error("12	Duplicate agent name");

    theAgents.push_back(
        new cAgent(vtoken));
}

void cAgent::unassignAll()
{
    for (cAgent *pa : theAgents)
        pa->assign(false);
}

std::string cAgent::specText()
{
    std::string ret;
    for (cAgent *pa : theAgents)
        ret += pa->text();
    return ret;
}