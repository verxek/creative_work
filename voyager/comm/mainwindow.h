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

    int col = 0;
    int x = 400;
    int y = 200;
    bool ris = false;
    int mat[512][512];
    int first, last, rast = 150, h = 360;
    QBrush front, back;
    QFont glFont;
    QPen textPen;

    ~MainWindow();

private:
    Ui::MainWindow *ui;

protected:
    void paintEvent(QPaintEvent*) override;

private slots:

    void on_table_btn_clicked();
    void on_visual_btn_clicked();
    void on_first_btn_clicked();
    void on_last_btn_clicked();

};
#endif // MAINWINDOW_H
