#ifndef CHANGEPASSWORDDIALOG_H
#define CHANGEPASSWORDDIALOG_H

#include <QDialog>
#include"studentList.h"
#include"teacherList.h"
namespace Ui {
class changePasswordDialog;
}

class changePasswordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit changePasswordDialog(QWidget *parent = nullptr);
    ~changePasswordDialog();
    int type;
    int id;
private:
    Ui::changePasswordDialog *ui;
signals:
    void display(int num);
private slots:
    void enableOkButton();
    void on_pushButton_2_clicked();
    void on_pushButton_1_clicked();
    void recSignal(int,int);
};

#endif // CHANGEPASSWORDDIALOG_H
