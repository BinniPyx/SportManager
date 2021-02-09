//                     Окно № 3
//
//  Добавление весовых категорий, год рождения, и остальные данные борцов
//
//
//
//
//
//
#ifndef GREKORIM_H
#define GREKORIM_H
#include "wrestlinglist.h"
#include <QDialog>
#include <QMessageBox>
#include "registr.h"
namespace Ui {
class GrekoRim;
}

class GrekoRim : public QDialog
{
    Q_OBJECT

public:
    explicit GrekoRim(QWidget *parent = nullptr);
    ~GrekoRim();
     int click=0;
     QString *year111=nullptr;
        DbConnect con;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pBweight_clicked();

    void on_pByear_clicked();

    void on_pushButton_3_clicked();

signals:
    void sendData(QString str);

private:
    Ui::GrekoRim *ui;
};

#endif // GREKORIM_H
