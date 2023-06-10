#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <QVector>
#include <QString>
#include <QPainter>
#include <QGridLayout>
#include <QPushButton>
#include <iostream>
#include <QMessageBox>
#include <QDebug>
using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_first_btn_clicked() // прием первого элемента графа
{
    if ((((ui->textEdit_2->toPlainText()).toInt() <= col) && (ui->textEdit_2->toPlainText()).toInt() > 1))
    {
        first = (ui->textEdit_2->toPlainText()).toInt();
    } else {
        first = 1;
    }
    QString he;

    ui->textEdit_2->setText(he.setNum(first));
}

void MainWindow::on_last_btn_clicked() // прием последнего элемента графы
{
    if ((((ui->textEdit_3->toPlainText()).toInt() < col) && (ui->textEdit_3->toPlainText()).toInt() >= 1))
    {
        last = (ui->textEdit_3->toPlainText()).toInt();
    } else {
        last = col;
    }
    QString he;

    ui->textEdit_3->setText(he.setNum(last));
}
void MainWindow::on_visual_btn_clicked()
{

    if ((((ui->textEdit_3->toPlainText()).toInt() < col) && (ui->textEdit_3->toPlainText()).toInt() >= 1))
    {
        last = (ui->textEdit_3->toPlainText()).toInt();
    } else {
        last = col;
    }
    if ((((ui->textEdit_2->toPlainText()).toInt() <= col) && (ui->textEdit_2->toPlainText()).toInt() > 1))
    {
        first = (ui->textEdit_2->toPlainText()).toInt();
    } else {
        first = 1;
    }

    if (last == first)
    {
        last = col;
        first = 1;
        QString sq = QString::number(last);
        ui->textEdit_2->setText("1");
        ui->textEdit_3->setText(sq);
    }
    int mat1[col][col];
    int way[100];
    long int var = 0;
    long int min = 10000;
    long int min_way;

    for (int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        for (int j = 0; j < ui->tableWidget->columnCount(); j++)
        {
            int h = (ui->tableWidget->item(i, j)->text()).toInt();
            mat1[i][j] = h;
            if ((h <= 0) || (h >= 1000))
            {
                mat[i][j] = 1000;
            }
            if ((h > 0) || (h < 1000))
            {
                mat[i][j] = h;
            }
        }
        first--;
        last--;
        switch (col) {
        case 3:

            for (int i2 = 0; i2 < col; i2++)
            {
                if ((first != i2) && (first != last) && (i2 != last))
                {
                    way[var] = ((first + 1) * 10 + (i2 + 1)) * 10 + last + 1;

                    if (mat[first][i2] + mat[i2][last] < min)
                    {
                        min = mat[first][i2] + mat[i2][last];
                        min_way = way[var];

                    }
                    var++;
                }
            }
        case 4:

            for (int i2 = 0; i2 < col; i2++)
            {
                for (int i3 = 0; i3  < col; i3++)
                {
                    if ((first != i2) && (first != i3) && (first != last) && (i3 != i2) && (i2 != last) && (i3 != last))
                    {
                        way[var] = ((((first + 1) * 10 + (i2 + 1)) * 10 + (i3 + 1)) * 10) + last + 1;
                        cout << way[var];
                        if ((mat[first][i2] + mat[i2][i3] + mat[i3][last]) < min)
                        {
                            min = mat[first][i2] + mat[i2][i3] + mat[i3][last];
                            min_way = way[var];

                        }
                        var++;
                    }
                }
            }

        case 5:

            for (int i2 = 0; i2 < col; i2++)
            {
                for (int i3 = 0; i3  < col; i3++)
                {
                    for (int i4 = 0; i4  < col; i4++)
                    {
                        if ((first != i2) && (first != i3) && (first != i4) &&
                                (first != last) && (i2 != i4) && (i2 != i3 ) &&
                                (i2 != last) && (i3 != i4) && (i3 != last) && (i4 != last))
                        {
                            way[var] = (((((first + 1) * 10 + (i2 + 1)) * 10 + (i3 + 1)) * 10) + (i4 + 1)) * 10 + last + 1;

                            if (mat[first][i2] + mat[i2][i3] + mat[i3][i4] + mat[i4][last] < min)
                            {
                                min = mat[first][i2] + mat[i2][i3] + mat[i3][i4] + mat[i4][last];
                                min_way = way[var];

                            }
                            var++;
                        }
                    }
                }
            }

        case 6:

            for (int i2 = 0; i2 < col; i2++)
            {
                for (int i3 = 0; i3  < col; i3++)
                {
                    for (int i4 = 0; i4  < col; i4++)
                    {
                        for (int i5 = 0; i5  < col; i5++)
                        {
                            if ((first != i2) && (first != i3) && (first != i4) && (first != i5) &&
                                    (first != last) && (i2 != i4) && (i2 != i3 ) && (i2 != i5) &&
                                    (i2 != last) && (i3 != i4) && (i4 != last) && (i3 != i5) && (i3 != last) && (i4 != last) &&
                                    (i4 != i5) && (i5 != last))
                            {
                                way[var] = (((((((first+1) * 10 + (i2+1)) * 10 + (i3+1)) * 10) + (i4+1)) * 10 + (i5+1)) * 10) + last + 1;

                                if ((mat[first][i2] + mat[i2][i3] + mat[i3][i4] + mat[i4][i5] + mat[i5][last]) < min)
                                {
                                    min = mat[first][i2] + mat[i2][i3] + mat[i3][i4] + mat[i4][i5] + mat[i5][last];
                                    min_way = way[var];

                                }
                                var++;
                            }
                        }
                    }
                }
            }

        case 7:

            for (int i2 = 0; i2 < col; i2++)
            {
                for (int i3 = 0; i3  < col; i3++)
                {
                    for (int i4 = 0; i4  < col; i4++)
                    {
                        for (int i5 = 0; i5  < col; i5++)
                        {
                            for (int i6 = 0; i6 < col; i6++)
                            {
                                if ((first != i2) && (first != i3) && (first != i4) && (first != i5) && (first != i6) &&
                                        (first != last) && (i2 != i4) && (i2 != i3 ) && (i2 != i5) && (i2 != i6) &&
                                        (i2 != last) && (i3 != i4) && (i3 != i5) && (i3 != i6) && (i3 != last) && (i4 != last) &&
                                        (i4 != i5) && (i4 != i6) && (i4 != last) && (i5 != last) && (i5 != i6) && (i6 != last))
                                {
                                    way[var] = (((((((first+1) * 10 + (i2+1)) * 10 + (i3+1)) * 10) + (i4+1)) * 10 + (i5+1)) * 10 + (i6+1)) * 10 + last + 1;

                                    if (mat[first][i2] + mat[i2][i3] + mat[i3][i4] + mat[i4][i5] + mat[i5][i6] + mat[i6][last] < min)
                                    {
                                        min = mat[first][i2] + mat[i2][i3] + mat[i3][i4] + mat[i4][i5] + mat[i5][i6] + mat[i6][last];
                                        min_way = way[var];

                                    }
                                    var++;
                                }
                            }

                        }
                    }
                }
            }
        }
    }




    QString s = QString::number(min_way);
    ui->label->setText(s);
    int ras= 0; int num[col];
    for (int i = 0; i < col; i++)
    {
        num[i] = min_way % 10;

        min_way = min_way / 10;


    }


    for (int i = 0; i < col-2; i++)
    {
        int a = num[i+1];
        int b = num[i+2];
        qDebug() << a << b;
        qDebug() << mat1[a][b];
        ras = ras + (mat1[a][b]);


    }


    QString st = QString::number(ras);
    ui->label_2->setText(st);
    paint = true;

}


