#ifndef MYUI_H
#define MYUI_H

#include <QMainWindow>
//前置声明
///G:\EXAMPLES_trunkwc\build-myUi-Desktop_Qt_5_5_1_MSVC2013_32bit-Debug\ui_myui.h
/// ui_myui.h 是系统生成的UI文件的用户接口(Ui_myUi这个类的子类myUi)

namespace Ui {
class myUi;
}

class myUi : public QMainWindow
{
    Q_OBJECT

public:
    explicit myUi(QWidget *parent = 0);
    ~myUi();
private slots:
    void onMyuibuttonClicked(void);
    void changeView();
private:
    Ui::myUi *ui;
};

#endif // MYUI_H
