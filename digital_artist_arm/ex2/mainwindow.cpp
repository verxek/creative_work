#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include "workspace.h"
#include <QTextStream>
#include <QFile>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->password->setEchoMode(QLineEdit::Password);

    QPixmap pix(":/img/img/malyarnaya-kist-88x128.png");
    int w = ui->image->width();
    int h = ui->image->height();

    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_autorize_clicked()  // войти
{
    QString login = ui->login->text();
    QString password = ui->password->text();
    bool bad_pass = false, authorization = false;

    QFile file("C:/Users/987/Documents/accounts.csv");
    if (!file.open(QFile::ReadOnly)){
        qDebug() << "file not open" ;

    } else {
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList item = line.split(";");
            QString login_1 = item[0];
            QString pass_1 = item[1];
            if (login == login_1)
            {if (password!=pass_1){
                    bad_pass = true;
                } else {
                    authorization = true;
                }
            }
        }
        file.close();
        if (bad_pass) ui->warning->setText("Неверный пароль!");
        else if (!authorization) ui->warning->setText("Пользователь с таким логином не найден!");
        else
        {
            this->hide();
            workspace* workspace1 = new workspace(this, login, true);
            workspace1->exec();

            ui->login->clear();
            ui->password->clear();
            ui->login->setFocus();
            this->show();
            ui->statusbar->showMessage("Вы вышли из учетной записи");

            delete workspace1;
        }
    }
}

void MainWindow::on_register_2_clicked()   // зарегистрироваться
{
    QString login = ui->login->text();
    QString password = ui->password->text();

    bool personal = true;

    QFile file("C:/Users/987/Documents/accounts.csv");
    if ( !file.open(QFile::ReadOnly) ) {
        qDebug() << "File not exists";
    }
    else {
        QTextStream in(&file);
        while (!in.atEnd() && personal)
        {
            QString line = in.readLine();
            QStringList item = line.split(";");
            if (item[0] == login) personal = false;
            QTextStream(stdout) << item[0] << " " << login << endl;
        }
        file.close();
    }
    if (personal){
        QFile file("C:/Users/987/Documents/accounts.csv");
        if ( !file.open(QFile::Append) ) {
            qDebug() <<"File not exists";
        } else {
            QTextStream out(&file);
            out << login << ";" << password <<  endl;
            file.close();
        }
    this->close();
    }
    else ui->warning->setText("Логин " + login + " занят");


    this->hide();
    workspace* workspace1 = new workspace(this, login, false);
    workspace1->exec();

    ui->login->clear();
    ui->password->clear();
    ui->login->setFocus();
    this->show();
    ui->statusbar->showMessage("Вы вышли из учетной записи");

    delete workspace1;
}







