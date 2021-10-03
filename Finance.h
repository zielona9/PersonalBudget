#ifndef FINANCE_H
#define FINANCE_H
#include <iostream>
#include "Date.h"

using namespace std;

class Finance
{
    int idUser;
    int vallue;
    string category;
    Date date;
public:
    void setIdUser(int newIdUser);
    void setVallue(int newVallue);
    void setCategory(string newCategory);
    void setDate(Date newDate);
    int getIdUser();
    int getValue();
    string getCategory();
    Date getDate();
};
#endif
