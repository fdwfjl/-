#include "gs_registerdialog.h"
#include "ui_gs_registerdialog.h"
#include <QMessageBox>
#include <QDebug>

gs_registerDialog::gs_registerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gs_registerDialog)
{
    ui->setupUi(this);
    InitSlot();
}

gs_registerDialog::~gs_registerDialog()
{
    delete ui;
    qDebug()<<"Delete The Dialog Success!";    
}

void gs_registerDialog::InitSlot()
{
    connect(ui->m_btn_SignIn,SIGNAL(clicked()),this,SLOT(ToAcceptSlot()));
    connect(ui->m_btn_Exit,SIGNAL(clicked()),this,SLOT(ToReceptSlot()));

}

void gs_registerDialog::ToAcceptSlot()
{
    QString theUser=ui->m_lineED_User->text();
    QString thePassword=ui->m_lineED_Password->text();
    if(theUser=="David")
    {
        if(thePassword=="123456789")
        {
            accept();
        }
        else
        {
            QMessageBox::warning(nullptr,"Warning", "Password Error!");
        }
    }
    else
    {
        QMessageBox::warning(nullptr,"Warning", "User Error");
    }

}

void gs_registerDialog::ToReceptSlot()
{
    reject();

}
