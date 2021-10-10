#include <iostream>
#include "User.h"
#include "PersonalBudget.h"
using namespace std;

int main()
{
   PersonalBudget personalBudget("users.xml","expenses.xml","incomes.xml");
   personalBudget.selectingOptionInMainMenu();
    return 0;
}
