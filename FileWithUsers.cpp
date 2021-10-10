#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user)
{
    CMarkup xml;
    bool fileExists=xml.Load(getNameFile());
    if(fileExists==false)
    {
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId",user.getId());
    xml.AddElem("Name",user.getName());
    xml.AddElem("Surname",user.getSurname());
    xml.AddElem("Login",user.getLogin());
    xml.AddElem("Password",user.getPassword());

    xml.Save(getNameFile());
}

vector <User> FileWithUsers::getUsersFromFile()
{
    CMarkup xml;
    vector <User> users;
    User user;
    bool fileExists=xml.Load(getNameFile());
    xml.ResetPos(); // top of document

    xml.FindElem();
    xml.IntoElem();

    while(xml.FindElem("User"))
    {
        xml.FindChildElem( "UserId" );
        user.setId(SupportingMethods().convertStringToInt(xml.GetChildData()));
        xml.FindChildElem( "Name" );
        user.setName(xml.GetChildData());
        xml.FindChildElem( "Surname" );
        user.setSurname(xml.GetChildData());
        xml.FindChildElem( "Login" );
        user.setLogin(xml.GetChildData());
        xml.FindChildElem( "Password" );
        user.setPassword(xml.GetChildData());
        users.push_back(user);
    }


    return users;
}
void FileWithUsers::changePasswordInFile(int userId, string password)
{

    CMarkup xml;

    bool fileExists=xml.Load(getNameFile());
    xml.ResetPos();

    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("User"))
    {
        xml.FindChildElem( "UserId" );
        int id=SupportingMethods().convertStringToInt(xml.GetChildData());
        if(id==userId)
        {
            xml.FindChildElem("Password");
            xml.RemoveChildElem();
            xml.AddChildElem("Password",password);
            break;
        }

    }
    xml.Save(getNameFile());
}
