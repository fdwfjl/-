#include "gs_acquisitiondialog.h"
#include "ui_gs_acquisitiondialog.h"
#include <QDebug>
#include <QMessageBox>
#include <QTimer>

gs_AcquisitionDialog::gs_AcquisitionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gs_AcquisitionDialog)
{
    ui->setupUi(this);
    m_ptimer30ms=new QTimer(this);
    m_ptimer30ms->setInterval(30);
    m_ptimer30ms->start();
    connect(m_ptimer30ms,SIGNAL(timeout()),this,SLOT(Timer30msSlot()));
    m_structAcquisitionAllPara.AcquisitionOneConfigurePath="GS_projectOne\\gs_acquisitionOne.xml";
    m_structAcquisitionAllPara.AcquisitionTwoConfigurePath="GS_projectOne\\gs_acquisitionTwo.xml";
    m_structAcquisitionOneDefaultPara.profilePath=m_structAcquisitionAllPara.AcquisitionOneConfigurePath.toStdWString().c_str();
    m_structAcquisitionOnePara.profilePath=m_structAcquisitionOneDefaultPara.profilePath;
    m_structAcquisitionTwoDefaultPara.profilePath=m_structAcquisitionAllPara.AcquisitionTwoConfigurePath.toStdWString().c_str();
    m_structAcquisitionTwoPara.profilePath=m_structAcquisitionAllPara.AcquisitionTwoConfigurePath.toStdWString().c_str();
}

gs_AcquisitionDialog::~gs_AcquisitionDialog()
{
    qDebug()<<QStringLiteral("删除采集卡界面成功！");
    delete ui;
}





void gs_AcquisitionDialog::IfHasDeviceSlot()
{
    if(m_bHasDevice==true)
    {
        emit HasDeviceSignal();
    }
    else
    {
        emit NoDeviceSignal();
    }
}

void gs_AcquisitionDialog::InitAcquisitionOneDefaultSlot(QString Frequency, QString SectionLength, QString ChannelCout, QString ChannelStart)
{
    m_structAcquisitionAllPara.AcquisitionOneDefaultFrequency=Frequency;
    m_structAcquisitionAllPara.AcquisitionOneDefaultSectionLength=SectionLength;
    m_structAcquisitionAllPara.AcquisitionOneDefaultChannelCount=ChannelCout;
    m_structAcquisitionAllPara.AcquisitionOneDefaultChannelStart=ChannelStart;

    m_structAcquisitionOneDefaultPara.ClockRatePerChannel=Frequency.toInt();
    m_structAcquisitionOneDefaultPara.sectionLength=SectionLength.toInt();
    m_structAcquisitionOneDefaultPara.ChannelCount=ChannelCout.toInt();
    m_structAcquisitionOneDefaultPara.ChannelStart=ChannelStart.toInt();
    m_bDefaultOneOk=true;
}

void gs_AcquisitionDialog::InitAcquisitionOneNowSlot(QString Frequency, QString SectionLength, QString ChannelCout, QString ChannelStart)
{
    m_structAcquisitionAllPara.AcquisitionOneNowFrequency=Frequency;
    m_structAcquisitionAllPara.AcquisitionOneNowSectionLength=SectionLength;
    m_structAcquisitionAllPara.AcquisitionOneNowChannelCount=ChannelCout;
    m_structAcquisitionAllPara.AcquisitionOneNowChannelStart=ChannelStart;
    m_structAcquisitionOnePara.ClockRatePerChannel=Frequency.toInt();
    m_structAcquisitionOnePara.sectionLength=SectionLength.toInt();
    m_structAcquisitionOnePara.ChannelCount=ChannelCout.toInt();
    m_structAcquisitionOnePara.ChannelStart=ChannelStart.toInt();
    m_bNowOneOk=true;
}

