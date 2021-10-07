#ifndef FINANCE_H
#define FINANCE_H
#include <iostream>
#include "Date.h"

using namespace std;

class Finance
{
    int idUser;
    double value;
    string category;
    int date;
public:
    void setIdUser(int newIdUser);
    void setValue(double newValue);
    void setCategory(string newCategory);
    void setDate(int newDate);
    int getIdUser();
    double getValue();
    string getCategory();
    int getDate();
};
#endif
