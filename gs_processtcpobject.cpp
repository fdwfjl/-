#include "gs_processtcpobject.h"
#include <QTimer>
#include <QDebug>

gs_processtcpobject::gs_processtcpobject(QObject *parent) : QObject(parent)
{
    InitPara();
    InitSlot();

}

void gs_processtcpobject::InitPara()
{
    m_iReceiveCount=0;
    m_iSendCount=0;
    m_pTimer1S=new QTimer(this);
    m_pTimer1S->setInterval(1000);
    m_pTimer1S->start();

}

void gs_processtcpobject::InitSlot()
{
    connect(m_pTimer1S,SIGNAL(timeout()),this,SLOT(The1STimerSlot()));

}



void gs_processtcpobject::ReceiveTheOrderSlot(QString sorder)
{ 
    qDebug()<<"GetTheOrder="<<sorder;
    int i=m_iReceiveCount%100;
    receiveData[i]=sorder;
    m_iReceiveCount=m_iReceiveCount+1;
}

void gs_processtcpobject::SendTheOrderSlot(QString sorder)
{      
    qDebug()<<"ReadFromSimen=="<<sorder;
    m_pTimer1S->stop();
    if(sorder.contains("OK",Qt::CaseSensitive))
    {
        qDebug()<<"ReceiveTheOK!";
        m_iSendCount=m_iSendCount+1;

    }
    if(sorder.contains("Status",Qt::CaseSensitive))
    {
        qDebug()<<"ReceiveTheStatus";
        m_iSendCount=m_iSendCount+1;
        emit SendToMainSignal(sorder);
    }
    if(m_iReceiveCount>m_iSendCount)
    {
        int i=m_iSendCount%100;
        emit SendToTcpSignal(receiveData[i]);
    }
    else if(m_iReceiveCount==m_iSendCount)
    {
        m_pTimer1S->start();
    }


}

void gs_processtcpobject::The1STimerSlot()
{
    if(m_iReceiveCount>m_iSendCount)
    {
        SendTheOrderSlot("start");
    }

}
