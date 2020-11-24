#ifndef REGISTDIALOG_H
#define REGISTDIALOG_H
#include<QString>
#include <QDialog>
#include<QComboBox>
#include<QLabel>
#include<QPushButton>
#include <QDialog>
#include"studentList.h"
#include"teacherList.h"
namespace Ui {
class registDialog;
}

class registDialog : public QDialog
{
    Q_OBJECT

public:
    explicit registDialog(QWidget *parent = nullptr);
    ~registDialog();

private:
    Ui::registDialog *ui;
signals:
    void display(int);
private slots:
    void interfaceTransform(int);
    void enableRegistButton();
    void on_okButton_clicked();
    void on_cancelButton_clicked();
};

#endif // REGISTDIALOG_H
