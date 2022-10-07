#ifndef APPINIT_H
#define APPINIT_H

#include <QObject>

class AppInit : public QObject
{
    Q_OBJECT
public:
    static AppInit *Instance();
    explicit AppInit(QObject *parent = 0);

protected:
    bool eventFilter(QObject *obj, QEvent *evt);

private:
    static AppInit *self;

    bool isok = false;

public slots:
    bool start();
    void initStyle();

};

#endif // APPINIT_H
