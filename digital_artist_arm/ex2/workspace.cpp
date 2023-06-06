#include "workspace.h"
#include "ui_workspace.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QDate>
#include "neworderform.h"
#include <QTextCharFormat>
#include <QString>
#include <QFile>
#include "irderinfo.h"


workspace::workspace(QWidget *parent, QString login, bool is_autorized) :
    QDialog(parent),
    ui(new Ui::workspace)
{
    ui->setupUi(this);
    log = login;

    connect(ui->logOut, &QPushButton::clicked, this, &workspace::on_logOut_clicked);
    //connect(ui->newOrder, &QPushButton::clicked, this, &workspace::on_newOrder_clicked);

    ui->helloLabel->setText(login);

    if (is_autorized)
    {
        QMessageBox::information(this, "Сообщение", "С возвращением, " + login, QMessageBox::Ok);
    } else {
        QMessageBox::information(this, "Сообщение", "Добро пожаловать, "+ login, QMessageBox::Ok);
    }

    QFile file("C:/Users/987/Documents/orders.csv");
    if (!file.open(QFile::ReadOnly)){
        qDebug() << "file not open" ;

    } else {

        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList item = line.split(";");
            QString login_1 = item[0];

            if (login_1 == log && (item[6] == "0")){

                    // активные заказы помечаем зеленым

                    QString dateString = item[2];
                    QDate date = QDate::fromString(dateString, "dd.MM.yyyy");
                    QTextCharFormat eventFormat;
                    eventFormat.setBackground(Qt::green); // Устанавливаем фон для событий
                    QDate eventDate(date); // Задаем дату события
                    ui->calendarWidget->setDateTextFormat(eventDate, eventFormat);
                    activeOrders++;
            }
        }
    }
    file.close();


    QFile filecompleted("C:/Users/987/Documents/completedorders.csv");
    if (!filecompleted.open(QFile::ReadOnly)){
        qDebug() << "file not open" ;

    } else {
        QString complete = "";
        QTextStream in(&filecompleted);

        while (!in.atEnd())
        {

               QString fileContent = in.readLine();
               QStringList item = fileContent.split(";");
               if (item[0] == log)
               {
                   complete = complete + item[1] + " " + item[2] + " " + item[4] + "\n";

               }

        }
        ui->completed_orders->setText(complete);
    }

    filecompleted.close();

    ui->activeOr->setText("Количество активных заказов: " + QString::number(activeOrders));

     // отображение ближайших заказов

    QList<QStringList> orders; // Список для хранения заказов из файла CSV

    // Чтение содержимого файла CSV

    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList item = line.split(';');
            if (item[6] == "0" && item[0] == login)
                orders.append(item);
        }
        file.close();
    }

    // Заполнение лейблов данными из ближайших заказов

    if (orders.size() >=  5)
    {
        ui->urgent_1->setText(orders[0][1] + " " + orders[0][3]);
        ui->urgent_2->setText(orders[1][1] + " " + orders[1][3]);
        ui->urgent_3->setText(orders[2][1] + " " + orders[2][3]);
        ui->urgent_4->setText(orders[3][1] + " " + orders[3][3]);
        ui->urgent_5->setText(orders[4][1] + " " + orders[4][3]);
    }
    else if (orders.size() == 4)
    {
        ui->urgent_1->setText(orders[0][1] + " " + orders[0][3]);
        ui->urgent_2->setText(orders[1][1] + " " + orders[1][3]);
        ui->urgent_3->setText(orders[2][1] + " " + orders[2][3]);
        ui->urgent_4->setText(orders[3][1] + " " + orders[3][3]);
    }
    else if (orders.size() == 3)
    {
        ui->urgent_1->setText(orders[0][1] + " " + orders[0][3]);
        ui->urgent_2->setText(orders[1][1] + " " + orders[1][3]);
        ui->urgent_3->setText(orders[2][1] + " " + orders[2][3]);
    }
    else if (orders.size() == 2)
    {
        ui->urgent_1->setText(orders[0][1] + " " + orders[0][3]);
        ui->urgent_2->setText(orders[1][1] + " " + orders[1][3]);
    }
    else {
         ui->urgent_1->setText(orders[0][1] + " " + orders[0][3]);
    }

    QPixmap bkgnd("C:/Users/987/Documents/ex2/img/white.png");
       bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
       QPalette p = palette();
       p.setBrush(QPalette::Background, bkgnd);
       setPalette(p);

}

