#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H
#include <iostream>
#include <vector>
#include "Markup.h"
#include "User.h"
#include "TextFile.h"
#include "SupportingMethods.h"
using namespace std;

class TextFile;
class FileWithUsers : public TextFile
{

public:
    FileWithUsers(string filename): TextFile(filename,"","") { };

    void addUserToFile(User user);
    void changePasswordInFile(int userId, string password);
    vector <User> getUsersFromFile();

};

#endif
