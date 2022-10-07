/********************************************************************************
** Form generated from reading UI file 'formmain.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMMAIN_H
#define UI_FORMMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_formMain
{
public:

    void setupUi(QWidget *formMain)
    {
        if (formMain->objectName().isEmpty())
            formMain->setObjectName(QStringLiteral("formMain"));
        formMain->resize(261, 528);

        retranslateUi(formMain);

        QMetaObject::connectSlotsByName(formMain);
    } // setupUi

    void retranslateUi(QWidget *formMain)
    {
        formMain->setWindowTitle(QApplication::translate("formMain", "Widget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class formMain: public Ui_formMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMMAIN_H
