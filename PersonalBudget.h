#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H
#include <iostream>
#include <vector>
#include "User.h"
#include "SupportingMethods.h"
#include"UserManager.h"
#include "FinancesManager.h"
using namespace std;

class PersonalBudget
{
    UserManager userManager;
    FinancesManager *financesManager;

    const string NAME_FILE_WITH_EXPENSES;
    const string NAME_FILE_WITH_REVENUE;

    void userLogin();
public:
    PersonalBudget(string fileNameWithUsers, string fileNameWithExpenses, string fileNameWithRevenue)
    :userManager(fileNameWithUsers), NAME_FILE_WITH_EXPENSES(fileNameWithExpenses), NAME_FILE_WITH_REVENUE(fileNameWithRevenue)
    {
        financesManager=NULL;
    }
    ~PersonalBudget()
    {
        delete financesManager;
        financesManager=NULL;
    }
    void selectingOptionInMainMenu();
};
#endif
