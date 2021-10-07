#include "FinancesManager.h"



int FinancesManager::addRevenue()
{
    Revenue revenue;
    char answer;
    Date date;
    string category;
    string value;
    DateManager dateManager;
    cout<<"Does the income relate to today?[Y/N]";
    answer=SupportingMethods().loadCharacter();
    if(answer=='y'||answer=='Y')
    {
        date=dateManager.downloadCurrentDate();
    }
    else if(answer=='n'||answer=='N')
    {
        date=dateManager.downloadUserDate();
    }
    else
   {
       cout<<"No correct answer given"<<endl;
       return 0;
   }
    cout<<"What does this income relate to?";
    category=SupportingMethods().loadLine();
    revenue.setCategory(category);
    cout<<"What is the amount of income?";
    value=SupportingMethods().loadLine();
    lastIdRevenue=fileWithRevenue.getIdOfLastIdRevenue();
    revenue.setValue(SupportingMethods().convertStringValueToDouble(value));
    revenue.setIdRevenue(++lastIdRevenue);
    revenue.setIdUser(USER_ID);
    revenue.setDate(SupportingMethods().convertDateToInt(date));
    revenues.push_back(revenue);
    FileWithRevenue fileWithRevenue;
    fileWithRevenue.addRevenueToFile(revenue);
    return 1;

}
int FinancesManager::addExpense()
{
    Expense expense;
    char answer;
    Date date;
    string category;
    string value;
    DateManager dateManager;
    cout<<"Does the expense relate to today?[Y/N]";
    answer=getchar();
    cin.sync();
    cin.clear();
    if(answer=='y'||answer=='Y')
    {
        date=dateManager.downloadCurrentDate();
    }
    else if(answer=='n'||answer=='N')
    {
        date=dateManager.downloadUserDate();
    }
    else
   {
       cout<<"No correct answer given"<<endl;
       return 0;
   }
   cin.sync();
    cin.clear();
    cout<<"What does this expense relate to?";
    category=SupportingMethods().loadLine();
    expense .setCategory(category);
    cout<<"What is the amount of expense ?";
    value=SupportingMethods().loadLine();
    expense.setValue(SupportingMethods().convertStringValueToDouble(value));
    lastIdExpense=fileWithExpenses.getIdOfLastIdExpense();
    expense.setIdExpense (++lastIdExpense);
    expense.setIdUser(USER_ID);
    expense.setDate(SupportingMethods().convertDateToInt(date));
    expenses.push_back(expense);
    FileWithExpenses fileWithExpenses;
    fileWithExpenses.addExpenseToFile(expense);
    return 1;
}
void FinancesManager::listRevenue(Date dateStart, Date dateEnd)
{
    Date date;
    DateManager dateManager;
    //sort(revenues.begin(),revenues.end(),Revenue::Finance().getDate);
    for(int i=0; i<revenues.size();i++)
    {

        Date date;
        date=SupportingMethods().convertIntToDate(expenses[i].getDate());
        if(dateManager.isGivenRangeContaintGivenDate(date,dateStart,dateEnd)==true)
        {
        cout<<revenues[i].getIdRevenue()<<endl;
        cout<<revenues[i].getValue()<<endl;
        cout<<revenues[i].getCategory()<<endl;
        cout<<revenues[i].getDate()<<endl;
        }
    }

}

void FinancesManager::listExpense(Date dateStart, Date dateEnd)
{
    Date date;
    DateManager dateManager;

     sort(expenses.begin(),expenses.end(),Expense::compareExpenses);
      for(int i=0; i<expenses.size();i++)
    {

        date=SupportingMethods().convertIntToDate(expenses[i].getDate());
        if(dateManager.isGivenRangeContaintGivenDate(date,dateStart,dateEnd)==true)
        {
        cout<<expenses[i].getIdExpense()<<endl;
        cout<<expenses[i].getValue()<<endl;
        cout<<expenses[i].getCategory()<<endl;
        cout<<expenses[i].getDate()<<endl;
        }
    }

}
void FinancesManager::currentMonthBalance()
{
    DateManager dateManager;
    Date date, dateStart;
    date=dateManager.downloadCurrentDate();
    dateStart.setMonth(date.getMonth());
    dateStart.setDay(1);
    dateStart.setYear(date.getYear());
    listExpense(dateStart,date);
    listRevenue(dateStart,date);
    system("pause");
}
void FinancesManager::balanceFromPreviousMonth()
{
    DateManager dateManager;
    Date date, dateStart, dateEnd;
    date=dateManager.downloadCurrentDate();
    if(date.getMonth()!=1)
    {
        dateStart.setMonth(date.getMonth()-1);
        dateStart.setYear(date.getYear());
        dateEnd.setMonth(date.getMonth()-1);
        dateEnd.setYear(date.getYear());
    }
    else
    {
        dateStart.setMonth(12);
        dateStart.setYear(date.getYear()-1);
        dateEnd.setMonth(12);
        dateEnd.setYear(date.getYear()-1);
    }
    dateStart.setDay(1);
    dateEnd.setDay(dateManager.numberOfDaysInMonth(dateEnd.getYear(),dateEnd.getMonth()));
    listExpense(dateStart,dateEnd);
    listRevenue(dateStart,dateEnd);
    system("pause");
}

void FinancesManager::balanceForSelectedPeriod()
{
    Date dateStart, dateEnd;
    DateManager dateManager;
    cout<<"Enter the starting date of the balance sheet"<<endl;
    dateStart=dateManager.downloadUserDate();
    cout<<"Specify the end date of the balance sheet"<<endl;
    dateEnd=dateManager.downloadUserDate();
    if(dateManager.checkStartDateIsSmallerThanEndDate(dateStart,dateEnd)==true)
    {
    listExpense(dateStart,dateEnd);
    listRevenue(dateStart,dateEnd);

    }
    else
        cout<<"Dates are in the wrong order"<<endl;
    system("pause");
}
