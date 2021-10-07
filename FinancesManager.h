#ifndef FINANCESMANAGER_H
#define FINANCESMANAGER_H
#include <iostream>
#include <vector>
#include <cstdio>
#include<algorithm>
#include "User.h"
#include "SupportingMethods.h"
#include "FileWithUsers.h"
#include "Revenue.h"
#include "FileWithRevenue.h"
#include "Expense.h"
#include "FileWithExpenses.h"
#include "Finance.h"
#include "Date.h"
#include "DateManager.h"
#include "UserManager.h"
using namespace std;

class FinancesManager
{
    vector <Revenue> revenues;
    vector <Expense> expenses;
     const int USER_ID;
    int lastIdRevenue;
    int lastIdExpense;
    FileWithExpenses fileWithExpenses;
    FileWithRevenue fileWithRevenue;
    void listRevenue(Date dateStart, Date dateEnd);
    void listExpense(Date dateStart, Date dateEnd);
    bool isGivenRangeContaintGivenDate(Date dateGiven, Date dateStart, Date dateEnd);

public:

    FinancesManager(int userId):USER_ID(userId)
    {
    expenses=fileWithExpenses.loadExpensesFromFile(userId);
    revenues=fileWithRevenue.loadRevenuesFromFile(userId);
    }

    int addRevenue();
    int addExpense();
    void currentMonthBalance();
    void balanceFromPreviousMonth();
    void balanceForSelectedPeriod();
};
#endif
