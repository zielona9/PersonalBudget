#include "UserManager.h"

char UserManager::selectOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Sign in" << endl;
    cout << "9. End of programme" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = SupportingMethods::loadCharacter();

    return choice;
}

 int UserManager::getNewUserId()
 {
     if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
 }

 char UserManager::selectOptionFromUserMenu()
 {
      char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add revenue" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Current month's balance" << endl;
    cout << "4. Balance from previous month" << endl;
    cout << "5. Balance for selected period" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice:  ";
    choice = SupportingMethods::loadCharacter();

    return choice;
 }

bool UserManager::ifLoginExists(string login)
{
   for(int i=0; i< users.size();i++)
    {
        if(users[i].getLogin()==login)
        {
            cout << endl << " There is a user with this login." << endl;
            return true;
        }

    }
    return false;
}
User UserManager::enterNewUserDetails()
{
    User user;

    user.setId(getNewUserId());
    string login, password,name,surname;
    do
    {
        cout<<"Enter your name: ";
        cin>>name;
        user.setName(name);
        cout<<"Enter your surname: ";
        cin>>surname;
        user.setSurname(surname);
        cout <<  "Enter your login:";
        cin>>login;
        user.setLogin(login);
    } while (ifLoginExists(user.getLogin()) == true);

    cout << "Enter your password: ";
    cin>>password;
    user.setPassword(password);

    return user;


}

 void UserManager::userRegistration()
 {
    User user = enterNewUserDetails();

    users.push_back(user);
    //plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Account successfully created" << endl << endl;
    system("pause");
 }
int UserManager::userLogin ()
{
    string login = "", password = "";

    cout << endl << "Enter your login";

    login = SupportingMethods().loadLine();

    for(int i=0; i< users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            for (int numberOfTrials = 3; numberOfTrials > 0; numberOfTrials--)
            {
                cout << "Enter your password. Trails remain: " << numberOfTrials << ": ";
                password = SupportingMethods().loadLine();

                if (users[i].getPassword() == password)
                {
                    cout << endl << "You have logged in" << endl << endl;
                    system("pause");
                    idOfLoggedInUser= users[i].getId();
                    return idOfLoggedInUser;
                }
            }
            cout << "Wrong password entered 3 times." << endl;
            system("pause");
            return 0;
        }

    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}
void UserManager::userLogout()
{
    idOfLoggedInUser=0;
    cout<<"Correctly logged out"<<endl;
}
