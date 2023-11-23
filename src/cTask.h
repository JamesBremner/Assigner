#pragma once

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

    static cTask* add( const std::string& name );

    static std::vector< cTask* >
    getAll()
    {
        return theTasks;
    }

    static cTask* find( const std::string& name );


};

