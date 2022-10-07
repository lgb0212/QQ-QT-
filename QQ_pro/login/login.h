#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QMenu>
#include <QDebug>
#include <QAction>
#include <QPoint>
#include <QCursor>
#include "api.h"
#include "app.h"
#include "iconfont.h"
#include "quiwidget.h"
#include <QIcon>
#include "iconhelper.h"
#pragma execution_character_set("utf-8")

#define SHADOW_WIDTH 1		// 阴影边框宽度;

namespace Ui {
class login;
}

//namespace nameSpace{
//  class className{

//  }
//}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
protected:
        void paintEvent(QPaintEvent *event) override;
        void mousePressEvent(QMouseEvent *e);
        void mouseMoveEvent(QMouseEvent *e);
private slots:
    void on_register_ID_pushButton_3_clicked();
    void menulevel_slots(QAction* a);
    void on_close_pushButton_2_clicked();

    void on_login_pushButton_2_clicked();

private:
    Ui::login *ui;

    QMenu *qq_menu;
    QAction *Action_1;
    QAction *Action_2;

    QPoint pos;

    void form_init();

};

#endif // LOGIN_H
