//                     Окно № 3
//
//  Добавление весовых категорий, год рождения, и остальные данные борцов
//
//
//
//
//
//
#include "grekorim.h"
#include "ui_grekorim.h"

#include <QtDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
GrekoRim::GrekoRim(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GrekoRim)
{

    ui->setupUi(this);
    ui->label->setStyleSheet("QLabel {"
    "border-style: solid;"
    "border-width: 1px;"
    "border-color: black; "
    "}");

//              Не помню что за блок кода. Пусть пока повисит тут.
//QSqlQuery query=QSqlQuery(con.db);
 /*for(int i=0;i<click;i++){
     QString ii=QString::number(i);
    query.exec("SELECT weight WHERE id = '"+ii+"'");
    QString data=query.value(0).toString();
     ui->cBweight->addItem(data);
 }*/

}

GrekoRim::~GrekoRim()
{
    delete ui;
    con.close();
}

//
//Даннаая функция выполняет добавление данных борцов в таблицу
//
void GrekoRim::on_pushButton_clicked()
{

    QString name=ui->name->text();
    QString sName=ui->sName->text();
    QString fName=ui->fName->text();
    QString town= ui->town->text();
    QString sClub= ui->sportClub->text();
    QString SCategory=ui->sCategory->text();
    QString weight=ui->cBweight->currentText();
    QString year=ui->cBweight_2->currentText(); //cBYear
  DbConnect con;
  QSqlQuery query=QSqlQuery(con.db);
  if(!(query.exec("INSERT INTO Wrestlers VALUES ('"+name+"','"+sName+"','"+fName+"','"+weight+"','"+year+"','"+town+"','"+sClub+"','"+SCategory+"')"))){
      qDebug()<<query.lastError().text();
  }
    QSqlTableModel* modelw=new QSqlTableModel(nullptr,con.db);
    modelw->setTable("Wrestlers");
    modelw->select();
    ui->tableView_2->setModel(modelw);
    con.close();
    con.connect();
}




//
// Кнопка с названием "Завершить". Не помню для чего нужна
//

void GrekoRim::on_pushButton_2_clicked()
{
    //-----Конектимся к бд серез класс
  /*  DbConnect con;
    con.connect();
        //-----Создаем переменную через которую будем выполнять запросы
    QSqlQuery query=QSqlQuery(con.db);
        //нажимая на кнопку завершить создаем таблицы с кол-вом введенных весовых категорий
    for(int i=0; i<ui->listWidget->count();++i)
    {
          //QListWidgetItem *item = ui->listWidget->item(i);
QString str= ui->listWidget->item(i)->text();

              //-----Создаем переменные
        //  query.exec("CREATE TABLE weight('"+item+"' int,  );");

          QTextStream Qcout(stdout);
     Qcout << str;

    }
*/
}




//
// Кнопка добавить(находится под добавлением весовых категорий-->> следовательно для этого и нужна)
//
void GrekoRim::on_pBweight_clicked()
{

      QSqlQuery query=QSqlQuery(con.db);
         QString weight=ui->lEweight->text();
      if(!(query.exec("INSERT INTO Weight VALUES ('"+weight+"');"))){
          qDebug()<<query.lastError().text();

      }
    QSqlTableModel* model=new QSqlTableModel(nullptr,con.db);
    model->setTable("Weight");
    model->select();
    ui->tableView->setModel(model);
if(!(query.exec("SELECT weight FROM Weight;"))){
qDebug()<<query.lastError().text();
}
while (query.next()) {
       QString w = query.value("weight").toString();
        ui->cBweight->addItem(w);

   }
  con.close();


}




//
// Кнопка добавить(находится под добавлением Года-->> следовательно для этого и нужна)
//
void GrekoRim::on_pByear_clicked()
{


    QSqlQuery queryy=QSqlQuery(con.db);
    QString year=ui->lEyear->text();
    if(!(queryy.exec("INSERT INTO Year (year) VALUES ('"+year+"');"))){
        qDebug()<<queryy.lastError().text();
    }
    QSqlTableModel* modely=new QSqlTableModel(nullptr,con.db);
    modely->setTable("Year");
    modely->select();
    ui->tableViewYear->setModel(modely);
    if(!(queryy.exec("SELECT year FROM Year;"))){
    qDebug()<<queryy.lastError().text();
    }
    while (queryy.next()) {
           QString y = queryy.value("year").toString();
            ui->cBweight_2->addItem(y);
            ui->comboBox->addItem(y);
            ui->comboBox_2->addItem(y);
            ui->comboBox_3->addItem(y);
            ui->comboBox_4->addItem(y);
            ui->comboBox_5->addItem(y);
            ui->comboBox_6->addItem(y);
             ui->comboBox_7->addItem(y);
              ui->comboBox_8->addItem(y);

       }
    con.close();
    con.connect();
}




//
// Находится под "Установить разницу в годах"
//Завершает выполнение операций на Окне № 3. Открывает Окно № 4
void GrekoRim::on_pushButton_3_clicked()
{


  QString year1=ui->comboBox_2->currentText();
   QString year2=ui->comboBox_3->currentText();
    QString year3=ui->comboBox_4->currentText();
     QString year4=ui->comboBox_5->currentText();
      QString year5=ui->comboBox_6->currentText();
       QString year6=ui->comboBox_7->currentText();
        QString year7=ui->comboBox_8->currentText();
        if((year1==nullptr)&&(year1==nullptr)&&(year2==nullptr)&&(year3==nullptr)&&(year4==nullptr)&&(year5==nullptr)&&(year6==nullptr)&&(year7==nullptr)){
                        QMessageBox::information(nullptr, "Message", "Введите года");
        }
        WrestlingList *wl=new WrestlingList;
        sendData(year1);
        connect(this, SIGNAL(sendDATA()), wl,SLOT(takeData()));
        this->close();

        wl->show();

}
