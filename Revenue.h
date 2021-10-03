#ifndef REVENUE_H
#define REVENUE_H
#include <iostream>
#include "Date.h"
#include "Finance.h"

using namespace std;

class Revenue : public Finance
{
private:
    int idRevenue;

public:
    void setIdRevenue(int newIdRevenue);
    int getIdRevenue();

};
#endif
