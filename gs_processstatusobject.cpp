#include "gs_processstatusobject.h"
#include <QDebug>

gs_processstatusobject::gs_processstatusobject(QObject *parent) : QObject(parent)
{

}

void gs_processstatusobject::processTheStatusSlot(QString sdata)
{
    QString theStatus;
    QString theSpeed;
    QString theCurrent;
    QString theFrequency;
    theStatus=sdata.section(':',0,0);
    theSpeed=sdata.section(':',1,1);
    theCurrent=sdata.section(':',2,2);
    theFrequency=sdata.section(':',3,3);
    theSpeed.remove(QRegExp("\\s"));
    theCurrent.remove(QRegExp("\\s"));
    theFrequency.remove(QRegExp("\\s"));
    emit ChangeTheFrequencyStatusSignal(theSpeed,theCurrent,theFrequency);
}
