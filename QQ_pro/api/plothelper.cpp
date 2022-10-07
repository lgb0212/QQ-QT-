#include "plothelper.h"
#include "quiwidget.h"

bool PlotHelper::lineIntersectSide1(QPointF p1, QPointF p2, QPointF p3, QPointF p4)
{
    // A(x1, y1), B(x2, y2)的直线方程为：
    // f(x, y) =  (y - y1) * (x1 - x2) - (x - x1) * (y1 - y2) = 0
    float fp3 = (p3.y() - p1.y()) * (p1.x() - p2.x()) - (p3.x() - p1.x()) * (p1.y() - p2.y());
    float fp4 = (p4.y() - p1.y()) * (p1.x() - p2.x()) - (p4.x() - p1.x()) * (p1.y() - p2.y());
    if(fp3 * fp4 > 0) {
        return false;
    }

    return true;
}

bool PlotHelper::lineIntersectSide2(QPointF p1, QPointF p2, QPointF p3, QPointF p4)
{
    //快速排斥实验
    if ((p1.x() > p2.x() ? p1.x() : p2.x()) < (p3.x() < p4.x() ? p3.x() : p4.x()) ||
            (p1.y() > p2.y() ? p1.y() : p2.y()) < (p3.y() < p4.y() ? p3.y() : p4.y()) ||
            (p3.x() > p4.x() ? p3.x() : p4.x()) < (p1.x() < p2.x() ? p1.x() : p2.x()) ||
            (p3.y() > p4.y() ? p3.y() : p4.y()) < (p1.y() < p2.y() ? p1.y() : p2.y())) {
        return false;
    }

    //跨立实验
    if ((((p1.x() - p3.x()) * (p4.y() - p3.y()) - (p1.y() - p3.y()) * (p4.x() - p3.x())) *
            ((p2.x() - p3.x()) * (p4.y() - p3.y()) - (p2.y() - p3.y()) * (p4.x() - p3.x()))) > 0 ||
            (((p3.x() - p1.x()) * (p2.y() - p1.y()) - (p3.y() - p1.y()) * (p2.x() - p1.x())) *
             ((p4.x() - p1.x()) * (p2.y() - p1.y()) - (p4.y() - p1.y()) * (p2.x() - p1.x()))) > 0) {
        return false;
    }

    return true;
}

void PlotHelper::loadData(QVector<double> &keys1, QVector<double> &values1,
                          QVector<double> &keys2, QVector<double> &values2,
                          QStringList &data, const QString &fileName,
                          int takeCount, int offsetY,
                          bool rightConnect, bool leftConnect)
{
    keys1.clear();
    values1.clear();
    keys2.clear();
    values2.clear();
    data.clear();

    //定义变量用于计算拐点
    double oldKey = 0.0;
    //是否做了抖动数据处理
    bool take = false;
    //是否数据起始位置
    bool start = false;

    QFile file(fileName);
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        while (!file.atEnd()) {
            QString line = file.readLine();
            line = line.replace("\r", "");
            line = line.replace("\n", "");
            line = line.replace(";", "");
            line = line.replace(" ", "");

            //如果是首次找到s开头则表示数据刚开始
            if (!start && line.startsWith("s,mm")) {
                start = true;
                continue;
            }

            //如果已经处于数据阶段,突然来了空行则表示数据阶段结束
            if (start && line.isEmpty()) {
                break;
            }

            if (!start) {
                continue;
            }

            //数据个数必须大于等于3
            QStringList list = line.split(",");
            if (list.count() < 3) {
                continue;
            }

            double key = list.at(1).toDouble();
            double value = list.at(2).toDouble();

            //增加偏移量用于测试数据
            if (offsetY > 0) {
                value += offsetY;
            }

            //逐渐增大的值放一个组合,变小的放一个组合
            if (key >= oldKey) {
                keys1 << key;
                values1 << value;
                data << line;
            } else if (key >= 1) {
                //这里大于1说明可能前面几个数据抖动
                //拐点最后的几个值扔掉或者做特殊处理,属于抖动数据
                if (!take) {
                    if (takeCount > 0 && takeCount <= keys1.count()) {
                        keys1.remove(keys1.count() - takeCount, takeCount);
                        values1.remove(values1.count() - takeCount, takeCount);
                    }

                    take = true;
                }

                keys2 << key;
                values2 << value;
                data << line;
            }

            oldKey = key;
        }
    }

    //拐点最后一条线连起来+起始位置连起来
    if (take) {
        if (rightConnect) {
            if (takeCount > 0) {
                values2[0] = values1.last();
            } else {
                keys2.insert(0, keys1.last());
                values2.insert(0, values1.last());
            }
        }

        if (leftConnect) {
            values2[values2.count() - 1] = values1.first();
        }
    }
}

void PlotHelper::loadData(QVector<double> &keys, QVector<double> &values, QStringList &data, const QString &fileName)
{
    keys.clear();
    values.clear();
    data.clear();

    //是否数据起始位置
    bool start = false;

    QFile file(fileName);
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        while (!file.atEnd()) {
            QString line = file.readLine();
            line = line.replace("\r", "");
            line = line.replace("\n", "");
            line = line.replace(";", "");
            line = line.replace(" ", "");

            //如果是首次找到s开头则表示数据刚开始
            if (!start && line.startsWith("X")) {
                start = true;
                continue;
            }

            //如果已经处于数据阶段,突然来了空行则表示数据阶段结束
            if (start && line.isEmpty()) {
                break;
            }

            if (!start) {
                continue;
            }

            //数据个数必须大于等于2
            QStringList list = line.split(",");
            if (list.count() < 2) {
                continue;
            }

            double key = list.at(0).toDouble();
            double value = list.at(1).toDouble();
            keys << key;
            values << value;
            data << line;
        }
    }
}
