#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include<QWidget>
#include<QStackedLayout>
#include"changepassworddialog.h"
#include"logindialog.h"
#include"registdialog.h"
#include"studentsystem.h"
#include"teachersystem.h"
#include <QDialog>

namespace Ui {
class mainWidget;
}

class mainWidget : public QDialog
{
    Q_OBJECT

public:
    explicit mainWidget(QWidget *parent = nullptr);
    ~mainWidget();

private:
    Ui::mainWidget *ui;
    changePasswordDialog *cpwDialog;
    loginDialog *logindialog;
    registDialog *registdialog;
    studentSystem *studentsystem;
    teacherSystem *teachersystem;
    QStackedLayout *layout;
};

#endif // MAINWIDGET_H
