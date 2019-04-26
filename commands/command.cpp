#include "command.h"

Command::Command(){}

Command::Command(QList<QByteArray> args){
    this->_args = args;
}

Command::~Command(){}
