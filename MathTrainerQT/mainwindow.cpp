#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QListWidgetItem>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);

    QListWidgetItem *item1 = new QListWidgetItem("Easy");
    item1->setTextAlignment(Qt::AlignCenter);
    ui->ListLevels->addItem(item1);
    ui->ListLevels->addItem("Normal");
    ui->ListLevels->addItem("Hard");
    ui->ListLevels->setCurrentRow(1);
    ui->ListLevels->setAcceptDrops(0);
   // ui->ListLevels->setFlow(QListView::TopToBottom);
    //ui->ListLevels->setTextAlignment(Qt::AlignCenter);


    //ui->LstOperation->currentItem()
}//

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

