#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H
#include <iostream>
#include <vector>
#include "Markup.h"
#include "User.h"
#include "SupportingMethods.h"
using namespace std;

class FileWithUsers
{
//string FILENAME_WITH_USERS;
//string replaceUserDataWithDataLinesSeparatedByVerticalDashes(User user);
//User getUserData(string singleUserDataSeparatedByVerticalDashes);

 public:
//FileOfUsers(){
    //FILENAME_WITH_USERS="User.xml";
//}
void addUserToFile(User user);
//void saveAllUsersToFile();
vector <User> loadUsersFromFile();

};

#endif
