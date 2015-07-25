/********************************************************************************
** Form generated from reading UI file 'veritas_gui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
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

class Ui_veritas_gui
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_Start;
    QPushButton *pushButton_Exit;
    QLabel *label;
    QPushButton *pushButton_Browse;
    QProgressBar *progressBar;
    QPushButton *pushButton_Help;

    void setupUi(QWidget *veritas_gui)
    {
        if (veritas_gui->objectName().isEmpty())
            veritas_gui->setObjectName(QString::fromUtf8("veritas_gui"));
        veritas_gui->setEnabled(true);
        veritas_gui->resize(400, 316);
        veritas_gui->setMinimumSize(QSize(400, 300));
        veritas_gui->setMaximumSize(QSize(500, 316));
        QFont font;
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        font.setKerning(true);
        veritas_gui->setFont(font);
        gridLayout = new QGridLayout(veritas_gui);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_Start = new QPushButton(veritas_gui);
        pushButton_Start->setObjectName(QString::fromUtf8("pushButton_Start"));

        gridLayout->addWidget(pushButton_Start, 3, 2, 1, 1);

        pushButton_Exit = new QPushButton(veritas_gui);
        pushButton_Exit->setObjectName(QString::fromUtf8("pushButton_Exit"));

        gridLayout->addWidget(pushButton_Exit, 3, 0, 1, 1);

        label = new QLabel(veritas_gui);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        pushButton_Browse = new QPushButton(veritas_gui);
        pushButton_Browse->setObjectName(QString::fromUtf8("pushButton_Browse"));

        gridLayout->addWidget(pushButton_Browse, 1, 1, 1, 1);

        progressBar = new QProgressBar(veritas_gui);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 2, 0, 1, 3);

        pushButton_Help = new QPushButton(veritas_gui);
        pushButton_Help->setObjectName(QString::fromUtf8("pushButton_Help"));

        gridLayout->addWidget(pushButton_Help, 3, 1, 1, 1);


        retranslateUi(veritas_gui);

        QMetaObject::connectSlotsByName(veritas_gui);
    } // setupUi

    void retranslateUi(QWidget *veritas_gui)
    {
        veritas_gui->setWindowTitle(QApplication::translate("veritas_gui", "Veritas", 0, QApplication::UnicodeUTF8));
        pushButton_Start->setText(QApplication::translate("veritas_gui", "Start", 0, QApplication::UnicodeUTF8));
        pushButton_Exit->setText(QApplication::translate("veritas_gui", "Exit", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("veritas_gui", "Select your files: ", 0, QApplication::UnicodeUTF8));
        pushButton_Browse->setText(QApplication::translate("veritas_gui", "Browse...", 0, QApplication::UnicodeUTF8));
        pushButton_Help->setText(QApplication::translate("veritas_gui", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class veritas_gui: public Ui_veritas_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERITAS_GUI_H
