#ifndef TEACHERLIST_H
#define TEACHERLIST_H
#include<QString>
#include<QFile>
#include<QTextStream>
#include<QDebug>
class teacherNode{
public:
    int id;
    QString name;
    teacherNode*next;
    QString getPassword();
    void setPassword(QString);
    teacherNode(int Id,QString Name,QString Password)
    {
        id=Id;
        name=Name;
        password=Password;
    }
private:
    QString password;
};
class teacherList{
public:
    void insertNode(teacherNode*&);
    void deleteNode(teacherNode*&);
    void initList();
    teacherNode*& findTeacher(int);
    int haveTeacher(int);
    void save();
    void traverseTeacher();
    teacherNode*teachers=NULL;
    teacherNode*tmpPtr=NULL;
};

#endif // TEACHERLIST_H
