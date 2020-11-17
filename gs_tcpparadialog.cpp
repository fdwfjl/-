#include "gs_tcpparadialog.h"
#include "ui_gs_tcpparadialog.h"
#include <QDebug>
#include <QMessageBox>

gs_TcpParaDialog::gs_TcpParaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gs_TcpParaDialog)
{
    ui->setupUi(this);
    m_IpParameter.TheIp=ui->m_lineED_IP->text();
    m_IpParameter.ThePort=ui->m_lineED_Port->text();
    InitSlot();
}

gs_TcpParaDialog::~gs_TcpParaDialog()
{
    delete ui;
    qDebug()<<QStringLiteral("IP设置窗口删除成功");
}

void gs_TcpParaDialog::InitSlot()
{
    //connect(ui->m_btn_IpSure,SIGNAL(clicked()),this,SLOT(TheIpParameterSureSlot()));
   // connect(ui->m_btn_IpDefault,SIGNAL(clicked()),this,SLOT(TheIpParameterDafaultSlot()));
}

void gs_TcpParaDialog::closeEvent(QCloseEvent *e)
{
    int ret=QMessageBox::question(nullptr, QStringLiteral("提示"), QStringLiteral("参数已改变，是否写入"), QMessageBox::Yes | QMessageBox::No, QMessageBox::NoButton);
    if(ret==QMessageBox::Yes)
    {
    //    ui->m_btn_IpSure->clicked();
    }
    else if(ret==QMessageBox::No)
    {
    //    ui->m_btn_IpDefault->clicked();
     //   ui->m_btn_IpSure->clicked();
    }
}

void gs_TcpParaDialog::TheIpParameterSureSlot()
{
    qDebug()<<QStringLiteral("TCP参数确认槽");
    m_IpParameter.TheIp=ui->m_lineED_IP->text();
    m_IpParameter.ThePort=ui->m_lineED_Port->text();
    accept();
}

void gs_TcpParaDialog::TheIpParameterDafaultSlot()
{
    qDebug()<<QStringLiteral("TCP默认参数槽");

}
