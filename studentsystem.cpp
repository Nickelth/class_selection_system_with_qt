#include "studentsystem.h"
#include "ui_studentsystem.h"
#include<QDebug>
#include"studentList.h"
#include"classList.h"
#include<QTableWidget>
#include<QListWidget>
studentSystem::studentSystem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::studentSystem)
{
    ui->setupUi(this);
    ui->okButton->hide();
    ui->cancelButton->hide();
    ui->listWidget->hide();
    showInfo(0);
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(showInfo(int)));
}

studentSystem::~studentSystem()
{
    delete ui;
}
void studentSystem::setOpType(int t)
{
    op=t;
}
void studentSystem::on_pushButton_1_clicked()
{
    emit display(4);
    emit setCpwType(0,id);
}
void studentSystem::on_pushButton_2_clicked()
{
    emit display(0);
}
void studentSystem::on_pushButton_3_clicked()
{
   op=0;
    ui->okButton->show();
    ui->cancelButton->show();
    ui->tableWidget->hide();
    ui->listWidget->show();
    ui->listWidget->clear();
    classList*cla=new classList;
    cla->initList();
    classNode*p=cla->classes;
    studentList*stu=new studentList;
    stu->initList();
    while(p)//显示所有未选与有课余量的课程
    {
        if(stu->studentHaveClass(id,p->name)||p->left==0)
        {
            p=p->next;
            continue;
        }
        QListWidgetItem *item=new QListWidgetItem;
        item->setText(p->name);
        ui->listWidget->addItem(item);
        p=p->next;
    }
}
void studentSystem::on_pushButton_4_clicked()
{
    op=1;
    ui->okButton->show();
    ui->cancelButton->show();
    ui->tableWidget->hide();
    ui->listWidget->show();
    ui->listWidget->clear();
    classList*cla=new classList;
    cla->initList();
    classNode*p=cla->classes;
    studentList*stu=new studentList;
    stu->initList();
    while(p)//显示所有已选课程
    {
        if(stu->studentHaveClass(id,p->name))
        {

        QListWidgetItem *item=new QListWidgetItem;
        item->setText(p->name);
        ui->listWidget->addItem(item);

        }
        p=p->next;
    }
}
void studentSystem::recSignal(int i)
{
    id=i;
    studentList*stu=new studentList;
    stu->initList();
    ui->label_2->setText(stu->findStudent(id)->name);
}
void studentSystem::showInfo(int index)
{
    ui->listWidget->hide();
    ui->tableWidget->show();
    ui->tableWidget->clear();
    ui->okButton->hide();
    ui->cancelButton->hide();
    if(index==0)
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
            if(!flag1)
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(p->name));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(p->teacherRes));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(p->left)));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(p->stuNum)));
            i++;
            p=p->next;
        }
        if(!flag1)flag1=1;

    }
    else if(index==1)
    {
        studentList*stu=new studentList;
        stu->initList();
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
            if(!stu->studentHaveClass(id,p->name))
            {
                p=p->next;
                continue;
            }
            if(!flag2)
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(p->name));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(p->teacherRes));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(p->left)));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(p->stuNum)));
            i++;
            p=p->next;
        }
        if(!flag2)flag2=1;
    }
}
void studentSystem::on_cancelButton_clicked()
{
    showInfo(ui->comboBox->currentIndex());
}
void studentSystem::on_okButton_clicked()
{
    studentList*stu=new studentList;
    stu->initList();
    classList*cla=new classList;
    cla->initList();
    QList<QListWidgetItem*> items=ui->listWidget->selectedItems();
    qDebug()<<op;
    if(op==0){
        for(int i=0;i<items.size();i++)
        {
            QString str=items[i]->text();
            stu->selectClass(id,str);
            cla->addStudent(str,stu->findStudent(id)->name);
        }
    }
    else if(op==1)
    {
        for(int i=0;i<items.size();i++)
        {
            QString str=items[i]->text();
            stu->deleteClass(id,str);
            cla->deleteStudent(str,stu->findStudent(id)->name);
        }
    }
    stu->save();
    cla->save();
    showInfo(ui->comboBox->currentIndex());
}
