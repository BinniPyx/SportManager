#ifndef WRESTLINGLIST_H
#define WRESTLINGLIST_H
#include <QComboBox>
#include <QWidget>
#include "grekorim.h"
#include <QDebug>
namespace Ui {
class WrestlingList;
}

class WrestlingList : public QWidget
{
    Q_OBJECT

public:
    explicit WrestlingList(QWidget *parent = nullptr);
    ~WrestlingList();

private slots:
    void on_pushButton_clicked();

    void takeData(QString str);

private:
    Ui::WrestlingList *ui;
};

#endif // WRESTLINGLIST_H
