#ifndef GS_ACQUISITIONDIALOG_H
#define GS_ACQUISITIONDIALOG_H

#include <QDialog>
#include "bdaqctrl.h"
#include "gs_acquisitionparameter.h"
#include "gs_acquisitionallpara.h"

enum AcquisitionNum
{
    TheAcquisitionOne=0,
    TheAcquisitionTwo=1
};

using namespace Automation::BDaq;

class QTimer;
namespace Ui {
class gs_AcquisitionDialog;
}


class gs_AcquisitionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit gs_AcquisitionDialog(QWidget *parent = 0);
    ~gs_AcquisitionDialog();

private:
    ConfigureAcquisition m_structAcquisitionOnePara;
    ConfigureAcquisition m_structAcquisitionTwoPara;
    ConfigureAcquisition m_structAcquisitionOneDefaultPara;
    ConfigureAcquisition m_structAcquisitionTwoDefaultPara;

    TwoAcquisitionPara m_structAcquisitionAllPara;

    bool m_bHasDevice;
    bool m_bDeviceOneFinish;
    bool m_bDeviceTwoFinish;

    bool m_bDefaultOneOk;
    bool m_bDefaultTwoOk;
    bool m_bNowOneOk;
    bool m_bNowTwoOk;

    QTimer*m_ptimer30ms;


public:


public slots:
    void IfHasDeviceSlot();
    void InitAcquisitionOneDefaultSlot(QString Frequency,QString SectionLength,QString ChannelCout,QString ChannelStart);
    void InitAcquisitionOneNowSlot(QString Frequency,QString SectionLength,QString ChannelCout,QString ChannelStart);
    void InitAcquisitionTwoDefaultSlot(QString Frequency,QString SectionLength,QString ChannelCout,QString ChannelStart);
    void InitAcquisitionTwoNowSlot(QString Frequency,QString SectionLength,QString ChannelCout,QString ChannelStart);
private:
    void InitParameter();
    void InitSlot();
    virtual void closeEvent(QCloseEvent *e) override;


private slots:
    void AcquisitionSureSlot();
    void AcquisitionDefaultSlot();   
    void DeviceChangeSlot(int index);
    void AcquisitionSaveSlot();
    void AcquisitionStartSlot();
    void AcquisitionStopSlot();
    void Timer30msSlot();




signals:
    void TheFirstDeviceParaSignal(ConfigureAcquisition);//采集卡1按保存后的参数
    void TheSecondDeviceParaSignal(ConfigureAcquisition);//采集卡2按保存后的参数
    void NoDeviceSignal();
    void HasDeviceSignal();
    void AcquisitionStartSignal();
    void AcquisitionStopSignal();
    void TheAcquisitionAllParaSignal(TwoAcquisitionPara);
private:
    Ui::gs_AcquisitionDialog *ui;
};

#endif // GS_ACQUISITIONDIALOG_H
