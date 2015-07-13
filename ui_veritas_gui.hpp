/********************************************************************************
** Form generated from reading UI file 'veritas_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERITAS_GUI_H
#define UI_VERITAS_GUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_veritasgui
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_Cancel;
    QPushButton *pushButton_Start;
    QProgressBar *progressBar;
    QLabel *label;
    QPushButton *pushButton_Browse;

    void setupUi(QWidget *veritasgui)
    {
        if (veritasgui->objectName().isEmpty())
            veritasgui->setObjectName(QString("veritasgui"));
        veritasgui->setEnabled(true);
        veritasgui->resize(400, 259);
        veritasgui->setMinimumSize(QSize(400, 0));
        veritasgui->setMaximumSize(QSize(500, 300));
        gridLayout = new QGridLayout(veritasgui);
        gridLayout->setObjectName(QString("gridLayout"));
        pushButton_Cancel = new QPushButton(veritasgui);
        pushButton_Cancel->setObjectName(QString("pushButton_Cancel"));

        gridLayout->addWidget(pushButton_Cancel, 3, 0, 1, 1);

        pushButton_Start = new QPushButton(veritasgui);
        pushButton_Start->setObjectName(QString("pushButton_Start"));

        gridLayout->addWidget(pushButton_Start, 3, 2, 1, 1);

        progressBar = new QProgressBar(veritasgui);
        progressBar->setObjectName(QString("progressBar"));
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 2, 0, 1, 3);

        label = new QLabel(veritasgui);
        label->setObjectName(QString("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        pushButton_Browse = new QPushButton(veritasgui);
        pushButton_Browse->setObjectName(QString("pushButton_Browse"));

        gridLayout->addWidget(pushButton_Browse, 1, 1, 1, 1);


        retranslateUi(veritasgui);

        QMetaObject::connectSlotsByName(veritasgui);
    } // setupUi

    void retranslateUi(QWidget *veritasgui)
    {
        veritasgui->setWindowTitle(QApplication::translate("veritasgui", "Veritas (GUI)", 0));
        pushButton_Cancel->setText(QApplication::translate("veritasgui", "Cancel", 0));
        pushButton_Start->setText(QApplication::translate("veritasgui", "Start", 0));
        label->setText(QApplication::translate("veritasgui", "Select your files: ", 0));
        pushButton_Browse->setText(QApplication::translate("veritasgui", "Browse...", 0));
    } // retranslateUi

};

namespace Ui {
    class veritasgui: public Ui_veritasgui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERITAS_GUI_H
