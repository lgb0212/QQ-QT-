/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *min_pushButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QPushButton *close_pushButton_2;
    QPushButton *pushButton_2;
    QLabel *title_label;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *ID_lineEdit;
    QLineEdit *password_lineEdit_2;
    QHBoxLayout *horizontalLayout;
    QCheckBox *auto_login_checkBox;
    QCheckBox *remember_password_checkBox_3;
    QPushButton *register_ID_pushButton_3;
    QPushButton *find_password_pushButton;
    QPushButton *login_pushButton_2;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(334, 228);
        gridLayout_2 = new QGridLayout(login);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(74, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 4, 1, 1);

        min_pushButton = new QPushButton(login);
        min_pushButton->setObjectName(QStringLiteral("min_pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(min_pushButton->sizePolicy().hasHeightForWidth());
        min_pushButton->setSizePolicy(sizePolicy);
        min_pushButton->setMinimumSize(QSize(30, 30));
        min_pushButton->setMaximumSize(QSize(30, 30));

        gridLayout->addWidget(min_pushButton, 0, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(74, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        pushButton = new QPushButton(login);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(30, 30));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 5, 1, 1);

        close_pushButton_2 = new QPushButton(login);
        close_pushButton_2->setObjectName(QStringLiteral("close_pushButton_2"));
        sizePolicy.setHeightForWidth(close_pushButton_2->sizePolicy().hasHeightForWidth());
        close_pushButton_2->setSizePolicy(sizePolicy);
        close_pushButton_2->setMinimumSize(QSize(30, 30));
        close_pushButton_2->setMaximumSize(QSize(30, 30));

        gridLayout->addWidget(close_pushButton_2, 0, 6, 1, 1);

        pushButton_2 = new QPushButton(login);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(30, 30));
        pushButton_2->setMaximumSize(QSize(30, 30));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        title_label = new QLabel(login);
        title_label->setObjectName(QStringLiteral("title_label"));
        title_label->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(title_label, 0, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        ID_lineEdit = new QLineEdit(login);
        ID_lineEdit->setObjectName(QStringLiteral("ID_lineEdit"));
        ID_lineEdit->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(ID_lineEdit);

        password_lineEdit_2 = new QLineEdit(login);
        password_lineEdit_2->setObjectName(QStringLiteral("password_lineEdit_2"));
        password_lineEdit_2->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(password_lineEdit_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        auto_login_checkBox = new QCheckBox(login);
        auto_login_checkBox->setObjectName(QStringLiteral("auto_login_checkBox"));

        horizontalLayout->addWidget(auto_login_checkBox);

        remember_password_checkBox_3 = new QCheckBox(login);
        remember_password_checkBox_3->setObjectName(QStringLiteral("remember_password_checkBox_3"));

        horizontalLayout->addWidget(remember_password_checkBox_3);

        register_ID_pushButton_3 = new QPushButton(login);
        register_ID_pushButton_3->setObjectName(QStringLiteral("register_ID_pushButton_3"));

        horizontalLayout->addWidget(register_ID_pushButton_3);

        find_password_pushButton = new QPushButton(login);
        find_password_pushButton->setObjectName(QStringLiteral("find_password_pushButton"));

        horizontalLayout->addWidget(find_password_pushButton);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        login_pushButton_2 = new QPushButton(login);
        login_pushButton_2->setObjectName(QStringLiteral("login_pushButton_2"));
        login_pushButton_2->setMinimumSize(QSize(0, 30));
        login_pushButton_2->setStyleSheet(QStringLiteral(""));

        verticalLayout_3->addWidget(login_pushButton_2);


        gridLayout_2->addLayout(verticalLayout_3, 1, 0, 1, 1);


        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Form", Q_NULLPTR));
        min_pushButton->setText(QString());
        pushButton->setText(QString());
        close_pushButton_2->setText(QString());
        pushButton_2->setText(QString());
        title_label->setText(QApplication::translate("login", "Q Q", Q_NULLPTR));
        auto_login_checkBox->setText(QApplication::translate("login", "\350\207\252\345\212\250\347\231\273\345\275\225", Q_NULLPTR));
        remember_password_checkBox_3->setText(QApplication::translate("login", "\350\256\260\344\275\217\345\257\206\347\240\201", Q_NULLPTR));
        register_ID_pushButton_3->setText(QApplication::translate("login", "\346\263\250\345\206\214\350\264\246\345\217\267", Q_NULLPTR));
        find_password_pushButton->setText(QApplication::translate("login", "\346\211\276\345\233\236\345\257\206\347\240\201", Q_NULLPTR));
        login_pushButton_2->setText(QApplication::translate("login", "\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
