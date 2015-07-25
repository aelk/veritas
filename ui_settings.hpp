/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
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

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(485, 340);
        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 100, 351, 18));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 231, 18));
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(320, 280, 102, 28));
        save_check_box = new QCheckBox(Form);
        save_check_box->setObjectName(QStringLiteral("save_check_box"));
        save_check_box->setGeometry(QRect(230, 240, 131, 23));
        pushButton_2 = new QPushButton(Form);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 280, 102, 28));
        label_3 = new QLabel(Form);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(340, 40, 151, 18));
        user_seq_len = new QLineEdit(Form);
        user_seq_len->setObjectName(QStringLiteral("user_seq_len"));
        user_seq_len->setGeometry(QRect(340, 90, 101, 41));
        min_seqs = new QLineEdit(Form);
        min_seqs->setObjectName(QStringLiteral("min_seqs"));
        min_seqs->setGeometry(QRect(240, 30, 91, 41));
        label_4 = new QLabel(Form);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 160, 341, 18));
        choose_directory = new QCommandLinkButton(Form);
        choose_directory->setObjectName(QStringLiteral("choose_directory"));
        choose_directory->setGeometry(QRect(270, 180, 195, 41));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        label->setText(QApplication::translate("Form", "Change the phrase length (the default is 6): ", 0));
        label_2->setText(QApplication::translate("Form", "Only show files with more than ", 0));
        pushButton->setText(QApplication::translate("Form", "Apply", 0));
        save_check_box->setText(QApplication::translate("Form", "Save changes", 0));
        pushButton_2->setText(QApplication::translate("Form", "Cancel", 0));
        label_3->setText(QApplication::translate("Form", "plagiarized phrases", 0));
        label_4->setText(QApplication::translate("Form", "Where do you want to save the results file to?", 0));
        choose_directory->setText(QApplication::translate("Form", "Choose directory...", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
