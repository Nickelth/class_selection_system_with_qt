#include "mainwindow.h"

#include <QApplication>
#include<QDebug>
#include"mainWidget.h"
int main(int argc, char *argv[])
{
    QApplication *app=new QApplication(argc,argv);
   mainWidget *m=new mainWidget;
   m->show();
    return app->exec();
}
