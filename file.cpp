#include "file.h"

File::File(QString name, QString content) :
    _name(name), _content(content)
{

}

QString File::toString(){
    return this->_content;
}

QString File::getName() const
{
    return _name;
}

QString File::getContent() const
{
    return _content;
}
