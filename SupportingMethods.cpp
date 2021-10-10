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
bool SupportingMethods::verifyThatIsNumber(string &number)
{
    int countDot=0;
    for(int i=0; i<number.size(); i++)
    {
        if(!isdigit(number[i]))
        {
            if (number[i]==',')
            {
                number[i]='.';
                countDot++;
            }
            else if(number[i]=='.')
                countDot++;
            if(number[i]!='.'||countDot>1)
            {
                cout<<"The correct value of the number is not given."<<endl;
                return false;
            }
        }
    }
    return true;
}
string SupportingMethods::convertDoubleToString(double number)
{
    string numberString;
    numberString=to_string(number);
    numberString.erase(numberString.find(".")+3,numberString.size()-numberString.find(".")-3);
    return numberString;
}
double SupportingMethods::convertStringValueToDouble(string number)
{
    double numberDouble;

    if(verifyThatIsNumber(number)==true)
        numberDouble=stod(number);

    return numberDouble;
}

string SupportingMethods::convertDateToString(Date date)
{
    string dateString;
    string monthString;
    string dayString;
    if(date.getDay()<10)
        dayString="0"+ convertIntToString(date.getDay());
    else
        dayString= convertIntToString(date.getDay());
    if(date.getMonth()<10)
        monthString="0"+convertIntToString(date.getMonth());
    else
        monthString=convertIntToString(date.getMonth());
    dateString=convertIntToString(date.getYear())+"-"+monthString+"-"+dayString;
    return dateString;
}
Date SupportingMethods::convertStringToDate(string dateString)
{
    Date date;

    date.setYear(convertStringToInt(dateString.substr(0,4)));
    date.setMonth(convertStringToInt(dateString.substr(5,2)));
    date.setDay(convertStringToInt(dateString.substr(8,2)));

    return date;

}

