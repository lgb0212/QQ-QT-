#include "qunit.h"
#include <QStringList>
#include <QDebug>
#include "app.h"
inline void zero_array(float *in, int len) {
    for(int i = 0; i < len; i++) in[i] = 0.0;
}

inline void copy_array(const float *in, float *out, int len) {
    for(int i = 0; i < len; i++) out[i] = in[i];
}
inline void copy_array(const double *in, double *out, int len) {
    for(int i = 0; i < len; i++) out[i] = in[i];
}

inline double mul_accum(const float *src1, const float *src2, int len) {
    double sum = 0.0;
    for(int i = 0; i < len; i++) {
        sum += (src1[i] * src2[i]);
    }
    return sum;
}
Qunit::Qunit(QObject *parent) : QObject(parent)
{

}

QString Qunit::toAudioVoltage(double const &Voltage)
{
    double Voltage1 = Voltage;
    if(Voltage1>4000)    Voltage1 = 4000;
    if(Voltage1<0)    Voltage1 = 0;

    QString str;
    if(Voltage1>=100)  str = QString().sprintf("%.0f",Voltage1);
    else           str = QString().sprintf("%.1f",Voltage1);
    return str;
}
QString Qunit::toAudioFreq(double const &Freq)
{
    double Freq1 = Freq;
    if(Freq1>15000)    Freq1 = 15000;
    if(Freq1<20)    Freq1 = 20;
    QString str;
    if(Freq1>=1000)  str = QString().sprintf("%.0f",Freq1);
    else           str = QString().sprintf("%.1f",Freq1);
    return str;
}
QString Qunit::toRfpoweruV(const double &value)
{

    float RFuv = pow(10,(value+107)/20.00);  //dbm->uV
    return QString().sprintf("%.2f",RFuv)+"uV";

}
QString Qunit::toRfpower(double const &value)
{
    double value1 = value;
    if(value1>-80)   value1 = -80;
    if(value1<-130)  value1 = -130;

     return QString().sprintf("%.1f",value1);
}
QString Qunit::toRfFreq(double const &value)
{
    double value1 = value;
    if(value1<400.0000)   value1 = 400.0000;
    if(value1>900.0000)   value1 = 900.0000;
    return QString().sprintf("%.4f",value1);
}
QString Qunit::toFMFreq(double const &value)
{
    double value1 = value;
    if(value1>20000)     value1 = 20000;
    if(value1<20.0)      value1 = 20.0;
    if(value1 == (int)value1)
        return QString().sprintf("%.0f",value1);
    else
        return QString().sprintf("%.1f",value1);

}
QString Qunit::toFMoffsit(double const &value)
{
    double value1 = value;
    if(value1>15000)     value1 = 15000;
    if(value1<100)       value1 = 100;

    return QString().sprintf("%.0f",value1);
}
QString Qunit::toPowerstr(double power)
{
    QString out;
    if(power > 46.99) power = 46.99;
    if(power<-130)      power = -130;
    double powerw = pow(10,power/10)/1000;
    if(power>=30)           out = QString().sprintf("%.2fW    %0.1fdBm",powerw,power);
    else if(power > 0)      out = QString().sprintf("%.3fW    %0.1fdBm",powerw,power);
    else if(power <= -130)  out = QString().sprintf("%.3fW    --.-dBm",0);

    else                 out = QString().sprintf("%.2fW    %0.1fdBm",0,power);
    return out;

}
double Qunit::toPowerW(double power)
{
    return pow(10,power/10)/1000;
}
QString Qunit::toPowerWstr(double power)
{
    QString out;
    if(power>=1)    out = QString().sprintf("%.2fW",power);
    else            out = QString().sprintf("%.3fW",power);
    return out;

}
double Qunit::toCIRFrequency(double Freq)
{
    double out;
    const double freqgroup[]={ 457.500e6, 457.550e6, 457.700e6, 457.800e6, 457.825e6,457.925e6,
                               467.450e6, 467.500e6, 467.550e6, 467.600e6,
                               467.650e6, 467.700e6,  467.750e6, 467.775e6,467.800e6,
                               467.825e6, 467.875e6, 467.925e6};
    for(int i =0;i<sizeof(freqgroup);i++)
    {
        if(abs(Freq-freqgroup[i])<abs(Freq-freqgroup[i+1]))
        {
            out = freqgroup[i];
            break;
        }
    }
    return out;
}
/**************************************************************************
函数名称：查找最小值,并记录下标
功能描述：
输入参数：
返   回：
**************************************************************************/
void Qunit::Find_minnumX(const double *in, float &min, int &x,int size)
{
    min = in[0];
    for(int i=0;i<size;i++)
    {
        if(in[i] < min)
        {
            min=in[i];
            x=i;
        }
    }

}

