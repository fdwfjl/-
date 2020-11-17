#ifndef GS_MYSQLOBJECT_H
#define GS_MYSQLOBJECT_H

#include <QObject>
#include <QSqlDatabase>
#include "gs_deviceparameter.h"


class QTimer;

class gs_mysqlObject : public QObject
{
    Q_OBJECT
public:
    explicit gs_mysqlObject(QObject *parent = nullptr);
private:
    int m_iCount;
    QVariantList OneList;
    QVariantList TwoList;
    QVariantList ThreeList;
    QVariantList FourList;
    QVariantList FiveList;
    QVariantList SixList;
    QVariantList SevenList;
    QSqlDatabase m_mysqlDatabase;

    DevicePara m_struct_DefaultPara;
    DevicePara m_struct_NowPara;




    QTimer*m_pTimer1sStart;
private:

    void InitSlot();
signals:
    void LinkMySqlSuccessSignal();
    void LinkMySqlFailSignal();
    void ProcessFinishSignal();
    void ProcessFinishTwentySignal();
    void WriteIntoMySqlSuccessSignal();
    void DeviceDefaultParaSignal(DevicePara thedata);
    void DeviceNowParaSignal(DevicePara thedata);
    void InitTheDeviceFailSignal();
    void ContinueGetThedataSignal();
public slots:

    void InitMySlot();
    void ProcessDataSlot(double* sdataOne,double* sdataTwo,int SectionLength,int ChannelCountOne,int ChannelCountTwo);
    void TwentyTimesSlot();
    void WriteIntoTheMySqlSlot();
    void ReadTheDefaultParaSlot();
    void WriteTheDeviceToMySqlSlot(QString Name,QString Parameter);
    void BeginThisObjectSlot();
private slots:
    void InitTheDeviceParaSlot();

};

#endif // GS_MYSQLOBJECT_H
