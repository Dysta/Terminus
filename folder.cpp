#include "folder.h"

Folder::Folder(QString name, Folder* parent) :
    _name(name), _parent(parent)
{

}

QList<Folder *> Folder::children() const
{
    return _children;
}

QList<File *> Folder::files() const
{
    return _files;
}

QString Folder::getName() const
{
    return _name;
}

Folder *Folder::getParent() const
{
    return _parent;
}

void Folder::setParent(Folder *parent)
{
    _parent = parent;
}

void Folder::addChild(Folder *child){
    this->_children.append(child);
}

void Folder::addFile(File * file){
    this->_files.append(file);
}

void Folder::removeFile(File *file){
    bool isDeleted = false;
    for (int i = 0; i < this->files().size(); i++){
        if (this->files().at(i)->getName() == file->getName()){
            this->_files.removeAt(i);
            isDeleted = true;
        }
    }
    if (!isDeleted){
        qDebug() << "file not found\n";
    }
}
