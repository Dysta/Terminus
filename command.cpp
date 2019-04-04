#include "command.h"

Command::Command(){}

Command::Command(QList<QByteArray> args){
    this->_args = args;
}

Command::~Command(){}

void Command::command_effect(){}
