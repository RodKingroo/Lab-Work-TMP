#include "mainwindow.h"
#include "./ui_mainwindow.h"

double num_first;

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
    connect(ui->pushButton_demiter,   SIGNAL(clicked()), this, SLOT(math_operation()));
    connect(ui->pushButton_plus,      SIGNAL(clicked()), this, SLOT(math_operation()));
    connect(ui->pushButton_minus,     SIGNAL(clicked()), this, SLOT(math_operation()));
    connect(ui->pushButton_times,     SIGNAL(clicked()), this, SLOT(math_operation()));

    ui->pushButton_demiter  ->  setCheckable(true);
    ui->pushButton_plus     ->  setCheckable(true);
    ui->pushButton_minus    ->  setCheckable(true);
    ui->pushButton_times    ->  setCheckable(true);
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

    if(ui->result_show->text().contains(".") && button->text() == "0") new_label = ui->result_show->text()+button->text();

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
        ui -> pushButton_plus->setChecked(false);
        ui -> pushButton_minus->setChecked(false);
        ui -> pushButton_times->setChecked(false);
        ui -> pushButton_demiter->setChecked(false);
    }
}

void MainWindow :: math_operation(){
    QPushButton *button = (QPushButton *)sender();

    num_first = ui->result_show->text().toDouble();
    ui->result_show->setText("0");

    button->setChecked(true);
}


void MainWindow::on_pushButton_answer_clicked()
{

    double label_number;
    double num_second;
    QString new_label;

    num_second = ui->result_show->text().toDouble();


    if(ui->pushButton_plus->isChecked()){
        label_number = num_first + num_second;
        new_label = QString::number(label_number, 'g', 10);

        ui->result_show->setText(new_label);
        ui->pushButton_plus->setChecked(false);
    }else if(ui->pushButton_minus->isChecked()){
        label_number = num_first - num_second;
        new_label = QString::number(label_number, 'g', 10);

        ui->result_show->setText(new_label);
        ui->pushButton_minus->setChecked(false);
    } else if(ui->pushButton_demiter->isChecked()){

        if(num_second == 0) ui->result_show->setText("3rr0r");
        else{
        label_number = num_first / num_second;
            new_label = QString::number(label_number, 'g', 10);

            ui->result_show->setText(new_label);
            ui->pushButton_demiter->setChecked(false);
        }
    }else if(ui->pushButton_times->isChecked()){
        label_number = num_first * num_second;
        new_label = QString::number(label_number, 'g', 10);

        ui->result_show->setText(new_label);
        ui->pushButton_times->setChecked(false);
    }
}

