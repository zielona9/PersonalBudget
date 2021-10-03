#ifndef FILEWITHREVENUE_H
#define FILEWITHREVENUE_H
#include <iostream>
#include <vector>
#include "Markup.h"
#include "Revenue.h"
#include "SupportingMethods.h"
using namespace std;

class FileWithRevenue
{
public:
    vector <Revenue> loadRevenuesFromFile(int userId);
    void addRevenueToFile(Revenue revenue);
};
#endif
