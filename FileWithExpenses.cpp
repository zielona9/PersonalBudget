#include "FileWithExpenses.h"

void FileWithExpenses::addExpenseToFile(Finance expense)
{
    addFinanceToFile(expense);
}

vector <Finance> FileWithExpenses::getExpensesFromFile(int userId)
{
    vector <Finance> expenses;
    Expense expense;
    expenses=getFinancesFromFile(userId);
    return expenses;
}
int FileWithExpenses::getIdOfLastIdExpense()
{
    CMarkup xml;
    int idExpense;
    int idOfLastIdExpense=0;
    bool fileExists=xml.Load(getNameFile());

    idOfLastIdExpense=getLastIdInFile();

    return idOfLastIdExpense;
}
