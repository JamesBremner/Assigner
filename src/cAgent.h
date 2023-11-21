#include <string>
#include <vector>

class cAgent
{
protected:

    static std::vector<cAgent *> theAgents;

    std::string myName;

    std::vector<std::pair<cTask*, double>> myTasks;

public:

    /// CTOR
    /// @param vtoken tokenized specification line

    cAgent(const std::vector<std::string> &vtoken);

    std::string name() const
    {
        return myName;
    }

    static void clear()
    {
        for (auto *pa : theAgents)
            delete pa;
        theAgents.clear();
    }

    /// @brief Add an agent
    /// @param vtoken tokenized specification line

    static void add(const std::vector<std::string> &vtoken);

    static std::vector<cAgent *>
    getAll()
    {
        return theAgents;
    }
};
