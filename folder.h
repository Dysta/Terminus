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
    Folder(QString name, Folder* = nullptr);
    void addChild(Folder *);
    void addFile(File *);
    void removeFile(File *);
    QList<Folder *> children() const;
    QList<File *> files() const;

    QString getName() const;

    Folder *getParent() const;
    void setParent(Folder *parent);

private:
    QString _name;
    Folder *_parent;
    QList<Folder *> _children;
    QList<File *> _files;
};

#endif // FOLDER_H
