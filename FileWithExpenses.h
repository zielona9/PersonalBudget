#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H
#include <iostream>
#include <vector>
#include "Markup.h"
#include "Expense.h"
#include "SupportingMethods.h"
#include "TextFile.h"
using namespace std;
class TextFile;
class FileWithExpenses : public TextFile
{

public:
   FileWithExpenses(string filename): TextFile(filename,"IdExpense","Expense"){};
    vector <Finance> getExpensesFromFile(int userId);
    void addExpenseToFile(Finance expense);
    int getIdOfLastIdExpense();
};
#endif
