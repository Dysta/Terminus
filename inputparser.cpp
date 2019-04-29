#include "inputparser.h"

InputParser::InputParser() {

}

void InputParser::parse(QByteArray buffer, int htmlSize){
    QByteArray bufferTmp = buffer.right(buffer.size() - htmlSize);
    QByteArray cmdTmp;
    QByteArray argTmp;
    bool isArg = false;
    bool isFlag = false;
    this->_cmd.clear();
    this->_args.clear();

    if (!bufferTmp.contains(' ')){
        this->_cmd = bufferTmp;
    }
    else {
        for (int i = 0; i < bufferTmp.size(); i++){
            if (bufferTmp[i] == ' ' && !isArg) isArg = true;

            if (!isArg){
                cmdTmp.append(bufferTmp[i]);
            }

            else {
                if (bufferTmp[i] != ' '){
                    argTmp.append(bufferTmp[i]);
                }

                if ((i == bufferTmp.length() - 1 || bufferTmp[i] == ' ') && !argTmp.isEmpty()){
                    this->_args.append(argTmp);
                    argTmp.clear();
                }
            }
        }
        if (!cmdTmp.isNull()) this->_cmd = cmdTmp;
    }

    this->prepareCommand();

    qDebug() << "cmd :" << this->_cmd;

    for (int i = 0; i < this->_args.size(); i++){
        qDebug() << "arg :" << this->_args[i];
    }

}

void InputParser::prepareCommand(){
    if (_cmd.isNull() || _cmd.isEmpty()) return;
    this->_command = nullptr;
    if (this->_cmd == "ls"){
        if (this->_args.isEmpty())
            this->_command = new Ls();
        else
            this->_command = new Ls(this->_args);
    }
    else if (this->_cmd == "cd"){
        if (!this->_args.isEmpty())
            this->_command = new Cd(this->_args);
        else
            this->_command = new Cd();
    }
    else if (this->_cmd == "exit") {
        qDebug() << "exit cmd : close windows";

    }
    else if (this->_cmd == "cat") {
        if (!this->_args.isEmpty())
            this->_command = new Cat(this->_args);
    }
    else if (this->_cmd == "chmod") {
        if (!this->_args.isEmpty())
            this->_command = new Chmod(this->_flags);
    }
    else if (this->_cmd == "echo") {
        this->_command = new Echo(this->_args);
    }
    else if (this->_cmd == "man") {
        this->_command = new Man(this->_args);
    }
    else {
        qDebug() << "unknow command";
    }

}

Command *InputParser::getCommand() const
{
    return _command;
}
