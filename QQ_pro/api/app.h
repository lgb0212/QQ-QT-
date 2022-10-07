#ifndef APP_H
#define APP_H

#include "head.h"
inline void times_ms(float times)
{
    QDateTime n=QDateTime::currentDateTime();
    QDateTime now;

      do{
      now=QDateTime::currentDateTime();
      } while (n.msecsTo(now)<=times);//6为需要延时的秒数
}
enum CHCMD {
 CMD_ENNULL = 0,//状态查询
 CMD_ENGPS = 1,
 CMD_ENDC5V = 2,
 CMD_ENVER = 3,
 CMD_ENOFF = 4,
};
class App
{
public:
    static QString ConfigFile;          //配置文件文件路径及名称
    static QString fileExcel;
    static QString fimeImage;
    static QString fimeBTS;

    //软件编号
    static QString codenumber;

    //全局通用变量

    //全局布局宽度高度值
    static int RowHeight;               //行高
    static int LeftWidth;               //左边宽度
    static int RightWidth;              //右边宽度
    static int TopHeight;               //顶部高度
    static int BottomHeight;            //底部高度
    static int DeviceWidth;             //设备对象宽度
    static int DeviceHeight;            //设备对象高度

    static int BtnMinWidth;             //按钮最小宽度
    static int BtnMinHeight;            //左侧导航按钮最小高度
    static int BtnIconSize;             //按钮图标宽度高度
    static int BorderWidth;             //高亮边框宽度
    static int IconSize;                //图标字体大小
    static int IconWidth;               //图标宽度
    static int IconHeight;              //图标高度
    static int SwitchBtnWidth;          //开关按钮宽度
    static int SwitchBtnHeight;         //开关按钮高度

    //基本配置参数
    static QString LastLoginer;         //最后登录用户
    static QString LogoCn;              //软件中文名称
    static QString appCn;              //软件中文名称

    static QString LogoEn;              //软件英文名称
    static QString LogoBg;              //软件logo
    static QString Version;             //版本
    static QString Author;              //版权
    static QString StyleName;           //样式


    static QString ShutDownTime;        //关机时间


    //心跳开关配置
    static bool startheart;
    static int  timetheart;


    //升级密码
    static QString password;
    //调试密码
    static QString passwordall;

    //串口配置文件
    static QString PortNameSerial;            //串口号
    static int BaudRateSerial;                //波特率
    static int DataBitSerial;                 //数据位
    static QString ParitySerial;              //校验位
    static double StopBitSerial;              //停止位

    static bool HexSendSerial;                //16进制发送
    static bool HexReceiveSerial;             //16进制接收
    static bool DebugSerial;                  //模拟设备
    static bool AutoClearSerial;              //自动清空

    static bool AutoSendSerial;               //自动发送
    static int SendIntervalSerial;            //自动发送间隔
    static bool AutoSaveSerial;               //自动保存
    static int SaveIntervalSerial;            //自动保存间隔
    static QString SendFileName;              //发送配置文件名
    static QString DeviceFileName;            //模拟设备数据文件名




    //场强仪参数
    static QString Temp;    //温度
    static QString Deviceinfo;  //设备编号
    static QString CursorPos;  //频谱mark

    static QString comMCU;
    static QString comGPS;
    static QString comUPS;
    static QString comWTG; //用于
    static QString comPWMT; //用于

    static bool GPSEnable;
    static bool DC5VEnable;
    static bool SpeakEnable;
    static int  SpeakVolume;

    //巡线任务
    static QString taskname;
    static bool scanfBTS;
    static QString scanfBTSRange;
    static QString LineSpace;
    static bool BTSMark;
    static bool autoBTSSave;

    static QString MCUDeviceCode;
    static QString MCUDeviceVersion;

//    auto BTS_Information = new Menu(*menuLayout, "信息");
//    auto BTS_Line = new stringEntry("线路", "");
//    auto BTS_Name = new stringEntry("基站名称", "");
//    auto BTS_K = new stringEntry("公里标", "");

//    auto BTS_Number = new stringEntry("BTS编号","");
//    auto BTS_Model = new stringEntry("BTS型号","");
//    auto BTS_Factory = new stringEntry("生产厂家", "");

//    auto BTS_Freq = new stringEntry("频点号", "");
//    auto BTS_people = new stringEntry("测试人员", "");

//    auto BTS_SAVE = new MenuAction("保存");

    static int PageCount;
    static QString BTS_Information;
    static QString BTS_Line;
    static QString BTS_Name;
    static QString BTS_K;
    static QString BTS_Number;
    static QString BTS_Model;
    static QString BTS_Factory;
    static QString BTS_Freq;
    static QString BTS_people;
    static QString BTS_GPS;
    static QString BTS_Picture;
    static QString peak_Amp;
    static QString peak_Freq;
    static bool BTS_SAVE;




    static void readConfig();           //读取配置文件,在main函数最开始加载程序载入
    static void writeConfig();          //写入配置文件,在更改配置文件程序关闭时调用
    static void newConfig();            //以初始值新建配置文件
    static bool checkConfig();          //校验配置文件
};

#endif // APP_H
