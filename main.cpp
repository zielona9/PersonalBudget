#include <iostream>
#include "User.h"
using namespace std;

int main()
{
    User user;
    user.setId(1);
    cout<<user.getId();
    return 0;
}
