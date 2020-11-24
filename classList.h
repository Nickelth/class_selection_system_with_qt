#ifndef CLASSLIST_H
#define CLASSLIST_H
#include<QString>
#include<QVector>
#include<QFile>
#include<QTextStream>
#include<QDebug>
class classNode{
public:
    QString name;
    QString teacherRes;
    int left;
    int stuNum;
    QVector<QString>selected;
    classNode*next;
    classNode(classNode*& cla)
    {
        name=cla->name;
        teacherRes=cla->teacherRes;
        left=cla->left;
        stuNum=cla->stuNum;
        selected=cla->selected;
        next=cla->next;
    }
    classNode(QString Name,QString TeacherRes,int Left,int StuNum,QVector<QString> Selected)
    {
        name=Name;
        teacherRes=TeacherRes;
        left=Left;
        stuNum=StuNum;
        selected=Selected;
        next=NULL;
    }
};
class classList
{
public:
    void initList();
    void insertNode(classNode*&);
    void deleteNode(classNode*&);
    classNode*& findClass(QString&);
    int addStudent(QString&,QString&);
    void deleteStudent(QString&,QString&);
    void traverseClass();
    void save();
    classNode*classes=NULL;
    classNode*tmpPtr=NULL;
};

#endif // CLASSLIST_H
