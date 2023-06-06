#include "irderinfo.h"
#include "ui_irderinfo.h"
#include <QDate>
#include "workspace.h"


irderinfo::irderinfo(QWidget *parent, QString name, QString date, QString type, QString money, QString email, bool is_ready) :
    QDialog(parent),
    ui(new Ui::irderinfo)
{
    ui->setupUi(this);
    ui->name->setText(name);
    ui->deadline->setText(date);
    ui->type->setText(type);
    ui->money->setText(money);
    ui->email->setText(email);
}

irderinfo::~irderinfo()
{
    delete ui;
}

void irderinfo::on_ok_btn_clicked()
{
    this->close();
}


void irderinfo::on_delete_order_btn_clicked()
{
    QString stringdate = ui->deadline->text();
    QDate d = QDate::fromString(stringdate, "dd.MM.yyyy");

    emit deleteEvent(d);

    this->close();
}


