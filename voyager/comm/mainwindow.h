#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QGridLayout>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private:
    Ui::MainWindow *ui;

    int col = 0;

    bool paint = false;
    int mat[50][50];
    int first, last;
    int d = 150, h = 360;
    int x = 400;
    int y = 200;

    QBrush front, back;
    QFont glFont;
    QPen textPen;

protected:
    void paintEvent(QPaintEvent*) override;

private slots:

    void on_table_btn_clicked();
    void on_visual_btn_clicked();
    void on_first_btn_clicked();
    void on_last_btn_clicked();

};
#endif // MAINWINDOW_H
