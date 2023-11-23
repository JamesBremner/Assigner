#include "Agents2Tasks.h"

std::vector<cAssign *> cAssign::theAssigns;

cAssign::cAssign(cSlot *ps, cAgent *pa, cTask *pt)
    : myAgent(pa),
      myTask(pt),
      mySlot(ps),
      myGroup(0)
{
    pa->assign(ps->day());
    ps->assign(pa->family());
}

cAssign::cAssign(cSlot *ps, cAgent *pa, cTask *pt, cAgentGroup *pg)
    : cAssign(ps, pa, pt)
{
    myGroup = pg;
}

std::vector<cAssign *>
cAssign::getSlotAssigns(cSlot *slot)
{
    std::vector<cAssign *> ret;
    for (auto *a : theAssigns)
        if (a->mySlot == slot)
            ret.push_back(a);
    return ret;
}

void cAssign::add(cSlot *ps, cAgent *pa, cTask *pt)
{
    theAssigns.push_back(
        new cAssign(ps, pa, pt));
    if (pa->name().find("_group") != -1)
    {
        // assign group agent  members
        for (cAgent *pm : pa->getMembers())
            theAssigns.push_back(
                new cAssign(ps, pm, pt, (cAgentGroup *)pa));
    }
}

std::string cAssign::text(const std::string& slotName ) const
{
    std::stringstream ss;

    ss << "A " << slotName 
        <<" "<< myAgent->name();
    if (myGroup)
        ss << " in " << myGroup->name();
    ss << " to " << myTask->name();
    return ss.str();
}

std::string cAssign::text(cSlot *pSlot)
{
    std::string ret;
    for (auto *pAssign : theAssigns)
        if (pAssign->slot() == pSlot)
            ret += pAssign->text( pSlot->name() ) + "\n";
    return ret;
}

void Agents2Tasks()
{
    cAssign::clear();

    // loop over slots
    for (cSlot *slot : cSlot::getAll())
    {
        cAgent::unassignAll();

        // loop over tasks required by slot
        for (cTask *pt : slot->getTasks())
        {

            /* sort agents
            by workload first then by family
            so family gets priority
            */

            // std::cout << "before sort\n";
            // for (cAgent *pa : cAgent::getAll())
            //     std::cout << pa->name() << "\n";

            cAgent::sortAssignedCount();
            cAgent::sortFamily(slot);

            // std::cout << "after sort\n";
            // for (cAgent *pa : cAgent::getAll())
            //     std::cout << pa->name() << "\n";

            cAgent *pBestAgent = 0;

            // loop over agents
            for (cAgent *pa : cAgent::getAll())
            {
                if (pa->isAssigned())
                    continue;

                if (pa->isAssignedRecently(slot->day()))
                    continue;

                if (!pBestAgent)
                {
                    pBestAgent = pa;
                    continue;
                }
                if (pa->cost(pt) < pBestAgent->cost(pt))
                    pBestAgent = pa;
            }

            // assign best agent to task
            if (pBestAgent)
                cAssign::add(slot, pBestAgent, pt);
        }
    }
}