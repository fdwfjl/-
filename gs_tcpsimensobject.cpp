#include "gs_tcpsimensobject.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QDebug>




gs_tcpsimensobject::gs_tcpsimensobject(QObject *parent) : QObject(parent)
{
    InitPara();
    InitSlot();

}

gs_tcpsimensobject::~gs_tcpsimensobject()
{
    qDebug()<<"TcpDestorySuccess!";
}

void gs_tcpsimensobject::InitPara()
{
    m_pTcpServer=new QTcpServer(this);
    m_pTcpSocket=new QTcpSocket(this);
    m_pTcpSocket=nullptr;
}

void gs_tcpsimensobject::InitSlot()
{
    connect(m_pTcpServer,SIGNAL(newConnection()),this,SLOT(ConnectServeSlot()));

}

void gs_tcpsimensobject::ConnectServeSlot()
{
    m_pTcpSocket=m_pTcpServer->nextPendingConnection();
    connect(m_pTcpSocket,SIGNAL(disconnected()),this,SLOT(DisconnectServerSlot()));
    connect(m_pTcpSocket,SIGNAL(readyRead()),this,SLOT(ServeReadSlot()));
    emit ConnectSuccessSignal();

}

void gs_tcpsimensobject::DisconnectServerSlot()
{
    m_pTcpSocket=nullptr;
    if(m_pTcpServer->isListening())
    {
        emit ListeningSignal();
    }
    else
    {
        bool ret=m_pTcpServer->listen(QHostAddress(m_StringIP),m_iPort);
        if(ret)
        {
            emit ListeningSignal();
        }
        else
        {
            emit DisconnectSignal();
        }
    }

}

void gs_tcpsimensobject::ListenServeSlot(QString Ip, QString Port)
{   
    if(m_pTcpServer->isListening())
    {
        m_pTcpServer->close();
    }
    m_StringIP=Ip;
    m_iPort=Port.toInt();  
    bool ret=m_pTcpServer->listen(QHostAddress(m_StringIP),m_iPort);  
    if(ret==true)
    {
        emit  ListeningSignal();
    }

}

void gs_tcpsimensobject::ServeReadSlot()
{
    QString thedata=m_pTcpSocket->readAll();
    emit ReadDataSignal(thedata);
}

void gs_tcpsimensobject::ServeWriteSlot(QString thedata)
{
    if(m_pTcpSocket!=nullptr)
    {
        qDebug()<<"IamwriteToTcpOrder="<<thedata;
        int Count=m_pTcpSocket->write(thedata.toStdString().c_str());
        emit WriteCountSignal(Count);
    }
    else if(m_pTcpSocket==nullptr)
    {
        emit WriteFailSignal();
        qDebug()<<"WriteFail!";
    }
}


