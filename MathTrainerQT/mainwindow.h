#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define ETS 30 //easy timer start
#include <chart.h>
#include <QMainWindow>
#include <QtSql/QtSql>
#include <QRandomGenerator>


#include <QtCharts>
#include <QChartView>
#include <QLine>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//QT_CHARTS_USE_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool nameCheck(QString name);
    void easyGame();
    QLineSeries *series = new QLineSeries();
    QChart *chart = new QChart();
    QChartView *chartView = new QChartView(chart);


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
    int easyTimer=30;
    QTimer *tmr;
    int easyLvl=1;
    bool isPlaying=false;
    int playerID=0;
    void testfunk();


};
#endif // MAINWINDOW_H
