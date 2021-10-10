#ifndef TEXTNAME_H
#define TEXTNAME_H

#include <iostream>
#include <fstream>
#include <vector>

#include"SupportingMethods.h"
#include "Finance.h"
#include "Markup.h"


using namespace std;

class TextFile
{
    const string FILE_NAME;
    const string NAME_OF_ID;
    const string NAME_OF_NODE;
public:
   TextFile(string fileName,string nameOfId, string nameOfNode)
   : FILE_NAME(fileName),NAME_OF_ID(nameOfId),NAME_OF_NODE(nameOfNode) {};
    string getNameFile();
    int getLastIdInFile();
    vector <Finance> getFinancesFromFile(int userId);
    void addFinanceToFile(Finance finance);

};
#endif
