#include "assigner.h"

class cSlot
{
    protected:
    static std::vector< cSlot* > theSlots;

    std::string myName;

    public:

    cSlot(  const std::string& name )
    : myName( name )
    {}

    std::string name() const
    {
        return myName;
    }

    static void clear()
    {
        for( auto* pa : theSlots )
            delete pa;
        theSlots.clear();
    }

    static void add( std::vector<std::string>& vtoken )
    {
        theSlots.push_back(
            new cSlot( vtoken[0] )); 
    }

    static std::vector< cSlot* >
    getAll()
    {
        return theSlots;
    }


};

