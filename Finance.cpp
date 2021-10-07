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
void Finance::setDate(int newDate)
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
int Finance::getDate()
{
    return date;
}
