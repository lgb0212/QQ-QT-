#include "dbhelper.h"
#include "quiwidget.h"

#define loadfromdb true

DBHelper::DBHelper(QObject *parent) : QObject(parent)
{
}
//bool DBHelper::countSQLServer(const QString &IP,const QString &sqlname,const QString &sa,const QString &password,const QString &connName)
//{
//    QSqlDatabase dbConn;
//    dbConn = QSqlDatabase::addDatabase("QODBC");   //数据库驱动类型为SQL Server
//    dbConn.setDatabaseName(QString("DRIVER={SQL SERVER};"
//                                "SERVER=%1;" //服务器名称
//                                "DATABASE=%2;"//数据库名
//                                "UID=%3;"           //登录名
//                                "PWD=%4;"        //密码
//                                ).arg(IP) //数据库地址120.77.222.64
//                                .arg(sqlname) //数据库名称
//                                .arg(sa) //登陆的用户名
//                                .arg(password) //登陆的密码
//                                );
//    if(dbConn.open())
//        return true;
//    else
//        return false;


//}
QStringList DBHelper::getContent(const QString &tableName,
                                 const QString &columnNames,
                                 const QString &whereSql)
{
    QStringList content;
    QSqlQuery query;

    QString sql = QString("select %1 from %2 %3").arg(columnNames).arg(tableName).arg(whereSql);
    query.exec(sql);
    int columnCount = query.record().count();
    while (query.next()) {
        QStringList list;
        for (int i = 0; i < columnCount; i++) {
            list << query.value(i).toString();
        }

        content.append(list.join(";"));
    }

    return content;
}
QStringList DBHelper::getDeviceIDLog(const QString &DeviceID , const QString &IOCONumber)
{
    QSqlQuery query;
    QString sql = QString("select CIR450,CIR821,CIR866,CIRGSM_R,CIRGSM_RD,ATPzhu,ATPbeifen,SaveTime from DeviceLog where 1=1 and DeviceID='%1' and IOCONumber='%2' order by SaveTime desc").arg(DeviceID).arg(IOCONumber);
    query.exec(sql);
    int columnCount = query.record().count();
    query.next();
    QStringList list;
    for (int i = 0; i < columnCount; i++) {
        list << query.value(i).toString();
    }
    return list;
}

bool DBHelper::inputData(int columnCount,
                         const QString &filter,
                         const QString &tableName,
                         QString &fileName,
                         const QString &defaultDir)
{
    bool result = true;
    fileName = QUIHelper::getFileName(filter, defaultDir);

    if (fileName.length() != 0) {
        QFile file(fileName);

        //先读取第一行判断列数是否和目标列数一致,不一致则返回
        if (file.open(QIODevice::ReadOnly | QFile::Text)) {
            QString line = QString::fromUtf8(file.readLine());
            QStringList list = line.split(";");
            if (list.count() != columnCount) {
                return false;
            }

            file.close();
        }

        //先删除原来的数据
        QString sql = QString("delete from %1").arg(tableName);
        QSqlQuery query;
        query.exec(sql);

        if (file.open(QIODevice::ReadOnly | QFile::Text)) {
            QSqlDatabase::database().transaction();

            while(!file.atEnd()) {
                QString line = QString::fromUtf8(file.readLine());
                QStringList list = line.split(";");

                if (list.count() == columnCount) {
                    sql = QString("insert into %1 values('").arg(tableName);

                    for (int i = 0; i < columnCount - 1; i++) {
                        sql = sql + list.at(i).trimmed() + "','";
                    }

                    sql = sql + list.at(columnCount - 1).trimmed() + "')";

                    query.clear();
                    query.exec(sql);
                }
            }

            if (!QSqlDatabase::database().commit()) {
                QSqlDatabase::database().rollback();
                result = false;
            }

            file.close();
        }
    }

    return result;
}

bool DBHelper::outputData(const QString &defaultName,
                          const QString &filter,
                          const QStringList &content,
                          QString &fileName,
                          const QString &defaultDir)
{
    bool result = true;
    QString name = QString("%1/%2").arg(defaultDir).arg(defaultName);
    fileName = QUIHelper::getSaveName(filter, name);
    outputData(fileName, content);
    return result;
}

bool DBHelper::outputData(QString &fileName,
                          const QStringList &content)
{
    if (fileName.length() != 0) {
        int rowCount = content.count();
        if (rowCount == 0) {
            QUIHelper::showMessageBoxError("没有要导出的数据!", 3);
            fileName.clear();
            return false;
        }

        QFile file(fileName);
        file.open(QIODevice::WriteOnly | QFile::Text);
        QTextStream stream(&file);
        for (int i = 0; i < rowCount; i++) {
            stream << content.at(i) << "\n";
        }
    }

    return true;
}

void DBHelper::loadDeviceLog()
{
      DBData::power.clear();
      DBData::zhubo.clear();
}