/**************************************************************************
函数名称：查找最大值
功能描述：
输入参数：
返   回：
**************************************************************************/
void Qunit::Find_maxnum(double *in, double &max, int size)
{
    max = in[0];
    for(int i=0;i<size;i++)
    {
        if(in[i]> max)
        {
            max=in[i];
        }
    }

}
void Qunit::Find_max(float a[],float &max,int &p,int &size)
{
    for(int i=0;i<size;i++){
        if(a[i]> max){
            max=a[i];
            p=(i+1);
        }
    }
}
void Qunit::CIRdelete_maxmin(std::vector<double> &a,double &max,double &min,int &size)
{
    if(a.size()==0) return;
    for(int i=0;i<size-1;i++)
        for(int j=size-1;j>i;j--)
        if(a[j]<a[j-1])
        {
            double temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
        }
    max = a[size-1];
    min = a[0];
    for(int i=0;i<size-2;i++)
    {
        a[i] = a[i+1];
    }
    size = size - 2;
    a.resize(size);

}
/**************************************************************************
函数名称：中值滤波器
功能描述：
输入参数：
返   回：
**************************************************************************/
double Qunit::midFilternum(QList<double> in)
{
    int size = in.size();
    if(size==0) return -1;
    double mid;
    for(int i=0;i<size-1;i++)
        for(int j=size-1;j>i;j--)
        if(in[j]<in[j-1])
        {
            double temp=in[j];
            in[j]=in[j-1];
            in[j-1]=temp;
        }
    return mid = in[size/2];
}
/**************************************************************************
函数名称：删除数组中小于等于某个数的所有元素
功能描述：
输入参数：
返   回：
**************************************************************************/
void Qunit::CIRdelete_maxnum(const double *in, double *out, double num, int *size)
{
    int j=0;
    const double eps=1e-8;
    for(int i=0;i<*size;i++)
    {
        if(num-in[i] < eps)
        {
            out[j++] = in[i];
        }
    }
    *size = j;
}
/**************************************************************************
函数名称：删除数组中大于某个数的所有元素
功能描述：
输入参数：
返   回：
**************************************************************************/
void Qunit::CIRdelete_minnum(const double *in, double *out, double num, int *size)
{
    int j=0;
    //copy_array(in,out,size);
    const double eps=1e-3;
    for(int i=0;i<*size;i++)
    {
        if(in[i] - num < eps )
        {
           out[j++] = in[i];
        }
    }
    *size = j;
}


/**************************************************************************
函数名称：求数组的平均数
功能描述：
输入参数：
返   回：
**************************************************************************/
void Qunit::num_avg(const double *in,double &avg, int &size)
{
    double sum=0;
    //copy_array(in,out,size);
    for(int i=0;i<size;i++)
    {
        sum=sum+in[i];
    }
    avg = sum/size;

}
/**************************************************************************
函数名称：遍历查找出现次数最多的数
功能描述：
输入参数：
返   回：
**************************************************************************/
void Qunit::Maps_max(const double *in,int size, double &maxdata)
{
    std::vector<double> x;
    std::vector<double> y;
    x.clear();
    y.clear();

    QMap<double , double> word_count;
    for(int i=0;i<size;i++)
    {
       ++word_count[in[i]];
    }
    int p = 0;
     for(QMap<double , double>::iterator iter = word_count.begin(); iter != word_count.end() ; ++iter)
     {
        x.push_back(iter.key());
        y.push_back(iter.value());
     }

     int max =y[0] ;
     int second = y[1];
     int second_p = 0;
     for(int i=0;i<y.size();i++)
     {
         if(y[i]> max)
         {
             second = max;
             max=y[i];
             p=i;
         }
         else if(y[i]<max && y[i]>second)
         {
             second = y[i];
             second_p = i;
         }
     }

     maxdata = x[p];

}
