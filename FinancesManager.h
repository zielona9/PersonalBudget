#ifndef FINANCESMANAGER_H
#define FINANCESMANAGER_H
#include <iostream>
#include <vector>
#include "User.h"
#include "SupportingMethods.h"
#include "FileWithUsers.h"
using namespace std;

class FinancesManager
{
    vector <Revenue> revenues;
    vector <Expense> expenses;

public:
    void addRevenue();
    void addExpense();
    void currentMonthBalance();
    void balanceFromPreviousMonth();
    void balanceForSelectedPeriod();
};
#endif
