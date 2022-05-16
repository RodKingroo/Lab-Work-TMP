#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,         SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_1,         SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_2,         SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_3,         SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_4,         SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_5,         SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_6,         SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_7,         SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_8,         SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_9,         SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_plusminus, SIGNAL(clicked()), this, SLOT(operation()));
    connect(ui->pushButton_proccent,  SIGNAL(clicked()), this, SLOT(operation()));
    connect(ui->pushButton_ac,        SIGNAL(clicked()), this, SLOT(operation()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow :: digit_numbers(){
    QPushButton *button = (QPushButton *)sender();

    double all_numbers;
    QString new_label;

    all_numbers = (ui->result_show->text()+button->text()).toDouble();
    new_label = QString::number(all_numbers, 'g', 10);

    ui -> result_show->setText(new_label);
}


void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->result_show->text().contains('.'))) ui -> result_show->setText(ui->result_show->text()+".");
}

void MainWindow :: operation(){
    QPushButton *button = (QPushButton *)sender();

    double all_numbers;
    QString new_label;

    if(button-> text()=="+/-"){
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = all_numbers*(-1);
        new_label = QString::number(all_numbers, 'g', 10);

        ui -> result_show->setText(new_label);
    }
    if(button-> text()=="%"){
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = all_numbers * 0.01;
        new_label = QString::number(all_numbers, 'g', 10);

        ui -> result_show->setText(new_label);
    }
    if(button-> text()=="AC"){
        all_numbers = 0;
        new_label = QString::number(all_numbers, 'g', 10);

        ui -> result_show->setText(new_label);
    }
}

