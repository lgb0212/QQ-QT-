#ifndef PLOTHELPER_H
#define PLOTHELPER_H

#include "qcustomplot.h"
#include "head.h"

#define HandleSize      16                  //手柄尺寸
#define IconLeft        10                  //左箭头指示偏移
#define IconRight       11                  //右箭头指示偏移
#define IconTop         12                  //上箭头指示偏移
#define IconBottom      12                  //下箭头指示偏移

#define HandleBorder    2                   //手柄边框宽度
#define HandleRadius    3                   //手柄边框圆角角度
#define HandleColor     QColor("#FF7FFF")   //手柄颜色

class PlotHelper
{
public:
    //判断线段(p1 p2)是否与线段(p3 p4)相交
    static bool lineIntersectSide1(QPointF p1, QPointF p2, QPointF p3, QPointF p4);
    static bool lineIntersectSide2(QPointF p1, QPointF p2, QPointF p3, QPointF p4);



    //读取文件取出数据
    static void loadData(QVector<double> &keys1, QVector<double> &values1,
                         QVector<double> &keys2, QVector<double> &values2,
                         QStringList &data, const QString &fileName,
                         int takeCount = 0, int offsetY = 0,
                         bool rightConnect = true, bool leftConnect = false);
    static void loadData(QVector<double> &keys, QVector<double> &values,
                         QStringList &data, const QString &fileName);
};

#endif // PLOTHELPER_H
