#ifndef GS_ACQUISITIONALLPARA_H
#define GS_ACQUISITIONALLPARA_H
#include <QString>
#include <QMetaType>

struct TwoAcquisitionPara
{
    QString AcquisitionOneDefaultFrequency;
    QString AcquisitionOneDefaultSectionLength;
    QString AcquisitionOneDefaultChannelCount;
    QString AcquisitionOneDefaultChannelStart;
    QString AcquisitionTwoDefaultFrequency;
    QString AcquisitionTwoDefaultSectionLength;
    QString AcquisitionTwoDefaultChannelCount;
    QString AcquisitionTwoDefaultChannelStart;
    QString AcquisitionOneNowFrequency;
    QString AcquisitionOneNowSectionLength;
    QString AcquisitionOneNowChannelCount;
    QString AcquisitionOneNowChannelStart;
    QString AcquisitionTwoNowFrequency;
    QString AcquisitionTwoNowSectionLength;
    QString AcquisitionTwoNowChannelCount;
    QString AcquisitionTwoNowChannelStart;
    QString AcquisitionOneDeviceName;
    QString AcquisitionTwoDeviceName;
    QString AcquisitionOneConfigurePath;
    QString AcquisitionTwoConfigurePath;
};

Q_DECLARE_METATYPE(TwoAcquisitionPara)
#endif // GS_ACQUISITIONALLPARA_H
