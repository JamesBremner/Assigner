
class cSlot
{
protected:

    static std::vector<cSlot *> theSlots;

    std::string myName;

    std::vector<cTask *> myTasks;

    std::set<int> myFamily;   // indices of family groups assigned to this slot


public:
    cSlot(const std::vector<std::string> &vtoken);

    std::string name() const
    {
        return myName;
    }

    std::string text() const;

    std::vector<cTask *>& getTasks()
    {
        return myTasks;
    }

    bool hasFamily( int family ) const;

    /// @brief get integer representation for day containing timeslot
    /// @return integer day
    ///
    /// Assumes slot name format YYYYMMDDHHMM
    /// returns int( YYYYMMDD )

    int day() const
    {
        return atoi(myName.substr(0, 8).c_str());
    }

    void assign(int iFamily)
    {
        myFamily.insert(iFamily);
    }

    static void clear()
    {
        for (auto *ps : theSlots)
            delete ps;
        theSlots.clear();
    }

    static void add(std::vector<std::string> &vtoken)
    {
        theSlots.push_back(
            new cSlot(vtoken));
    }

    static bool isSane();

    static std::vector<cSlot *>
    getAll()
    {
        return theSlots;
    }

    static std::string specText()
    {
        std::string ret;
        for (cSlot *ps : theSlots)
            ret += ps->text() + "\n";
        return ret;
    }
};
