#ifndef FILEWITHREVENUE_H
#define FILEWITHREVENUE_H
#include <iostream>
#include <vector>
#include "Markup.h"
#include "Revenue.h"
#include "SupportingMethods.h"
#include "TextFile.h"
using namespace std;
class TextFile;
class FileWithRevenue : public TextFile
{

public:
    FileWithRevenue(string filename): TextFile(filename,"IdRevenue","Revenue"){};
    vector <Finance> getRevenuesFromFile(int userId);
    void addRevenueToFile(Finance revenue);
    int getIdOfLastIdRevenue();
};
#endif
