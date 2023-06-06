#include "spravka.h"
#include "ui_spravka.h"

spravka::spravka(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::spravka)
{
    ui->setupUi(this);
}

spravka::~spravka()
{
    delete ui;
}

void spravka::on_okbtn_clicked()
{
    close();
}

