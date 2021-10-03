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
 xml.AddElem("IdExpense",expense.getIdExpense());
 xml.AddElem("Vallue",expense.getValue());
 xml.AddElem("Category",expense.getCategory());
 xml.AddElem("Date",SupportingMethods().convertDateToString(expense.getDate()));

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
while(xml.FindElem("Expense"))
{
     xml.FindChildElem( "IdExpense" );
    expense.setIdExpense(SupportingMethods().convertStringToInt(xml.GetChildData()));
    xml.FindChildElem( "Vallue" );
    expense.setVallue(SupportingMethods().convertStringToInt(xml.GetChildData()));
    xml.FindChildElem( "Category" );
    expense.setCategory(xml.GetChildData());
    xml.FindChildElem( "Date" );
    expense.setDate(SupportingMethods().convertStringToDate(xml.GetChildData()));

    expenses.push_back(expense);
}


return expenses;
}
