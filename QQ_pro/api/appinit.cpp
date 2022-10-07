#include "appinit.h"
#include "quiwidget.h"
#include "dbhelper.h"
#include "dbpage.h"
#include "appkey.h"
#include "saveruntime.h"
#include "applive.h"
#include "savelog.h"
#include "udiskapi.h"
#include "frminput2018.h"
#include "webhelper.h"
#include "head.h"
AppInit *AppInit::self = NULL;
AppInit *AppInit::Instance()
{
    if (!self) {
        QMutex mutex;
        QMutexLocker locker(&mutex);
        if (!self) {
            self = new AppInit;
        }
    }

    return self;
}

AppInit::AppInit(QObject *parent) : QObject(parent)
{
}

bool AppInit::eventFilter(QObject *obj, QEvent *evt)
{
    QWidget *w = (QWidget *)obj;
    if (!w->property("canMove").toBool()) {
        return QObject::eventFilter(obj, evt);
    }

    static QPoint mousePoint;
    static bool mousePressed = false;

    QMouseEvent *event = static_cast<QMouseEvent *>(evt);
    if (event->type() == QEvent::MouseButtonPress) {
        if (event->button() == Qt::LeftButton) {
            mousePressed = true;
            mousePoint = event->globalPos() - w->pos();
            return true;
        }
    } else if (event->type() == QEvent::MouseButtonRelease) {
        mousePressed = false;
        return true;
    } else if (event->type() == QEvent::MouseMove) {
        if (mousePressed && (event->buttons() && Qt::LeftButton)) {
            w->move(event->globalPos() - mousePoint);
            return true;
        }
    }

    return QObject::eventFilter(obj, evt);
}

bool AppInit::start()
{
    qApp->installEventFilter(this);
    //载入配置文件
    App::ConfigFile = QString("%1/config/%2.ini").arg(QUIHelper::appPath()).arg(QUIHelper::appName());
    App::readConfig();
   // App::StyleName = ":/qss/flatwhite.css";
    AppInit::Instance()->initStyle();

    AppLive::Instance()->start(6666);


    //设置全局字体
    QUIConfig::IconMain = 0xf108;
    QUIConfig::FontSize = 12;
    QFont font;
    font.setFamily(QUIConfig::FontName);
    font.setPixelSize(QUIConfig::FontSize);
    qApp->setFont(font);

    //设置编码
    QUIHelper::setCode();

  //  QString qmFile = ":/config/qt_zh_CN.qm";
//    QString qmFile =  QString("%1/config/qt_zh_es.qm").arg(QUIHelper::appPath());

//    //设置翻译文件
//    QUIHelper::setTranslator(qmFile);
    //初始化随机数种子
    QUIHelper::initRand();

    //新建不存在的目录
    QUIHelper::newDir("config");
    QUIHelper::newDir("db");
    QUIHelper::newDir("log");
    QUIHelper::newDir("picture");
    QUIHelper::newDir("play");
    QUIHelper::newDir("manuals/helpimage");
    QUIHelper::newDir("BTS");
    //初始化web控件配置信息
    WebHelper::initWebSetting();
    WebHelper::initMapData();


    //启动程序运行记录类
    SaveRunTime::Instance()->start();
    //启动调试日志
    //SaveLog::Instance()->start();

//    //初始化本机设备编号
//    if(App::codenumber.size() == 0){
//        App::codenumber = QUIHelper::generateUniqueRandomNumber();
//        App::writeConfig();
//    }

    frmInput2018::Instance()->hide();
    frmInput2018::Instance()->setWindowOpacity(0.9);
    frmInput2018::Instance()->setPosition("control");
    frmInput2018::Instance()->setStyle("silvery");
    //以下方法设置字体+面板宽高+图标大小+候选字高度
    frmInput2018::Instance()->setFontInfo("Microsoft YaHei", 10, 12);
    frmInput2018::Instance()->setFrmSize(600, 250);
    frmInput2018::Instance()->setIconSize(25, 25);
    frmInput2018::Instance()->setTopHeight(50);

    //启动注册机服务类
    //AppKey::Instance()->start();
    //判断数据库文件是否存在,不存在则从资源文件复制出来
    QString dbName = QString("%1/db/%2.db").arg(QUIHelper::appPath()).arg(QUIHelper::appName());


    QFile dbFile(dbName);
    if (!dbFile.exists() || dbFile.size() == 0) {
        dbFile.remove();
        QUIHelper::copyFile(QString(":/Data.db").arg(QUIHelper::appName()), dbName);
    }
    //程序启动后打开数据库连接,在任何窗体需要的地方调用数据库
    QSqlDatabase dbConn;
    dbConn = QSqlDatabase::addDatabase("QSQLITE");
    dbConn.setDatabaseName(dbName);
    dbConn.open();

    QStringList list = DBHelper::loadAllTables();
    bool isBTSlog = false;
    if(list.count() > 0)
    {
        for(int i = 0 ; i<list.count() ; i++)
        {
            if(list.at(i) == "BTSlog")
            {
                isBTSlog = true;
            }
        }
        if(!isBTSlog)
        {
            dbConn.close();
            //没有这表重新创建
            dbFile.remove();
            QUIHelper::copyFile(QString(":/Data.db"), dbName);
            dbConn.open();
        }

    }
   DBHelper::loadBTSTaskLog();

    //设置开机自动运行
#ifdef Q_OS_WIN
    QString strPath = QApplication::applicationFilePath();
    strPath = QDir::toNativeSeparators(strPath);
    QUIHelper::runWithSystem(QUIHelper::appName(), strPath, false);
#endif

#if 0
    //启动守护程序服务类
    bool livetoolstatus = QUIHelper::CheckAppRunningStatus("livetool.exe");
    if(livetoolstatus == false){
        QProcess *p = new QProcess(this);
        p->start("$$PWD/../livetool.exe",QStringList());
    }
#endif
    return true;
}

