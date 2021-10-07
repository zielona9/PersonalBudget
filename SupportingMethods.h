#ifndef SUPPORTINGMETHODS_H
#define SUPPORTINGMETHODS_H
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include "Date.h"

using namespace std;

class SupportingMethods
{
    public:
  static char loadCharacter();
  static string loadLine();
  static int convertStringToInt(string number);
  static string convertIntToString(int number);
  static string convertDateToString(Date date);
  static int convertDateToInt(Date date);
  static Date convertIntToDate(int dateInt);
  static Date convertStringToDate(string dateString);
  //static string changeComaToDotInDouble(string number);
  static bool verifyThatIsNumber(string &number);
  static double convertStringValueToDouble(string number);
  static string convertDoubleToString(double number);
};

#endif
