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
    void userLogin();
public:
    PersonalBudget()
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
