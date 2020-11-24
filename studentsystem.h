#ifndef STUDENTSYSTEM_H
#define STUDENTSYSTEM_H

#include <QWidget>
#include"studentList.h"
namespace Ui {
class studentSystem;
}

class studentSystem : public QWidget
{
    Q_OBJECT

public:
    explicit studentSystem(QWidget *parent = nullptr);
    ~studentSystem();
signals:
    void display(int);
    void setCpwType(int,int);
    void opType(int);
private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_okButton_clicked();
    void on_cancelButton_clicked();
    void recSignal(int);
    void showInfo(int);
    void setOpType(int);
private:
    Ui::studentSystem *ui;
    int id;
    int op=0;//0为选课，1为退课
    int flag1=0;
    int flag2=0;
};

#endif // STUDENTSYSTEM_H
