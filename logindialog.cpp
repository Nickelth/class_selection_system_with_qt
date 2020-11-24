#include "logindialog.h"
#include<QString>
#include<QDebug>
#include<QMessageBox>
loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    connect(comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(interfaceTransform(int)));
    connect(lineEdit,SIGNAL(textChanged(const QString&)),this,SLOT(enableLoginButton()));
    connect(lineEdit_2,SIGNAL(textChanged(const QString&)),this,SLOT(enableLoginButton()));
}

void loginDialog::interfaceTransform(int index)
{
    index=comboBox->currentIndex();
    if(index==0)label_1->setText("学号：");
    else if(index==1)label_1->setText("工号：");
}
void loginDialog::enableLoginButton()
{
    if(lineEdit->text()!=NULL&&lineEdit_2->text()!=NULL)
    loginButton->setEnabled(1);
    else
        loginButton->setEnabled(0);
}
void loginDialog::on_loginButton_clicked()
{
    if(comboBox->currentIndex()==0)//学生登录
    {
        studentList stu;
        stu.initList();
        int id=lineEdit->text().toInt();
        QString psw=lineEdit_2->text();
        if(!stu.haveStudent(id))
        {
            QMessageBox::warning(NULL,"登录失败","用户不存在");
            return;
        }
        if(psw!=stu.findStudent(id)->getPassword())
        {
            QMessageBox::warning(NULL,"登录失败","密码错误");
            return;
        }
        emit display(2);
        emit userId(id);
    }
    else if(comboBox->currentIndex()==1)//教师登录
    {
        teacherList tea;
        tea.initList();
        int id=lineEdit->text().toInt();
        QString psw=lineEdit_2->text();
        if(!tea.haveTeacher(id))
        {
            QMessageBox::warning(NULL,"登录失败","用户不存在");
            return;
        }
        if(psw!=tea.findTeacher(id)->getPassword())
        {
            QMessageBox::warning(NULL,"登录失败","密码错误");
            return;
        }
        emit display(3);
        emit userId(id);
    }
}
void loginDialog::on_registButton_clicked()
{
    emit display(1);
}
