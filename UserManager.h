#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include "User.h"
#include "SupportingMethods.h"
using namespace std;

class UserManager
{
    int idOfLoggedInUser;
    vector <User> users;

    bool ifLoginExists(string login);
    int getNewUserId();
    User enterNewUserDetails();
public:
    //UserManager();
    bool ifUserIsLoggedIn();
    void userRegistration();
    int userLogin ();
    //void listAllUsers();
   // void changePasswordOfLoggedInUser();
   // void setIdOfLoggedInUser();
    void userLogout();
   // int getIdOfLoggedInUser();
    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();

};
#endif
