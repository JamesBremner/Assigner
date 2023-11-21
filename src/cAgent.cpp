#include "assigner.h"
#include "cTask.h"
#include "cAgent.h"
#include "cAssign.h"
#include "cSlot.h"

cAgent::cAgent(const std::vector<std::string> &vtoken)
    : myName(vtoken[0])
{
}

void cAgent::add(const std::vector<std::string> &vtoken)
{
    if (std::find_if(
            theAgents.begin(), theAgents.end()
                                   [&](cAgent * pa){
                                       return pa->name == vtoken[0]}) != theAgents.end())
        throw std::runtime_error("12	Duplicate agent name");

    theAgents.push_back(
        new cAgent(vtoken));
}