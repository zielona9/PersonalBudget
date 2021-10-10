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
    UserManager(string fileNameWithUsers):fileWithUsers(fileNameWithUsers)
    {
        idOfLoggedInUser=0;
        users=fileWithUsers.getUsersFromFile();
    };
    void setIdOfLoggedInUser(int userId);
    bool isUserLoggedIn();

    void userRegistration();
    int userLogin();
    void listAllUsers();
    void changePasswordOfLoggedInUser();
    void userLogout();

    int getIdOfLoggedInUser();
    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();

};
#endif
