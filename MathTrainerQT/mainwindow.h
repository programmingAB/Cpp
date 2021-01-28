#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QtSql>
#include <QRandomGenerator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool nameCheck(QString name);
    void easyGame();

    //void keyPressEvent(QKeyEvent * e);

private slots:
    void on_ButtonStart_clicked();

    void on_ButtonBest_Score_clicked();

    void on_PlayButton_clicked();

    void on_pushButton_2_clicked();
    void updateTime();

private:
    Ui::MainWindow *ui;
    QSqlDatabase con;
    QSqlQuery sqlDB;
    int gen1;
    int gen2;
    int timer=30;
    QTimer *tmr;

};
#endif // MAINWINDOW_H
