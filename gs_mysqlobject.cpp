#include "gs_mysqlobject.h"
#include <QDebug>
#include <QSqlQuery>
#include <QTimer>
gs_mysqlObject::gs_mysqlObject(QObject *parent) : QObject(parent)
{
    m_iCount=0;
    m_pTimer1sStart=new QTimer(this);
    m_pTimer1sStart->setInterval(1000);
    InitSlot();
}

void gs_mysqlObject::InitMySlot()
{
    qDebug()<<"MySqlSlot";
    m_mysqlDatabase=QSqlDatabase::addDatabase("QMYSQL");
    m_mysqlDatabase.setHostName("127.0.0.1");
    m_mysqlDatabase.setUserName("root");
    m_mysqlDatabase.setPassword("abc123456789");
    m_mysqlDatabase.setDatabaseName("mydatas");
    if(!m_mysqlDatabase.open())
    {
        emit LinkMySqlFailSignal();
        qDebug()<<"openFail!";
    }
    else
    {
        emit LinkMySqlSuccessSignal();
        m_pTimer1sStart->start();
        qDebug()<<"openSuccess!";
    }


}

void gs_mysqlObject::InitSlot()
{
    connect(this,SIGNAL(ProcessFinishSignal()),this,SLOT(TwentyTimesSlot()));
    connect(this,SIGNAL(ProcessFinishTwentySignal()),this,SLOT(WriteIntoTheMySqlSlot()));
    connect(this,SIGNAL(LinkMySqlSuccessSignal()),this,SLOT(ReadTheDefaultParaSlot()));
    connect(m_pTimer1sStart,SIGNAL(timeout()),this,SLOT(InitTheDeviceParaSlot()));
}

void gs_mysqlObject::ProcessDataSlot(double* sdataOne,double* sdataTwo,int SectionLength,int ChannelCountOne,int ChannelCountTwo)
{
    double*p=sdataOne;
    double*pp=sdataTwo;
    for(int i=0;i<SectionLength*ChannelCountOne/4;++i)
    {
        OneList<<sdataOne[5*i];
        TwoList<<sdataOne[5*i+1];
        ThreeList<<sdataOne[5*i+2];
        FourList<<sdataOne[5*i+3];
        FiveList<<sdataTwo[5*i+4];
    }
    for(int i=0;i<SectionLength*ChannelCountTwo/4;++i)
    {

        SixList<<sdataTwo[2*i];
        SevenList<<sdataTwo[2*i+1];
    }
    delete[]p;
    delete[]pp;
    sdataOne=nullptr;
    sdataTwo=nullptr;
    p=nullptr;
    pp=nullptr;
    emit ProcessFinishSignal();
}

void gs_mysqlObject::TwentyTimesSlot()
{
    m_iCount=m_iCount+1;
    if(m_iCount==20)
    {
        emit ProcessFinishTwentySignal();
        m_iCount=0;
    }
    else
    {
        emit ContinueGetThedataSignal();
    }
}





void gs_mysqlObject::WriteIntoTheMySqlSlot()
{
    QSqlQuery query(m_mysqlDatabase);
    query.exec("SET autocommit=0;");
    query.prepare("INSERT INTO mytable VALUES(?,?,?,?,?,?,?)");
    query.addBindValue(SixList);
    query.addBindValue(SevenList);
    query.addBindValue(OneList);
    query.addBindValue(TwoList);
    query.addBindValue(ThreeList);
    query.addBindValue(FourList);
    query.addBindValue(FiveList);    
    query.execBatch();
    bool ret=query.exec("COMMIT");
    if(ret==true)
    {
        OneList.clear();
        TwoList.clear();
        ThreeList.clear();
        FourList.clear();
        FiveList.clear();
        SixList.clear();
        SevenList.clear();
        emit WriteIntoMySqlSuccessSignal();
        emit ContinueGetThedataSignal();
    }
}

void gs_mysqlObject::ReadTheDefaultParaSlot()
{

}

void gs_mysqlObject::WriteTheDeviceToMySqlSlot(QString Name, QString Parameter)
{
    QSqlQuery query(m_mysqlDatabase);


}

void gs_mysqlObject::BeginThisObjectSlot()
{
    emit ContinueGetThedataSignal();
}

void gs_mysqlObject::InitTheDeviceParaSlot()
{
    m_pTimer1sStart->stop();
    QSqlQuery query(m_mysqlDatabase);
    bool ret=query.exec("SELECT*FROM devicepara;");
    if(ret==true)
    {
        qDebug()<<"SQLOK";
        query.seek(0);
        m_struct_DefaultPara.qString_theWorkSpeed=query.value(1).toString();
        m_struct_DefaultPara.qString_theWorkAccelerate=query.value(2).toString();
        m_struct_DefaultPara.qString_theWorkDecelerate=query.value(3).toString();
        m_struct_DefaultPara.qString_theJogSpeed=query.value(4).toString();
        m_struct_DefaultPara.qString_theAcquisitionOne_Frequency=query.value(5).toString();
        m_struct_DefaultPara.qString_theAcquisitionOne_SectionLength=query.value(6).toString();
        m_struct_DefaultPara.qString_theAcquisitionOne_ChannelCount=query.value(7).toString();
        m_struct_DefaultPara.qString_theAcquisitionOne_ChannelStart=query.value(8).toString();
        m_struct_DefaultPara.qString_theAcquisitionTwo_Frequency=query.value(9).toString();
        m_struct_DefaultPara.qString_theAcquisitionTwo_SectionLength=query.value(10).toString();
        m_struct_DefaultPara.qString_theAcquisitionTwo_ChannelCount=query.value(11).toString();
        m_struct_DefaultPara.qString_theAcquisitionTwo_ChannelStart=query.value(12).toString();
        emit DeviceDefaultParaSignal(m_struct_DefaultPara);
        query.seek(1);
        m_struct_NowPara.qString_theWorkSpeed=query.value(1).toString();
        m_struct_NowPara.qString_theWorkAccelerate=query.value(2).toString();
        m_struct_NowPara.qString_theWorkDecelerate=query.value(3).toString();
        m_struct_NowPara.qString_theJogSpeed=query.value(4).toString();
        m_struct_NowPara.qString_theAcquisitionOne_Frequency=query.value(5).toString();
        m_struct_NowPara.qString_theAcquisitionOne_SectionLength=query.value(6).toString();
        m_struct_NowPara.qString_theAcquisitionOne_ChannelCount=query.value(7).toString();
        m_struct_NowPara.qString_theAcquisitionOne_ChannelStart=query.value(8).toString();
        m_struct_NowPara.qString_theAcquisitionTwo_Frequency=query.value(9).toString();
        m_struct_NowPara.qString_theAcquisitionTwo_SectionLength=query.value(10).toString();
        m_struct_NowPara.qString_theAcquisitionTwo_ChannelCount=query.value(11).toString();
        m_struct_NowPara.qString_theAcquisitionTwo_ChannelStart=query.value(12).toString();
        emit DeviceNowParaSignal(m_struct_NowPara);
    }
    else
    {
        emit InitTheDeviceFailSignal();
    }


}
