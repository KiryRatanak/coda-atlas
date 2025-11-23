#include "core/SwitchCase.hpp"
#include "validation/Validation.hpp"
#include "ui/LabelMenu.hpp"
#include "utils/Logger.hpp"

void inHeaderSwitch(int option)
{
    switch(option)
    {
        case 1:
            cout << "login\n";
            msgPressEnter();
            msgSuccess();
            break;

        case 2:
            cout << "request\n";
            msgPressEnter();
            msgUnsuccess();
            break;

        case 3:
            cout << "about us\n";
            msgTryAgain();
            msgPressEnter();
            break;
    }
}




void headerSwitch()
{
    int option;

    do
    {
        option = validatedNumberHeader();  // ONLY get input here

        inHeaderSwitch(option);            // RUN ACTION HERE

    } while (option != 0);
}
