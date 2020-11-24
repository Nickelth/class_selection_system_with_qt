#include"studentList.h"
#include<QDebug>
void studentList::insertNode(studentNode*& obj)
{
    if (!students)
    {
        students = obj;
        students->next = obj;
        obj->next = NULL;
        return;
    }
    studentNode* p = students;
    while (p->next)p = p->next;
    p->next = obj;
    obj->next = NULL;
}
void studentList::deleteNode(studentNode*& obj)
{
    if(!haveStudent(obj->id))return;
    studentNode* s = students;
    if (s == obj)
    {
        students = (studentNode*)s->next;
        delete s;
        s = NULL;
        return;
    }
    else
    {
        while (s->next != obj)
        {
            s = (studentNode*)s->next;
        }
        studentNode* p = (studentNode*)obj->next;
        s->next = p;
        delete obj;
        obj = NULL;
    }
}
void studentList::initList()
{
    QFile fi("D:\\Qt\\projects\\classSelectionProgram\\studentList.txt");
    fi.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream st(&fi);
    int tmpId;
    QString tmpName;
    QString tmpPassword;
    int tmpNOC;
    QString str;
    QVector<QString> tmpChosen;
    while(!st.atEnd())
    {
    st>>tmpId>>tmpName>>tmpPassword>>tmpNOC;
    for(int i=0;i<tmpNOC;i++){
        st>>str;
        tmpChosen.push_back(str);
    }
    studentNode*stu=new studentNode(tmpId,tmpName,tmpPassword,tmpNOC,tmpChosen);
    insertNode(stu);
    tmpChosen.clear();
    }
    if(haveStudent(0))
    deleteNode(findStudent(0));//最后会多读一个无用数据，需要删除
}
void studentList::traverseStudent()
{
    studentNode* p = students;
    while (p)
    {

            qDebug() << p->id << ' ' << p->name << ' ' << p->numOfChosen << ' ';
            for (int i = 0; i < p->numOfChosen; i++)
                qDebug() << p->chosen[i] << ' ';

        p = p->next;
    }

}
studentNode*& studentList::findStudent(int id)
{
    tmpPtr=students;
    while(tmpPtr)
    {
        if(tmpPtr->id==id)return tmpPtr;
        tmpPtr=tmpPtr->next;
    }
}
int studentList::haveStudent(int id)
{
    tmpPtr=students;
    while(tmpPtr)
    {
        if(tmpPtr->id==id)return 1;
        tmpPtr=tmpPtr->next;
    }
    return 0;
}
void studentList::selectClass(int id,QString& className)
{
    findStudent(id)->chosen.push_back(className);
    findStudent(id)->numOfChosen++;
}
void studentList::deleteClass(int id,QString& className)
{

    for(int i=0;i<findStudent(id)->chosen.size();i++)
        if(findStudent(id)->chosen.at(i)==className)
        {
            findStudent(id)->chosen.remove(i);
            findStudent(id)->numOfChosen--;
            return;
        }
}
int studentList::studentHaveClass(int id, QString& className)
{
    for(int i=0;i<findStudent(id)->chosen.size();i++)
        if(findStudent(id)->chosen.at(i)==className)
        {
            return 1;
        }
    return 0;
}
void studentList::save()
{
    QFile fi("D:\\Qt\\projects\\classSelectionProgram\\studentList.txt");
    fi.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream st(&fi);
    studentNode*p=students;
    while(p)
    {
        st<<p->id<<' '<<p->name<<' '<<p->getPassword()<<' '<<p->numOfChosen<<' ';
        for(int i=0;i<p->numOfChosen;i++)
            st<<p->chosen[i]<<' ';
        st<<Qt::endl;
        p=p->next;
    }
    fi.close();
}
