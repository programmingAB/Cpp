#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QListWidgetItem>
#include <QDebug>
#include <QTimer>
#include <QQueue>

//#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tmr=new QTimer(this);

    ui->plot->addGraph();
    ui->plot->addGraph();
    ui->plot->addGraph();

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
    sqlDB.exec(
                "CREATE TABLE players ("
                    "ID	INTEGER NOT NULL UNIQUE,"
                    "name	TEXT UNIQUE,"
                    "PRIMARY KEY(ID AUTOINCREMENT));"
                );

    sqlDB.exec(
               "CREATE TABLE results ("
                    "ID	INTEGER NOT NULL,"
                    "level	TEXT NOT NULL,"
                    "game5	INTEGER,"
                    "game4	INTEGER,"
                    "game3	INTEGER,"
                    "game2	INTEGER,"
                    "game1	INTEGER,"
                    "FOREIGN KEY(ID) REFERENCES players(ID) ON DELETE NO ACTION ON UPDATE NO ACTION);"
                );

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

    // get the palette
    auto palette = ui->lcdNumber->palette();
    ui->lcdNumber->setPalette(Qt::black);



}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::nameCheck(QString name)
{

    sqlDB.exec("SELECT * FROM players");

    while(sqlDB.next())
    {
        qDebug() << sqlDB.value(1).toString();// << " " <<name;
        if(sqlDB.value(1).toString()==name)
        {
            playerID=sqlDB.value(0).toString();
            initializeVectors(playerID);
            qDebug()<<"playerID: "<<playerID;
            return true;
        }
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
        //ui->labelWarning->setText("Input a another name");
        ui->stackedWidget->setCurrentIndex(1);
        ui->label->setText("Hello, "+(ui->InputName->text())/*+"!\n Choose your level \nand have fun playing!"*/);
    }
    else
    {
        sqlDB.exec("INSERT INTO players (name) VALUES ('"+(ui->InputName->text())+"')");
        nameCheck(ui->InputName->text());
        sqlDB.exec("INSERT INTO results VALUES ('"+playerID+"', 'easy', 0, 0, 0, 0, 0 )");
        sqlDB.exec("INSERT INTO results VALUES ('"+playerID+"', 'normal', 0, 0, 0, 0, 0 )");
        sqlDB.exec("INSERT INTO results VALUES ('"+playerID+"', 'hard', 0, 0, 0, 0, 0 )");
        initializeVectors(playerID);
        ui->stackedWidget->setCurrentIndex(1);
        ui->label->setText("Hello, "+(ui->InputName->text()));
    }
}

void MainWindow::on_ButtonBest_Score_clicked()
{
    nameCheck(ui->InputName->text());
    //ui->plot->clearGraphs();

    testfunk();
    ui->label->setText("Hello, "+(ui->InputName->text())/*+g"!\n Choose your level \nand have fun playing!"*/);
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_PlayButton_clicked()
{
    if (!isPlaying)
    {
        isPlaying=true;
        if (ui->ListLevels->currentRow()==0)
        {
            isEasy=true;
            isNormal=false;
            isHard=false;
            ui->lineAnswer->setText("");
            ui->lineAnswer->setFocus();
            level=0;
            ui->labelLevel->setText(QString::number(level));
            //easyTimer=30;
            ui->progressBar->setMinimum(0);
            ui->progressBar->setMaximum(ETS);
            ui->progressBar->setValue(ETS);
            tmr->start(1000);
            easyGame();
        }
    }
}

void MainWindow::on_CheckButton_clicked()
{
    QString Qanswer = ui->lineAnswer->text();
    int Ianswer=Qanswer.toInt();
    if (Ianswer==gen1+gen2)
    {
        level++;
        ui->labelLevel->setText(QString::number(level));
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
    if(isEasy)
    {
        easyTimer--;

        ui->progressBar->setValue(easyTimer);
        ui->lcdNumber->display(easyTimer);
        qDebug()<<easyTimer;
        if (!easyTimer)
        {
            tmr->stop();
            //QMessageBox::information(this, "Out of time", "time is out");
            isPlaying=false;
            easyTimer=ETS;
            ui->progressBar->setMaximum(easyTimer);
            ui->progressBar->setValue(easyTimer);
            ui->lcdNumber->display(easyTimer);
            ui->term->setText("");
            ui->lineAnswer->setText("");
            VEasy.erase(VEasy.begin());
            qDebug()<<"level is: "<<level;
            VEasy.push_back(level);
            sqlDB.exec( "update results set "
                        "game1="+QString::number(VEasy[4])+", "
                        "game2="+QString::number(VEasy[3])+", "
                        "game3="+QString::number(VEasy[2])+", "
                        "game4="+QString::number(VEasy[1])+", "
                        "game5="+QString::number(VEasy[0])+" "
                        "where level='easy' and ID="+playerID+""
                      );
            qDebug()<<endl;
            qDebug()<<"In updatetime()";
            for (double d: VEasy)
                qDebug()<<"VEasy: "<<d;
            /*sqlDB.exec("update results "
                       "setButtonStart game1="+QString::number(VEasy[4])+" "

                       "where level='easy' and ID="+playerID+"");*/
        }
    }
}



void MainWindow::initializeVectors(QString playerID)
{


    //easy
    sqlDB.exec("SELECT * FROM results where level='easy' and ID="+playerID+"");
    while(sqlDB.next())
    {
        for (int i=2; i<=6; i++)
            VEasy.push_back(sqlDB.value(i).toInt());
    }
    qDebug()<<"in initializeVectors function";
    for (double d: VEasy)
        qDebug()<<"VEasy: "<<d;

    //normal
    sqlDB.exec("SELECT * FROM results where level='normal' and ID="+playerID+"");
    while(sqlDB.next())
    {
        for (int i=2; i<=6; i++)
            VNormal.push_back(sqlDB.value(i).toInt());
    }

    //hard
    sqlDB.exec("SELECT * FROM results where level='hard' and ID="+playerID+"");
    while(sqlDB.next())
    {
        for (int i=2; i<=6; i++)
            VHard.push_back(sqlDB.value(i).toInt());
    }


}

void MainWindow::on_ButtonBest_Score2_clicked()
{
    //nameCheck(ui->InputName->text());
    testfunk();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_Start3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::testfunk()
{
    ui->plot->replot();
    //ui->plot->clearData();
    qDebug()<<"In testfunk()";
    QVector<double> x(5);
    for (int i=0; i<5;i++)
    {
        x[i]=i+1;
    }


    ui->plot->xAxis->setRange(1,5);
    ui->plot->yAxis->setRange(0,20);
    //easy
   // ui->plot->addGraph();
    ui->plot->graph(0)->setData(x, VEasy);
    ui->plot->graph(0)->setName("Easy");
    ui->plot->replot();
    ui->plot->update();
    //normal
    //ui->plot->addGraph();
    ui->plot->graph(1)->setPen(QPen(Qt::red));
    ui->plot->graph(1)->setData(x, VNormal);
    ui->plot->graph(1)->setName("Normal");
    ui->plot->replot();
    ui->plot->update();
    //hard
    //ui->plot->addGraph();
    ui->plot->graph(2)->setPen(QPen(Qt::yellow));
    ui->plot->graph(2)->setData(x, VHard);
    ui->plot->graph(2)->setName("Hard");
    ui->plot->replot();
    ui->plot->update();

    ui->plot->legend->setVisible(true);

    //VEasy.clear();
    //x.clear();
   // ui->plot->clearGraphs();


}
