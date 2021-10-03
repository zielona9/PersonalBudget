#ifndef DATE_H
#define DATE_H
#include <iostream>

using namespace std;

class Date
{
int year;
int month;
int day;
public:
int getYear();
int getMonth();
int getDay();
void setYear(int newYear);
void setMonth(int newMonth);
void setDay(int newDay);
};
#endif
