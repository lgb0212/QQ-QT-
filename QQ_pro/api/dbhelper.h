#ifndef DBHELPER_H
#define DBHELPER_H

#include "quiwidget.h"
class DBData;
class DBHelper : public QObject
{
    Q_OBJECT
public:
    explicit DBHelper(QObject *parent = 0);


    //获取指定表名字段数据内容
    static QStringList getContent(const QString &tableName,
                                  const QString &columnNames,
                                  const QString &whereSql = QString());
   // static bool countSQLServer(const QString &IP, const QString &sqlname, const QString &sa, const QString &password, const QString &connName);

    static QStringList getDeviceIDLog(const QString &DeviceID , const QString &IOCONumber);
    //导入数据文件
    static bool inputData(int columnCount,
                          const QString &filter,
                          const QString &tableName,
                          QString &fileName,
                          const QString &defaultDir = QCoreApplication::applicationDirPath());
    //导出数据文件
    static bool outputData(const QString &defaultName,
                           const QString &filter,
                           const QStringList &content,
                           QString &fileName,
                           const QString &defaultDir = QCoreApplication::applicationDirPath());
    //导出数据
    static bool outputData(QString &fileName,
                           const QStringList &content);


    //载入设备数据信息
    static void loadDeviceLog();
    //载入BTS任务信息 任务名
    static void loadBTSTaskLog();


    //载入BTS任务信息 所有信息
    static void loadBTSTaskLogall(QString task,DBData::BTS_Informations &BTS_informations);
    //清空设备信息
    static void clearDeviceInfo();

    //插入设备运行记录
    static void addDeviceLog(const QString &saveTime = DATETIME);
    //插入BTS运行记录
    static void addBTSLog(DBData::GpsPointInfo gpspointInfo, const QString &saveTime = DATETIME);

    //插入设备报警记录
    static void addAlarmLog(const QString &deviceID, const QString &IOCONumber,
                            const QString &triggerValue, const QString &content, const QString &SaveTime, const QString &remark);
    //更新设备报警记录
    static void updateAlarmLog(const QString &deviceID, const QString &content,
                               const QString &SaveTime, const QString &remark);

    static QStringList loadAllTables();




};

#endif // DBHELPER_H
