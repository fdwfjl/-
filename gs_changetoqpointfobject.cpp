#include "gs_changetoqpointfobject.h"
#include <QPointF>
#include <QDebug>

gs_changetoqpointfobject::gs_changetoqpointfobject(QObject *parent) : QObject(parent)
{
    m_dXcoordinateOffset=theLength/1024.0;
    m_dYcoordinateOffset=theWidth/70.0;
    m_iNumber=0;
    qDebug()<<"YOffset"<<m_dYcoordinateOffset;

}

void gs_changetoqpointfobject::StartTheObject()
{
    emit GetTheDataPointSignal(m_iNumber);
}

void gs_changetoqpointfobject::SetCurrentIndexSlot(int CurrentIndex)
{
    m_iCurrentIndex=CurrentIndex;
}

void gs_changetoqpointfobject::SetTheQpointfSlot(double *dataOne, double *dataTwo, int SectionLength, int ChannelCountOne, int ChannelCountTwo)
{
    if(dataOne==nullptr || dataTwo==nullptr)
    {
        qDebug()<<"I am free";
        emit GetTheDataPointSignal(m_iNumber);
    }
    else
    {
    QPointF*pressureOne=new QPointF[SectionLength];
    QPointF*pressureTwo=new QPointF[SectionLength];
    QPointF*pressureThree=new QPointF[SectionLength];
    QPointF*thetemperatureone=new QPointF[SectionLength];
    QPointF*thetemperaturetwo=new QPointF[SectionLength];
    QPointF*distanceLaserOne=new QPointF[SectionLength];
    QPointF*distanceLaserTwo=new QPointF[SectionLength];
    QPointF*a=pressureOne;
    QPointF*b=pressureTwo;
    QPointF*c=pressureThree;
    QPointF*d=thetemperatureone;
    QPointF*e=thetemperaturetwo;
    QPointF*f=distanceLaserOne;
    QPointF*g=distanceLaserTwo;

    for(int i=0;i<SectionLength;++i) //采集卡1
    {
        a->setX(i*m_dXcoordinateOffset);
        b->setX(i*m_dXcoordinateOffset);
        c->setX(i*m_dXcoordinateOffset);
        d->setX(i*m_dXcoordinateOffset);
        e->setX(i*m_dXcoordinateOffset);

        a->setY((6-*dataOne)*10*m_dYcoordinateOffset);
        dataOne++;
        b->setY((6-*dataOne)*10*m_dYcoordinateOffset);
        dataOne++;
        c->setY((6-*dataOne)*10*m_dYcoordinateOffset);
        dataOne++;
        d->setY((6-*dataOne)*10*m_dYcoordinateOffset);
        dataOne++;
        e->setY((6-*dataOne)*10*m_dYcoordinateOffset);
        dataOne++;
        a++;
        b++;
        c++;
        d++;
        e++;

    }

    for(int i=0;i<SectionLength;++i)  //采集卡2
    {
        f->setX(i*m_dXcoordinateOffset);
        g->setX(i*m_dXcoordinateOffset);

        f->setY((6-*dataTwo)*10*m_dYcoordinateOffset);
        dataTwo++;
        g->setY((6-*dataTwo)*10*m_dYcoordinateOffset);
        dataTwo++;
        f++;
        g++;
    }
    emit ToDistanceSignal(distanceLaserOne,distanceLaserTwo,DistanceChart);
    emit ToProcessureSignal(pressureOne,pressureTwo,pressureThree,ProcessureChart);
    emit ToTemperatureSignal(thetemperatureone,thetemperaturetwo,Temperature);
    dataOne=nullptr;
    dataTwo=nullptr;
    a=nullptr;
    b=nullptr;
    c=nullptr;
    d=nullptr;
    e=nullptr;
    f=nullptr;
    g=nullptr;
    pressureOne=nullptr;
    pressureTwo=nullptr;
    pressureThree=nullptr;
    thetemperatureone=nullptr;
    thetemperaturetwo=nullptr;
    distanceLaserOne=nullptr;
    distanceLaserTwo=nullptr;
    m_iNumber++;
    emit GetTheDataPointSignal(m_iNumber);
    }
    qDebug()<<"m_iNumber="<<m_iNumber;
}
