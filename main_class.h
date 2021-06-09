#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>

#include<QTimer>
#include<QTime>
#include<iostream>
#include<string>
class MainClass : public QObject
{
        Q_OBJECT
    public:
        explicit MainClass(QObject *parent = nullptr);
        void setName();
        QString displayName();
    public  slots:
       void processPing(const QString& msg);
       void processPong(const QString& msg);
       void sendPing();

    signals:
       void ping(QString = "", int = 0);
       void pong(QString);
       void msgPinged(QString);
       void msgPonged(QString);
    protected:
        QString name;
        int a = 0;


};

#endif // MAINCLASS_H
