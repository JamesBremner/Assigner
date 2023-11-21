#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <wex.h>
#include "cStarterGUI.h"

#include "cTask.h"
#include "cAgent.h"
#include "cAssign.h"
#include "cSlot.h"

 std::vector< cTask* > cTask::theTasks;
 std::vector< cAgent* > cAgent::theAgents;
 std::vector< cAssign* > cAssign::theAssigns;
 std::vector< cSlot* > cSlot::theSlots;


class cGUI : public cStarterGUI
{
public:
    cGUI()
        : cStarterGUI(
              "Starter",
              {50, 50, 1000, 500}),
          lb(wex::maker::make < wex::label >(fm))
    {

        unitTest();

        lb.move(50, 50, 150, 30);
        lb.text("Unit tests passed");

        show();
        run();
    }

private:
    wex::label &lb;
};

main()
{
    cGUI theGUI;
    return 0;
}
