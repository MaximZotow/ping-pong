#include "main_class.h"
#include <QUuid>
#include<QPlainTextEdit>

MainClass::MainClass(QObject *parent) : QObject(parent)
{
    setName();
}

void MainClass::setName()
{
    //name = QRandomGenerator::global()->generate() & 1000;

    name = QUuid::createUuid().toString();
}

QString MainClass::displayName()
{
    return name;
}



void MainClass::processPing(const QString& msg)
{
    // Вывести на экран, что принял ping
    // Отослать ответ...
//    std::cout << "Message pinged # " << msg.toStdString()<< ". Time: "<<
//                 QTime::currentTime().toString("hh:mm:ss").toStdString()
//              <<std::endl;

    emit pong(msg);
}

void MainClass::processPong(const QString& msg)
{
    // ? Display pong process
//    std::cout << "Message ponged # " << msg.toStdString() << ". Time: "<<
//                 QTime::currentTime().toString("hh:mm:ss").toStdString() <<
//                 std::endl;
    QString m;
     m.append("Message ponged # ");
     m.append(QString::number(a));
     m.append(". Time: ");
     m.append(QTime::currentTime().toString("hh:mm:ss"));
     emit msgPonged(m);

}

void MainClass::sendPing()
{
    ++a;
    emit ping(QString::number(a));
    QString m;
     m.append("Message pinged # ");
     m.append(QString::number(a));
     m.append(". Time: ");
     m.append(QTime::currentTime().toString("hh:mm:ss"));
     emit msgPinged(m);
}

