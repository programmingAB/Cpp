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
    sqlDB.exec("CREATE TABLE player(name TEXT, BestScore INTEGER, date TEXT, Level INTEGER)");

    // Set default stackedWidget
    ui->stackedWidget->setCurrentIndex(0);

    //create items into the QListWidgets
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::nameCheck(QString name)
{

    sqlDB.exec("SELECT name FROM player");
    //qDebug() << sqlDB.size();

    while(sqlDB.next())
    {
        qDebug() << sqlDB.value(0).toString() << " " <<name;
        if(sqlDB.value(0).toString()==name)
        {
            qDebug()<<"+";
            return true;

        }
        else
        {
            qDebug()<<"-";

        }
    }
     return false;
}

void MainWindow::easyGame()
{

    gen1 = QRandomGenerator::global()->bounded(0,10);
    gen2 = QRandomGenerator::global()->bounded(0,10);
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
       // ui->labelWarning->setText("Input a another name");
        ui->stackedWidget->setCurrentIndex(1);
        ui->labelHello->setText("Hello, "+(ui->InputName->text()));
    }
    else
    {
        sqlDB.exec("INSERT INTO player (name) VALUES ('"+(ui->InputName->text())+"')");
        ui->stackedWidget->setCurrentIndex(1);
        ui->labelHello->setText("Hello, "+(ui->InputName->text()));
    }
}


void MainWindow::on_ButtonBest_Score_clicked()
{
    QMessageBox::about(this, "Info", "The function has not yet been realized.");
}


void MainWindow::on_PlayButton_clicked()
{
    if (ui->ListLevels->currentRow()==0)
    {
        timer=30;
        ui->progressBar->setMinimum(0);
        ui->progressBar->setMaximum(timer);
        ui->progressBar->setValue(timer);
        tmr->start(1000);
        easyGame();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString Qanswer = ui->lineAnswer->text();
    int Ianswer=Qanswer.toInt();
    if (Ianswer==gen1+gen2)
    {
        ui->lineAnswer->setText("");
        easyGame();
    }
}

void MainWindow::updateTime()
{
    ui->progressBar->setValue(timer);
    qDebug()<<timer;
    timer--;
}
