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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_veritas_gui
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_Cancel;
    QPushButton *pushButton_Start;
    QProgressBar *progressBar;
    QLabel *label;
    QPushButton *pushButton_Browse;

    void setupUi(QWidget *veritas_gui)
    {
        if (veritas_gui->objectName().isEmpty())
            veritas_gui->setObjectName(QStringLiteral("veritas_gui"));
        veritas_gui->setEnabled(true);
        veritas_gui->resize(400, 259);
        veritas_gui->setMinimumSize(QSize(400, 0));
        gridLayout = new QGridLayout(veritas_gui);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_Cancel = new QPushButton(veritas_gui);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));

        gridLayout->addWidget(pushButton_Cancel, 3, 0, 1, 1);

        pushButton_Start = new QPushButton(veritas_gui);
        pushButton_Start->setObjectName(QStringLiteral("pushButton_Start"));

        gridLayout->addWidget(pushButton_Start, 3, 2, 1, 1);

        progressBar = new QProgressBar(veritas_gui);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 2, 0, 1, 3);

        label = new QLabel(veritas_gui);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        pushButton_Browse = new QPushButton(veritas_gui);
        pushButton_Browse->setObjectName(QStringLiteral("pushButton_Browse"));

        gridLayout->addWidget(pushButton_Browse, 1, 1, 1, 1);


        retranslateUi(veritas_gui);

        QMetaObject::connectSlotsByName(veritas_gui);
    } // setupUi

    void retranslateUi(QWidget *veritas_gui)
    {
        veritas_gui->setWindowTitle(QApplication::translate("veritas_gui", "Veritas (GUI)", 0));
        pushButton_Cancel->setText(QApplication::translate("veritas_gui", "Cancel", 0));
        pushButton_Start->setText(QApplication::translate("veritas_gui", "Start", 0));
        label->setText(QApplication::translate("veritas_gui", "Select your files: ", 0));
        pushButton_Browse->setText(QApplication::translate("veritas_gui", "Browse...", 0));
    } // retranslateUi

};

namespace Ui {
    class veritas_gui: public Ui_veritas_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERITAS_GUI_H
