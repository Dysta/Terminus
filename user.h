#ifndef USER_H
#define USER_H

#include <QString>

#include "folder.h"
#include "file.h"


class User
{
public:
    User();
    User(QString name);

    Folder *currentFolder() const;
    void setCurrentFolder(Folder *currentFolder);

private:
    QString _name;

    Folder* _currentFolder;

};

#endif // USER_H
