#ifndef GS_ACQUISITIONOBJECT_H
#define GS_ACQUISITIONOBJECT_H

#include <QObject>
#include "bdaqctrl.h"
#include "gs_acquisitiondialog.h"
#include "gs_acquisitionparameter.h"


class gs_acquisitionObject : public QObject
{
    Q_OBJECT
public:
    explicit gs_acquisitionObject(QObject *parent = nullptr);
    ~gs_acquisitionObject();

private:

   ConfigureAcquisition m_struct_AcquisitionPara;
   WaveformAiCtrl*m_pWaveformAiCtrl;
   int m_iRawDataBufferLength;
   static const int sectionCount=0;




private:
   void InitPara();
   void InitSlot();
   void InitTheAcquisition();
   void CheckError(ErrorCode errorCode);
   void DataReadyRead(double* sdata );
   void OverRunSignalEmit();
   void CacheOverFlowEmit();
   void StopEmit();

private:
   static void BDAQCALL OnDataReadyEvent(void * sender, BfdAiEventArgs * args, void * userParam);
   static void BDAQCALL OnOverRunEvent(void * sender, BfdAiEventArgs * args, void * userParam);
   static void BDAQCALL OnCacheOverflowEvent(void * sender, BfdAiEventArgs * args, void * userParam);
   static void BDAQCALL OnStoppedEvent(void * sender, BfdAiEventArgs * args, void * userParam);

    
public slots:
   void OpenTheAcquisitionDialogSlot();
   void StartTheAcquisitionSlot();
   void StopTheAcqusitionSlot();
   void GetTheAcquisitionParaSlot(ConfigureAcquisition thestruct);// 初始化参数


private slots:
   void AcquisitionChangeSlot();

signals:
   void NoDeviceSignal();
   void DataReadySignal(double* sdata,int SectionLength,int ChannelCount);
   void OverRunSignal();
   void CacheOverFlowSignal();
   void StopSignal();
   void DeviceErrorSignal(int error);

};

#endif // GS_ACQUISITIONOBJECT_H
