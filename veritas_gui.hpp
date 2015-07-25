#ifndef VERITAS_GUI_HPP
#define VERITAS_GUI_HPP

#include "utils.hpp"
#include "ui_veritas_gui.hpp"
#include "ui_settings.hpp"

class Veritas : public QWidget, private Ui::veritas_gui
{
    Q_OBJECT

public:
    Veritas();
    void update_progress_bar(const unsigned int value);

public slots:
    void getFiles();
    void startApp();
    void openREADME();
    void exitApp();

private:
    Ui::veritas_gui *ui;
    std::string path;
    string_list file_names;
};

#endif
