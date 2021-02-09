//             Окно № 2
// Пока что с одной кнопкой, следовательно на данном этапе разработки бесполезное
//
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "grekorim.h"
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




//
//Переход к Окну  № 3
//
void MainWindow::on_pushButton_clicked()
{
GrekoRim *gr=new GrekoRim;
this->close();
gr->show();
}
