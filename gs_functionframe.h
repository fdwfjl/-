#ifndef GS_FUNCTIONFRAME_H
#define GS_FUNCTIONFRAME_H

#include <QFrame>
#include <QPointF>


enum ChartModeTwo
{
    TheDistanceChart=0,
    TheProcessureChart=1,
    TheTemperature=2,
    TheStopChart=3
};

class QPoint;
class gs_functionFrame : public QFrame
{
    Q_OBJECT
public:
    explicit gs_functionFrame(QWidget *parent);
public:
    void paintEvent(QPaintEvent *);
private:
    int m_iChartNum;
    QPointF*m_pPointFGroupOne;
    QPointF*m_pPointFGroupTwo;
    QPointF*m_pPointFGroupThree;
    QPoint m_pPointFirstLeft;
    QPoint m_pPointFirstRight;
    QPoint m_pPointSecondLeft;
    QPoint m_pPointSecondRight;

    QPointF*m_pPressureOne;
    QPointF*m_pPressureTwo;
    QPointF*m_pPressureThree;
    QPointF*m_pTempOne;
    QPointF*m_pTempTwo;
    QPointF*m_pDistanceLaserOne;
    QPointF*m_pDistanceLaserTwo;


    int m_iConstXDrawLineOffset;
    int m_iConstYDrawLineOffset;


private:
    void InitPara();
signals:
    void DrawCharSuccessSignal();
public slots:   
    void DrawDistanceSlot(QPointF* distanceLaserOne,QPointF* distanceLaserTwo,int theChartMode);
    void DrawPressureSlot(QPointF* pressureOne,QPointF* pressureTwo,QPointF* pressureThree,int theChartMode);
    void DrawTemperatureSlot(QPointF* temperatureOne,QPointF* temperatureTwo,int theChartMode);
    void DrawStopSlot(int theChartMode);
};

#endif // GS_FUNCTIONFRAME_H
