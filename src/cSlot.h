#include "assigner.h"

class cSlot
{
protected:

    static std::vector<cSlot *> theSlots;

    std::string myName;

    std::vector<cTask *> myTasks;

public:
    cSlot(const std::vector<std::string> &vtoken);

    std::string name() const
    {
        return myName;
    }

    std::string text();

    static void clear()
    {
        for (auto *pa : theSlots)
            delete pa;
        theSlots.clear();
    }

    static void add(std::vector<std::string> &vtoken)
    {
        theSlots.push_back(
            new cSlot(vtoken));
    }

    static std::vector<cSlot *>
    getAll()
    {
        return theSlots;
    }

    static std::string specText()
    {
        std::string ret;
        for (cSlot *ps : theSlots)
            ret += ps->text();
        return ret;
    }
};
