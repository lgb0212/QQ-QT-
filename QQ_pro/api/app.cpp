

#include "app.h"
#include "quiwidget.h"
QString App::LastLoginer = "admin";
QString App::LogoCn = QString::fromUtf8(app_model);
QString App::appCn = QString::fromUtf8("无线频谱分析仪");
QString App::LogoEn = "Chengdu XinYu Technology Co., Ltd.";
QString App::LogoBg = "config/XYKJ.ico";

QString App::ConfigFile = "config.ini";
QString App::fileExcel = "D:/" + App::LogoCn + "/Excel";
QString App::fimeImage = "D:/" + App::LogoCn + "/Image";
QString App::fimeBTS = "D:/" + App::LogoCn + "/BTS";
QString App::codenumber = "30112022163201";


int App::RowHeight = 25;
int App::LeftWidth = 110;
int App::RightWidth = 120;
int App::TopHeight = 25;
int App::BottomHeight = 50;
int App::DeviceWidth = 75;
int App::DeviceHeight = 35;

int App::BtnMinWidth = 70;
int App::BtnMinHeight = 55;
int App::BtnIconSize = 18;
int App::BorderWidth = 4;
int App::IconSize = 20;
int App::IconWidth = 24;
int App::IconHeight = 24;
int App::SwitchBtnWidth = 65;
int App::SwitchBtnHeight = 26;




QString App::StyleName = ":/qss/flatwhite.css";
QString App::ShutDownTime = "20分钟";

QString App::password = "86663027";
QString App::passwordall = "028-86663027";


QString App::PortNameSerial = "COM1";
int App::BaudRateSerial = 115200;
int App::DataBitSerial = 8;
QString App::ParitySerial = "无";
double App::StopBitSerial = 1;

bool App::HexSendSerial = false;
bool App::HexReceiveSerial = false;
bool App::DebugSerial = false;
bool App::AutoClearSerial = false;

bool App::AutoSendSerial = false;
int App::SendIntervalSerial = 1000;
bool App::AutoSaveSerial = false;
int App::SaveIntervalSerial = 5000;
QString App::SendFileName = "send.txt";
QString App::DeviceFileName = "device.txt";


//场强仪设备
QString App::Temp;    //温度
QString App::Deviceinfo;  //设备编号
QString App::CursorPos;   //频谱MARK
//端口号
QString App::comMCU = "COM4";
QString App::comGPS = "COM3";
QString App::comUPS = "COM5";
QString App::comWTG = "COM6";
QString App::comPWMT = "COM2";//功率计

bool App::GPSEnable = false;
bool App::DC5VEnable = false;
bool App::SpeakEnable = false;
int  App::SpeakVolume = 50;

QString App::taskname = "task 1";
bool App::scanfBTS = false;
QString App::scanfBTSRange = "20 Km";
QString App::LineSpace = "1";
bool App::BTSMark = true;
bool App::autoBTSSave = false;

QString App::MCUDeviceCode = "";
QString App::MCUDeviceVersion = "";
QString App::Version = "V2.0";
QString App::Author = QString::fromUtf8("成都新域科技有限公司");

int App::PageCount = 18;
QString App::BTS_Information = "";
QString App::BTS_Line = "";
QString App::BTS_Name = "";
QString App::BTS_K = "";
QString App::BTS_Number = "";
QString App::BTS_Model = "";
QString App::BTS_Factory = "";
QString App::BTS_Freq = "";
QString App::BTS_people = "成都新域";
QString App::BTS_GPS = "无信号";
QString App::BTS_Picture = "";
QString App::peak_Amp;
QString App::peak_Freq;
bool App::BTS_SAVE = false;


void App::readConfig()
{
    if (!checkConfig()) {
        return;
    }

    QSettings set(App::ConfigFile, QSettings::IniFormat);
    set.setIniCodec("GB2312");
    set.beginGroup("AppConfig");
    App::codenumber = set.value("codenumber", App::codenumber).toString();

    //App::LogoCn = set.value("LogoCn", App::LogoCn).toString();
    //App::LogoEn = set.value("LogoEn", App::LogoEn).toString();
    //App::LogoBg = set.value("LogoBg", App::LogoBg).toString();
    //App::Author = set.value("Author", App::Author).toString();
    App::StyleName = set.value("StyleName", App::StyleName).toString();
    App::ShutDownTime = set.value("ShutDownTime", App::ShutDownTime).toString();
    App::SpeakEnable = set.value("SpeakEnable").toBool();
    App::GPSEnable = set.value("GPSEnable").toBool();
    App::DC5VEnable = set.value("DC5VEnable").toBool();
    App::SpeakVolume = set.value("SpeakVolume").toInt();
    set.endGroup();

    set.beginGroup("ComConfig");
    App::PortNameSerial = set.value("PortNameSerial").toString();
    App::BaudRateSerial = set.value("BaudRateSerial").toInt();
    App::DataBitSerial = set.value("DataBitSerial").toInt();
    App::ParitySerial = set.value("ParitySerial").toString();
    App::StopBitSerial = set.value("StopBitSerial").toInt();

    App::comPWMT = set.value("ComPWMT").toString();

    App::HexSendSerial = set.value("HexSendSerial").toBool();
    App::HexReceiveSerial = set.value("HexReceiveSerial").toBool();
    App::DebugSerial = set.value("DebugSerial").toBool();
    App::AutoClearSerial = set.value("AutoClearSerial").toBool();

    App::AutoSendSerial = set.value("AutoSendSerial").toBool();
    App::SendIntervalSerial = set.value("SendIntervalSerial").toInt();
    App::AutoSaveSerial = set.value("AutoSaveSerial").toBool();
    App::SaveIntervalSerial = set.value("SaveIntervalSerial").toInt();

    App::SendFileName = set.value("SendFileName").toString();
    App::DeviceFileName = set.value("DeviceFileName").toString();
    set.endGroup();

    set.beginGroup("BTSConfig");
    App::BTS_Line = set.value("BTS_Line").toString();
    App::BTS_Name = set.value("BTS_Name").toString();
    App::BTS_K = set.value("BTS_K").toString();
    App::BTS_Number = set.value("BTS_Number").toString();
    App::BTS_Model = set.value("BTS_Model").toString();
    App::BTS_Factory = set.value("BTS_Factory").toString();
    App::BTS_Freq = set.value("BTS_Freq").toString();
    App::BTS_people = set.value("BTS_people").toString();


    set.endGroup();

    set.beginGroup("BTSTask");
    App::taskname = set.value("taskname").toString();
    App::scanfBTS = set.value("scanfBTS").toBool();
    App::scanfBTSRange = set.value("scanfBTSRange").toString();
    App::LineSpace = set.value("LineSpace").toString();
    App::BTSMark = set.value("BTSMark").toBool();
    App::autoBTSSave = set.value("autoBTSSave").toBool();
    set.endGroup();


}

