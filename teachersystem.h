#ifndef TEACHERSYSTEM_H
#define TEACHERSYSTEM_H

#include <QWidget>
#include<QTableWidget>
#include<QTableWidgetItem>
#include<QStringList>
#include"teacherList.h"
namespace Ui {
class teacherSystem;
}

class teacherSystem : public QWidget
{
    Q_OBJECT

public:
    explicit teacherSystem(QWidget *parent = nullptr);
    ~teacherSystem();
signals:
    void display(int);
    void setCpwType(int,int);
private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void recSignal(int);
    void showInfo(int);
private:
    Ui::teacherSystem *ui;
    int id;
};

#endif // TEACHERSYSTEM_H
