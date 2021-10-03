#ifndef EXPENSE_H
#define EXPENSE_H
#include <iostream>
#include"Date.h"
#include"Finance.h"

using namespace std;

class Expense:public Finance
{
    int idExpense;

public:
  void setIdExpense(int newIdExpense);
    int getIdExpense();
};
#endif