void App::writeConfig()
{
    QSettings set(App::ConfigFile, QSettings::IniFormat);
    set.setIniCodec("GB2312");
    set.beginGroup("AppConfig");
    set.setValue("codenumber", App::codenumber);
    set.setValue("LogoCn", App::LogoCn);
    set.setValue("LogoEn", App::LogoEn);
    set.setValue("LogoBg", App::LogoBg);
    set.setValue("Author", App::Author);
    set.setValue("StyleName", App::StyleName);
    set.setValue("ShutDownTime", App::ShutDownTime);
    set.setValue("SpeakEnable", App::SpeakEnable);
    set.setValue("GPSEnable", App::GPSEnable);
    set.setValue("DC5VEnable", App::DC5VEnable);
    set.setValue("SpeakVolume", App::SpeakVolume);

    set.endGroup();



    set.beginGroup("ComConfig");
    set.setValue("PortNameSerial", App::PortNameSerial);
    set.setValue("BaudRateSerial", App::BaudRateSerial);
    set.setValue("DataBitSerial", App::DataBitSerial);
    set.setValue("ParitySerial", App::ParitySerial);
    set.setValue("StopBitSerial", App::StopBitSerial);

    set.setValue("ComPWMT", App::App::comPWMT);

    set.setValue("HexSendSerial", App::HexSendSerial);
    set.setValue("HexReceiveSerial", App::HexReceiveSerial);
    set.setValue("DebugSerial", App::DebugSerial);
    set.setValue("AutoClearSerial", App::AutoClearSerial);

    set.setValue("AutoSendSerial", App::AutoSendSerial);
    set.setValue("SendIntervalSerial", App::SendIntervalSerial);
    set.setValue("AutoSaveSerial", App::AutoSaveSerial);
    set.setValue("SaveIntervalSerial", App::SaveIntervalSerial);

    set.setValue("SendFileName", App::SendFileName);
    set.setValue("DeviceFileName", App::DeviceFileName);
    set.endGroup();

    set.beginGroup("BTSConfig");
    set.setValue("BTS_Line", App::BTS_Line);
    set.setValue("BTS_Name", App::BTS_Name);
    set.setValue("BTS_K", App::BTS_K);
    set.setValue("BTS_Number", App::BTS_Number);
    set.setValue("BTS_Model", App::BTS_Model);
    set.setValue("BTS_Factory", App::BTS_Factory);
    set.setValue("BTS_Freq", App::BTS_Freq);
    set.setValue("BTS_people", App::BTS_people);
    set.endGroup();

    set.beginGroup("BTSTask");
    set.setValue("taskname", App::taskname);
    set.setValue("scanfBTS", App::scanfBTS);
    set.setValue("scanfBTSRange", App::scanfBTSRange);
    set.setValue("LineSpace", App::LineSpace);
    set.setValue("BTSMark", App::BTSMark);
    set.setValue("autoBTSSave", App::autoBTSSave);
    set.endGroup();

}

void App::newConfig()
{
    writeConfig();
}

bool App::checkConfig()
{
    //如果配置文件大小为0,则以初始值继续运行,并生成配置文件
    QFile file(App::ConfigFile);
    if (file.size() == 0) {
        newConfig();
        return false;
    }

    //如果配置文件不完整,则以初始值继续运行,并生成配置文件
    if (file.open(QFile::ReadOnly)) {
        bool ok = true;

        while (!file.atEnd()) {
            QString line = file.readLine();
            line = line.replace("\r", "");
            line = line.replace("\n", "");
            QStringList list = line.split("=");
            if (list.count() == 2) {
                //加入配置参数不能为空判断
//                if (list.at(1) == "") {
//                    ok = false;
//                    break;
//                }
            }
        }

        if (!ok) {
            newConfig();
            return false;
        }
    } else {
        newConfig();
        return false;
    }

    return true;
}
