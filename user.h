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

    QString name() const;
    void setName(const QString &name);

private:
    QString _name;

    Folder* _currentFolder;

};

#endif // USER_H
