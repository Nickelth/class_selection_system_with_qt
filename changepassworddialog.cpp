#include "changepassworddialog.h"
#include "ui_changepassworddialog.h"
#include<QMessageBox>
changePasswordDialog::changePasswordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changePasswordDialog)
{
    ui->setupUi(this);
    connect(ui->lineEdit,SIGNAL(textChanged(const QString&)),this,SLOT(enableOkButton()));
    connect(ui->lineEdit_2,SIGNAL(textChanged(const QString&)),this,SLOT(enableOkButton()));
}

changePasswordDialog::~changePasswordDialog()
{
    delete ui;
}
void changePasswordDialog::enableOkButton()
{
    if(ui->lineEdit->text()!=NULL&&ui->lineEdit_2->text()!=NULL)
   ui->pushButton_1->setEnabled(1);
    else
     ui->pushButton_1->setEnabled(0);
}
void changePasswordDialog::on_pushButton_1_clicked()
{

    if(type==0)//学生改密
    {
        studentList *stu=new studentList;
        stu->initList();
        QString str1=ui->lineEdit->text();
        QString str2=ui->lineEdit_2->text();
        if(str1!=stu->findStudent(id)->getPassword())
        {
            QMessageBox::warning(NULL,"失败","旧密码不匹配");
            return;
        }
        stu->findStudent(id)->setPassword(str2);
        stu->save();
        emit display(2);
    }
    else if(type==1)//教师改密
    {
        teacherList *tea=new teacherList;
        tea->initList();
        QString str1=ui->lineEdit->text();
        QString str2=ui->lineEdit_2->text();
        if(str1!=tea->findTeacher(id)->getPassword())
        {
            QMessageBox::warning(NULL,"失败","旧密码不匹配");
            return;
        }
        tea->findTeacher(id)->setPassword(str2);
        tea->save();
        emit display(3);
    }
}
void changePasswordDialog::on_pushButton_2_clicked()
{
    if(type==0)
    emit display(2);
    else if(type==1)
    emit display(3);
}
void changePasswordDialog::recSignal(int t,int i)
{
    type=t;
    id=i;
}
