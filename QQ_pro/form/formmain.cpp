#include "formmain.h"
#include "ui_formmain.h"

formMain::formMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::formMain)
{
    ui->setupUi(this);
    this->form_init();
}

formMain::~formMain()
{
    delete ui;
}


void formMain:: form_init()
{
    login_ui = new login();
    login_ui->show();
}


