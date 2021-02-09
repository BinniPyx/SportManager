#ifndef STARTWINDOW_H
#define STARTWINDOW_H
#include <QSqlDatabase>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
//class DbConnect;
class StartWindow;
}
QT_END_NAMESPACE


class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString *dbp=nullptr;
     QString *dbm=nullptr;
    StartWindow(QWidget *parent = nullptr);

    ~StartWindow();

private slots:


    void on_pushButton_2_clicked();


    
    void on_pb_exit_clicked();

private:
    Ui::StartWindow *ui;
};
#endif // STARTWINDOW_H
