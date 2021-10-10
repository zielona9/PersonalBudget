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
    else if(date.getDay()<1||date.getDay()>numberOfDaysInMonth(date.getYear(),date.getMonth()))
        return false;
    else
        return true;
}
bool DateManager::isDateFormatCorrect(string dateString)
{
    Date date;
    if(dateString.size()!=10)
    {
        cout<<"Incorrect data were entered. Please enter the date again."<<endl;
        return false;
    }

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
int DateManager::numberOfDaysInMonth(int year, int month)
{
    int numberOfDays;
    switch(month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        numberOfDays=31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        numberOfDays=30;
        break;
    case 2:
    {
        if(isThisLeapYear(year)==true)
            numberOfDays=29;
        else
            numberOfDays=28;
        break;
    }
    }
    return numberOfDays;
}
bool DateManager::isGivenRangeContaintGivenDate(Date dateGiven, Date dateStart, Date dateEnd)
{
    if(checkStartDateIsSmallerThanEndDate(dateStart,dateGiven)==true)
    {
        if(checkStartDateIsSmallerThanEndDate(dateGiven,dateEnd)==true)
            return true;
        else
            return false;
    }
    else
        return false;
}

bool DateManager::checkStartDateIsSmallerThanEndDate(Date dateStart, Date dateEnd)
{
    if(dateStart.getYear()==dateEnd.getYear())
    {
        if(dateStart.getMonth()==dateEnd.getMonth())
        {
            if(dateStart.getDay()<=dateEnd.getDay())
                return true;
            else
                return false;
        }
        else if(dateStart.getMonth()<dateEnd.getMonth())
            return true;
        else
            return false;
    }
    else if(dateStart.getYear()<dateEnd.getYear())
        return true;
    else
        return false;
}
