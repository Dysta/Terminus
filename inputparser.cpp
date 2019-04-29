#include "inputparser.h"

InputParser::InputParser() {

}

void InputParser::parse(QByteArray buffer, int htmlSize){
    QByteArray bufferTmp = buffer.right(buffer.size() - htmlSize);
    QByteArray cmdTmp;
    QByteArray argTmp;
    bool isArg = false;
    bool nextArg = false;
    bool isFlag = false;
    this->_cmd.clear();
    this->_args.clear();
    this->_flags.clear();

    if (!bufferTmp.contains(' ')){
        this->_cmd = bufferTmp;
    }
    else {
        for (int i = 0; i < bufferTmp.size(); i++){
            if (bufferTmp[i] == ' ' && !isArg) isArg = true;
            if (bufferTmp[i] == '-' && !isFlag){
                isArg = false;
                isFlag = true;
            }
            if (!isArg && !isFlag){
                cmdTmp.append(bufferTmp[i]);
            }


            if (isArg){
                if (bufferTmp[i] != ' '){
                    argTmp.append(bufferTmp[i]);
                }

                if ((i == bufferTmp.length() - 1 || bufferTmp[i] == ' ') && !argTmp.isEmpty()){
                    this->_args.append(argTmp);
                    argTmp.clear();
                }

            }
            else if (isFlag && bufferTmp[i] != '-') {
                QByteArray flagTmp;
                flagTmp.append('-');
                flagTmp.append(bufferTmp[i]);
                this->_flags.append(flagTmp);
            }


        }
        if (!cmdTmp.isNull()) this->_cmd = cmdTmp;
    }

    this->prepareCommand();

    qDebug() << "cmd :" << this->_cmd;

    for (int i = 0; i < this->_flags.size(); i++){
        qDebug() << "flag :" << this->_flags[i];
    }
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
    } else if (this->_cmd == "exit") {
        qDebug() << "exit cmd : close windows";

    } else if (this->_cmd == "cat") {
        if (!this->_args.isEmpty())
            this->_command = new Cat(this->_args);
    } else {
        qDebug() << "unknow command";
    }

}

Command *InputParser::getCommand() const
{
    return _command;
}
