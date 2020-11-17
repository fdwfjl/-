#ifndef GS_ACQUISITIONPARAMETER_H
#define GS_ACQUISITIONPARAMETER_H
#include "bdaqctrl.h"
#include <QString>
#include <QMetaType>



using namespace Automation::BDaq;
struct ConfigureAcquisition
{
    QString DeviceName;
    int ChannelCount;
    int ChannelStart;
    int32 ClockRatePerChannel;
    int32 sectionLength;
    const wchar_t* profilePath;
};
Q_DECLARE_METATYPE(ConfigureAcquisition)
#endif // GS_ACQUISITIONPARAMETER_H
