#pragma once

class cAssign
{

    static std::vector<cAssign *> theAssigns;

    cSlot *mySlot;
    cAgent *myAgent;
    cTask *myTask;
    cAgentGroup * myGroup;

public:

    // construct assignment of single agent
    cAssign(cSlot *ps, cAgent *pa, cTask *pt);

    // construct assignment of group agent member
    cAssign(cSlot *ps, cAgent *pa, cTask *pt, cAgentGroup* pg );


    cSlot* slot() const{
        return mySlot;
    }

    /// @brief Get display text for this assignment
    /// @return 

    std::string text(const std::string& slotName) const;

    static void clear()
    {
        for (auto *pa : theAssigns)
            delete pa;
        theAssigns.clear();
    }

    /// @brief Assign agent to task in slot
    /// @param ps slot
    /// @param pa agent
    /// @param pt task

    static void add(cSlot *ps, cAgent *pa, cTask *pt);

    /// @brief Get display text for the assignments in a slot
    /// @param pSlot 
    /// @return 

    static std::string text(cSlot *pSlot);

    /// @brief get assignments in a timeslot
    /// @param slot 
    /// @return 

    static std::vector<cAssign *>
    getSlotAssigns( cSlot* slot );

};

void Agents2Tasks();
