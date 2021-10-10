#include "Finance.h"

void Finance::setIdUser(int newIdUser)
{
    idUser=newIdUser;
}
void Finance::setValue(double newValue)
{
    value=newValue;
}
void Finance::setCategory(string newCategory)
{
    category=newCategory;
}
void Finance::setDate(string newDate)
{
    date=newDate;
}
int Finance::getIdUser()
{
    return idUser;
}
double Finance::getValue()
{
    return value;
}
string Finance::getCategory()
{
    return category;
}
string Finance::getDate()
{
    return date;
}
    void Finance::setIdFinance(int newIdFinance)
    {
        idFinance=newIdFinance;
    }
    int Finance::getIdFinance()
    {
        return idFinance;
    }
