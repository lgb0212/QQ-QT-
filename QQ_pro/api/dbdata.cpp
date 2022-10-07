#include "dbdata.h"

//用户信息链表
int DBData::UserInfo_Count = 0;
QList<QString> DBData::UserInfo_UserName = QList<QString>();
QList<QString> DBData::UserInfo_UserPwd = QList<QString>();
QList<QString> DBData::UserInfo_UserType = QList<QString>();
QList<QString> DBData::UserInfo_UserAdmin = QList<QString>();
//端口信息表
int DBData::PortInfo_Count=0;
QList<QString> DBData::PortInfo_DeviceID = QList<QString>();
QList<QString> DBData::PortInfo_DeviceStatus = QList<QString>();

//设备信息表
int DBData::DeviceInfo_Count = 0;
QList<int> DBData::DeviceInfo_ID = QList<int>();
QList<QString> DBData::DeviceInfo_DeviceID = QList<QString>();
QList<QString> DBData::DeviceInfo_IOCOName = QList<QString>();
QList<QString> DBData::DeviceInfo_CIRName = QList<QString>();
QList<QString> DBData::DeviceInfo_CIRNumber = QList<QString>();
QList<QString> DBData::DeviceInfo_ATPName = QList<QString>();
QList<QString> DBData::DeviceInfo_ATPNumber = QList<QString>();
QList<QString> DBData::DeviceInfo_Operator = QList<QString>();
QList<QString> DBData::DeviceInfo_DeviceStatus = QList<QString>();
QList<QString> DBData::DeviceInfo_Remarks = QList<QString>();


//功率数据表
QList<float> DBData::power = QList<float>();
QList<float> DBData::zhubo = QList<float>();
QString DBData::times = QString();

QString DBData::MapPath = QString();
QList<QString> DBData::MapNames = QList<QString>();
QString DBData::SoundPath = QString();
QList<QString> DBData::SoundNames = QList<QString>();

//
QList<QString> DBData::sqlvalue1 = QList<QString>();
QList<QString> DBData::sqlvalue2= QList<QString>();
QList<QString> DBData::sqlvalue3= QList<QString>();
QList<QString> DBData::sqlvalue4= QList<QString>();
QList<QString> DBData::sqlvalue5= QList<QString>();
QList<QString> DBData::sqlvalue6= QList<QString>();
QList<QString> DBData::sqlvalue7= QList<QString>();
QList<QString> DBData::sqlvalue8= QList<QString>();
QList<QString> DBData::sqlvalue9= QList<QString>();
QList<QString> DBData::sqlvalue10= QList<QString>();

QList<bool> DBData::CIRoptions = QList<bool>();
QList<bool> DBData::LBJoptions = QList<bool>();
QList<bool> DBData::CZToptions = QList<bool>();

QList<QString> DBData::egFreq = QList<QString>();
struct DBData::SAVEDATA;

QStringList DBData::BTS_Info;
QList<QString> DBData::BTS_TaskInfo= QList<QString>();

struct DBData::BTSInformation;
struct DBData::GpsPointInfo;
