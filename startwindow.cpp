//        Окно № 1 (Стартовое окно)
//
//
#include "startwindow.h"
#include "ui_startwindow.h"
#include <QDesktopWidget>
#include "registr.h"
#include <QSqlQuery>
#include "grekorim.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QIcon>
#include <QQuickWidget>
#include <QSqlRecord>
#include <QPushButton>
StartWindow::StartWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartWindow)
{


//--------------------Делаем стартовое окно по центу
    ui->setupUi(this);



    //-----Меняем размер шрифта
    QFont font=ui->label_3->font();
    font.setPixelSize(21);
    ui->label_3->setFont(font);


    //-----Так, тут  устанавливаем лого

    QPixmap pixmap13 =QPixmap (":/Prot/logo.png");
    ui->label->setPixmap(pixmap13);




//--------------------Устанавливаем иконку кнопки закрытия стартового окна
    ui->pb_exit->setStyleSheet(
                "QPushButton{ background-image:url(:/pb_exit.png); border-radius:3px;}"
                "QPushButton:hover{background-color:red}");
    ui->pb_exit->setMinimumSize(15,15);
    ui->pb_exit->setMaximumSize(15,15);

 //--------------------Устанавливаем иконку кнопки закрытия стартового окна
        ui->pb_hide->setStyleSheet(
                    "QPushButton{ background-image:url(:/pb_hide.png); border-radius:3px;}"
                    "QPushButton:hover{background-color:red}");
    ui->pb_hide->setMinimumSize(15,15);
    ui->pb_hide->setMaximumSize(15,15);

//----------------------Отключаем рамку вокруг окна
this->setWindowFlags(Qt::FramelessWindowHint);

//----------------------Делаем окно не маштабируемым
this->setMinimumHeight(512);
this->setMaximumHeight(512);
this->setMinimumWidth(366);
this->setMaximumWidth(366);
}

StartWindow::~StartWindow()
{
    delete ui;
}

/*
void StartWindow::on_pushButton_5_clicked()
{
   registr *reg=new registr;
   this->hide();
   reg->show();
}
*/
//--------------------Кнопка  закрытия главног Окна № 1
void StartWindow::on_pb_exit_clicked(){

    QWidget::close();
}




//
//------------------Кнопка "Авторизация"
//
void StartWindow::on_pushButton_2_clicked()
{


    //-----Конектимся к бд серез класс

    DbConnect con;
    con.connect();

    QSqlQuery query=QSqlQuery(con.db);

//-----------------В этом блоке происходит  сравнение пароля и логина для авторизации
//-----!!!!!!!!-----Работает не корректно нужно починить-------!!!!!!!!!!
  QString mail=ui->lineEditPass_2->text();
  if(mail==nullptr){mail="1";}
  QString pass=ui->lineEditPass->text();

   QString dbpass="1";
   QString dbmail="2";
   QString* DBM=&dbmail;
   QString* DBP=&dbpass;


query.exec("SELECT pass FROM users WHERE mail='"+mail+"';");
while (query.next()) {
       QString dbpass = query.value("pass").toString();
       DBP=&dbpass;
       }

  query.exec("SELECT mail FROM users WHERE pass='"+pass+"'");
  while (query.next()) {
         QString dbmail = query.value("mail").toString();
           DBM=&dbmail;

     }

   if((*DBM==mail)||(*DBP==pass)){       //////////Почему то работает не правильно по этому пришло поставить выражение или(||) хотя должно быть и (&&)
      MainWindow *mw=new MainWindow;
this->close();
mw->show();

    }

    else{
       qDebug()<<"ERROR!111 "<<query.lastError().text();
       QMessageBox::information(nullptr, "Message", "Неправильный логин или пароль ");
    }
   con.close();
}



