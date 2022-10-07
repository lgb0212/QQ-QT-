#include <QtCore>
#include <QtGui>
#include <QtSql>
#include <QtNetwork>

#if (QT_VERSION > QT_VERSION_CHECK(5,0,0))
#include <QtWidgets>
#include <QtPrintSupport>
#endif

#ifdef webkit
#include <QtWebKit>
#if (QT_VERSION > QT_VERSION_CHECK(5,0,0))
#include <QtWebKitWidgets>
#endif
#elif webengine
#include <QtWebEngineWidgets>
#elif webie
#include <QAxWidget>
#endif


#define FULL 1      //全功能打开
#define app_model "XY-P30"      //型号
#define app_name "无线频谱分析仪"      //名称
#pragma execution_character_set("utf-8")

#include "app.h"
#include "dbdata.h"
#include "iconhelper.h"

