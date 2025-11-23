#include "validation/Validation.hpp"
#include "utils/Logger.hpp"
#include "ui/LabelMenu.hpp"
#include "core/SwitchCase.hpp"

int validatedNumberHeader()
{
    int option;

    while (true)
    {
        displayHeader();
        cin >> option;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            msgWithoutNumber();
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ONLY ONE HERE

            if (option == 0)
                return option;

            if (option != 1 && option != 2 && option != 3)
                msgWrongPutHeader();
            else
                return option;
        }
    }
}

