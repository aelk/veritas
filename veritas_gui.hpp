#ifndef VERITAS_GUI_HPP
#define VERITAS_GUI_HPP

#include <vector>
#include <string>
#include "ui_veritas_gui.hpp"

class Veritas : public QWidget, private Ui::veritasgui
{
    Q_OBJECT

public:
    Veritas(QWidget *parent = 0);
    void update_progress_bar(int value);

public slots:
    void getFiles();
    void startApp();

private:
    Ui::veritasgui *ui;
    std::vector<std::string> file_names;
};

#endif
