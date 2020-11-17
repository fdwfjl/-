#include "gs_functionframe.h"
#include <QPainter>
#include <QPen>
#include <QPoint>
#include <QDebug>


gs_functionFrame::gs_functionFrame(QWidget *parent) : QFrame(parent)
{
    InitPara();
    m_iChartNum=-1;

}

void gs_functionFrame::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    QPen pen(Qt::darkYellow);
    p.setPen(pen);
    for(int i=1;i<7;++i)
    {
        p.drawLine(m_pPointFirstLeft.x(),m_pPointFirstLeft.y()+i*m_iConstYDrawLineOffset,m_pPointFirstRight.x(),m_pPointFirstRight.y()+i*m_iConstYDrawLineOffset);
    }
    pen.setColor(Qt::darkBlue);
    p.setPen(pen);
    for(int i=1;i<10;++i)
    {
        p.drawLine(m_pPointFirstLeft.x()+i*m_iConstXDrawLineOffset,m_pPointFirstLeft.y(),m_pPointFirstLeft.x()+i*m_iConstXDrawLineOffset,m_pPointSecondLeft.y());
    }
    switch (m_iChartNum) {
    case TheDistanceChart:
    {
        QPointF*pp=m_pDistanceLaserOne;
        QPointF*qq=m_pDistanceLaserTwo;
        for(int i=0;i<1024;++i)
        {
            qDebug()<<"i="<<i<<"OneX="<<pp[i].x();
            qDebug()<<"i="<<i<<"OneY="<<pp[i].y();
            qDebug()<<"i="<<i<<"TwoX="<<qq[i].x();
            qDebug()<<"i="<<i<<"TwoY="<<qq[i].y();
        }
        pen.setColor(Qt::red);
        p.setPen(pen);
        p.drawPolyline(pp,1024);
        pen.setColor(Qt::green);
        p.setPen(pen);
        p.drawPolyline(qq,1024);
        delete[]m_pDistanceLaserOne;
        delete[]m_pDistanceLaserTwo;
        m_pDistanceLaserOne=nullptr;
        m_pDistanceLaserTwo=nullptr;
        pp=nullptr;
        qq=nullptr;
        break;
    }
    case TheProcessureChart:
    {
        QPointF*pp=m_pPressureOne;
        QPointF*qq=m_pPressureTwo;
        QPointF*tt=m_pPressureThree;
        pen.setColor(Qt::red);
        p.setPen(pen);
        p.drawPolyline(pp,1024);
        pen.setColor(Qt::green);
        p.setPen(pen);
        p.drawPolyline(qq,1024);
        pen.setColor(Qt::yellow);
        p.setPen(pen);
        p.drawPolyline(tt,1024);
        delete[]m_pPressureOne;
        delete[]m_pPressureTwo;
        delete[]m_pPressureThree;
        m_pPressureOne=nullptr;
        m_pPressureTwo=nullptr;
        m_pPressureThree=nullptr;
        pp=nullptr;
        qq=nullptr;
        tt=nullptr;
        break;
    }
    case TheTemperature:
    {
        QPointF*pp=m_pTempOne;
        QPointF*qq=m_pTempTwo;
        pen.setColor(Qt::red);
        p.setPen(pen);
        p.drawPolyline(pp,1024);
        pen.setColor(Qt::green);
        p.setPen(pen);
        p.drawPolyline(qq,1024);
        delete[]m_pTempOne;
        delete[]m_pTempTwo;
        m_pTempOne=nullptr;
        m_pTempTwo=nullptr;
        pp=nullptr;
        qq=nullptr;
        break;
    }
    case TheStopChart:
        break;
    }
}

void gs_functionFrame::InitPara()
{
    QColor backgound=QColor(220,220,220,100);
    m_pPointFGroupOne=nullptr;
    m_pPointFGroupTwo=nullptr;
    m_pPointFGroupThree=nullptr;
    m_pPressureOne=nullptr;
    m_pPressureTwo=nullptr;
    m_pPressureThree=nullptr;
    m_pTempOne=nullptr;
    m_pTempTwo=nullptr;
    m_pDistanceLaserOne=nullptr;
    m_pDistanceLaserTwo=nullptr;
    this->setFixedSize(911,471);
   // this->setGeometry(40,10,911,471);
    this->setPalette(backgound);
    this->setAutoFillBackground(true);
    this->setStyleSheet("border:1px solid black;");
    m_pPointFirstLeft.setX(this->rect().x());
    m_pPointFirstLeft.setY(this->rect().y());
    m_pPointFirstRight.setX(this->rect().x()+911);
    m_pPointFirstRight.setY(this->rect().y());
    m_pPointSecondLeft.setX(this->rect().x());
    m_pPointSecondLeft.setY(this->rect().y()+471);
    m_pPointSecondRight.setX(this->rect().x()+911);
    m_pPointSecondRight.setY(this->rect().y()+471);
    m_iConstXDrawLineOffset=qRound(911.0/10.0);
    m_iConstYDrawLineOffset=qRound(471.0/7.0);

}

void gs_functionFrame::DrawDistanceSlot(QPointF *distanceLaserOne, QPointF *distanceLaserTwo, int theChartMode)
{
    m_pDistanceLaserOne=distanceLaserOne;
    m_pDistanceLaserTwo=distanceLaserTwo;
    m_iChartNum=theChartMode;
    update();
    qDebug()<<"TheFour";
}

void gs_functionFrame::DrawPressureSlot(QPointF *pressureOne, QPointF *pressureTwo, QPointF *pressureThree, int theChartMode)
{
    m_pPressureOne=pressureOne;
    m_pPressureTwo=pressureTwo;
    m_pPressureThree=pressureThree;
    m_iChartNum=theChartMode;
    update();
    qDebug()<<"TheFive";
}

void gs_functionFrame::DrawTemperatureSlot(QPointF *temperatureOne, QPointF *temperatureTwo, int theChartMode)
{
    m_pTempOne=temperatureOne;
    m_pTempTwo=temperatureTwo;
    m_iChartNum=theChartMode;
    update();
}

void gs_functionFrame::DrawStopSlot(int theChartMode)
{
    m_iChartNum=theChartMode;
}





