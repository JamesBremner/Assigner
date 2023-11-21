#include "assigner.h"
#include "cTask.h"
#include "cAgent.h"
#include "cAssign.h"
#include "cSlot.h"

void input(
    std::istream &ifs)
{
    cTask::clear();
    cAgent::clear();
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
            // allocator.addAgentGroup( vtoken );
            break;

        case 't':
            cSlot::add(vtoken);
            break;
        }
    }

    // allocator.isAgentSane();
    // allocator.isSlotSane();
    // allocator.log( allocator.textProblem() );
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
