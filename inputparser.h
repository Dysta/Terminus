#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <QString>
#include <QList>

class InputParser
{
public:
    InputParser();

private:
    QString _cmd;
    QList<QString> _args;


};

#endif // INPUTPARSER_H
