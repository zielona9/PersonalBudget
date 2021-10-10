#include "TextFile.h"

string TextFile::getNameFile()
{
    return FILE_NAME;
}
int TextFile::getLastIdInFile()
{
     CMarkup xml;
        int id;
    int lastIdInFile=0;
    bool fileExists=xml.Load(getNameFile());
    xml.ResetPos();

    xml.FindElem();
    xml.IntoElem();
      while(xml.FindElem(NAME_OF_NODE))
    {

        xml.FindChildElem(NAME_OF_ID );

        id=SupportingMethods().convertStringToInt(xml.GetChildData());
            if(lastIdInFile<id)
                lastIdInFile=id;

    }
    return lastIdInFile;
}
vector <Finance> TextFile:: getFinancesFromFile(int userId)
{
     CMarkup xml;
    vector <Finance> finances;
    Finance finance;
    bool fileExists=xml.Load(getNameFile());
    xml.ResetPos(); // top of document

    xml.FindElem();
    xml.IntoElem();
    int idUserFromFile;
    while(xml.FindElem(NAME_OF_NODE))
    {
         xml.FindChildElem( "IdUser" );
        idUserFromFile=SupportingMethods().convertStringToInt(xml.GetChildData());
        if(userId==idUserFromFile)
       {
            finance.setIdUser(idUserFromFile);
            xml.FindChildElem(NAME_OF_ID);
            finance.setIdFinance(SupportingMethods().convertStringToInt(xml.GetChildData()));
            xml.FindChildElem( "Value" );
            finance.setValue(SupportingMethods().convertStringValueToDouble(xml.GetChildData()));
            xml.FindChildElem( "Category" );
            finance.setCategory(xml.GetChildData());
            xml.FindChildElem( "Date" );
            finance.setDate(xml.GetChildData());
            finances.push_back(finance);
        }

    }

    return finances;
}
void TextFile::addFinanceToFile(Finance finance)
{
    CMarkup xml;
    bool fileExists=xml.Load(getNameFile());
    if(fileExists==false)
    {
        xml.AddElem(NAME_OF_NODE+"s");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem(NAME_OF_NODE);
    xml.IntoElem();
    xml.AddElem("IdUser",SupportingMethods().convertIntToString(finance.getIdUser()));
    xml.AddElem(NAME_OF_ID,SupportingMethods().convertIntToString(finance.getIdFinance()));
    xml.AddElem("Value",SupportingMethods().convertDoubleToString(finance.getValue()));
    xml.AddElem("Category",finance.getCategory());
    xml.AddElem("Date",finance.getDate());

    xml.Save(getNameFile());
}
