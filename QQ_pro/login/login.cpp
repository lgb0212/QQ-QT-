#include "login.h"
#include "ui_login.h"
#include "iconhelper.h"
#include "quihelper.h"
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
//    setAttribute(Qt::WA_StyledBackground);
    this->setWindowFlags(Qt::FramelessWindowHint);//隐藏关闭窗口

    this->form_init();
}

login::~login()
{
    delete ui;
}

//界面初始化
void login :: form_init()
{

    my_QUIHelper::setFont();
    my_QUIHelper::setCode();
    //加载样式表
    QFile file(":/qss/blacksoft.css");
    if (file.open(QFile::ReadOnly)) {
        QString qss =file.readAll();
        QString paletteColor = qss.mid(20, 7);
        this->setPalette(QPalette(QColor(paletteColor)));
        this->setStyleSheet(qss);
        file.close();
        qDebug()<<qss;
    }


    QSizePolicy sp_retain = ui->pushButton_2->sizePolicy();
    sp_retain.setRetainSizeWhenHidden(true);
    ui->pushButton_2->setSizePolicy(sp_retain);
//    ui->pushButton->setSizePolicy(sp_retain);

    ui->pushButton_2->hide();
    ui->pushButton->hide();
//    this->setStyleSheet("QWidget{background: white;}");

    my_IconHelper::setIcon(ui->min_pushButton, 0xf068);
    my_IconHelper::setIcon(ui->close_pushButton_2, 0xf00d);


    ui->ID_lineEdit->setPlaceholderText("请输入账号");
    ui->password_lineEdit_2->setPlaceholderText("请输入密码");

    ui->register_ID_pushButton_3->setFlat(true);
    ui->find_password_pushButton->setFlat(true);




}


void login::on_register_ID_pushButton_3_clicked()
{
//    qDebug()<<"注册账号";
//    qDebug()<<"坐标为"<<ui->register_ID_pushButton_3->pos();

//    qq_menu->setFixedWidth(ui->register_ID_pushButton_3->width());
//    QPoint pos;
//    pos.setX(0);
//    pos.setY(-qq_menu->sizeHint().height());

//    qq_menu->exec(ui->register_ID_pushButton_3->mapToGlobal(pos));
}

void login::menulevel_slots(QAction* a)
{
    qDebug()<<"菜单获取值为"<<a->data().toInt();
}

//绘制界面边框
void login::paintEvent(QPaintEvent *event)
{
    QPen pen;
    QColor color;
    QRectF rectangle3(0, 0, width() -1, height() -1);	//坐标大小
    QPainter p(this);
    color.setRgb(64,157,167);
    pen.setWidth(5);			//画笔宽度
    pen.setColor(color);
    p.setPen(pen);
    p.drawRoundedRect(rectangle3, 0, 0);
}

/*拖动曲线图界面*/
void login::mousePressEvent(QMouseEvent *e)
{//仅对鼠标左键响应
    if (e->button() == Qt::LeftButton)
        pos = e->globalPos();
}
void login::mouseMoveEvent(QMouseEvent *e)
{//仅对鼠标左键响应
    if (!e->buttons().testFlag(Qt::LeftButton))
            return;
    int dx = e->globalX() - pos.x();
    int dy = e->globalY() - pos.y();
    pos = e->globalPos();
    move(x()+dx, y()+dy);
}

void login::on_close_pushButton_2_clicked()
{
    this->close();
}

void login::on_login_pushButton_2_clicked()
{

}
