#include "file.h"

File::File(QString name, QString content, int mode) :
    _name(name), _content(content), _mode(mode)
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

int File::getMode() const
{
    return _mode;
}

void File::setMode(int mode)
{
    if (mode > Mode::XRW || mode < Mode::RD_ONLY) return;
    _mode = mode;
}
