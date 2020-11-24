#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H
#include<QString>
#include <QDialog>
#include<QComboBox>
#include<QLabel>
#include<QPushButton>
#include"ui_logindialog.h"
#include"studentList.h"
#include"teacherList.h"
class loginDialog : public QDialog,public Ui::loginDialog
{
    Q_OBJECT
public:
    explicit loginDialog(QWidget *parent = nullptr);
signals:
    void display(int);
    void userId(int);
public slots:
    void interfaceTransform(int);//学生登录界面与教师登录界面的切换
    void enableLoginButton();//当id与密码框都不为空时，登录按钮有效
    void on_loginButton_clicked();
    void on_registButton_clicked();
};

#endif // LOGINDIALOG_H
