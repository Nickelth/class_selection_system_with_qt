#ifndef STUDENTLIST_H
#define STUDENTLIST_H
//学生类链表
#include<QString>
#include<QVector>
#include<QFile>
#include<QTextStream>
#include<QDebug>
class studentNode{
public:
    int id;
    QString name;
    int numOfChosen;
    QVector<QString> chosen;
    studentNode*next;
    QString getPassword(){return password;}
    void setPassword(QString psd){password=psd;}
    studentNode(int Id,  QString Name, QString Password,int NOC, QVector<QString>Chosen)
    {
        id=Id;
        name=Name;
        password=Password;
        numOfChosen=NOC;
        chosen=Chosen;
        next = NULL;
    }
    studentNode(studentNode*& stu)
    {
        id=stu->id;
        name=stu->name;
        numOfChosen=stu->numOfChosen;
        password=stu->getPassword();
        chosen=stu->chosen;
        next=stu->next;
    }
private:
    QString password;
};
class studentList
{
public:
    void insertNode(studentNode*&);
    void deleteNode(studentNode*&);
    void initList();
    void traverseStudent();
    void selectClass(int,QString&);//向指定id的学生添加课程，注意执行该操作后需要在课程类中更改相关课程信息
    void deleteClass(int,QString&);
    studentNode*& findStudent(int);
    int haveStudent(int);
    int studentHaveClass(int,QString&);
    void save();
    studentNode*students=NULL;
    studentNode*tmpPtr=NULL;
};
#endif // STUDENTLIST_H
