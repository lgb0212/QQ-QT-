#ifndef API_H
#define API_H

#include <QObject>

class API : public QObject
{
    Q_OBJECT
public:
    explicit API(QObject *parent = 0);


    static QString getFileName(const QString &filter, const QString &defaultDir = "", const QString &fileName = "");
    static QString getDefaultDir();

};

#endif // API_H
