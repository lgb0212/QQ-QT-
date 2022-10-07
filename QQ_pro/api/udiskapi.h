#ifndef UDISKAPI_H
#define UDISKAPI_H

#include <QWidget>
#ifdef Q_OS_WIN
#include <windows.h>
#include <Dbt.h>
#endif
#include <QAbstractNativeEventFilter>

class uDiskapi : public QWidget , public QAbstractNativeEventFilter
{
    Q_OBJECT
public:
    explicit uDiskapi(QWidget *parent = nullptr);
protected:
     #ifdef Q_OS_WIN
    bool nativeEventFilter(const QByteArray &eventType, void *message, long *result);
    #endif
signals:
    #ifdef Q_OS_WIN
    void sigUDiskCome(QString uDiskName);
    void sigUDiskRemove(QString uDiskName);
#endif
private:
#ifdef Q_OS_WIN
    char FirstDriveFromMask(ULONG unitmask);
#endif
};

#endif // UDISKAPI_H
