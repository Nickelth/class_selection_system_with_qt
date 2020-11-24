#include "teachersystem.h"
#include "ui_teachersystem.h"
#include"studentList.h"
#include"classList.h"
teacherSystem::teacherSystem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::teacherSystem)
{
    ui->setupUi(this);
    showInfo(0);
   connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(showInfo(int)));
}

teacherSystem::~teacherSystem()
{
    delete ui;
}
void teacherSystem::on_pushButton_2_clicked()
{
    emit display(0);
}
void teacherSystem::on_pushButton_1_clicked()
{
    emit display(4);
    emit setCpwType(1,id);
}
void teacherSystem::recSignal(int i)
{
    id=i;
    teacherList*tea=new teacherList;
    tea->initList();
    ui->label_2->setText(tea->findTeacher(id)->name);
}
void teacherSystem::showInfo(int index)
{
    ui->tableWidget->clear();
    if(index==0)
    {
        studentList *stu=new studentList;
        stu->initList();
        studentNode*p=stu->students;
        QStringList str;
        str<<"id"<<"姓名"<<"已选课程数";
        ui->tableWidget->setColumnCount(3);
        ui->tableWidget->setHorizontalHeaderLabels(str);
        int i=0;
        while(p)
        {
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(p->id)));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(p->name));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(p->numOfChosen)));
            i++;
           p=p->next;
        }
    }
    else if(index==1)
    {
        classList *cla=new classList;
        cla->initList();
        classNode *p=cla->classes;
        QStringList str;
        str<<"课程名"<<"任课教师"<<"课余量"<<"已选人数";
        ui->tableWidget->setColumnCount(4);
        ui->tableWidget->setHorizontalHeaderLabels(str);
        int i=0;
        while(p)
        {
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(p->name));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(p->teacherRes));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(p->left)));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(p->stuNum)));
            i++;
            p=p->next;
        }
    }
}
