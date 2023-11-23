#include <fstream>
#include <wex.h>

class cGUI
{
public:
    cGUI()
        : fm(wex::maker::make()),
          bnStart(wex::maker::make<wex::button>(fm)),
          bnDisplay(wex::maker::make<wex::button>(fm)),
          plDisplay(wex::maker::make<wex::panel>(fm))
    {
        // App window
        fm.move({50, 50, 400, 400});
        fm.text("A2T Starter");

        // Start button
        bnStart.move(100, 50, 200, 30);
        bnStart.text("Start A2T");
        bnStart.events().click(
            []
            {
                std::string error;
                if (wex::free::startProcess(
                        "Agents2Tasks.exe ../dat/ex10.txt console.txt",
                        error))
                {
                    wex::msgbox("ERROR starting A2T " + error);
                }
            });

        // Display button
        bnDisplay.move(100, 100, 200, 30);
        bnDisplay.text("Display Results");
        bnDisplay.events().click(
            [this]
            {
                std::ifstream ifs("console.txt");
                if (!ifs.is_open())
                {
                    wex::msgbox("ERROR no output from A2T");
                    return;
                }
                std::string text;
                char ch;
                while (ifs.get(ch))
                    text += ch;
                plDisplay.text(text);
                plDisplay.update();

            });

        // Display
        plDisplay.move(0, 150, 400, 400);
        fm.show();
        fm.run();
    }
private:
    wex::gui &fm;
    wex::button &bnStart;
    wex::button &bnDisplay;
    wex::panel &plDisplay;
};

main()
{
    cGUI theGUI;
    return 0;
}
