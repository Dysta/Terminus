#include "inputparser.h"

InputParser::InputParser() {

}

void InputParser::parse(QByteArray buffer, int htmlSize){
    QByteArray bufferTmp = buffer.right(buffer.size() - htmlSize);
    QByteArray cmdTmp;
    bool isArg = false;
    bool nextArg = false;
    this->_cmd.clear();
    this->_args.clear();
    if (!bufferTmp.contains(' ')){
        this->_cmd = bufferTmp;
    }
    else {
        for (int i = 0; i < bufferTmp.size(); i++){
            if (!isArg){
                if (bufferTmp[i] == '-') isArg = true;
                else if (bufferTmp[i] != ' ') cmdTmp.append(bufferTmp[i]);
            }
            else{
                if (bufferTmp[i] != '-' && bufferTmp[i] != ' ' && nextArg) {
                    QByteArray argTmp;
                    argTmp.append('-');
                    argTmp.append(bufferTmp[i]);
                    this->_args.append(argTmp);
                }
                else if (bufferTmp[i] != '-' && bufferTmp[i] != ' ' && !nextArg){
                    QByteArray argTmp;
                    argTmp.append('-');
                    argTmp.append(bufferTmp[i]);
                    nextArg = true;
                    this->_args.append(argTmp);
                }
            }
        }
        if (!cmdTmp.isNull()) this->_cmd = cmdTmp;
    }

    this->prepareCommand();
    /*
    qDebug() << "cmd :" << this->_cmd;

    for (int i = 0; i < this->_args.size(); i++){
        qDebug() << "arg :" << this->_args[i];
    }
    */
}

void InputParser::prepareCommand(){

    if (this->_cmd == "ls"){
        if (this->_args.isEmpty())
            this->_command = new Ls();
        else
            this->_command = new Ls(this->_args);
    }
    else if (this->_cmd == "cd"){
        if (this->_args.isEmpty())
            this->_command = new Cd();
        else
            this->_command = new Cd(this->_args);
    } else {
        this->_command = nullptr;
        qDebug() << "unknow command";
    }

}

Command *InputParser::getCommand() const
{
    return _command;
}
