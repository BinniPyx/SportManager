#pragma once

#ifndef REGISTR_H
#define REGISTR_H
#include "QSqlDatabase"
#include <QDialog>
#include <QDebug>
#include <QSqlError>
namespace Ui {
class DbConnect;
class registr;
}

class DbConnect{
public:
    QSqlDatabase db;
public:
    void connect(){
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setHostName("127.0.0.1");
        db.setDatabaseName("/home/alex/Desktop/SportTest/SportManagerNew-master/users.sqlite");
        db.setUserName("root");
        db.setPassword("");
       db.open();
       if(!db.open()){
           qDebug()<<db.lastError();
       }
    }
    /*void connect(){
               QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
               db.setDatabaseName("users.db");


    }*/
    void close(){ db.close();}
};

class registr : public QDialog
{
    Q_OBJECT

public:
    explicit registr(QWidget *parent = nullptr);
    ~registr();

private slots:
    void on_pushButton_3_clicked();



private:
    Ui::registr *ui;
};

#endif // REGISTR_H
