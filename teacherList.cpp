#include"teacherList.h"
QString teacherNode::getPassword()
{
    return password;
}
void teacherNode::setPassword(QString str)
{
    password=str;
}
void teacherList::insertNode(teacherNode *&obj)
{
    if (!teachers)
    {
        teachers = obj;
        teachers->next = obj;
        obj->next = NULL;
        return;
    }
    teacherNode* p = teachers;
    while (p->next)p = (teacherNode*)p->next;
    p->next = obj;
    obj->next = NULL;
}
void teacherList::deleteNode(teacherNode *&obj)
{
    teacherNode* s = teachers;
    if (s == obj)
    {
        teachers = (teacherNode*)s->next;
        delete s;
        s = NULL;
        return;
    }
    else
    {
        while (s->next != obj)
        {
            s = (teacherNode*)s->next;
        }
        teacherNode* p = (teacherNode*)obj->next;
        s->next = p;
        delete obj;
        obj = NULL;
    }
}
void teacherList::initList()
{
    QFile fi("D:\\Qt\\projects\\classSelectionProgram\\teacherList.txt");
    fi.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream st(&fi);
    int tmpId;
    QString tmpName;
    QString tmpPassword;
    while(!st.atEnd())
    {
    st>>tmpId>>tmpName>>tmpPassword;
    teacherNode*tea=new teacherNode(tmpId,tmpName,tmpPassword);
    insertNode(tea);
    }
    deleteNode(findTeacher(0));//最后会多读一个无用数据，需要删除
}
void teacherList::save()
{
    QFile fi("D:\\Qt\\projects\\classSelectionProgram\\teacherList.txt");
    fi.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream st(&fi);
    teacherNode*p=teachers;
    while(p)
    {
        st<<p->id<<' '<<p->name<<' '<<p->getPassword()<<Qt::endl;
        p=p->next;
    }
    fi.close();
}
void teacherList::traverseTeacher()
{
    teacherNode* p = teachers;
    while (p)
    {

        qDebug() << p->id << ' ' << p->name <<Qt::endl;

        p = p->next;
    }
}
teacherNode*& teacherList::findTeacher(int id)
{
    tmpPtr=teachers;
    while(tmpPtr)
    {
        if(tmpPtr->id==id)return tmpPtr;
        tmpPtr=tmpPtr->next;
    }
}
int teacherList::haveTeacher(int id)
{
    teacherNode*p=teachers;
    while(p)
    {
        if(p->id==id)return 1;
        p=p->next;
    }
    return 0;
}
