#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include "User.h"
#include "SupportingMethods.h"
#include "FileWithUsers.h"
using namespace std;

class UserManager
{
    int idOfLoggedInUser;
    vector <User> users;
    FileWithUsers fileWithUsers ;

    bool doesLoginExists(string login);
    int getNewUserId();
    User enterNewUserDetails();
public:
    UserManager()
    {
        idOfLoggedInUser=0;
        users=fileWithUsers.loadUsersFromFile();
    }
    bool isUserLoggedIn();
    void userRegistration();
    int userLogin();
    void listAllUsers();
   void changePasswordOfLoggedInUser();
   // void setIdOfLoggedInUser();
    void userLogout();
   // int getIdOfLoggedInUser();
    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();

};
#endif
