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
    vector <Finance> revenues;
    vector <Finance> expenses;
    const int USER_ID;
    int lastIdRevenue;
    int lastIdExpense;
    FileWithExpenses fileWithExpenses;
    FileWithRevenue fileWithRevenue;
    double listRevenue(Date dateStart, Date dateEnd);
    double listExpense(Date dateStart, Date dateEnd);
    bool isGivenRangeContaintGivenDate(Date dateGiven, Date dateStart, Date dateEnd);
    void summaryOfIncomesAndExpense(Date dateStart,Date dateEnd );
    Finance getInformFromUser(string typeOfFinance);
public:

    FinancesManager(string nameFileWithRevenues, string nameFileWithExpenses, int userId)
    :fileWithRevenue(nameFileWithRevenues),fileWithExpenses(nameFileWithExpenses),USER_ID(userId)
    {
    expenses=fileWithExpenses.getExpensesFromFile(userId);
    revenues=fileWithRevenue.getRevenuesFromFile(userId);
    }

    void addRevenue();
    void addExpense();
    void currentMonthBalance();
    void balanceFromPreviousMonth();
    void balanceForSelectedPeriod();
};
#endif
