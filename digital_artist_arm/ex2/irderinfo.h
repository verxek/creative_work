#ifndef IRDERINFO_H
#define IRDERINFO_H

#include <QDialog>
#include <QDate>

namespace Ui {
class irderinfo;
}

class irderinfo : public QDialog
{
    Q_OBJECT

public:
    explicit irderinfo(QWidget *parent = nullptr,QString name = "", QString date = "", QString type = "", QString money = "", QString email = "", bool is_ready = false);
    ~irderinfo();


signals:

    void deleteEvent(QDate d);

private slots:
    void on_ok_btn_clicked();
    void on_delete_order_btn_clicked();

private:
    Ui::irderinfo *ui;
};

#endif // IRDERINFO_H
