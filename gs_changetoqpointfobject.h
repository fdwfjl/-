#ifndef GS_CHANGETOQPOINTFOBJECT_H
#define GS_CHANGETOQPOINTFOBJECT_H

#include <QObject>
#define theLength 911.0
#define theWidth 471.0

enum ChartMode
{
    DistanceChart=0,
    ProcessureChart=1,
    Temperature=2
};


class gs_changetoqpointfobject : public QObject
{
    Q_OBJECT
public:
    explicit gs_changetoqpointfobject(QObject *parent = nullptr);

private:
    int m_iCurrentIndex;
    double m_dXcoordinateOffset;
    double m_dYcoordinateOffset;
    int m_iNumber;

signals:
    void ToDistanceSignal(QPointF* distanLaserOne,QPointF* distanceLaserTwo,int chartmode);
    void ToProcessureSignal(QPointF* pressureOne,QPointF* pressureTwo,QPointF* pressureThree,int chartmode);
    void ToTemperatureSignal(QPointF* tempOne,QPointF* tempTwo,int chartmode);
    void GetTheDataPointSignal(int i);

public slots:
    void StartTheObject();
    void SetCurrentIndexSlot(int CurrentIndex);
    void SetTheQpointfSlot(double* dataOne,double* dataTwo,int SectionLength,int ChannelCountOne,int ChannelCountTwo);
};

#endif // GS_CHANGETOQPOINTFOBJECT_H
