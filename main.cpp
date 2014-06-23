#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QStringList>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("218.4.199.210");
    db.setDatabaseName("sys_storesystem");
    db.setUserName("root");
    db.setPassword("xkxj*211-2");
    if(!db.open()){
        qDebug()<<"Unable to open database";
    }else{
        qDebug()<<"Database connection established";
    }

    QSqlQuery query(db);
    query.exec("select *from store_staff");//check command
    while(query.next())
    {
        int rowNum = query.at();
        qDebug()<<"rowNum is:"<<rowNum;
        qDebug()<<query.value(0).toString()<<" "<<query.value(1).toString()<<query.value(2).toString()<<" "<<query.value(3).toString()//Read from MYSQL
                    <<query.value(4).toString()<<" "<<query.value(5).toString()<<query.value(6).toString()<<" "<<query.value(7).toString()
        <<query.value(8).toString()<<" "<<query.value(9).toString()<<query.value(10).toString()<<" "<<query.value(11).toString();
    }

    db.close();
    return a.exec();
}
