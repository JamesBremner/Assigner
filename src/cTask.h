#include <string>
#include <vector>

class cTask
{
    static std::vector< cTask* > theTasks;

    std::string myName;

    public:

    cTask(  const std::string& name )
    : myName( name )
    {}

    std::string name() const
    {
        return myName;
    }

    static void clear()
    {
        for( auto* pt : theTasks )
            delete pt;
        theTasks.clear();
    }

    static void add( const std::string& name )
    {
        theTasks.push_back(
            new cTask( name )); 
    }

    static std::vector< cTask* >
    getAll()
    {
        return theTasks;
    }


};

