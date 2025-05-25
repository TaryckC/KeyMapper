#include <QApplication>
#include "gui/KeyBindingInterface.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    KeyBindingInterface window;
    window.show();

    return app.exec();
}