void AppInit::initStyle()
{
    QFile file(App::StyleName);
    if (file.open(QFile::ReadOnly)) {
        QString qss = QLatin1String(file.readAll());
        file.close();

        QUIHelper::getQssColor(qss, QUIConfig::TextColor, QUIConfig::PanelColor, QUIConfig::BorderColor, QUIConfig::NormalColorStart,
                               QUIConfig::NormalColorEnd, QUIConfig::DarkColorStart, QUIConfig::DarkColorEnd, QUIConfig::HighColor);

       // qDebug()<<qss;
        //追加样式
        QStringList list;

        //主背景
        list.append(QString("QWidget#widgetMain{background:%1;}").arg(QUIConfig::BorderColor));

        //中英文标题字体大小
        list.append(QString("#labLogoCn{font-size:%1px;}#labLogoEn{font-size:%2px;}")
                    .arg(QUIConfig::FontSize + 5).arg(QUIConfig::FontSize + 2));

        //右上角菜单
        list.append(QString("QWidget#widgetMenu>QPushButton{border-radius:0px;padding:0px;margin:1px 1px 2px 1px;}"));

        //视频画面
        bool black = (App::StyleName.contains("black"));
        list.append(QString("QWidget#widgetVideo>QLabel{font-size:%1px;border:2px solid %2;background:%3;}")
                    .arg(QUIConfig::FontSize + 10).arg(QUIConfig::BorderColor).arg(QUIConfig::NormalColorStart));
        list.append(QString("QWidget#widgetVideo>QLabel:focus{border:2px solid %1;background:%2;}")
                    .arg(QUIConfig::HighColor).arg(black ? QUIConfig::NormalColorEnd : QUIConfig::DarkColorStart));

        //画面分割栏
        list.append(QString("QWidget#widgetSplite>QPushButton{background:transparent;border:none;}"));

        //顶部导航按钮,可以自行修改圆角角度
        int topBtnRadius = 20;
        list.append(QString("QWidget#widgetBtn>QPushButton{font-size:%1px;background:transparent;border:none;border-radius:%2px;}")
                    .arg(QUIConfig::FontSize + 3).arg(topBtnRadius));
        list.append(QString("QWidget#widgetBtn>QPushButton:focus,QWidget#widgetBtn>QPushButton:hover{background:%1;border:2px solid %2;}")
                    .arg(QUIConfig::DarkColorEnd).arg(QUIConfig::BorderColor));

        //左侧导航按钮,可以自行修改圆角角度
        int leftBtnRadius = 5;
        list.append(QString("QWidget[flag=\"btn\"]>QPushButton{min-height:%1px;max-height:%1px;}").arg(30));
        list.append(QString("QWidget[flag=\"btn\"]>QPushButton{font-size:%1px;background:transparent;border:none;border-radius:%2px;}")
                    .arg(QUIConfig::FontSize + 3).arg(leftBtnRadius));
        list.append(QString("QWidget[flag=\"btn\"]>QPushButton:focus,QWidget[flag=\"btn\"]>QPushButton:hover{background:%1;border:2px solid %2;}")
                    .arg(QUIConfig::DarkColorEnd).arg(QUIConfig::BorderColor));
//        list.append(QString("QPushButton:focus,QPushButton:checked,QPushButton:hover{background:%1;border:2px solid %2;}")
//                    .arg(QUIConfig::DarkColorEnd).arg(QUIConfig::BorderColor));
        //面板框
        list.append(QString("QFrame[flag=\"btn\"]{background:%1;}").arg(QUIConfig::BorderColor));
        list.append(QString("QFrame[flag=\"btn\"]>QPushButton{font-size:%1px;font-weight:bold;}")
                    .arg(QUIConfig::FontSize + 3));

        //翻页导航标签
        list.append(QString("QFrame[flag=\"navlab\"] QLabel{min-height:%1px;max-height:%1px;font:%2px;}").arg(30).arg(QUIConfig::FontSize + 3));

        //字体放大
        list.append(QString("#widgetControl>QLabel{font-size:%1px;}").arg(QUIConfig::FontSize + 12));
        list.append(QString("#widgetControl>QCheckBox::indicator{width:%1px;height:%1px;}").arg(30));

        //左侧导航栏及按钮图标大小
        list.append(QString("QLineEdit#txtCard,QLabel#labTip,QLabel#labCard,QLabel#labTime{font-weight:bold;font-size:%1px;min-height:%2px;qproperty-alignment:AlignCenter;}").arg(QUIConfig::FontSize + 2).arg(28));
        list.append(QString("QWidget[flag=\"navbtn\"] QPushButton,QFrame[flag=\"navbtn\"] QPushButton{qproperty-iconSize:%1px;min-width:%2px;}").arg(App::BtnIconSize).arg(App::BtnMinWidth));

        list.append(QString("QLCDNumber{background-color:%1;color:%2;}")
                    .arg(QUIConfig::NormalColorStart).arg(QUIConfig::TextColor));

        //选项卡
        list.append(QString("QTabWidget::pane{border:0px border-color: %1;}QTabBar::tab{min-width:%2px;min-height:%3px;}").arg(QUIConfig::BorderColor).arg(64).arg(20));

        //树状控件
        list.append(QString("QListView,QTreeView{padding:5px 0px 0px 0px;border-width:0px;}"));

        //文本框控件
        list.append(QString("QTextEdit,QTextEdit:hover,QTextEdit:focus{border-width:0px;border-radius:0px;}"));
        list.append(QString("QTextBrowser{border-width: 1px;border-color: %1;}").arg(QUIConfig::BorderColor));

        //自定义面板标题控件
        list.append(QString("NavTitle{qproperty-backgroundColor:%1;qproperty-textColor:%2;qproperty-borderColor:%3;}")
                    .arg(QUIConfig::NormalColorStart).arg(QUIConfig::TextColor).arg(QUIConfig::BorderColor));

        //开关按钮
        list.append(QString("SwitchButton{min-width:62px;max-height:25px;}"));



//        list.append(QString("QGroupBox{border:6px solid %1;background:%2;border-radius:15px; margin-top:0ex;}")
//                    .arg(QUIConfig::BorderColor).arg(QUIConfig::BorderColor));

//        list.append(QString("QCustomPlot{background:%1;}").arg(QUIConfig::BorderColor));
        //将新增的样式加到统一样式表中
        qss += list.join("");
        qApp->setPalette(QPalette(QUIConfig::PanelColor));
        qApp->setStyleSheet(qss);
    }
}
