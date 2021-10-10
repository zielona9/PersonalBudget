#include "FileWithRevenue.h"

void FileWithRevenue::addRevenueToFile(Finance revenue)
{
 addFinanceToFile(revenue);
}

vector <Finance> FileWithRevenue::getRevenuesFromFile(int userId)
{
    vector <Finance> revenues;
    revenues=getFinancesFromFile(userId);
    return revenues;
}

int FileWithRevenue::getIdOfLastIdRevenue()
{
    int idOfLastIdRevenue=0;
    idOfLastIdRevenue=getLastIdInFile();

    return idOfLastIdRevenue;
}
