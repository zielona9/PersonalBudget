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
    string date;
    int idFinance;
public:

    struct sortByDate
    {
        inline bool operator() (Finance& firstDate, Finance& secondDate)
        {
            return (firstDate.getDate() < secondDate.getDate());
        }
    };
    void setIdUser(int newIdUser);
    void setValue(double newValue);
    void setCategory(string newCategory);
    void setDate(string newDate);
    void setIdFinance(int newIdFinance);
    int getIdFinance();
    int getIdUser();
    double getValue();
    string getCategory();
    string getDate();
};
#endif