void workspace::on_newOrder_clicked()
{
    newOrderForm* orderForm = new newOrderForm(this);
    connect(orderForm, &newOrderForm::sendInfo, this, &workspace::receiveInformation);

    orderForm->exec();
    this->update();
}


workspace::~workspace()
{
    delete ui;
}

void workspace::receiveInformation(QString name, QDate date,QString type,QString money, QString email)
{
}


void workspace::deleteEventSlot(QDate d)
{
    QString current = d.toString("dd.MM.yyyy");
    QFile file("C:/Users/987/Documents/completedorders.csv");
    if ( !file.open(QFile::Append) ) {
        qDebug() <<"File append not exists";
    } else {
        QFile filesource("C:/Users/987/Documents/orders.csv");
        if ( !filesource.open(QFile::ReadOnly) ) {
            qDebug() <<"File read not exists";
        } else {
            QTextStream in(&filesource); // добавляем готовый заказ в файл с готовыми заказами

            while (!in.atEnd())
            {

            QString line = in.readLine();
            QStringList item = line.split(";");
            QString login_1 = item[0];
            QString name_1 = item[1];
            QString type_1 = item[3];
            QString money_1 = item[4];
            QString email_1 = item[5];
            QString dateString = item[2];
            QString login = this->log;

            if ((login_1 == login) && (current == dateString))
            {
                QTextStream out(&file);
                out << login << ";" << name_1 << ";" << dateString << ";" <<  type_1 << ";" <<  money_1 << ";" <<  email_1  << endl;

            }
        }
    }


    file.close();
    filesource.close();

    QString filePath = "C:/Users/987/Documents/orders.csv";

        // Открыть файл в режиме чтения и записи
        QFile file(filePath);
        if (!file.open(QFile::ReadWrite | QFile::Text))
        {
            qDebug() << "Не удалось открыть файл";
        } else {

            // Создать объект QTextStream для чтения и записи файла
            QTextStream stream(&file);

            // Прочитать все строки из файла в список
            QStringList lines;
            while (!stream.atEnd())
            {
                QString line = stream.readLine();
                lines.append(line);
            }


            int targetIndex = 0; // Индекс целевой строки
            for (int i = 0; i < lines.size(); i++)
            {
                QStringList item = lines[i].split(";");
                QString login = this->log;
                if (current == item[2] && login == item[0])
                {
                    targetIndex = i;
                }
            }

            // Проверить, что целевой индекс находится в пределах списка строк
            if (targetIndex >= 0 && targetIndex < lines.size())
            {
                // Получить целевую строку
                QString targetLine = lines[targetIndex];

                // Разбить строку на элементы с помощью разделителя ";"
                QStringList elements = targetLine.split(';');

                // Изменить нужные элементы
                elements[6] = "1";

                // Соединить элементы обратно в строку, используя разделитель ";"
                QString newLine = elements.join(';');

                // Заменить целевую строку на новую строку
                lines[targetIndex] = newLine;
            }
            else
            {
                qDebug() << "Недопустимый индекс строки";
            }

            // Перезаписать все строки в файл
            file.resize(0); // Очистить содержимое файла
            for (const QString& line : lines)
            {
                stream << line << endl;
            }

        }
        // Закрыть файл
        file.close();
    }
}


void workspace::on_logOut_clicked()
{
    this->close();
    MainWindow* mainwindow = new MainWindow(this);
    mainwindow->show();
}

void workspace::on_calendarWidget_clicked(const QDate &date)
{
    QDate current = date;
    QFile file("C:/Users/987/Documents/orders.csv");
    if (!file.open(QFile::ReadOnly)){
        qDebug() << "file not open" ;

    } else {

        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList item = line.split(";");

            QString name1 = item[1];
            QString type1 = item[3];
            QString money1 = item[4];
            QString email1 = item[5];
            QString login = this->log;

            QString newstringdate = item[2];
            QDate newdate = QDate::fromString(newstringdate, "dd.MM.yyyy");

            if (current == newdate)
            {
                irderinfo* infowindow = new irderinfo(this, name1, newstringdate, type1,  money1,email1, false);
                infowindow->show();
                connect(infowindow, &irderinfo::deleteEvent, this, &workspace::deleteEventSlot);
            }
        }
    }
    this->update();
    file.close();
}



