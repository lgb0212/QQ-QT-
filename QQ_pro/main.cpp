#include "formmain.h"
#include <QApplication>
#include "quihelper.h"
#include <QApplication>
#include <QFile>
#include <QPalette>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //设置不应用操作系统设置比如字体
    QApplication::setDesktopSettingsAware(false);
#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
    QApplication::setAttribute(Qt::AA_Use96Dpi);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5,14,0))
    QApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::Floor);
#endif




    formMain w;

//    my_QUIHelper::setFormInCenter(&w);
//    w.show();

    return a.exec();
}