void MainWindow::on_table_btn_clicked() // построение матрицы смежности
{

    if (((ui->textEdit->toPlainText()).toInt()<8)|| (ui->textEdit->toPlainText()).toInt()>1)
    {
        col = (ui->textEdit->toPlainText()).toInt();
    }
    else {
        col = 2;
    }

    ui->tableWidget->setRowCount(col);
    ui->tableWidget->setColumnCount(col);

    first = 1;
    last = col;

    ui->textEdit_2->setText("1");
    ui->textEdit_2->setText(ui->textEdit->toPlainText());

    for (int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        for (int j = 0; j < ui->tableWidget->columnCount(); j++)
        {
            QTableWidgetItem* item = ui->tableWidget->item(i, j);
            if (i == j)
            {
                ui->tableWidget->setItem(i, j, new QTableWidgetItem("1000"));
                ui->tableWidget->item(i, j)->setBackground(QColor(60, 179, 113));
            } else {
                if (item == NULL) {
                    ui->tableWidget->setItem(i, j, new QTableWidgetItem("100"));
                }
            }
        }
    }
}

void MainWindow::paintEvent(QPaintEvent*) // визуализация графа
{
    if (paint == true)
    {
        QPainter painter;
        painter.begin(this);

        int R = 300;
        int r = 40;
        double pi = 3.1415;
        int HeightText = 30;
        int xa = 1000;
        int ya = 600;

        int disp = 60;

        front = QBrush(QColor(60, 179, 113));
        back = QBrush(QColor(200,200,200));
        textPen = QPen(QColor(33,33,33));

        painter.setBrush(front);
        painter.setPen(textPen);
        painter.setFont(glFont);
        textPen.setWidth(4);

        for (int i = 0; i < col; i++)
        {
            double a = pi*3/2+pi*2/col*i;
            int xc = cos(a)*R+xa;
            int yc = sin(a)*R+ya;
            int c1 = xc-20;
            int c2 = yc - HeightText/2;
            int c3 = 40;
            int c4 = HeightText;
            int mat1[256][256];

            QString text; text.setNum(i+1);
            painter.drawEllipse(QRectF(xc-r, yc-r, 2*r, 2*r));
            painter.drawText(QRect(c1,c2,c3,c4), Qt::AlignCenter, text);

            for (int k = 0; k < col; k++)
            {
                if (i != k)
                {
                    mat1[i][k] = mat[i][k];
                    if (mat1[i][k] != mat1[k][i])
                    {  // линия
                        double a2 = pi*3/2 + pi*2/col*k;
                        double xc2 = cos(a2)*R+xa;
                        double yc2 = sin(a2)*R+ya;
                        double l = sqrt((xc2-xc)*(xc2-xc)+(yc2-yc)*(yc2-yc));

                        int xl1 = (xc2-xc)/l*r+xc;
                        int yl1 = (yc2-yc)/l*r+yc;
                        int xl2 = xc2-(xc2-xc)/l*r;
                        int yl2 = yc2-(yc2-yc)/l*r;

                        painter.drawLine(xl1,yl1,xl2,yl2);
                        // текст
                        c1 = (xl2+xl1)/2-20+qrand()%disp-disp/2;
                        c2 = (yl2+yl1)/2 - HeightText/2+qrand()%disp-disp/2;
                        c3 = 40;
                        c4 = HeightText;
                        text.setNum(mat[i][k]);
                        painter.drawText(QRect(c1,c2,c3,c4), Qt::AlignCenter, text);

                    }
                }
            }
        }
    }

}
