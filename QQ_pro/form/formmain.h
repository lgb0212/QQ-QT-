#ifndef FORMMAIN_H
#define FORMMAIN_H

#include <QWidget>
#include "login.h"
namespace Ui {
class formMain;
}

class formMain : public QWidget
{
    Q_OBJECT

public:
    explicit formMain(QWidget *parent =  nullptr);
    ~formMain();

private:
    Ui::formMain *ui;
    void form_init();
    login *login_ui;
};

#endif // WIDGET_H
