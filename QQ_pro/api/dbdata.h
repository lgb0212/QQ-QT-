#ifndef DBDATA_H
#define DBDATA_H

#include <QStringList>
#include <QImage>
#include <QLabel>

class DBData
{
public:

    //用户信息链表
    static int UserInfo_Count;
    static QList<QString> UserInfo_UserName;
    static QList<QString> UserInfo_UserPwd;
    static QList<QString> UserInfo_UserType;
    static QList<QString> UserInfo_UserAdmin;

    //端口信息表
    static int PortInfo_Count;
    static QList<QString> PortInfo_DeviceID;
    static QList<QString> PortInfo_DeviceStatus;

    //设备信息表
    static int DeviceInfo_Count;
    static QList<int> DeviceInfo_ID;
    static QList<QString> DeviceInfo_DeviceID;
    static QList<QString> DeviceInfo_IOCOName;
    static QList<QString> DeviceInfo_CIRName;
    static QList<QString> DeviceInfo_CIRNumber;
    static QList<QString> DeviceInfo_ATPName;
    static QList<QString> DeviceInfo_ATPNumber;
    static QList<QString> DeviceInfo_Operator;
    static QList<QString> DeviceInfo_DeviceStatus;
    static QList<QString> DeviceInfo_Remarks;



    static QList<float> power;
    static QList<float> zhubo;
    static QString times;

    static QString MapPath;
    static QList<QString> MapNames;
    static QString SoundPath;
    static QList<QString> SoundNames;

    //服务器数据库链表
    static QList<QString> sqlvalue1;
    static QList<QString> sqlvalue2;
    static QList<QString> sqlvalue3;
    static QList<QString> sqlvalue4;
    static QList<QString> sqlvalue5;
    static QList<QString> sqlvalue6;
    static QList<QString> sqlvalue7;
    static QList<QString> sqlvalue8;
    static QList<QString> sqlvalue9;
    static QList<QString> sqlvalue10;
    //设备选项链表
    static QList<bool> CIRoptions;
    static QList<bool> LBJoptions;
    static QList<bool> CZToptions;
    //设备常用频点
    static QList<QString> egFreq;

    static QStringList BTS_Info;

    static QList<QString> BTS_TaskInfo;     //任务列表

    struct SAVEDATA
    {
        bool issaveok;
        QString centerfrequency;    //中心频率
        QString metermodel; //测量方式

        QString value0;
        QString value1;
        QString value2;
        QString value3;
        QString value4;
        QString value5;
        QString value6;
        QString value7;
        QString value8;
        QString value9;

        QString value10;
        QString value11;
        QString value12;
        QString value13;
        QString value14;
        QString value15;
        QString value16;
        QString value17;
        QString value18;
        QString value19;
        QString value20;
        QString value21;
        QString value22;

        QString value23;
        QString value24;
        QString value25;
        QString value26;
        QString value27;
        QString value28;
        QString value29;

        QString time;

    };
    typedef struct BTSInformation
    {
         QList<QString> BTS_Line;
         QList<QString> BTS_Name;
         QList<QString> BTS_K;
         QList<QString> BTS_Number;
         QList<QString> BTS_Model;
         QList<QString> BTS_Factory;
         QList<QString> BTS_Freq;
         QList<QString> BTS_people;
         QList<QString> BTS_GPS;
         QList<QString> BTS_Picture;
         QList<QString> peak_Amp;
         QList<QString> peak_Freq;
         QList<QString> BTS_Long;      //经度
         QList<QString> BTS_Lat;       //纬度
         QList<QString> BTS_Type;      //基站类型
         QList<QString> BTS_Bcch;      //BCCH
         QList<QString> BTS_Tch1;      //TCH1
         QList<QString> BTS_Tch2;      //TCH2

         QList<QString> BTS_time;

    }BTS_Informations;
    struct GpsPointInfo {

        QString BTS_TASKName;  //任务 名
        QString BTS_Line;//任务线路
        QString BTS_Name;//  基站名
        QString BTS_K;
        QString BTS_Number;
        QString BTS_Model;
        QString BTS_Factory;
        QString BTS_people;
        QString peak_Amp;
        QString peak_Freq;
        QString BTS_LongLat;      //经度维度
        QString BTS_Long;      //经度
        QString BTS_Lat;       //纬度
        QString BTS_Type;      //基站类型
        QString BTS_Bcch;      //BCCH
        QString BTS_Tch1;      //TCH1
        QString BTS_Tch2;      //TCH2

        bool scanfBTS;
        bool isMark;          //是否标记
        QString time;         //时间

    }Gps_PointInfo;

};

#endif // DBDATA_H
