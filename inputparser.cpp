#include "inputparser.h"

InputParser::InputParser(){}

void InputParser::parser(QByteArray buffer){
    QByteArray cmd = "";
    QByteArray arg = "";
    bool isArg = false;
    if (!buffer.contains(' ')){
        this->_cmd = buffer;
    }
    for (int i = 0; i < buffer.size(); i++){
        if (buffer[i] == ' ') isArg = true;
        else cmd.append(buffer[i]);

        if (isArg){
            if (buffer[i] != ' ') arg.append(buffer[i]);
            else{
                this->_args.append(arg);
                arg.clear();
            }
        }

    }
}
