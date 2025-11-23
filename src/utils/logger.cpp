#include "utils/Logger.hpp"
#include "validation/Validation.hpp"

void msgTryAgain()
{
    cout << red
         << "             ⚠️  please try again... " << reset << endl;
}

void msgSuccess()
{
    cout << green
         << "                             ✅ successfully. " << reset << endl;
}

void msgUnsuccess()
{
    cout << red
         << "                             ❌ unsuccessfully..! " << reset << endl;
}

void msgPressEnter()
{
    cout << yellow
         << "                             👍 press enter to continue... " << reset;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
};

void msgWrongPutHeader()
{
    cout << red
         << "                             ⚠️  please put 0 to 3... " << reset << endl;
         msgPressEnter();
}

void msgExitProgram()
{
    cout << green
         << "                             ✨ exit program successfully. " << reset << endl;
    msgPressEnter();
    return;
}

void msgWithoutNumber()
{
    cout << red
         << "                             ⚠️  invalid input..! please enter a number... " << reset << endl;
         msgPressEnter();
}
