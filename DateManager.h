#ifndef DATEMANAGER_H
#define DATEMANAGER_H
#include <iostream>
#include <windows.h>
#include <winbase.h>
#include "Date.h"
#include "SupportingMethods.h"
using namespace std;

class DateManager
{
    int numberOfDaysInMonth(Date date);
    bool isThisLeapYear(int year);
    bool checkDateEnterCorectly(Date date);
    bool isDateFormatCorrect(string dateString);
public:
    Date downloadCurrentDate();
    Date downloadUserDate();


};
#endif
