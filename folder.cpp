#include "folder.h"

Folder::Folder(QString name, QList<Folder*> children, QList<File *> files, Folder* parent)
{
    this->name = name;
    this->children = children;
    this->files = files;
    this->parent = parent;
}
