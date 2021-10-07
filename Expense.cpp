#include "Expense.h"

void Expense::setIdExpense(int newIdExpense)
{
    idExpense=newIdExpense;
}

int Expense::getIdExpense()
{
    return idExpense;
}
bool Expense::compareExpenses (Expense* i,Expense* j)
{
    return i->getDate() < j->getDate();
}
