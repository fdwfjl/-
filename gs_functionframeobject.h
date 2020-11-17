#ifndef GS_FUNCTIONFRAMEOBJECT_H
#define GS_FUNCTIONFRAMEOBJECT_H
#include "gs_functionframe.h"
#include <QObject>

class gs_functionframeobject : public QObject
{
    Q_OBJECT
public:
    explicit gs_functionframeobject(QObject *parent = nullptr);
    ~gs_functionframeobject();

public:
    gs_functionFrame*m_pTheChartFrame;

signals:

public slots:
    void DrawTheDistanceSlot(QPointF* distanceLaserOne,QPointF* distanceLaserTwo,int theChartMode);
    void DrawThePressureSlot(QPointF* pressureOne,QPointF* pressureTwo,QPointF* pressureThree,int theChartMode);
    void DrawTheTempSlot(QPointF* temperatureOne,QPointF* temperatureTwo,int theChartMode);
};

#endif // GS_FUNCTIONFRAMEOBJECT_H
