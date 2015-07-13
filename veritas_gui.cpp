//#include <QtWidgets>
#include <QtGui>
#include "compare_files.hpp"
#include "veritas_gui.hpp"

Veritas::Veritas(QWidget *parent)
{
    setupUi(this);
    connect(pushButton_Browse, SIGNAL(clicked()), this, SLOT(getFiles()));
    connect(pushButton_Start, SIGNAL(clicked()), this, SLOT(startApp()));
}

void Veritas::getFiles()
{
    QStringList QStrList_file_names =
        QFileDialog::getOpenFileNames(this, tr("Browse..."), "~/", tr(".txt files (*.txt)"));

    for (auto file_name : QStrList_file_names) {
        file_names.push_back(file_name.toStdString());
    }
}

void Veritas::startApp()
{
    start_comparisons(file_names, this);
}

void Veritas::update_progress_bar(int value)
{
    progressBar->setValue(value);
}
