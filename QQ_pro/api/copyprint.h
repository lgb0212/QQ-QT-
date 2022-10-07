#ifndef WORDPRINT_H
#define WORDPRINT_H

#include <QThread>


class copyPrint : public QObject
{
    Q_OBJECT
public:
     static copyPrint *Instance();
     explicit copyPrint(QObject *parent = 0);
    ~copyPrint();
private slots:
     void copyfiletofile(const QString filePath , const QString toFileName);
public:

private:
    static QScopedPointer<copyPrint> self;


private:
    quint64 getDirSize(const QString filePath);
    bool copyFile(const QString &fromFIleName, const QString &toFileName);

signals:
    void copystatus(int,QString);
    void copysize(quint64);
    void copysizefile(int,int);
    void copyerror(int);
};

#endif // WORDPRINT_H
