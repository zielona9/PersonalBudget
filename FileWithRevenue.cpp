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
    xml.AddElem("IdUser",SupportingMethods().convertIntToString(revenue.getIdUser()));
    xml.IntoElem();
    xml.AddElem("IdRevenue",SupportingMethods().convertIntToString(revenue.getIdRevenue()));
    xml.IntoElem();
    xml.AddElem("Value",SupportingMethods().convertIntToString(revenue.getValue()));
    xml.AddElem("Category",revenue.getCategory());
    xml.AddElem("Date",revenue.getDate());

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
    int idUserFromFile;
    while(xml.FindElem("Revenue"))
    {
         xml.FindChildElem( "IdUser" );
        idUserFromFile=SupportingMethods().convertStringToInt(xml.GetChildData());
        if(userId==idUserFromFile)
       {
            revenue.setIdUser(idUserFromFile);
            xml.FindChildElem( "IdRevenue" );
            revenue.setIdRevenue(SupportingMethods().convertStringToInt(xml.GetChildData()));
            xml.FindChildElem( "Value" );
            revenue.setValue(SupportingMethods().convertStringValueToDouble(xml.GetChildData()));
            xml.FindChildElem( "Category" );
            revenue.setCategory(xml.GetChildData());
            xml.FindChildElem( "Date" );
            revenue.setDate(SupportingMethods().convertStringToInt(xml.GetChildData()));
        }
        revenues.push_back(revenue);
    }

    return revenues;
}
int FileWithRevenue::getIdOfLastIdRevenue()
{
    CMarkup xml;
    int idRevenue;
    int idOfLastIdRevenue=0;
    bool fileExists=xml.Load("incomes.xml");
    xml.ResetPos(); // top of document

    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("Revenue"))
    {

        xml.FindChildElem( "IdRevenue" );

        idRevenue=SupportingMethods().convertStringToInt(xml.GetChildData());
            if(idOfLastIdRevenue<idRevenue)
                idOfLastIdRevenue=idRevenue;

    }
    return idOfLastIdRevenue;
}
