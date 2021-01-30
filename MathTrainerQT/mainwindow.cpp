#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QListWidgetItem>
#include <QDebug>
#include <QTimer>

//#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tmr=new QTimer(this);

    //SIGNALS
    connect(tmr, SIGNAL(timeout()), this, SLOT(updateTime()));


    // Create DB connection
    con = QSqlDatabase::addDatabase("QSQLITE");
    con.setDatabaseName("mathTrainer.db");
    if(!con.open())
    {
        QMessageBox mb;
        mb.setText("DB is not opened");
        mb.exec();
        return;
    }
    sqlDB = QSqlQuery(con);

    // DB create
    sqlDB.exec("CREATE TABLE players "
        "(ID INTEGER NOT NULL UNIQUE,"
        "name TEXT UNIQUE,"
        "res4E INTEGER, res3E INTEGER, res2E INTEGER, res1E INTEGER, resE INTEGER,"
        "reas4N INTEGER, res3N INTEGER, res2N INTEGER, res1N INTEGER, resN INTEGER,"
        "res4H INTEGER, res3H INTEGER, res2H INTEGER, res1H INTEGER, resH INTEGER,"
        "BestScore	INTEGER,"
        "Level INTEGER,"
        "Date TEXT,"
        "PRIMARY KEY(ID AUTOINCREMENT));");

    // Set default stackedWidget
    ui->stackedWidget->setCurrentIndex(0);

    //Create items into the QListWidgets
    QListWidgetItem *item1 = new QListWidgetItem("Easy");
    item1->setTextAlignment(Qt::AlignCenter);
    ui->ListLevels->addItem(item1);
    QListWidgetItem *item2 = new QListWidgetItem("Normal");
    item2->setTextAlignment(Qt::AlignCenter);
    ui->ListLevels->addItem(item2);
    QListWidgetItem *item3 = new QListWidgetItem("Hard");
    item3->setTextAlignment(Qt::AlignCenter);
    ui->ListLevels->addItem(item3);
    ui->ListLevels->setCurrentRow(0);
    ui->ListLevels->setAcceptDrops(0);


    ui->label->setWordWrap(true);

    // Start value of lcdNumber
    ui->lcdNumber->display(ETS);



}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::nameCheck(QString name)
{

    sqlDB.exec("SELECT ID, name FROM players");

    while(sqlDB.next())
    {
        qDebug() << sqlDB.value(1).toString();// << " " <<name;
        if(sqlDB.value(1).toString()==name)
        {
            playerID=sqlDB.value(0).toInt();
            qDebug()<<playerID;
            qDebug()<<"+";
            return true;
        }
        else
            qDebug()<<"-";
    }
     return false;
}

void MainWindow::easyGame()
{
    gen1 = QRandomGenerator::global()->bounded(0,10*easyLvl);
    gen2 = QRandomGenerator::global()->bounded(0,10*easyLvl);
    qDebug()<<gen1<<" "<<gen2;
    ui->term->setText(QString::number(gen1)+" + "+QString::number(gen2));
}

void MainWindow::on_ButtonStart_clicked()
{
    QString name=ui->InputName->text();
    if (ui->InputName->text().isEmpty())
            ui->labelWarning->setText("Input your name please");
    else if (nameCheck(name))
    {
        qDebug()<<ui->InputName->text();
        ui->labelWarning->setText("Input a another name");
        ui->stackedWidget->setCurrentIndex(1);
        ui->label->setText("Hello, "+(ui->InputName->text())/*+"!\n Choose your level \nand have fun playing!"*/);
    }
    else
    {
        sqlDB.exec("INSERT INTO players (name) VALUES ('"+(ui->InputName->text())+"')");
        ui->stackedWidget->setCurrentIndex(1);
        ui->label->setText("Hello, "+(ui->InputName->text()));
    }
}

void MainWindow::on_ButtonBest_Score_clicked()
{
    testfunk();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_PlayButton_clicked()
{
    if (!isPlaying)
    {
        isPlaying=true;
        if (ui->ListLevels->currentRow()==0)
        {
            ui->lineAnswer->setText("");
            ui->lineAnswer->setFocus();
            easyTimer=30;
            ui->progressBar->setMinimum(0);
            ui->progressBar->setMaximum(ETS);
            ui->progressBar->setValue(ETS);
            tmr->start(1000);
            easyGame();
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString Qanswer = ui->lineAnswer->text();
    int Ianswer=Qanswer.toInt();
    if (Ianswer==gen1+gen2)
    {
        ui->lineAnswer->setText("");
        ui->lineAnswer->setFocus();
        easyLvl++;
        easyTimer+=5;
        if (easyTimer>ETS)
            ui->progressBar->setMaximum(easyTimer);
        ui->progressBar->setValue(easyTimer);
        ui->lcdNumber->display(easyTimer);
        easyGame();
    }
}

void MainWindow::updateTime()
{
    easyTimer--;
    ui->progressBar->setValue(easyTimer);
    ui->lcdNumber->display(easyTimer);
    qDebug()<<easyTimer;

}

void MainWindow::testfunk()
{
    int size=10;
    QVector<double> x(size), y(size);
    for (int i=0; i<size;i++)
    {
        x[i]=i;
        y[i]=i*i;
    }

    ui->plot->addGraph();
    ui->plot->graph(0)->setData(x, y);
    ui->plot->xAxis->setRange(0,10);
    ui->plot->yAxis->setRange(0,10);



    /*QLineSeries *series = new QLineSeries();

    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

    QChart *chart = new QChart();
    chart->legend()->hide();
            chart->addSeries(series);
            chart->createDefaultAxes();
            chart->setTitle("Simple line chart example");

            QChartView *chartView = new QChartView(chart);
               chartView->setRenderHint(QPainter::Antialiasing);
               //chartView->setParent(ui->verticalFrame);*/

}
