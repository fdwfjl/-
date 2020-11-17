#include "gs_changetwotooneobject.h"
#include <QTimer>
#include <QDebug>

gs_ChangeTwoToOneObject::gs_ChangeTwoToOneObject(QObject *parent) : QObject(parent)
{
    InitPara();
    InitSlot();
}

gs_ChangeTwoToOneObject::~gs_ChangeTwoToOneObject()
{
    qDebug()<<"Delete ChangeTwoToOneSuccess";
}

void gs_ChangeTwoToOneObject::InitPara()
{
    m_iChannelOneCount=0;
    m_iChannelTwoCount=0;
    m_iSectionLength=0;
    m_iProcessOneDecadeChart=0;
    m_iProcessTwoDecadeChart=0;
    m_iProcessOneTimesChart=0;
    m_iProcessTwoTimesChart=0;
    m_iSendSignalDecadeChart=0;
    m_iSendSignalTimesChart=0;

    m_iProcessOneDecadeSql=0;
    m_iProcessTwoDecadeSql=0;
    m_iProcessOneTimesSql=0;
    m_iProcessTwoTimesSql=0;
    m_iSendSignalDecadeSql=0;
    m_iSendSignalTimesSql=0;


    m_p10msTimer=new QTimer(this);
    m_p10msTimer->setInterval(10);
    m_p10msTimer->start();
}

void gs_ChangeTwoToOneObject::InitSlot()
{
    connect(m_p10msTimer,SIGNAL(timeout()),this,SLOT(IfCanStartSlot()));
}

int gs_ChangeTwoToOneObject::GetDataOneChartNumber()
{
    return m_iProcessOneDecadeChart*10000+m_iProcessOneTimesChart;

}

int gs_ChangeTwoToOneObject::GetDataTwoChartNumber()
{
    return m_iProcessTwoDecadeChart*10000+m_iProcessTwoTimesChart;
}

int gs_ChangeTwoToOneObject::GetProcessAllChartNumber()
{
    return m_iSendSignalDecadeChart*10000+m_iSendSignalTimesChart;
}

int gs_ChangeTwoToOneObject::GetDataOneSqlNumber()
{
    return m_iProcessOneDecadeSql*10000+m_iProcessOneTimesSql;
}

int gs_ChangeTwoToOneObject::GetDataTwoSqlNumber()
{
    return m_iProcessTwoDecadeSql*10000+m_iProcessTwoTimesSql;
}

int gs_ChangeTwoToOneObject::GetProcessAllSqlNumber()
{
    return m_iSendSignalDecadeSql*10000+m_iSendSignalTimesSql;
}

void gs_ChangeTwoToOneObject::ProcessOneSlot(double *sdata, int iSectionLength, int ChannelOneCount)
{
    qDebug()<<"TheOneAddress="<<sdata;
    p[m_iProcessOneTimesChart][0]=sdata;
    qDebug()<<"A1="<<m_iProcessOneTimesChart;
    m_iSectionLength=iSectionLength;
    m_iChannelOneCount=ChannelOneCount;
    m_iProcessOneTimesChart++;
    m_iProcessOneTimesSql++;
    if(m_iProcessOneTimesChart==10000)
    {
        m_iProcessOneDecadeChart++;
        m_iProcessOneDecadeSql++;
        m_iProcessOneTimesChart=0;
    }
    emit ProcessOnePutIntoSuccessSignal(m_iProcessOneDecadeChart*10000+m_iProcessOneTimesChart);
}

void gs_ChangeTwoToOneObject::ProcessTwoSlot(double *sdata, int iSectionLength, int ChannelTwoCount)
{
    qDebug()<<"TheTwoAddress"<<sdata;
    p[m_iProcessTwoTimesChart][1]=sdata;
    qDebug()<<"A2="<<m_iProcessTwoTimesChart;
    m_iSectionLength=iSectionLength;
    m_iChannelTwoCount=ChannelTwoCount;
    m_iProcessTwoTimesChart++;
    m_iProcessTwoTimesSql++;
    if(m_iProcessTwoTimesChart==10000)
    {
        m_iProcessTwoDecadeChart++;
        m_iProcessTwoDecadeSql++;
        m_iProcessTwoTimesChart=0;
    }
    emit ProcessTwoPutIntoSuccessSignal(m_iProcessTwoDecadeChart*10000+m_iProcessTwoTimesChart);
}

void gs_ChangeTwoToOneObject::GetChartDataSlot(int i)
{
    if(i<10000)
    {
        double *a=p[i][0];
        double *b=p[i][1];
        qDebug()<<"theA="<<a;
        qDebug()<<"theB="<<b;
        emit DataToChartSignal(a,b,m_iSectionLength,m_iChannelOneCount,m_iChannelTwoCount);
    }
    else
    {
        i=i-10000;
        double *a=p[i][0];
        double *b=p[i][1];
        emit DataToChartSignal(a,b,m_iSectionLength,m_iChannelOneCount,m_iChannelTwoCount);
    }
}

void gs_ChangeTwoToOneObject::GetSqlDataSlot(int i)
{
    if(i<10000)
    {
        double *a=p[i][0];
        double *b=p[i][1];
        emit DataToMySqlSignal(a,b,m_iSectionLength,m_iChannelOneCount,m_iChannelTwoCount);
    }
    else
    {
        i=i-10000;
        double *a=p[i][0];
        double *b=p[i][1];
        emit DataToMySqlSignal(a,b,m_iSectionLength,m_iChannelOneCount,m_iChannelTwoCount);
    }

}





void gs_ChangeTwoToOneObject::IfCanStartSlot()
{
    if (m_iProcessOneTimesChart>0&&m_iProcessTwoTimesChart>0)
    {
        m_p10msTimer->stop();
        emit CanGetDataChartSignal();
        emit CanGetDataSqlSignal();
    }
}
