#include "wrestlinglist.h"
#include "ui_wrestlinglist.h"
#include <QMenuBar>
WrestlingList::WrestlingList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WrestlingList)
{
    ui->setupUi(this);

    QMenu *mMenu=new QMenu("1");
    mMenu->addAction("do");
    ui->pushButton_2->setMenu(mMenu);


}

WrestlingList::~WrestlingList()
{
    delete ui;
}

void WrestlingList::on_pushButton_clicked()
{
    GrekoRim gr;

    //qDebug()<<"wrest"<<gr.year;
}

void WrestlingList::takeData(QString str){
    qDebug()<<str;
}
