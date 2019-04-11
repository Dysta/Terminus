#ifndef FOLDER_H
#define FOLDER_H

#include <QString>
#include <QList>
#include <iostream>
#include <QDebug>

#include "file.h"

class Folder
{
public:
    Folder(QString name, QList<Folder*> children, QList<File *> files, Folder* parent = nullptr);
private:
    QString name;
    Folder* parent;
    QList<Folder*> children;
    QList<File *> files;
};

#endif // FOLDER_H
