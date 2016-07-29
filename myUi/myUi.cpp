#include "myUi.h"
#include "ui_myui.h"

#include "subUi.h"

#include <QFile>

#include <QUiLoader>
#include <QString>

myUi::myUi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::myUi)
{
    ui->setupUi(this);
    //信号槽连接
    connect(ui->myUiButton, SIGNAL(clicked(bool)), this, SLOT(onMyuibuttonClicked()));

//    ui->menuBar->addMenu("a");
//    ui->menuBar->addMenu("b");
//    ui->menuBar->addMenu("c");

    ////////////菜单栏////////////////
    /// \brief a
    ///
    QMenu *a = new QMenu("a");
    QMenu *b = new QMenu("b");
    QMenu *c = new QMenu(QStringLiteral("工具栏"));

    //动作
    QAction *open = new QAction(QStringLiteral("打开"), this);
    QAction *save = new QAction(QStringLiteral("保存"), this);
    QAction *close = new QAction(QStringLiteral("关闭"), this);
    open->setIcon(QIcon(":/mySource/open"));
    save->setIcon(QIcon(":/mySource/panel"));
    close->setIcon(QIcon(":/mySource/ZoomPlus"));

    //菜单添加动作
    a->addAction(open);
    a->addAction(save);
    a->addAction(close);

    b->addAction(open);
    b->addAction(save);
    b->addAction(close);

    //菜单栏添加菜单
    ui->menuBar->addMenu(a);
    ui->menuBar->addMenu(b);
    ui->menuBar->addMenu(c);

    connect(open, SIGNAL(triggered(bool)), ui->myUiButton, SLOT(show()));
    connect(close, SIGNAL(triggered(bool)), ui->myUiButton, SLOT(hide()));
    connect(save, SIGNAL(triggered(bool)), ui->myUiButton, SLOT(click()));

    ////////////工具栏////////////////
    /// \brief a
    ///

    QAction *toolBar1Action = new QAction(QStringLiteral("工具栏1"), this);
    QAction *toolBar2Action = new QAction(QStringLiteral("工具栏2"), this);
    QAction *toolBar3Action = new QAction(QStringLiteral("工具栏3"), this);

    //工具栏菜单C
    c->addAction(toolBar1Action);
    c->addAction(toolBar2Action);
    c->addAction(toolBar3Action);

    //第一个工具栏
    ui->toolBar_1->addAction(open);
    ui->toolBar_1->addAction(save);
    ui->toolBar_1->addAction(close);

    //只是文字
    //ui->toolBar_1->setToolButtonStyle(Qt::ToolButtonTextOnly);

    //只是图片
    //ui->toolBar_1->setToolButtonStyle(Qt::ToolButtonIconOnly);

    //图片文字
    //ui->toolBar_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    //文字在图片下方
    ui->toolBar_1->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    connect(toolBar1Action, SIGNAL(triggered(bool)), this, SLOT(changeView()));
    connect(toolBar2Action, SIGNAL(triggered(bool)), ui->toolBar_2, SLOT(close()));
    connect(toolBar3Action, SIGNAL(triggered(bool)), ui->toolBar_3, SLOT(close()));


    ///动态加载Ui文件
    ///

    QUiLoader loader;

    QFile file("G:/myExamples/myUi/sub.ui");
    file.open(QFile::ReadOnly);

    QWidget *formWidget = loader.load(&file, 0);
    file.close();
    formWidget->move(100, 100);
    formWidget->resize(300, 200);
    formWidget->hide();

    //窗口关联打开关闭动作
    connect(open, SIGNAL(triggered(bool)), formWidget, SLOT(show()));
    connect(close, SIGNAL(triggered(bool)), formWidget, SLOT(hide()));
}

myUi::~myUi()
{
    delete ui;
}

#include <QDebug>
int i = 0;
void myUi::onMyuibuttonClicked()
{
    qDebug() << QString("myUiButton clicked %1").arg(i++);
}

int k = 0;
void myUi::changeView()
{
    if(k%2 == 1){
        ui->toolBar_1->show();
    } else {
        ui->toolBar_1->hide();
    }
    k++;
}
