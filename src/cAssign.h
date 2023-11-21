#include <string>
#include <vector>

class cAssign
{

    static std::vector< cAssign* > theAssigns;

    cAgent* myAgent;
    cTask* myTask;

    public:

    cAssign(  cAgent* pa, cTask* pt )
    : myAgent( pa ),
    myTask( pt )
    {}

    std::string text() const
    {
        std::stringstream ss;
        ss << myAgent->name() <<" to "<< myTask->name();
        return ss.str();
    }

        static void clear()
    {
        for( auto* pa : theAssigns )
            delete pa;
        theAssigns.clear();
    }

    static void add( cAgent* pa, cTask* pt )
    {
        theAssigns.push_back(
            new cAssign( pa, pt )); 
    }

    static std::vector< cAssign* >
    getAll()
    {
        return theAssigns;
    }


};

