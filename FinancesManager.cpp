#include "FinancesManager.h"

Finance FinancesManager::getInformFromUser(string typeOfFinance)
{
    Finance finance;
    char answer;
    Date date;
    string category, value;
    DateManager dateManager;
    bool correctDate=true;
    do
    {
        cout<<"Does the"<<typeOfFinance<<" relate to today? [Y/N] ";
        answer=SupportingMethods().loadCharacter();
        if(answer=='y'||answer=='Y')
        {
            date=dateManager.downloadCurrentDate();
            correctDate=true;
        }
        else if(answer=='n'||answer=='N')
        {
            date=dateManager.downloadUserDate();
            correctDate=true;
        }
        else
        {
            cout<<"No correct answer given"<<endl;
            correctDate=false;
        }

    }
    while(correctDate!=true);
    cin.sync();
    cin.clear();

    cout<<"What does this "<<typeOfFinance<<" relate to?";
    category=SupportingMethods().loadLine();
    finance.setCategory(category);
    cout<<"What is the amount of "<<typeOfFinance<<" ?";
    value=SupportingMethods().loadLine();
    finance.setIdUser(USER_ID);
    finance.setDate(SupportingMethods().convertDateToString(date));
    finance.setValue(SupportingMethods().convertStringValueToDouble(value));
    return finance;
}

void FinancesManager::addRevenue()
{
    Finance revenue;

    revenue=getInformFromUser(" income ");
    lastIdRevenue=fileWithRevenue.getIdOfLastIdRevenue();
    revenue.setIdFinance(++lastIdRevenue);

    revenues.push_back(revenue);

    fileWithRevenue.addRevenueToFile(revenue);
}
void FinancesManager::addExpense()
{
    Finance expense;
    expense=getInformFromUser("expense");
    lastIdExpense=fileWithExpenses.getIdOfLastIdExpense();
    expense.setIdFinance (++lastIdExpense);

    expenses.push_back(expense);

    fileWithExpenses.addExpenseToFile(expense);
}
double FinancesManager::listRevenue(Date dateStart, Date dateEnd)
{
    Date date;
    DateManager dateManager;
    double sumRevenues=0;
    sort(revenues.begin(),revenues.end(),Finance::sortByDate());
    for(int i=0; i<revenues.size(); i++)
    {
        Date date;
        date=SupportingMethods().convertStringToDate(revenues[i].getDate());
        if(dateManager.isGivenRangeContaintGivenDate(date,dateStart,dateEnd)==true)
        {
            cout<<"IdRevenue: "<<revenues[i].getIdFinance()<<endl;
            cout<<"Value: "<<revenues[i].getValue()<<endl;
            cout<<"Category: "<<revenues[i].getCategory()<<endl;
            cout<<"Date: "<<revenues[i].getDate()<<endl;
            sumRevenues+=revenues[i].getValue();
        }
    }
    return sumRevenues;
}

double FinancesManager::listExpense(Date dateStart, Date dateEnd)
{
    Date date;
    DateManager dateManager;
    double sumExpenses=0;
    sort(expenses.begin(),expenses.end(),Finance::sortByDate());
    for(int i=0; i<expenses.size(); i++)
    {

        date=SupportingMethods().convertStringToDate(expenses[i].getDate());
        if(dateManager.isGivenRangeContaintGivenDate(date,dateStart,dateEnd)==true)
        {
            cout<<"IdExpense: "<<expenses[i].getIdFinance()<<endl;
            cout<<"Value: "<<expenses[i].getValue()<<endl;
            cout<<"Category: "<<expenses[i].getCategory()<<endl;
            cout<<"Date: "<<expenses[i].getDate()<<endl;
            sumExpenses+=expenses[i].getValue();
        }
    }
    return sumExpenses;
}
void FinancesManager::summaryOfIncomesAndExpense(Date dateStart,Date dateEnd )
{
    double sumRevenues, sumExpenses;
    sumRevenues=listRevenue(dateStart,dateEnd);
    sumExpenses=listExpense(dateStart,dateEnd);
    cout<<"Total revenue: "<<sumRevenues<<endl;
    cout<<"Total expanses: "<<sumExpenses<<endl;
    cout<<"Difference between revenue and expenses: "<<sumRevenues-sumExpenses<<endl;
}
void FinancesManager::currentMonthBalance()
{
    DateManager dateManager;
    Date date, dateStart;

    date=dateManager.downloadCurrentDate();
    dateStart.setMonth(date.getMonth());
    dateStart.setDay(1);
    dateStart.setYear(date.getYear());
    summaryOfIncomesAndExpense(dateStart,date);
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
    summaryOfIncomesAndExpense(dateStart,dateEnd);

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
        summaryOfIncomesAndExpense(dateStart,dateEnd);

    else
        cout<<"Dates are in the wrong order"<<endl;
    system("pause");
}
