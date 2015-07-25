#include <QtGui>
#include <QUrl>
#include <QDesktopServices>
#include "compare_files.hpp"
#include "veritas_gui.hpp"

Veritas::Veritas()
{
    setupUi(this);
    connect(pushButton_Browse, SIGNAL(clicked()), this, SLOT(getFiles()));
    connect(pushButton_Start, SIGNAL(clicked()), this, SLOT(startApp()));
    connect(pushButton_Help, SIGNAL(clicked()), this, SLOT(openREADME()));
    connect(pushButton_Exit, SIGNAL(clicked()), this, SLOT(exitApp()));
}

void Veritas::update_progress_bar(const unsigned int value)
{
    progressBar->setValue(value);
}

void Veritas::getFiles()
{
    QStringList QStrList_file_names =
        QFileDialog::getOpenFileNames(this, tr("Browse..."), "~/Desktop",
                                      tr(".txt files (*.txt)"));

    if (QStrList_file_names.size() > 0) {
        QDir dir = QFileInfo(QStrList_file_names[0]).absoluteDir();
        path = dir.absolutePath().toStdString();

        for (auto file_name : QStrList_file_names) {
            const std::string fname = file_name.toStdString();
            if (fname.find(RESULT_FILE_NAME) == std::string::npos) {
                file_names.push_back(fname);
            }
        }
    }
}

void Veritas::startApp()
{
    start_comparisons(this, file_names, path);
}

void Veritas::openREADME()
{
    QDesktopServices::openUrl(
        QUrl("https://github.com/aelk/veritas/blob/master/README.md",
             QUrl::TolerantMode));
}

void Veritas::exitApp()
{
    exit(EXIT_FAILURE);
}
