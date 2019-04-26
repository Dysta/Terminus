#include "user.h"

User::User()
{

}

User::User(QString name) :
    _name(name)
{

}

Folder *User::currentFolder() const
{
    return _currentFolder;
}

void User::setCurrentFolder(Folder *currentFolder)
{
    _currentFolder = currentFolder;
}
