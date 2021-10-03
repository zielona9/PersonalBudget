#include "DateManager.h"

Date DateManager::downloadCurrentDate()
{
    Date date;
    SYSTEMTIME st;
    GetSystemTime(&st);
    date.setDay(st.wDay);
    date.setMonth(st.wMonth);
    date.setYear(st.wYear);
    return date;
}
Date DateManager::downloadUserDate()
{
    string userDate;
    Date date;
    do
    {
        cout<<"Enter date in format yyyy-mm-dd ";
        cin>>userDate;
    }
    while(isDateFormatCorrect(userDate)==false);

        date=SupportingMethods().convertStringToDate(userDate);

    return date;
}
bool DateManager::isThisLeapYear(int year)
{
    if((year%4==0&&year%100!=0)||year%400==0)
        return true;
    else
        return false;
}
bool DateManager::checkDateEnterCorectly(Date date)
{
    if(date.getYear()<2000)
        return false;
    else if(date.getMonth()<1||date.getMonth()>12)
        return false;
    else if(date.getDay()<1||date.getDay()>numberOfDaysInMonth(date))
        return false;
    else
        return true;
}
bool DateManager::isDateFormatCorrect(string dateString)
{
    Date date;
    for(int i=0; i<dateString.size(); i++)
    {
        if((i!=4&& i!=7 && isdigit(dateString[i])==false)||((i==4||i==7)&&dateString[i]!='-'))
        {
            cout<<"Incorrect data were entered. Please enter the date again."<<endl;
            return false;
        }
    }
    date=SupportingMethods().convertStringToDate(dateString);
    if(checkDateEnterCorectly(date)==false)
    {
        cout<<"Incorrect data were entered. Please enter the date again."<<endl;
        return false;
    }
    else
        return true;
}
int DateManager::numberOfDaysInMonth(Date date)
{
    int numberOfDays;
    switch(date.getMonth())
    {
    case 1:case 3:case 5:case 7:case 8:case 10:case 12:
        numberOfDays=31;
        break;
    case 4: case 6: case 9: case 11:
        numberOfDays=31;
        break;
    case 2:
    {
        if(isThisLeapYear(date.getYear())==true)
            numberOfDays=29;
        else
            numberOfDays=28;
        break;
    }
    }
    return numberOfDays;
}
