#include "gs_functionframeobject.h"

gs_functionframeobject::gs_functionframeobject(QObject *parent) : QObject(parent)
{
    m_pTheChartFrame=new gs_functionFrame(this);
}

gs_functionframeobject::~gs_functionframeobject()
{
    delete m_pTheChartFrame;
    m_pTheChartFrame=nullptr;

}

void gs_functionframeobject::DrawTheDistanceSlot(QPointF *distanceLaserOne, QPointF *distanceLaserTwo, int theChartMode)
{
    m_pTheChartFrame->DrawDistanceSlot(distanceLaserOne,distanceLaserTwo,theChartMode);
}

void gs_functionframeobject::DrawThePressureSlot(QPointF *pressureOne, QPointF *pressureTwo, QPointF *pressureThree, int theChartMode)
{
    m_pTheChartFrame->DrawPressureSlot(pressureOne,pressureTwo,pressureThree,theChartMode);
}

void gs_functionframeobject::DrawTheTempSlot(QPointF *temperatureOne, QPointF *temperatureTwo, int theChartMode)
{
    m_pTheChartFrame->DrawTemperatureSlot(temperatureOne,temperatureTwo,theChartMode);
}
