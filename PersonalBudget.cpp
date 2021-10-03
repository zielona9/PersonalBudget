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
    userManager.userLogin();
    if(userManager.isUserLoggedIn())
    {
        //adresatMenedzer= new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI,uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());

    while(login==true)
      {
            choice = userManager.selectOptionFromUserMenu();
         switch (choice)
            {
            case '1':
                //
                break;
            case '2':
                //adresatMenedzer->wyszukajAdresatowPoImieniu();
                break;
            case '3':
              //adresatMenedzer->wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                 //adresatMenedzer->wyswietlWszystkichAdresatow();
                break;
            case '5':
                 // adresatMenedzer->usunAdresata();
                break;
            case '6':
                userManager.changePasswordOfLoggedInUser();
                break;
            case '7':
                userManager.userLogout();
                login=false;
                break;
            }
      }
    }
}
