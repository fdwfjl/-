#ifndef GS_DEVICEPARAMETER_H
#define GS_DEVICEPARAMETER_H
#include <QMetaType>

struct DevicePara
{
    QString qString_theWorkSpeed;
    QString qString_theWorkAccelerate;
    QString qString_theWorkDecelerate;
    QString qString_theJogSpeed;
    QString qString_theAcquisitionOne_Frequency;
    QString qString_theAcquisitionOne_SectionLength;
    QString qString_theAcquisitionOne_ChannelCount;
    QString qString_theAcquisitionOne_ChannelStart;
    QString qString_theAcquisitionTwo_Frequency;
    QString qString_theAcquisitionTwo_SectionLength;
    QString qString_theAcquisitionTwo_ChannelCount;
    QString qString_theAcquisitionTwo_ChannelStart;
};
Q_DECLARE_METATYPE(DevicePara)
#endif // GS_DEVICEPARAMETER_H
