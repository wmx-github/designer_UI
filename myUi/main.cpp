#include "myUi.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myUi w;
    w.show();

    return a.exec();
}
