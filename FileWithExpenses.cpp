#include "FileWithExpenses.h"
/*
void FileWithUsers::saveAllUsersToFile()
{
    for(int i=0; i<users.size();i++)
        addUserToFile(users[i]);
}
*/
void FileWithExpenses::addExpenseToFile(Expense expense)
{
    CMarkup xml;
    bool fileExists=xml.Load("expenses.xml");
    if(fileExists==false)
    {
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("IdUser",SupportingMethods().convertIntToString(expense.getIdUser()));
    xml.AddElem("IdExpense",SupportingMethods().convertIntToString(expense.getIdExpense()));
    xml.AddElem("Value",SupportingMethods().convertDoubleToString(expense.getValue()));
    xml.AddElem("Category",expense.getCategory());
    xml.AddElem("Date",expense.getDate());

    xml.Save("expenses.xml");
}

vector <Expense> FileWithExpenses::loadExpensesFromFile(int userId)
{
    CMarkup xml;
    vector <Expense> expenses;
    Expense expense;
    bool fileExists=xml.Load("expenses.xml");
    xml.ResetPos(); // top of document

    xml.FindElem();
    xml.IntoElem();
    int idUserFromFile;

    while(xml.FindElem( "Expense"))
    {
        xml.FindChildElem( "IdUser" );
        idUserFromFile=SupportingMethods().convertStringToInt(xml.GetChildData());
        if(userId==idUserFromFile)
       {
        expense.setIdUser(idUserFromFile);
        xml.FindChildElem( "IdExpense" );
        expense.setIdExpense(SupportingMethods().convertStringToInt(xml.GetChildData()));
        xml.FindChildElem( "Value" );
        expense.setValue(SupportingMethods().convertStringValueToDouble(xml.GetChildData()));
        xml.FindChildElem( "Category" );
        expense.setCategory(xml.GetChildData());
        xml.FindChildElem( "Date" );
        expense.setDate(SupportingMethods().convertStringToInt(xml.GetChildData()));
        expenses.push_back(expense);
       }

    }


    return expenses;
}
int FileWithExpenses::getIdOfLastIdExpense()
{
    CMarkup xml;
    int idExpense;
    int idOfLastIdExpense=0;
    bool fileExists=xml.Load("expenses.xml");
    xml.ResetPos(); // top of document

    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("Expense"))
    {

        xml.FindChildElem( "IdExpense" );
        idExpense=SupportingMethods().convertStringToInt(xml.GetChildData());

        if(idOfLastIdExpense<idExpense)
            idOfLastIdExpense=idExpense;

    }
    return idOfLastIdExpense;
}
