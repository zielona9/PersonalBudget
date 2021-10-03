#include "FileWithRevenue.h"
/*
void FileWithUsers::saveAllUsersToFile()
{
    for(int i=0; i<users.size();i++)
        addUserToFile(users[i]);
}
*/
void FileWithRevenue::addRevenueToFile(Revenue revenue)
{
    CMarkup xml;
    bool fileExists=xml.Load("incomes.xml");
    if(fileExists==false)
    {
        xml.AddElem("Revenues");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Revenue");
    xml.IntoElem();
    xml.AddElem("IdRevenue",SupportingMethods().convertIntToString(revenue.getIdRevenue()));
    xml.AddElem("Vallue",SupportingMethods().convertIntToString(revenue.getValue()));
    xml.AddElem("Category",revenue.getCategory());
    xml.AddElem("Date",SupportingMethods().convertDateToString(revenue.getDate()));

    xml.Save("incomes.xml");
}

vector <Revenue> FileWithRevenue::loadRevenuesFromFile(int userId)
{
    CMarkup xml;
    vector <Revenue> revenues;
    Revenue revenue;
    bool fileExists=xml.Load("incomes.xml");
    xml.ResetPos(); // top of document

    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("Revenue"))
    {
        xml.FindChildElem( "IdRevenue" );
       revenue.setIdRevenue(SupportingMethods().convertStringToInt(xml.GetChildData()));
        xml.FindChildElem( "Vallue" );
       revenue.setVallue(SupportingMethods().convertStringToInt(xml.GetChildData()));
        xml.FindChildElem( "Category" );
        revenue.setCategory(xml.GetChildData());
        xml.FindChildElem( "Date" );
        revenue.setDate(SupportingMethods().convertStringToDate(xml.GetChildData()));

        revenues.push_back(revenue);
    }


    return revenues;
}
