#ifndef FORM_H
#define FORM_H

#include<QMainWindow>
#include<QCoreApplication>
#include<QWidget>
#include<QTimer>
#include<main_class.h>
#include<QListView>
#include<QStringList>
#include<QTextStream>
#include<QStringListModel>
#include<QScrollBar>
QT_BEGIN_NAMESPACE
namespace Ui { class Form; }
QT_END_NAMESPACE

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_textChanged(const QString &arg1);


private:
    Ui::Form *ui;
    QTimer timer;

    MainClass test1, test2;
};

#endif // FORM_H
