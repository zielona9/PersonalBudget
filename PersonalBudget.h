#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H
#include <iostream>
#include <vector>
#include "User.h"
#include "SupportingMethods.h"
#include"UserManager.h"
using namespace std;

class PersonalBudget
{
    UserManager userManager;
    void userLogin();
public:
    void selectingOptionInMainMenu();
};
#endif
