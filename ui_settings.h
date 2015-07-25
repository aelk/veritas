/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QCheckBox *save_check_box;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QLineEdit *user_seq_len;
    QLineEdit *min_seqs;
    QLabel *label_4;
    QCommandLinkButton *choose_directory;

    void setupUi(QWidget *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(485, 340);
        label = new QLabel(Settings);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 100, 351, 18));
        label_2 = new QLabel(Settings);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 231, 18));
        pushButton = new QPushButton(Settings);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 280, 102, 28));
        save_check_box = new QCheckBox(Settings);
        save_check_box->setObjectName(QString::fromUtf8("save_check_box"));
        save_check_box->setGeometry(QRect(230, 240, 131, 23));
        pushButton_2 = new QPushButton(Settings);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 280, 102, 28));
        label_3 = new QLabel(Settings);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(340, 40, 151, 18));
        user_seq_len = new QLineEdit(Settings);
        user_seq_len->setObjectName(QString::fromUtf8("user_seq_len"));
        user_seq_len->setGeometry(QRect(340, 90, 101, 41));
        min_seqs = new QLineEdit(Settings);
        min_seqs->setObjectName(QString::fromUtf8("min_seqs"));
        min_seqs->setGeometry(QRect(240, 30, 91, 41));
        label_4 = new QLabel(Settings);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 160, 341, 18));
        choose_directory = new QCommandLinkButton(Settings);
        choose_directory->setObjectName(QString::fromUtf8("choose_directory"));
        choose_directory->setGeometry(QRect(270, 180, 195, 41));

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QWidget *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Settings", "Change the phrase length (the default is 6): ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Settings", "Only show files with more than ", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Settings", "Apply", 0, QApplication::UnicodeUTF8));
        save_check_box->setText(QApplication::translate("Settings", "Save changes", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Settings", "Cancel", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Settings", "plagiarized phrases", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Settings", "Where do you want to save the results file to?", 0, QApplication::UnicodeUTF8));
        choose_directory->setText(QApplication::translate("Settings", "Choose directory...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
