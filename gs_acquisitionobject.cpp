#include "gs_acquisitionobject.h"
#include <QDebug>

gs_acquisitionObject::gs_acquisitionObject(QObject *parent) : QObject(parent)
{
    InitPara();
    InitSlot();
    
}

gs_acquisitionObject::~gs_acquisitionObject()
{   
    if(m_pWaveformAiCtrl!=nullptr)
    {
        m_pWaveformAiCtrl->Dispose();
    }
   // qDebug()<<QStringLiteral("删除设备卡线程成功~!");

}

void gs_acquisitionObject::InitPara()
{

    m_pWaveformAiCtrl=WaveformAiCtrl::Create();
    m_pWaveformAiCtrl->addDataReadyHandler(OnDataReadyEvent,this);
    m_pWaveformAiCtrl->addOverrunHandler(OnOverRunEvent,this);
    m_pWaveformAiCtrl->addCacheOverflowHandler(OnCacheOverflowEvent,this);
    m_pWaveformAiCtrl->addStoppedHandler(OnStoppedEvent,this);

}

void gs_acquisitionObject::InitSlot()
{


}

void gs_acquisitionObject::InitTheAcquisition()
{
    if(m_struct_AcquisitionPara.DeviceName=="None")
    {
        emit NoDeviceSignal();
    }
    else
    {
        ErrorCode errorCode = Success;
        m_iRawDataBufferLength=m_struct_AcquisitionPara.ChannelCount*m_struct_AcquisitionPara.sectionLength;
        std::wstring description=m_struct_AcquisitionPara.DeviceName.toStdWString();
        DeviceInformation selected(description.c_str());

        errorCode=m_pWaveformAiCtrl->setSelectedDevice(selected);
        CheckError(errorCode);
        errorCode=m_pWaveformAiCtrl->LoadProfile(m_struct_AcquisitionPara.profilePath);
        CheckError(errorCode);

        errorCode=m_pWaveformAiCtrl->getConversion()->setChannelCount(m_struct_AcquisitionPara.ChannelCount);
        CheckError(errorCode);
        errorCode=m_pWaveformAiCtrl->getConversion()->setChannelStart(m_struct_AcquisitionPara.ChannelStart);
        CheckError(errorCode);
        errorCode=m_pWaveformAiCtrl->getConversion()->setClockRate(m_struct_AcquisitionPara.ClockRatePerChannel);
        CheckError(errorCode);

        errorCode=m_pWaveformAiCtrl->getRecord()->setSectionLength(m_struct_AcquisitionPara.sectionLength);
        CheckError(errorCode);
        errorCode=m_pWaveformAiCtrl->getRecord()->setSectionCount(sectionCount);     //0表示STREAMING模式
        CheckError(errorCode);

    }

}

void gs_acquisitionObject::CheckError(ErrorCode errorCode)
{
    if(BioFailed(errorCode))
    {
        emit DeviceErrorSignal(errorCode);
    }
}

void gs_acquisitionObject::DataReadyRead(double* sdata )
{
    emit DataReadySignal(sdata,m_struct_AcquisitionPara.sectionLength,m_struct_AcquisitionPara.ChannelCount);
}

void gs_acquisitionObject::OverRunSignalEmit()
{
    emit OverRunSignal();
}

void gs_acquisitionObject::CacheOverFlowEmit()
{
    emit CacheOverFlowSignal();
}

void gs_acquisitionObject::StopEmit()
{
    emit StopSignal();
}


void gs_acquisitionObject::OnDataReadyEvent(void *sender, BfdAiEventArgs *args, void *userParam)
{
    Q_UNUSED(args);
    gs_acquisitionObject * uParam=(gs_acquisitionObject*)userParam;
    double* theData=new double[uParam->m_iRawDataBufferLength];
    ErrorCode ret=((WaveformAiCtrl*)sender)->GetData(uParam->m_struct_AcquisitionPara.sectionLength*uParam->m_struct_AcquisitionPara.ChannelCount,theData,0,0);
    if(ret!=Success && ret!=WarningRecordEnd)
    {
        uParam->CheckError(ret);
    }
    else
    {
        uParam->DataReadyRead(theData);
    }

}

void gs_acquisitionObject::OnOverRunEvent(void *sender, BfdAiEventArgs *args, void *userParam)
{

    Q_UNUSED(args);
    Q_UNUSED(sender);
    gs_acquisitionObject* uParam=(gs_acquisitionObject*)userParam;
    uParam->OverRunSignalEmit();
    qDebug()<<QString("OverRunEvent");


}

void gs_acquisitionObject::OnCacheOverflowEvent(void *sender, BfdAiEventArgs *args, void *userParam)
{
    Q_UNUSED(sender);
    Q_UNUSED(args);
    gs_acquisitionObject* uParam=(gs_acquisitionObject*)userParam;
    uParam->CacheOverFlowEmit();
    qDebug()<<QString("CacheOverFlowEvent");

}

void gs_acquisitionObject::OnStoppedEvent(void *sender, BfdAiEventArgs *args, void *userParam)
{
    Q_UNUSED(sender);
    Q_UNUSED(args);
    gs_acquisitionObject* uParam=(gs_acquisitionObject*)userParam;
    uParam->StopEmit();
    qDebug()<<QString("StoppedEvent");
}

void gs_acquisitionObject::OpenTheAcquisitionDialogSlot()
{

    
}

void gs_acquisitionObject::StartTheAcquisitionSlot()
{
    ErrorCode errorCode = Success;
    errorCode=m_pWaveformAiCtrl->Prepare();
    CheckError(errorCode);
    errorCode=m_pWaveformAiCtrl->Start();
    CheckError(errorCode);
    
}

void gs_acquisitionObject::StopTheAcqusitionSlot()
{
    ErrorCode errorCode = Success;
    errorCode=m_pWaveformAiCtrl->Stop();
    CheckError(errorCode);
}

void gs_acquisitionObject::GetTheAcquisitionParaSlot(ConfigureAcquisition thestruct)
{
    m_struct_AcquisitionPara=thestruct;
    InitTheAcquisition();
    qDebug()<<"deviceName="<<m_struct_AcquisitionPara.DeviceName;
    qDebug()<<"Frequency:="<<m_struct_AcquisitionPara.ClockRatePerChannel;
    qDebug()<<"SectionLength="<<m_struct_AcquisitionPara.sectionLength;
    qDebug()<<"ChannelCount="<<m_struct_AcquisitionPara.ChannelCount;
    qDebug()<<"ChannelStart="<<m_struct_AcquisitionPara.ChannelStart;
    qDebug()<<"ThePath="<<*m_struct_AcquisitionPara.profilePath;
    //qDebug()<<QStringLiteral("采集卡参数修改成功");
}

void gs_acquisitionObject::AcquisitionChangeSlot()
{


}
