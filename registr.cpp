#include "registr.h"
#include "ui_registr.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QMessageBox>
registr::registr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registr)
{
    ui->setupUi(this);
}

registr::~registr()
{
    delete ui;
}

void registr::on_pushButton_3_clicked()
{       //-----Конектимся к бд серез класс
    DbConnect con;
    con.connect();
        //-----Создаем переменную через которую будем выполнять запросы
    QSqlQuery query=QSqlQuery(con.db);
        //-----Создаем переменные в которые сохраняем регистрационные данные пользователя
  QString pass=ui->lineEdit_Pass->text();
  QString rpPass=ui->lineEdit_repeatPass->text();
  QString country=ui->lineEdit_Country->text();
  QString name=ui->lineEdit_Name->text();
  QString surname=ui->lineEdit_surname->text();
  QString mail=ui->lineEdit_mail->text();


    if((query.exec("SELCECT id FROM user WHERE (mail='"+mail+"')")==false)&&(ui->lineEdit_Pass->text()==ui->lineEdit_repeatPass->text())){
        if(!query.exec("INSERT INTO users VALUES ('"+country+"','"+name+"','"+surname+"','"+pass+"','"+mail+"')  ")){

            QString d= query.lastQuery();
                  QTextStream Qcout(stdout);
            Qcout << d;
        }


    }
    else{
        QMessageBox::information(nullptr, "Message", "Пользователь с таким эмейлом уже зарегистрирован или пароли не совпадают ");
    }
}


