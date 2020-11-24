#include "mainwidget.h"
#include "ui_mainwidget.h"

mainWidget::mainWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainWidget)
{
    ui->setupUi(this);
    cpwDialog =new changePasswordDialog;
    logindialog=new loginDialog;
    registdialog=new registDialog;
    studentsystem=new studentSystem;
    teachersystem=new teacherSystem;
    layout=new QStackedLayout;

    layout->addWidget(logindialog);
    layout->addWidget(registdialog);
    layout->addWidget(studentsystem);
    layout->addWidget(teachersystem);
    layout->addWidget(cpwDialog);
    setLayout(layout);

    connect(cpwDialog,SIGNAL(display(int)),layout,SLOT(setCurrentIndex(int)));
    connect(logindialog,SIGNAL(display(int)),layout,SLOT(setCurrentIndex(int)));
    connect(registdialog,SIGNAL(display(int)),layout,SLOT(setCurrentIndex(int)));
    connect(studentsystem,SIGNAL(display(int)),layout,SLOT(setCurrentIndex(int)));
    connect(teachersystem,SIGNAL(display(int)),layout,SLOT(setCurrentIndex(int)));

    connect(logindialog,SIGNAL(userId(int)),studentsystem,SLOT(recSignal(int)));
    connect(logindialog,SIGNAL(userId(int)),teachersystem,SLOT(recSignal(int)));
    connect(studentsystem,SIGNAL(setCpwType(int,int)),cpwDialog,SLOT(recSignal(int,int)));
    connect(teachersystem,SIGNAL(setCpwType(int,int)),cpwDialog,SLOT(recSignal(int,int)));
}

mainWidget::~mainWidget()
{
    delete ui;
}
