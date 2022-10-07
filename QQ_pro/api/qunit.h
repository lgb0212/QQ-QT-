#ifndef QUNIT_H
#define QUNIT_H

#include <QObject>
//工作模式枚举
enum systemwork {
    WORK_FREE = 0,        //空闲模式
    WORK_RFOUT = 1,       //发射机手动模式
    WORK_RFIN = 2,        //接收机手动模式
    WORK_CIR = 3,        //CIR自动测量
    WORK_LBJ = 4,         //LBJ自动测量
    WORK_CHE = 5,         //车站台自动测量
    WORK_ANT = 6,         //天馈线自动测量
    WORK_ANAL = 7,        //频谱分析仪模式
    WORK_LINK = 8,        //数据上传

};
//当前界面枚举
enum mywidget {
    widgetMain = 0,        //主界面
    widgetSet = 1,        //设置界面
    widgetCIR = 2,        //CIR自动测试界面
    widgetLBJ = 3,        //LBJ自动测量
    widgetCHE = 4,        //车站台自动测量
    widgetANT = 5,        //天馈线自动测量
    widgetSend = 6,        //发射机
    widgetReceiver = 7,    //接收机
    widgetAnalysis = 8,    //频谱分析仪
    widgetSql = 9,        //数据管理界面
    widgetHelp = 10,       //帮助界面

};

class Qunit : public QObject
{
    Q_OBJECT
public:
    explicit Qunit(QObject *parent = 0);
    //音频电压单位变换
    static QString toAudioVoltage(double const &Voltage);
    //音频频率单位变换
    static QString toAudioFreq(double const &Freq);

    //射频功率dbm->uV
    static QString toRfpoweruV(double const &value);
    static QString toRfpower(double const &value);
    static QString toRfFreq(double const &value);
    static QString toFMFreq(double const &value);
    static QString toFMoffsit(double const &value);


    //输入单位变换
    static QString toPowerstr(double power);
    static double toPowerW(double power);
    static QString toPowerWstr(double power);
    static double toCIRFrequency(double Freq);
    //查找最小值，并记录下标
    static void Find_minnumX(const double *in, float &min, int &x,int size);
    //查找最大值
    static void Find_max(float a[],float &max,int &p,int &size);
    static void Find_maxnum(double *in, double &max, int size);
    //删除最大最小值
    static void CIRdelete_maxmin(std::vector<double> &a,double &max,double &min,int &size);
    //删除数组中大于某个数的所有元素
    static void CIRdelete_minnum(const double *in, double *out, double num, int *size);
     //删除数组中小于等于某个数的所有元素
    static void CIRdelete_maxnum(const double *in, double *out, double num, int *size);

    //中值滤波器
    static double midFilternum(QList<double> in);
    //求数组的平均数
    static void num_avg(const double *in,double &avg, int &size);
    //遍历数组中出现次数最多的数据
    static void Maps_max(const double *in,int size, double &maxdata);



    static QString getGSMRValue_power(const float value);


signals:

public slots:
};

#endif // QUNIT_H
