#include "PersonalBudget.h"

void PersonalBudget::selectingOptionInMainMenu()
{
    char choice;
    bool menu=true;

    while(menu)
    {
        choice = userManager.selectOptionFromMainMenu();

        switch (choice)
        {
        case '1':
            userManager.userRegistration();
            break;
        case '2':
            userLogin();
            break;
        case '3':
            userManager.listAllUsers();
            break;
        case '9':
            exit(0);
            menu=false;
            break;
        default:
            cout << endl << "There is no such option in the menu." << endl << endl;
            system("pause");
            break;
        }
    }
}

void PersonalBudget::userLogin()
{
    char choice;
    bool login=true;
    int userId;
    userId=userManager.userLogin();
    if(userManager.isUserLoggedIn())
    {
        financesManager= new FinancesManager(NAME_FILE_WITH_REVENUE,NAME_FILE_WITH_EXPENSES,userId);

        while(login==true)
        {
            choice = userManager.selectOptionFromUserMenu();
            switch (choice)
            {
            case '1':
                financesManager->addRevenue();
                break;
            case '2':
                financesManager->addExpense();
                break;
            case '3':
                financesManager->currentMonthBalance();
                break;
            case '4':
                financesManager->balanceFromPreviousMonth();
                break;
            case '5':
                financesManager->balanceForSelectedPeriod();
                break;
            case '6':
                userManager.changePasswordOfLoggedInUser();
                break;
            case '7':
                userManager.userLogout();
                delete financesManager;
                financesManager=NULL;
                login=false;
                break;
            }
            cin.clear();
            cin.sync();
        }
    }
}
