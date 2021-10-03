#include "Finance.h"

void Finance::setIdUser(int newIdUser)
{
   idUser=newIdUser;
}
void Finance::setVallue(int newVallue)
{
    vallue=newVallue;
}
void Finance::setCategory(string newCategory)
{
    category=newCategory;
}
void Finance::setDate(Date newDate)
{
    date=newDate;
}
int Finance::getIdUser()
{
    return idUser;
}
int Finance::getValue()
{
    return vallue;
}
string Finance::getCategory()
{
    return category;
}
Date Finance::getDate()
{
    return date;
}