void gs_AcquisitionDialog::InitAcquisitionTwoDefaultSlot(QString Frequency, QString SectionLength, QString ChannelCout, QString ChannelStart)
{
    m_structAcquisitionAllPara.AcquisitionTwoDefaultFrequency=Frequency;
    m_structAcquisitionAllPara.AcquisitionTwoDefaultSectionLength=SectionLength;
    m_structAcquisitionAllPara.AcquisitionTwoDefaultChannelCount=ChannelCout;
    m_structAcquisitionAllPara.AcquisitionTwoDefaultChannelStart=ChannelStart;
    m_structAcquisitionTwoDefaultPara.ClockRatePerChannel=Frequency.toInt();
    m_structAcquisitionTwoDefaultPara.sectionLength=SectionLength.toInt();
    m_structAcquisitionTwoDefaultPara.ChannelCount=ChannelCout.toInt();
    m_structAcquisitionTwoDefaultPara.ChannelStart=ChannelStart.toInt();
    m_bDefaultTwoOk=true;
}

void gs_AcquisitionDialog::InitAcquisitionTwoNowSlot(QString Frequency, QString SectionLength, QString ChannelCout, QString ChannelStart)
{
    m_structAcquisitionAllPara.AcquisitionTwoNowFrequency=Frequency;
    m_structAcquisitionAllPara.AcquisitionTwoNowSectionLength=SectionLength;
    m_structAcquisitionAllPara.AcquisitionTwoNowChannelCount=ChannelCout;
    m_structAcquisitionAllPara.AcquisitionTwoNowChannelStart=ChannelStart;
    m_structAcquisitionTwoPara.ClockRatePerChannel=Frequency.toInt();
    m_structAcquisitionTwoPara.sectionLength=SectionLength.toInt();
    m_structAcquisitionTwoPara.ChannelCount=ChannelCout.toInt();
    m_structAcquisitionTwoPara.ChannelStart=ChannelStart.toInt();
    m_bNowTwoOk=true;
}





void gs_AcquisitionDialog::InitParameter()
{
    WaveformAiCtrl * waveformAictrl=WaveformAiCtrl::Create();
    Array<DeviceTreeNode> * supportedDevice=waveformAictrl->getSupportedDevices();
    if(supportedDevice->getCount()==0)
    {
        m_bHasDevice=false;
        ui->m_comebox_Device->addItem(QStringLiteral("未找到设备!"));
        ui->m_comebox_StartChannel->addItem(QString("-1"));
        ui->m_comebox_ChannelCount->addItem(QString("-1"));
    }
    else if(supportedDevice->getCount()>0)
    {
        m_bHasDevice=true;
        ui->m_comebox_Device->blockSignals(true);
        for(int i=0;i<supportedDevice->getCount();++i)
        {
            DeviceTreeNode const &node=supportedDevice->getItem(i);
            QString description =QString::fromWCharArray(node.Description);
            ui->m_comebox_Device->addItem(description);
            switch (i) {
            case TheAcquisitionTwo:
                m_structAcquisitionAllPara.AcquisitionOneDeviceName=description;
                m_structAcquisitionOneDefaultPara.DeviceName=description;
                m_structAcquisitionOnePara.DeviceName=description;
                break;
            case TheAcquisitionOne:
                m_structAcquisitionAllPara.AcquisitionTwoDeviceName=description;
                m_structAcquisitionTwoDefaultPara.DeviceName=description;
                m_structAcquisitionTwoPara.DeviceName=description;
                break;
            }
        }
        ui->m_comebox_Device->blockSignals(false);
        ui->m_comebox_Device->setCurrentIndex(0);
        DeviceChangeSlot(0);
    }
    //m_structAcquisitionPara.profilePath=QString("david").toStdWString().c_str();
    waveformAictrl->Dispose();
    supportedDevice->Dispose();
    emit TheFirstDeviceParaSignal(m_structAcquisitionOnePara);
    emit TheSecondDeviceParaSignal(m_structAcquisitionTwoPara);

}

void gs_AcquisitionDialog::InitSlot()
{    
    connect(ui->m_comebox_Device,SIGNAL(currentIndexChanged(int)),this,SLOT(DeviceChangeSlot(int)));
    connect(ui->m_btn_AcquisitionSure,SIGNAL(clicked()),this,SLOT(AcquisitionSureSlot()));
    connect(ui->m_btn_AcquisitionDefault,SIGNAL(clicked()),this,SLOT(AcquisitionDefaultSlot()));
    //connect(ui->m_btn_AcquisitionStart,SIGNAL(clicked()),this,SLOT(AcquisitionStartSlot()));
  //  connect(ui->m_btn_AcquisitionStop,SIGNAL(clicked()),this,SLOT(AcquisitionStopSlot()));
}

