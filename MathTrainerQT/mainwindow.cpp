#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QListWidgetItem>
//#include <QKeyEvent>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    QListWidgetItem *item1 = new QListWidgetItem("Easy");
    item1->setTextAlignment(Qt::AlignCenter);
    ui->ListLevels->addItem(item1);
    QListWidgetItem *item2 = new QListWidgetItem("Normal");
    item2->setTextAlignment(Qt::AlignCenter);
    ui->ListLevels->addItem(item2);
    QListWidgetItem *item3 = new QListWidgetItem("Hard");
    item3->setTextAlignment(Qt::AlignCenter);
    ui->ListLevels->addItem(item3);
    ui->ListLevels->setCurrentRow(1);
    ui->ListLevels->setAcceptDrops(0);
    ui->label->setWordWrap(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ButtonStart_clicked()
{

    if (ui->InputName->text().isEmpty())
            ui->labelWarning->setText("Input your name please");
    else
        ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{

}

void MainWindow::on_ButtonBest_Score_clicked()
{
    QMessageBox::about(this, "Info", "The function has not yet been realized.");
}

