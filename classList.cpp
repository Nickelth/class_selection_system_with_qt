#include"classList.h"
void classList::insertNode(classNode*& cla)
{
    if (!classes)
    {
        classes = cla;
        classes->next = cla;
        cla->next = NULL;
        return;
    }
    classNode* p = classes;
    while (p->next)p = (classNode*)p->next;
    p->next = cla;
    cla->next = NULL;
}
void classList::deleteNode(classNode*& obj)
{
    classNode* s = classes;
    if (s == obj)
    {
        classes = (classNode*)s->next;
        delete s;
        s = NULL;
        return;
    }
    else
    {
        while (s->next != obj)
        {
            s = (classNode*)s->next;
        }
        classNode* p = (classNode*)obj->next;
        s->next = p;
        delete obj;
        obj = NULL;
    }
}
classNode*& classList::findClass(QString& str)
{
    tmpPtr=classes;
    while(tmpPtr)
    {
        if(tmpPtr->name==str)return tmpPtr;
        tmpPtr=tmpPtr->next;
    }
}
int classList::addStudent(QString & className, QString & stuName)
{
    if(findClass(className)->left==0)return 0;
    findClass(className)->selected.push_back(stuName);
    findClass(className)->left--;
    findClass(className)->stuNum++;
    return 1;
}
void classList::deleteStudent(QString &className, QString &stuName)
{
    for(int i=0;i<findClass(className)->selected.size();i++)
    {
        if(findClass(className)->selected.at(i)==stuName)
        {
            findClass(className)->selected.remove(i);
            findClass(className)->left++;
            findClass(className)->stuNum--;
            break;
        }
    }
}
void classList::initList()
{
    QFile fi("D:\\Qt\\projects\\classSelectionProgram\\classList.txt");
    fi.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream st(&fi);
    QString tmpName;
    QString tmpTR;
    int tmpLeft;
    int tmpNum;
    QString str;
    QVector<QString> tmpselected;
    while(!st.atEnd())
    {
    st>>tmpName>>tmpTR>>tmpLeft>>tmpNum;
    for(int i=0;i<tmpNum;i++)
    {
        st>>str;
        tmpselected.push_back(str);
    }
    classNode *cla=new classNode(tmpName,tmpTR,tmpLeft,tmpNum,tmpselected);
    insertNode(cla);
    tmpselected.clear();
    }
    classNode*p=classes;
    while(p)//删除多余数据
    {
        if(p->left==0&&p->stuNum==0)
        {
            deleteNode(p);
            break;
        }
        p=p->next;
    }
    fi.close();
}
void classList::save()
{
    QFile fi("D:\\Qt\\projects\\classSelectionProgram\\classList.txt");
    fi.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream st(&fi);
    classNode*p=classes;
    while(p)
    {
    st<<p->name<<' '<<p->teacherRes<<' '<<p->left<<' '<<p->stuNum<<' ';
    for(int i=0;i<p->stuNum;i++)
        st<<p->selected[i]<<' ';
    st<<Qt::endl;
    p=p->next;
    }
    fi.close();
}
void classList::traverseClass()
{
    classNode* p = classes;
    while (p)
    {

            qDebug()<<p->name << ' ' << p->teacherRes << ' '<<p->left<<' '<<p->stuNum;
            for (int i = 0; i < p->stuNum; i++)
                qDebug() << p->selected[i] << ' ';
        }
        p = p->next;
}