void gs_AcquisitionDialog::closeEvent(QCloseEvent *e)
{
    Q_UNUSED(e);
    int ret= QMessageBox::question(nullptr, "Tips","Change The Parameter?", QMessageBox::Yes |QMessageBox::No, QMessageBox::NoButton);
    if(ret==QMessageBox::Yes)
    {
        accept();
    }
    else if(ret==QMessageBox::No)
    {
        accept();
    }
}

void gs_AcquisitionDialog::AcquisitionSureSlot()
{
    if(ui->m_comebox_Device->count()==0)
    {
        QMessageBox::warning(nullptr,QStringLiteral("警告"),QStringLiteral("未找到连接的设备"), QMessageBox::Ok,QMessageBox::NoButton);
    }
    else
    {
        int i=ui->m_comebox_Device->currentIndex();
        switch (i) {
        case TheAcquisitionTwo:
            m_structAcquisitionAllPara.AcquisitionOneNowFrequency=ui->m_lineED_ClockRate->text();
            m_structAcquisitionAllPara.AcquisitionOneNowSectionLength=ui->m_lineED_SectionLength->text();
            m_structAcquisitionAllPara.AcquisitionOneNowChannelCount=ui->m_comebox_ChannelCount->currentText();
            m_structAcquisitionAllPara.AcquisitionOneNowChannelStart=ui->m_comebox_StartChannel->currentText();

            m_structAcquisitionOnePara.ClockRatePerChannel=m_structAcquisitionAllPara.AcquisitionOneNowFrequency.toInt();
            m_structAcquisitionOnePara.sectionLength=m_structAcquisitionAllPara.AcquisitionOneNowSectionLength.toInt();
            m_structAcquisitionOnePara.ChannelCount=m_structAcquisitionAllPara.AcquisitionOneNowChannelCount.toInt();
            m_structAcquisitionOnePara.ChannelStart=m_structAcquisitionAllPara.AcquisitionOneNowChannelStart.toInt();
            emit TheFirstDeviceParaSignal(m_structAcquisitionOnePara);
            break;
        case TheAcquisitionOne:
            m_structAcquisitionAllPara.AcquisitionTwoNowFrequency=ui->m_lineED_ClockRate->text();
            m_structAcquisitionAllPara.AcquisitionTwoNowSectionLength=ui->m_lineED_SectionLength->text();
            m_structAcquisitionAllPara.AcquisitionTwoNowChannelCount=ui->m_comebox_ChannelCount->currentText();
            m_structAcquisitionAllPara.AcquisitionTwoNowChannelStart=ui->m_comebox_StartChannel->currentText();

            m_structAcquisitionTwoPara.ClockRatePerChannel=m_structAcquisitionAllPara.AcquisitionTwoNowFrequency.toInt();
            m_structAcquisitionTwoPara.sectionLength=m_structAcquisitionAllPara.AcquisitionTwoNowSectionLength.toInt();
            m_structAcquisitionTwoPara.ChannelCount=m_structAcquisitionAllPara.AcquisitionTwoNowChannelCount.toInt();
            m_structAcquisitionTwoPara.ChannelStart=m_structAcquisitionAllPara.AcquisitionTwoNowChannelStart.toInt();
            emit TheSecondDeviceParaSignal(m_structAcquisitionTwoPara);
            break;
        }
    }
   emit TheAcquisitionAllParaSignal(m_structAcquisitionAllPara);
}

