#include "SupportingMethods.h"
char SupportingMethods::loadCharacter()
{
    string in = "";
    char character  = {0};

    while (true)
    {
        getline(cin, in);

        if (in.length() == 1)
        {
            character = in[0];
            break;
        }
        cout << "This is not a single character. Type again." << endl;
    }
    return character;
}

string SupportingMethods::loadLine()
{
    string in = "";
    getline(cin, in);
    return in;
}
string SupportingMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
int SupportingMethods::convertStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

  string SupportingMethods::convertDateToString(Date date)
  {
      string dateString;
      dateString=SupportingMethods().convertIntToString(date.getYear())+"-"+SupportingMethods().convertIntToString(date.getMonth())+"-"+SupportingMethods().convertIntToString(date.getDay());
      return dateString;
  }
  Date SupportingMethods::convertStringToDate(string dateString)
  {
      Date date;

      date.setYear(convertStringToInt(dateString.substr(0,4)));
      date.setMonth(convertStringToInt(dateString.substr(4,2)));
      date.setDay(convertStringToInt(dateString.substr(6,2)));

      return date;

  }
