#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <QDialog>
#include <QDate>
#include <QString>
#include "neworderform.h"
#include "irderinfo.h"



namespace Ui {
class workspace;
}

class workspace : public QDialog
{
    Q_OBJECT

public:
    explicit workspace(QWidget *parent, QString login, bool is_autorized);
    ~workspace();

signals:

public slots:

    void receiveInformation( QString name, QDate date,QString type,QString money, QString email);

    void deleteEventSlot(QDate d);

private slots:

    void on_newOrder_clicked();

    void on_logOut_clicked();

    void on_calendarWidget_clicked(const QDate &date);

private:

    Ui::workspace *ui;

    QString log;
    int activeOrders = 0;
    bool autorized;

protected:
};

#endif // WORKSPACE_H
