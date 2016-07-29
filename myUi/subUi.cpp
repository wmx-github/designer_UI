#include "subUi.h"
#include "ui_myui.h"

#include <QLabel>

//#include <QUiLoader>
//#include <QFile>
subUi::subUi(QWidget *parent)
{
    QLabel *lab = new QLabel(this);
    lab->move(10, 10);
    lab->resize(80, 30);
    lab->setText("hahahaha");

//    QUiLoader loader;

//    QFile file(":/myUi/sub.ui");
//    file.open(QFile::ReadOnly);

//    QWidget *formWidget = loader.load(&file, this);
//    file.close();
//    formWidget->resize(300, 200);
//    formWidget->show();

}

subUi::~subUi()
{

}
