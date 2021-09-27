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
