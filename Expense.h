#ifndef EXPENSE_H
#define EXPENSE_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
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
