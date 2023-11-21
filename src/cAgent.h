#include <string>
#include <vector>

class cAgent
{
protected:

    static std::vector<cAgent *> theAgents;

    std::string myName;

    std::vector<std::pair<cTask*, double>> myTasks;

    static std::vector<std::string> vFamily; // family group names
    int myFamily;                            // family group index

    bool myAssigned;

public:

    /// CTOR
    /// @param vtoken tokenized specification line

    cAgent(const std::vector<std::string> &vtoken);


    void assign( bool f = true )
    {
        myAssigned = f;
    }

    std::string name() const
    {
        return myName;
    }

    double cost( cTask* task ) const
    {
        return myTasks[0].second;
    }

    bool isAssigned() const
    {
        return myAssigned;
    }

    std::string text() const;

    static void clear()
    {
        for (auto *pa : theAgents)
            delete pa;
        theAgents.clear();
    }

    /// @brief Add an agent
    /// @param vtoken tokenized specification line

    static void add(const std::vector<std::string> &vtoken);

    static void unassignAll();

    static std::vector<cAgent *>
    getAll()
    {
        return theAgents;
    }

    static std::string specText();
};
