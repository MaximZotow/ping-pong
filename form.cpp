#include "form.h"
#include "ui_form.h"
#include<iostream>
#include<QLabel>

using namespace std;
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
        timer.setInterval(1000);

}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{

    ui->plainTextEdit->appendPlainText("started ping");
    ui->plainTextEdit_2->appendPlainText("started pong");
    cout << timer.isActive()<< endl;

    QPlainTextEdit textedit;
    QObject::connect(&timer, SIGNAL(timeout()),
                     &test1, SLOT(sendPing()));

    cout << timer.isActive()<< endl;

    QObject:: connect(&test1, SIGNAL(ping(QString)),
                      &test2, SLOT(processPing(QString)));

    QObject:: connect(&test2, SIGNAL(pong(QString)),
                      &test1, SLOT(processPong(QString)));

    QObject::connect(&test1, SIGNAL(msgPinged(QString)),
                     ui->plainTextEdit, SLOT(appendPlainText(QString)));

    QObject::connect(&test1, SIGNAL(msgPonged(QString)),
                     ui->plainTextEdit_2, SLOT(appendPlainText(QString)));

    connect(ui->plainTextEdit->verticalScrollBar(), SIGNAL(sliderMoved(int)), ui->plainTextEdit_2->verticalScrollBar(), SLOT(setValue(int)));
    connect(ui->plainTextEdit_2->verticalScrollBar(), SIGNAL(sliderMoved(int)), ui->plainTextEdit->verticalScrollBar(), SLOT(setValue(int)));
    timer.start();
    //ui->plainTextEdit_2->verticalScrollBar()->setValue(ui->plainTextEdit->verticalScrollBar()->maximum());
}

void Form::on_pushButton_2_clicked()
{
    //cout << timer.isActive()<< endl;

    ui->plainTextEdit->appendPlainText("stopped ping");
    ui->plainTextEdit_2->appendPlainText("stopped pong");
    QObject::disconnect(&timer, SIGNAL(timeout()),
                     &test1, SLOT(sendPing()));

    //cout << timer.isActive()<< endl;

    QObject:: disconnect(&test1, SIGNAL(ping(QString)),
                      &test2, SLOT(processPing(QString)));

    QObject:: disconnect(&test2, SIGNAL(pong(QString)),
                      &test1, SLOT(processPong(QString)));

}

void Form::on_lineEdit_textChanged(const QString &arg1)
{
    timer.setInterval(arg1.toInt());
}



