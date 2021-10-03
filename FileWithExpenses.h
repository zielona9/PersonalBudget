#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H
#include <iostream>
#include <vector>
#include "Markup.h"
#include "Expense.h"
#include "SupportingMethods.h"
using namespace std;

class FileWithExpenses
{
public:
    vector <Expense> loadExpensesFromFile(int userId);
    void addExpenseToFile(Expense revenue);
};
#endif
