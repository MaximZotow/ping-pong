#include <QApplication>
#include <QtCore/qglobal.h>
#include<main_class.h>
#include<form.h>
#include<QLabel>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Form f;
    f.show();
    return a.exec();
}
