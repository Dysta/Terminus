#include "inputparser.h"

InputParser::InputParser(){}

void InputParser::parse(QByteArray buffer, int htmlSize, Folder *currendFolder){
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

    this->launchCommand(currendFolder);
    /*
    qDebug() << "cmd :" << this->_cmd;

    for (int i = 0; i < this->_args.size(); i++){
        qDebug() << "arg :" << this->_args[i];
    }
    */
}

void InputParser::launchCommand(Folder *currentFolder){

    if (this->_cmd == "ls"){
        Ls* ls_command;
        if (this->_args.isEmpty())
            ls_command = new Ls();
        else
            ls_command = new Ls(this->_args);

        ls_command->command_effect(currentFolder);
    }
    else if (this->_cmd == "cd"){
        Cd *cd_command;
        if (this->_args.isEmpty())
            cd_command = new Cd();
        else
            cd_command = new Cd(this->_args);

        cd_command->command_effect(currentFolder);
    }
    else {
        qDebug() << "unknown command";
    }

}