void gs_AcquisitionDialog::AcquisitionDefaultSlot()
{
    int i=ui->m_comebox_Device->currentIndex();
    switch (i) {
    case TheAcquisitionTwo:
        ui->m_comebox_ChannelCount->setCurrentIndex(m_structAcquisitionOneDefaultPara.ChannelCount);
        ui->m_comebox_StartChannel->setCurrentIndex(m_structAcquisitionOneDefaultPara.ChannelStart);
        ui->m_lineED_ClockRate->setText(QString::number(m_structAcquisitionOneDefaultPara.ClockRatePerChannel));
        ui->m_lineED_SectionLength->setText(QString::number(m_structAcquisitionOneDefaultPara.sectionLength));
        break;
    case TheAcquisitionOne:
        ui->m_comebox_ChannelCount->setCurrentIndex(m_structAcquisitionTwoDefaultPara.ChannelCount);
        ui->m_comebox_StartChannel->setCurrentIndex(m_structAcquisitionTwoDefaultPara.ChannelStart);
        ui->m_lineED_ClockRate->setText(QString::number(m_structAcquisitionTwoDefaultPara.ClockRatePerChannel));
        ui->m_lineED_SectionLength->setText(QString::number(m_structAcquisitionTwoDefaultPara.sectionLength));
        break;
    }






}

void gs_AcquisitionDialog::DeviceChangeSlot(int index)
{
    ui->m_comebox_StartChannel->clear();
    ui->m_comebox_ChannelCount->clear();
    std::wstring description=ui->m_comebox_Device->currentText().toStdWString();
    DeviceInformation selected(description.c_str());

    WaveformAiCtrl* waveformAiCtrl=WaveformAiCtrl::Create();
    ErrorCode error=waveformAiCtrl->setSelectedDevice(selected);
    if(error!=0)
    {
        int ret= QMessageBox::warning(nullptr,QStringLiteral("错误"),QString("%1").arg(error), QMessageBox::Ok,QMessageBox::NoButton);
        if(ret==QMessageBox::Ok) reject();
    }
    int channelCount= waveformAiCtrl->getChannelCount();
    int logicChannelCount= waveformAiCtrl->getChannelCount();

    for(int i=0;i<channelCount;++i)
    {
        ui->m_comebox_ChannelCount->addItem(QString::number(i));
    }
    for(int i=0;i<logicChannelCount;++i)
    {
        ui->m_comebox_StartChannel->addItem(QString::number(i+1));
    }
    waveformAiCtrl->Dispose();
    // ui->m_comebox_StartChannel->setCurrentIndex(0);
    // ui->m_comebox_ChannelCount->setCurrentIndex(1);
    switch (index) {
    case TheAcquisitionTwo:
        ui->m_comebox_StartChannel->setCurrentIndex(m_structAcquisitionOnePara.ChannelStart);
        ui->m_comebox_ChannelCount->setCurrentIndex(m_structAcquisitionOnePara.ChannelCount);
        ui->m_lineED_ClockRate->setText(QString::number(m_structAcquisitionOnePara.ClockRatePerChannel));
        ui->m_lineED_SectionLength->setText(QString::number(m_structAcquisitionOnePara.sectionLength));
        break;
    case TheAcquisitionOne:
        ui->m_comebox_StartChannel->setCurrentIndex(m_structAcquisitionTwoPara.ChannelStart);
        ui->m_comebox_ChannelCount->setCurrentIndex(m_structAcquisitionTwoPara.ChannelCount);
        ui->m_lineED_ClockRate->setText(QString::number(m_structAcquisitionTwoPara.ClockRatePerChannel));
        ui->m_lineED_SectionLength->setText(QString::number(m_structAcquisitionTwoPara.sectionLength));
        break;
    }
}

void gs_AcquisitionDialog::AcquisitionSaveSlot()
{
    emit TheFirstDeviceParaSignal(m_structAcquisitionOnePara);
    emit TheSecondDeviceParaSignal(m_structAcquisitionTwoPara);
    accept();
}

void gs_AcquisitionDialog::AcquisitionStartSlot()
{
    if (m_bHasDevice==false)
    {
        qDebug()<<"No Device,StartAcquisitionFail!";
    }
    else
    {
        emit AcquisitionStartSignal();
    }

}

void gs_AcquisitionDialog::AcquisitionStopSlot()
{
    if(m_bHasDevice==false)
    {
        qDebug()<<"NO Device,StopAcquisitionFail!";
    }
    else
    {
        emit AcquisitionStopSignal();
    }

}

void gs_AcquisitionDialog::Timer30msSlot()
{
    if(m_bDefaultOneOk==true && m_bDefaultTwoOk==true && m_bNowOneOk==true && m_bNowTwoOk==true)
    {
        m_ptimer30ms->stop();
        InitParameter();
        InitSlot();
    }

}
