#include "assigner.h"
#include "cTask.h"
#include "cAgent.h"
#include "cAssign.h"
#include "cSlot.h"

std::string cAssign::text(cSlot *pSlot)
{
    std::string ret;
    for (auto *pAssign : theAssigns)
        if (pAssign->slot() == pSlot)
            ret += pAssign->text() + "\n";
    return ret;
}

void assign()
{
    cAssign::clear();

    // loop over slots
    for (cSlot *slot : cSlot::getAll())
    {
        cAgent::unassignAll();

        // loop over tasks reuired by slot
        for (cTask *pt : slot->getTasks() )
        {

            cAgent *pBestAgent = 0;

            // loop over agents
            for (cAgent *pa : cAgent::getAll())
            {
                if( pa->isAssigned() )
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
            cAssign::add(slot, pBestAgent, pt);
        }
    }
}