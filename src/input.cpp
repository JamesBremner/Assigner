#include "Agents2Tasks.h"


void input(
    std::istream &ifs)
{
    cTask::clear();
    cAgent::clear();
    cSlot::clear();
    cAssign::clear();

    std::string line;
    while (getline(ifs, line))
    {
        std::vector<std::string> vtoken;
        std::stringstream sst(line);
        std::string a;
        while (getline(sst, a, ' '))
            if (a.length())
                vtoken.push_back(a);

        switch (line[0])
        {

        case 'a':
            cAgent::add(vtoken);
            break;

        case 'g':
            cAgentGroup::add(vtoken);
            break;

        case 't':
            cSlot::add(vtoken);
            break;
        }
    }

    cAgent::saveInputOrder();

    cAgent::isSane();
    cSlot::isSane();

}

void readfile(
    const std::string &fname)
{
    std::ifstream ifs(fname);
    if (!ifs.is_open())
        throw std::runtime_error("15 "
                                 "Cannot open input file");
    input(ifs);
}
void readstring(
    const std::string &sin)
{
    std::stringstream ins(sin);
    input(ins);
}

std::string specText()
{
    std::string ret;
    ret += cAgent::specText();
    ret += cSlot::specText();
    return ret;
}

void writefile( const std::string& fname )
{
    std::ofstream ofs( fname );
    if( ! ofs.is_open() )
            throw std::runtime_error("14 Cannot open output file");
    ofs << specText();
    for( cSlot* ps : cSlot::getAll() )
    {
        ofs << cAssign::text( ps );
    }
}
