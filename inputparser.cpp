#include "inputparser.h"

InputParser::InputParser(){}

void InputParser::parse(QByteArray buffer){
    QByteArray cmdTmp;
    bool isArg = false;
    bool nextArg = false;
    this->_cmd.clear();
    this->_args.clear();
    if (!buffer.contains(' ')){
        this->_cmd = buffer;
    }
    else {
        for (int i = 0; i < buffer.size(); i++){
            if (!isArg){
                if (buffer[i] == '-') isArg = true;
                else if (buffer[i] != ' ') cmdTmp.append(buffer[i]);
            }
            else{
                if (buffer[i] != '-' && buffer[i] != ' ' && nextArg) {
                    QByteArray argTmp;
                    argTmp.append('-');
                    argTmp.append(buffer[i]);
                    this->_args.append(argTmp);
                }
                else if (buffer[i] != '-' && buffer[i] != ' ' && !nextArg){
                    QByteArray argTmp;
                    argTmp.append('-');
                    argTmp.append(buffer[i]);
                    nextArg = true;
                    this->_args.append(argTmp);
                }
            }
        }
        if (!cmdTmp.isNull()) this->_cmd = cmdTmp;
    }

    this->launchCommand();
    /*
    qDebug() << "cmd :" << this->_cmd;

    for (int i = 0; i < this->_args.size(); i++){
        qDebug() << "arg :" << this->_args[i];
    }
    */
}

void InputParser::launchCommand(){

    if (this->_cmd == "ls"){
        Ls* ls_command;
        if (this->_args.isEmpty())
            ls_command = new Ls();
        else
            ls_command = new Ls(this->_args);

        ls_command->command_effect();
    }
    else {
        qDebug() << "unknown command";
    }

}
