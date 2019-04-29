#ifndef FILE_H
#define FILE_H

#include <QString>
#include <QList>
#include <iostream>
#include <QDebug>

class File
{
public:
    enum Mode {
        RD_ONLY,
        WR_ONLY,
        EX_ONLY,
        RW,
        XRW
    };

    File(QString name, QString content, int mode);
    QString toString();
    QString getName() const;
    QString getContent() const;
    int getMode() const;
    void setMode(int mode);

private:

    QString _name;
    QString _content;
    int _mode;
};

#endif // FILE_H
