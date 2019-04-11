#include "file.h"

File::File(QString name, QString content)
{
    this->name = name;
    this->content = content;
}

QString File::toString(){
    return this->content;
}
