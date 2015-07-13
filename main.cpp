#include <QApplication>
#include "veritas_gui.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Veritas *dialog = new Veritas;
    dialog->show();
    return app.exec();
}
