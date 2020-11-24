#include "registdialog.h"
#include "ui_registdialog.h"
#include<QVector>
#include<QMessageBox>
registDialog::registDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registDialog)
{
    ui->setupUi(this);
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(interfaceTransform(int)));
    connect(ui->lineEdit_1,SIGNAL(textChanged(const QString&)),this,SLOT(enableRegistButton()));
    connect(ui->lineEdit_2,SIGNAL(textChanged(const QString&)),this,SLOT(enableRegistButton()));

}

void registDialog::interfaceTransform(int index)
{
    index=ui->comboBox->currentIndex();
    if(index==0)ui->label_1->setText("学号：");
    else if(index==1)ui->label_1->setText("工号：");
}
void registDialog::enableRegistButton()
{
    if(ui->lineEdit_1->text()!=NULL&&ui->lineEdit_2->text()!=NULL)
    ui->okButton->setEnabled(1);
    else
        ui->okButton->setEnabled(0);
}
registDialog::~registDialog()
{
    delete ui;
}
void registDialog::on_okButton_clicked()
{
    if(ui->comboBox->currentIndex()==0)
    {
        int id=ui->lineEdit_1->text().toInt();
        QString name=ui->lineEdit_2->text();
        QString password=ui->lineEdit_3->text();
        QVector<QString> c;
        studentList *stu=new studentList;

        studentNode *ns=new studentNode(id,name,password,0,c);
        stu->initList();
        if(stu->haveStudent(id))
        {
            QMessageBox::warning(NULL,"失败","用户已存在");
            return;
        }
        stu->insertNode(ns);
        stu->save();
    }
    else
    {
        int id=ui->lineEdit_1->text().toInt();
        QString name=ui->lineEdit_2->text();
        QString password=ui->lineEdit_3->text();
        teacherList *tea=new teacherList;

        teacherNode *nt=new teacherNode(id,name,password);
        tea->initList();
        if(tea->haveTeacher(id))
        {
            QMessageBox::warning(NULL,"失败","用户已存在");
            return;
        }
        tea->insertNode(nt);
        tea->save();
    }
    emit display(0);
}
void registDialog::on_cancelButton_clicked()
{
    emit display(0);
}
