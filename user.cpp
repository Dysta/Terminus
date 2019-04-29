#include "user.h"

User::User()
    : _name("Jarvis")
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

QString User::name() const
{
    return _name;
}

void User::setName(const QString &name)
{
    _name = name;
}
