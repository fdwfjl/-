#ifndef GS_WINDOWONE_H
#define GS_WINDOWONE_H
#include <QMainWindow>
#include "gs_deviceparameter.h"



class QMenu;
class QThread;
class QLabel;
class QTimer;

class gs_FrequencyDialog;
class gs_MysqlDialog;
class gs_TcpParaDialog;
class gs_AcquisitionDialog;
class gs_acquisitionObject;
class gs_mysqlObject;
class gs_functionFrame;
class gs_ChangeTwoToOneObject;
class gs_tcpsimensobject;
class gs_changetoqpointfobject;
class gs_processstatusobject;
class gs_processtcpobject;

class gs_functionframeobject;

namespace Ui {
class GS_WindowOne;
}

class GS_WindowOne : public QMainWindow
{
    Q_OBJECT

public:
    explicit GS_WindowOne(QWidget *parent = 0);
    ~GS_WindowOne();
private:
    QThread*m_pThreadAcquisitionOne;   //采集卡1线程
    QThread*m_pThreadAcquisitionTwo;   //采集卡2线程
    QThread*m_pThreadMySqlOne;         //MySQL线程
    QThread*m_pThreadChangeTwoToOne;   //把两部分内存变成一部分的线程
    QThread*m_pThreadTcpSimen;         //Tcp线程
    QThread*m_pThreadChangeToQPointF;   //生成QPointF线程
    QThread*m_pThreadProcessTheFrequencyStatus;  //处理变频器状态的线程
    QThread*m_pThreadSaveTheTcpOrder;   //保存Tcp命令的线程

//    QThread*m_pThreadDistanceChart;
//    QThread*m_pThreadPressureChart;
//    QThread*m_pThreadTempChart;
//    gs_functionframeobject*m_pDistanceChartObject;
//    gs_functionframeobject*m_pPressureChartObject;
//    gs_functionframeobject*m_pTempChartObject;


    gs_FrequencyDialog*m_pFrequencyDialog; //变频器界面
    gs_MysqlDialog*m_pMysqlDialog;     //数据库界面
    gs_TcpParaDialog*m_pTcpParaDialog;   //Tcp界面
    gs_AcquisitionDialog*m_pAcquisitionDialog;  //采集卡界面
    gs_acquisitionObject*m_pAcquisitionObjectOne;  //采集卡1的object
    gs_acquisitionObject*m_pAcquisitionObjectTwo;  //采集卡2的object
    gs_mysqlObject*m_pMySqlObjectOne;              //数据库的object
    gs_ChangeTwoToOneObject*m_pChangeTwoToOneObject;  //把采集到的两个内存的数据合二为一
    gs_tcpsimensobject*m_pTcpSimenObject;         //西门子TCPObject
    gs_changetoqpointfobject*m_pChangeToQPointfObject;   //把采集到的点变成QPointF的Object
    gs_processstatusobject*m_pProcessTheFrequencyStatusObject;  //处理接收到的变频器状态字符串的Object
    gs_processtcpobject*m_pSaveTheTcpOrderObject;    //把发送给TCP的命令保存到容器中的Object

    gs_functionFrame*m_pfunFrameDistance;   //Distance图表
    gs_functionFrame*m_pfunFramePressure;   //压力图表
    gs_functionFrame*m_pfunFrameTempureture;  //温度图表

    QLabel*m_pLabelStatus;
    QTimer*m_pTimer1SOpenMySql;    //1S计时器，初始化和打开MySql
    QTimer*m_pTimer1STcpSimen;     //1S计时器，打开TCP服务器和Simen通讯
    QTimer*m_pTimer1SCheckAcquisition;  //1S计时器，检查采集卡
    QTimer*m_pTimer1SOpenAcquisition; //1S计时器，打开采集卡

    const QString m_red_SheetStyle = "min-width: 20px; min-height: 20px;max-width:20px; max-height: 20px;border-radius: 10px;  border:2px solid black;background:red";
    const QString m_yellow_SheetStyle="min-width: 20px; min-height: 20px;max-width:20px; max-height: 20px;border-radius: 10px;  border:2px solid black;background:yellow";
    const QString m_green_SheetStyle = "min-width: 20px; min-height: 20px;max-width:20px; max-height: 20px;border-radius: 10px;  border:2px solid black;background:green";
    const QString m_red2_SheetStyle="background:red";
    const QString m_green2_SheetStyle="background:green";
    const QString m_yellow2_SheetStyle="background:yellow";

    DevicePara m_struct_DefaultDevice;   //设备的默认参数
    DevicePara m_struct_NowDevice;       //设备的保存后的参数

    int i_text;

private:
    void InitUI();
    void InitTimer();
    void InitStatusLayout();
    void InitOtherLayout();
    void InitStatus();
    void InitSlot();
    void InitChangeStatusSlot();
    void InitTcpOrederSlot();
    void InitStartAndStopAcquisitionSlot();
    void InitProcessAcquisionSlot();
    void InitDrawCharSlot();
    void InitMySqlSlot();
    void InitAcquisitionSlot();
    

private slots:
    void OpenTheSetFrequencyDialogSlot();
    void OpenTheSetMySqlDialogSlot();
    void OpenTheSetIpDialogSlot();
    void OpenTheSetAcquisitionSlot();
    void FrequecyParameterChangeSlot();
    void IpParameterChangeSlot();
    void MySqlChangeSlot();
    void AcquisitionChangeSlot();
    void ListenTheTcpSlot();
    void ChangeMySqlStatusSlot();
    void ChangeTcpListeningStatusSlot();
    void ChangeTcpLinkStatusSuccessSlot();
    void ChangeTcpDisconnectSlot();
    void ChangeAcquisitionRedStatusSlot();
    void ChangeAcquisitionGreenStatusSlot();
    void InitTheDefaultDeviceSlot(DevicePara thedata);
    void InitTheNowDeviceSlot(DevicePara thedata);
    void ChangeTheFrequencySlot(QString Speed,QString Current,QString Frequency);
    void StartTheAcquisitionSlot();
    void StopTheAcquisitionSlot();

signals:
    void TheTcpListenSignal(QString IP,QString Port);
    void ChangeFrequencyDefaultSignal(QString workSpeed,QString workAcc,QString workDec,QString jogSpeed);//改变默认参数的信号
    void ChangeFrequencyNowSignal(QString workSpeed,QString workAcc,QString workDec,QString jogSpeed);  //改变现在参数的信号
    void ChangeAcquisitionOneDefaultSignal(QString Frequency,QString SectionLength,QString ChannelCount,QString ChannelStart);   //改变采集卡1的默认参数
    void ChangeAcquisitionOneNowSignal(QString Frequency,QString SectionLength,QString ChannelCount,QString ChannelStart);   //改变采集采集卡1的现在参数
    void ChangeAcquisitionTwoDefaultSignal(QString Frequency,QString SectionLength,QString ChannelCount,QString ChannelStart); //改变采集卡2的默认参数
    void ChangeAcquisitionTwoNowSignal(QString Frequency,QString SectionLength,QString ChannelCount,QString ChannelStart);    //改变采集卡2的现在参数
    void StartTheAcquisitionOneSignal();
    void StartTheAcquisitionTwoSignal();
    void StopTheAcquisitionOneSignal();
    void StopTheAcquisitionTwoSignal();
    void StopDrawChartSignal(int theChartMode);
private:
    Ui::GS_WindowOne *ui;
};

#endif // GS_WINDOWONE_H