void DBHelper::addDeviceLog(const QString &saveTime)
{
    QString sql = "insert into mainData(BTS_Line,BTS_Name,BTS_K,BTS_Number,BTS_Model,BTS_Factory,BTS_People,"
                  "Peak_Amp,Peak_Freq,position,picture,SaveTime) values('";
    sql += App::BTS_Line + "','";
    sql += App::BTS_Name+ "','";
    sql += App::BTS_K + "','";
    sql += App::BTS_Number + "','";
    sql += App::BTS_Model + "','";
    sql += App::BTS_Factory + "','";
    sql += App::BTS_people + "','";
    sql += App::peak_Amp + "','";
    sql += App::peak_Freq + "','";
    sql += App::BTS_GPS + "','";
    sql += App::BTS_Picture + "','";
    sql += saveTime + "')";

    QSqlQuery query;
    query.exec(sql);
}
//载入BTS任务信息
void DBHelper::loadBTSTaskLog()
{

    DBData::BTS_TaskInfo.clear();
    QSqlQuery query;
    QString sql = "select DISTINCT BTS_TASKName from BTSlog";
    query.exec(sql);
    while(query.next()) {
        QString TaskInf = query.value(0).toString();
        DBData::BTS_TaskInfo.append(TaskInf);
    }

}
//载入BTS任务信息 所有
void DBHelper:: loadBTSTaskLogall(QString task , DBData::BTS_Informations &BTS_informations)
{
    BTS_informations.BTS_Name.clear();
    BTS_informations.BTS_K.clear();
    BTS_informations.BTS_Type.clear();
    BTS_informations.BTS_Tch1.clear();
    BTS_informations.BTS_Tch2.clear();
    BTS_informations.BTS_Long.clear();
    BTS_informations.BTS_Lat.clear();
    BTS_informations.peak_Amp.clear();
    BTS_informations.peak_Freq.clear();
    BTS_informations.BTS_time.clear();

    DBData::BTS_TaskInfo.clear();
    QSqlQuery query;
    QString sql = QString("select BTS_Line,BTS_Name,BTS_Long,BTS_Lat,BTS_K,BTS_Factory,"
                          "BTS_BCCH,BTS_TCH1,BTS_TCH2,Peak_Amp,Peak_Freq,SaveTime from BTSlog where BTS_TASKName='%1'").arg(task);


    query.exec(sql);
    while(query.next()) {
             BTS_informations.BTS_Long.push_back(query.value(2).toString());
             BTS_informations.BTS_Lat.push_back(query.value(3).toString());

             BTS_informations.BTS_Name.push_back(query.value(1).toString());

             BTS_informations.BTS_K.push_back(query.value(4).toString());

             BTS_informations.BTS_Type.push_back(query.value(5).toString());

             BTS_informations.BTS_Bcch.push_back(query.value(6).toString());

             BTS_informations.BTS_Tch1.push_back(query.value(7).toString());
             BTS_informations.BTS_Tch2.push_back(query.value(8).toString());
             BTS_informations.peak_Amp.push_back(query.value(9).toString());
             BTS_informations.peak_Freq.push_back(query.value(10).toString());
             BTS_informations.BTS_time.push_back(query.value(11).toString());

//        DBData::BTS_TaskInfo.append(TaskInf);
    }

}

void DBHelper::addBTSLog(DBData::GpsPointInfo gpspointInfo,const QString &saveTime)
{


    QString sql = "insert into BTSlog(BTS_TASKName,BTS_Line,BTS_Name,BTS_Long,BTS_Lat,BTS_K,BTS_Factory,"
                  "BTS_BCCH,BTS_TCH1,BTS_TCH2,Peak_Amp,Peak_Freq,SaveTime) values('";
    sql += gpspointInfo.BTS_TASKName + "','";
    sql += gpspointInfo.BTS_Line + "','";
    sql += gpspointInfo.BTS_Name+ "','";
    sql += gpspointInfo.BTS_Long + "','";
    sql += gpspointInfo.BTS_Lat + "','";
    sql += gpspointInfo.BTS_K + "','";
    sql += gpspointInfo.BTS_Type + "','";
    sql += gpspointInfo.BTS_Bcch + "','";
    sql += gpspointInfo.BTS_Tch1 + "','";
    sql += gpspointInfo.BTS_Tch2 + "','";
    sql += gpspointInfo.peak_Amp + "','";
    sql +=gpspointInfo.peak_Freq + "','";
    sql += saveTime + "')";

    QSqlQuery query;
    query.exec(sql);


}

void DBHelper::addAlarmLog(const QString &deviceID, const QString &IOCONumber,
                           const QString &triggerValue, const QString &content, const QString &SaveTime , const QString &remark)
{
    QString sql = "insert into AlarmLog(DeviceID,IOCONumber,TriggerValue,Channel,SaveTime,Remark) values('";
    sql += deviceID + "','";
    sql += IOCONumber + "','";
    sql += triggerValue + "','";
    sql += content + "','";
    sql += SaveTime + "','";
    sql += remark + "')";
    QSqlQuery query;
    query.exec(sql);
}

void DBHelper::updateAlarmLog(const QString &deviceID, const QString &content,
                              const QString &SaveTime, const QString &remark)
{
    //找到最近的该设备该种类型报警的rowid
    QString sql = QString("select rowid from AlarmLog where DeviceID='%1' and Content='%2' order by SaveTime desc limit 1")
                  .arg(deviceID).arg(content);
    QSqlQuery query;
    query.exec(sql);
    if (query.next()) {
        QString rowid = query.value(0).toString();
        sql = QString("update AlarmLog set SaveTime='%1',Remark='%2' where rowid='%3'").arg(SaveTime).arg(remark).arg(rowid);
        query.clear();
        query.exec(sql);
    }
}
QStringList DBHelper::loadAllTables()
{
    QStringList list;
    QSqlQuery query;
    QString sql = "select name from sqlite_master where type='table' order by name;";
    query.exec(sql);
    while(query.next()) {
        QString TaskInf = query.value(0).toString();
        list.append(TaskInf);
    }
    return list;

}

