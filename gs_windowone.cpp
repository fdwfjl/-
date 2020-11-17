#include "gs_windowone.h"
#include "ui_gs_windowone.h"
#include <QMenu>
#include <QDebug>
#include <QThread>
#include <QAction>
#include <QTimer>
#include "gs_configure.h"





GS_WindowOne::GS_WindowOne(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GS_WindowOne)
{
    this->setWindowFlags(Qt::WindowCloseButtonHint|Qt::WindowMinimizeButtonHint);
    ui->setupUi(this);
    InitUI();
    qRegisterMetaType<DevicePara>("DevicePara");
    qRegisterMetaType<TwoAcquisitionPara>("TwoAcquisitionPara");
    qRegisterMetaType<ConfigureAcquisition>("ConfigureAcquisition");
    InitTimer();
    InitStatus();
    InitStatusLayout();
    InitOtherLayout();
    InitSlot();
    InitChangeStatusSlot();
    InitTcpOrederSlot();
    InitStartAndStopAcquisitionSlot();
    InitProcessAcquisionSlot();
    InitDrawCharSlot();
    InitMySqlSlot();
    InitAcquisitionSlot();
    ui->m_tabWidget_One->setCurrentIndex(0);
    ui->m_statusBar->showMessage("I am ready!");
    ui->m_textED_theErrorInformation->setText("what the fuck!");
}

GS_WindowOne::~GS_WindowOne()
{
    delete ui;
    delete m_pFrequencyDialog;
    delete m_pMysqlDialog;
    delete m_pTcpParaDialog;
    delete m_pAcquisitionDialog;
    m_pFrequencyDialog=nullptr;
    m_pMysqlDialog=nullptr;
    m_pTcpParaDialog=nullptr;
    m_pAcquisitionDialog=nullptr;
}

void GS_WindowOne::InitUI()
{

    m_pFrequencyDialog=new gs_FrequencyDialog();
    m_pMysqlDialog=new gs_MysqlDialog();
    m_pTcpParaDialog=new gs_TcpParaDialog();
    m_pAcquisitionDialog=new gs_AcquisitionDialog();
    m_pfunFrameDistance=new gs_functionFrame(ui->m_frame_Distance);
    m_pfunFramePressure=new gs_functionFrame(ui->m_frame_pressure);
    m_pfunFrameTempureture=new gs_functionFrame(ui->m_frame_tempture);

    m_pAcquisitionObjectOne=new gs_acquisitionObject();
    m_pAcquisitionObjectTwo=new gs_acquisitionObject();
    m_pThreadAcquisitionOne=new QThread;
    m_pThreadAcquisitionTwo=new QThread;
    m_pAcquisitionObjectOne->moveToThread(m_pThreadAcquisitionOne);
    m_pAcquisitionObjectTwo->moveToThread(m_pThreadAcquisitionTwo);

    m_pThreadMySqlOne=new QThread;
    m_pMySqlObjectOne=new gs_mysqlObject;
    m_pMySqlObjectOne->moveToThread(m_pThreadMySqlOne);

    m_pChangeTwoToOneObject=new gs_ChangeTwoToOneObject;
    m_pThreadChangeTwoToOne=new QThread;
    m_pChangeTwoToOneObject->moveToThread(m_pThreadChangeTwoToOne);

    m_pTcpSimenObject=new gs_tcpsimensobject;
    m_pThreadTcpSimen=new QThread;
    m_pTcpSimenObject->moveToThread(m_pThreadTcpSimen);

    m_pThreadChangeToQPointF=new QThread;
    m_pChangeToQPointfObject=new gs_changetoqpointfobject;
    m_pChangeToQPointfObject->moveToThread(m_pThreadChangeToQPointF);

    m_pThreadProcessTheFrequencyStatus=new QThread;
    m_pProcessTheFrequencyStatusObject=new gs_processstatusobject;
    m_pProcessTheFrequencyStatusObject->moveToThread(m_pThreadProcessTheFrequencyStatus);


    m_pThreadSaveTheTcpOrder=new QThread;
    m_pSaveTheTcpOrderObject=new gs_processtcpobject;
    m_pSaveTheTcpOrderObject->moveToThread(m_pThreadSaveTheTcpOrder);



    m_pThreadAcquisitionOne->start();
    m_pThreadAcquisitionTwo->start();
    m_pThreadMySqlOne->start();
    m_pThreadChangeTwoToOne->start();
    m_pThreadTcpSimen->start();
    m_pThreadChangeToQPointF->start();
    m_pThreadProcessTheFrequencyStatus->start();
    m_pThreadSaveTheTcpOrder->start();


}

void GS_WindowOne::InitTimer()
{
    m_pTimer1SOpenMySql=new QTimer(this);
    m_pTimer1SOpenMySql->setInterval(1000);
    m_pTimer1SOpenMySql->start();

    m_pTimer1STcpSimen=new QTimer(this);
    m_pTimer1STcpSimen->setInterval(1000);
    m_pTimer1STcpSimen->start();

    m_pTimer1SCheckAcquisition=new QTimer(this);
    m_pTimer1SCheckAcquisition->setInterval(1000);
    m_pTimer1SCheckAcquisition->start();

    m_pTimer1SOpenAcquisition=new QTimer(this);
    m_pTimer1SOpenAcquisition->setInterval(1000);
    // m_pTimer1SOpenAcquisition->start();

}

void GS_WindowOne::InitStatusLayout()
{
    ui->m_label_StatusTCP->setStyleSheet(m_red_SheetStyle);
    ui->m_label_StatusMySqlW->setStyleSheet(m_red_SheetStyle);
    ui->m_label_StatusAccquisition->setStyleSheet(m_red_SheetStyle);
    ui->m_label_StatusFrequenc->setStyleSheet(m_red_SheetStyle);
}

void GS_WindowOne::InitOtherLayout()
{
    ui->m_label_DistanceOneRed->setStyleSheet(m_red2_SheetStyle);
    ui->m_label_DistanceTwoGreen->setStyleSheet(m_green2_SheetStyle);
    ui->m_label_PressureARed->setStyleSheet(m_red2_SheetStyle);
    ui->m_label_PressureBGreen->setStyleSheet(m_green2_SheetStyle);
    ui->m_label_PressureCYellow->setStyleSheet(m_yellow2_SheetStyle);
    ui->m_label_TemptureARed->setStyleSheet(m_red2_SheetStyle);
    ui->m_label_TemptureBGreen->setStyleSheet(m_green2_SheetStyle);
}

void GS_WindowOne::InitStatus()
{
    m_pLabelStatus=new QLabel(this);
    m_pLabelStatus->setText("Ver:1.0");
    ui->m_statusBar->addPermanentWidget(m_pLabelStatus);



}

void GS_WindowOne::InitSlot()
{
    /* 控件间的界面信号与槽 */
    connect(ui->m_actionSetFrequency,SIGNAL(triggered(bool)),this,SLOT(OpenTheSetFrequencyDialogSlot()));
    connect(ui->m_actionSetMySql,SIGNAL(triggered(bool)),this,SLOT(OpenTheSetMySqlDialogSlot()));
    connect(ui->m_actionSetIP,SIGNAL(triggered(bool)),this,SLOT(OpenTheSetIpDialogSlot()));
    connect(ui->m_actionSetAcquisition,SIGNAL(triggered(bool)),this,SLOT(OpenTheSetAcquisitionSlot()));
    connect(m_pTcpParaDialog,SIGNAL(accepted()),this,SLOT(IpParameterChangeSlot()));
    connect(m_pFrequencyDialog,SIGNAL(accepted()),this,SLOT(FrequecyParameterChangeSlot()));
    connect(m_pMysqlDialog,SIGNAL(accepted()),this,SLOT(MySqlChangeSlot()));
    connect(m_pAcquisitionDialog,SIGNAL(accepted()),this,SLOT(AcquisitionChangeSlot()));
    connect(m_pAcquisitionDialog,SIGNAL(rejected()),this,SLOT(AcquisitionChangeSlot()));
    connect(ui->m_action_AcquisitionStart,SIGNAL(triggered(bool)),this,SLOT(StartTheAcquisitionSlot()));
    connect(ui->m_action_AcquisitionStop,SIGNAL(triggered(bool)),this,SLOT(StopTheAcquisitionSlot()));

    /* 关于线程1采集卡1的信号和槽 */
    connect(m_pThreadAcquisitionOne,SIGNAL(finished()),m_pThreadAcquisitionOne,SLOT(deleteLater()));
    connect(m_pThreadAcquisitionTwo,SIGNAL(finished()),m_pAcquisitionObjectOne,SLOT(deleteLater()));
    connect(ui->m_actionStartCollect,SIGNAL(triggered(bool)),m_pAcquisitionObjectOne,SLOT(StartTheAcquisitionSlot()));
    connect(ui->m_actionStopCollect,SIGNAL(triggered(bool)),m_pAcquisitionObjectOne,SLOT(StopTheAcqusitionSlot()));

    /* 关于线程2采集卡2的信号和槽 */
    connect(m_pThreadAcquisitionTwo,SIGNAL(finished()),m_pThreadAcquisitionTwo,SLOT(deleteLater()));
    connect(m_pThreadAcquisitionTwo,SIGNAL(finished()),m_pAcquisitionObjectTwo,SLOT(deleteLater()));
    connect(ui->m_actionStartCollect,SIGNAL(triggered(bool)),m_pAcquisitionObjectTwo,SLOT(StartTheAcquisitionSlot()));
    connect(ui->m_actionStopCollect,SIGNAL(triggered(bool)),m_pAcquisitionObjectTwo,SLOT(StopTheAcqusitionSlot()));

    /* 关于线程3采集卡1采集卡2与数据库1信号和槽 */
    connect(m_pThreadMySqlOne,SIGNAL(finished()),m_pThreadMySqlOne,SLOT(deleteLater()));
    connect(m_pThreadMySqlOne,SIGNAL(finished()),m_pMySqlObjectOne,SLOT(deleteLater()));


    /* 线程4是将两块内存变成一个信号发出出去 */

    connect(m_pThreadChangeTwoToOne,SIGNAL(finished()),m_pThreadChangeTwoToOne,SLOT(deleteLater()));
    connect(m_pThreadChangeTwoToOne,SIGNAL(finished()),m_pChangeTwoToOneObject,SLOT(deleteLater()));

    /* 线程5是TCP通讯的 */
    connect(m_pThreadTcpSimen,SIGNAL(finished()),m_pThreadTcpSimen,SLOT(deleteLater()));
    connect(m_pThreadTcpSimen,SIGNAL(finished()),m_pTcpSimenObject,SLOT(deleteLater()));

    /* 线程6是生成QPointF的 */
    connect(m_pThreadChangeToQPointF,SIGNAL(finished()),m_pThreadChangeToQPointF,SLOT(deleteLater()));
    connect(m_pThreadChangeToQPointF,SIGNAL(finished()),m_pChangeToQPointfObject,SLOT(deleteLater()));

    /* 线程7是处理变频器状态的字符串线程 */
    connect(m_pThreadProcessTheFrequencyStatus,SIGNAL(finished()),m_pThreadProcessTheFrequencyStatus,SLOT(deleteLater()));
    connect(m_pThreadProcessTheFrequencyStatus,SIGNAL(finished()),m_pProcessTheFrequencyStatusObject,SLOT(deleteLater()));

    /* 线程8是保存TCP命令的线程 */
    connect(m_pThreadSaveTheTcpOrder,SIGNAL(finished()),m_pThreadSaveTheTcpOrder,SLOT(deleteLater()));
    connect(m_pThreadSaveTheTcpOrder,SIGNAL(finished()),m_pSaveTheTcpOrderObject,SLOT(deleteLater()));



}

void GS_WindowOne::InitChangeStatusSlot()
{
    connect(m_pTimer1SOpenMySql,SIGNAL(timeout()),m_pMySqlObjectOne,SLOT(InitMySlot()));
    connect(m_pMySqlObjectOne,SIGNAL(LinkMySqlSuccessSignal()),this,SLOT(ChangeMySqlStatusSlot()));
    connect(m_pMySqlObjectOne,SIGNAL(DeviceDefaultParaSignal(DevicePara)),this,SLOT(InitTheDefaultDeviceSlot(DevicePara)));
    connect(m_pMySqlObjectOne,SIGNAL(DeviceNowParaSignal(DevicePara)),this,SLOT(InitTheNowDeviceSlot(DevicePara)));

    connect(m_pTimer1STcpSimen,SIGNAL(timeout()),this,SLOT(ListenTheTcpSlot()));
    connect(this,SIGNAL(TheTcpListenSignal(QString,QString)),m_pTcpSimenObject,SLOT(ListenServeSlot(QString,QString)));
    connect(m_pTcpSimenObject,SIGNAL(ListeningSignal()),this,SLOT(ChangeTcpListeningStatusSlot()));
    connect(m_pTcpSimenObject,SIGNAL(ConnectSuccessSignal()),this,SLOT(ChangeTcpLinkStatusSuccessSlot()));
    connect(m_pTcpSimenObject,SIGNAL(DisconnectSignal()),this,SLOT(ChangeTcpDisconnectSlot()));

    connect(m_pTimer1SCheckAcquisition,SIGNAL(timeout()),m_pAcquisitionDialog,SLOT(IfHasDeviceSlot()));
    connect(m_pAcquisitionDialog,SIGNAL(NoDeviceSignal()),this,SLOT(ChangeAcquisitionRedStatusSlot()));
    connect(m_pAcquisitionDialog,SIGNAL(HasDeviceSignal()),this,SLOT(ChangeAcquisitionGreenStatusSlot()));

    connect(this,SIGNAL(ChangeFrequencyDefaultSignal(QString,QString,QString,QString)),m_pFrequencyDialog,SLOT(FromMySqlDefaultSlot(QString,QString,QString,QString)));
    connect(this,SIGNAL(ChangeFrequencyNowSignal(QString,QString,QString,QString)),m_pFrequencyDialog,SLOT(FromMySqlSlot(QString,QString,QString,QString)));

    //  connect(this,SIGNAL(ChangeAcquisitonDeviceSignal(QString,QString)),m_pAcquisitionDialog,SLOT(InitTheDeviceSlot(QString,QString)));

}

void GS_WindowOne::InitTcpOrederSlot()
{
    connect(m_pFrequencyDialog,SIGNAL(WorkSpeedChangeSignal(QString)),m_pSaveTheTcpOrderObject,SLOT(ReceiveTheOrderSlot(QString)));
    connect(m_pFrequencyDialog,SIGNAL(WorkAccelerateChangeSignal(QString)),m_pSaveTheTcpOrderObject,SLOT(ReceiveTheOrderSlot(QString)));
    connect(m_pFrequencyDialog,SIGNAL(WorkDecelerateChangeSignal(QString)),m_pSaveTheTcpOrderObject,SLOT(ReceiveTheOrderSlot(QString)));
    connect(m_pFrequencyDialog,SIGNAL(JogSpeedChangeSignal(QString)),m_pSaveTheTcpOrderObject,SLOT(ReceiveTheOrderSlot(QString)));
    connect(m_pFrequencyDialog,SIGNAL(WriteToTcpDataSignal(QString)),m_pSaveTheTcpOrderObject,SLOT(ReceiveTheOrderSlot(QString)));

    connect(m_pSaveTheTcpOrderObject,SIGNAL(SendToTcpSignal(QString)),m_pTcpSimenObject,SLOT(ServeWriteSlot(QString)));
    connect(m_pTcpSimenObject,SIGNAL(ReadDataSignal(QString)),m_pSaveTheTcpOrderObject,SLOT(SendTheOrderSlot(QString)));
    connect(m_pSaveTheTcpOrderObject,SIGNAL(SendToMainSignal(QString)),m_pProcessTheFrequencyStatusObject,SLOT(processTheStatusSlot(QString)));
    connect(m_pProcessTheFrequencyStatusObject,SIGNAL(ChangeTheFrequencyStatusSignal(QString,QString,QString)),m_pFrequencyDialog,SLOT(ShowTheStatusSlot(QString,QString,QString)));
    connect(m_pTcpSimenObject,SIGNAL(ConnectSuccessSignal()),m_pFrequencyDialog,SLOT(StartTheTimerSlot()));
    connect(m_pProcessTheFrequencyStatusObject,SIGNAL(ChangeTheFrequencyStatusSignal(QString,QString,QString)),this,SLOT(ChangeTheFrequencySlot(QString,QString,QString)));
}

void GS_WindowOne::InitStartAndStopAcquisitionSlot()
{
    connect(m_pAcquisitionDialog,SIGNAL(AcquisitionStartSignal()),m_pAcquisitionObjectOne,SLOT(StartTheAcquisitionSlot()));
    connect(m_pAcquisitionDialog,SIGNAL(AcquisitionStartSignal()),m_pAcquisitionObjectTwo,SLOT(StartTheAcquisitionSlot()));
    connect(m_pAcquisitionDialog,SIGNAL(AcquisitionStopSignal()),m_pAcquisitionObjectOne,SLOT(StopTheAcqusitionSlot()));
    connect(m_pAcquisitionDialog,SIGNAL(AcquisitionStopSignal()),m_pAcquisitionObjectTwo,SLOT(StopTheAcqusitionSlot()));
}

void GS_WindowOne::InitProcessAcquisionSlot()
{
    connect(m_pAcquisitionObjectOne,SIGNAL(DataReadySignal(double*,int,int)),m_pChangeTwoToOneObject,SLOT(ProcessOneSlot(double*,int,int)));
    connect(m_pAcquisitionObjectTwo,SIGNAL(DataReadySignal(double*,int,int)),m_pChangeTwoToOneObject,SLOT(ProcessTwoSlot(double*,int,int)));
}

void GS_WindowOne::InitDrawCharSlot()
{
    connect(m_pChangeTwoToOneObject,SIGNAL(CanGetDataChartSignal()),m_pChangeToQPointfObject,SLOT(StartTheObject()));
    connect(m_pChangeToQPointfObject,SIGNAL(GetTheDataPointSignal(int)),m_pChangeTwoToOneObject,SLOT(GetChartDataSlot(int)));
    connect(m_pChangeTwoToOneObject,SIGNAL(DataToChartSignal(double*,double*,int,int,int)),m_pChangeToQPointfObject,SLOT(SetTheQpointfSlot(double*,double*,int,int,int)));
    connect(m_pChangeToQPointfObject,SIGNAL(ToDistanceSignal(QPointF*,QPointF*,int)),m_pfunFrameDistance,SLOT(DrawDistanceSlot(QPointF*,QPointF*,int)));
    connect(m_pChangeToQPointfObject,SIGNAL(ToProcessureSignal(QPointF*,QPointF*,QPointF*,int)),m_pfunFramePressure,SLOT(DrawPressureSlot(QPointF*,QPointF*,QPointF*,int)));
    connect(m_pChangeToQPointfObject,SIGNAL(ToTemperatureSignal(QPointF*,QPointF*,int)),m_pfunFrameTempureture,SLOT(DrawTemperatureSlot(QPointF*,QPointF*,int)));
    connect(this,SIGNAL(StopDrawChartSignal(int)),m_pfunFrameDistance,SLOT(DrawStopSlot(int)));
    connect(this,SIGNAL(StopDrawChartSignal(int)),m_pfunFramePressure,SLOT(DrawStopSlot(int)));
    connect(this,SIGNAL(StopDrawChartSignal(int)),m_pfunFrameTempureture,SLOT(DrawStopSlot(int)));
  // connect(m_pChangeToQPointfObject,SIGNAL(ToTemperatureSignal(QPointF*,QPointF*,int)),m_pTempChartObject,SLOT(DrawTheTempSlot(QPointF*,QPointF*,int)));
}

void GS_WindowOne::InitMySqlSlot()
{
    //connect(m_pChangeTwoToOneObject,SIGNAL(CanGetDataSqlSignal()),m_pMySqlObjectOne,SLOT(BeginThisObjectSlot()));
   // connect(m_pMySqlObjectOne,SIGNAL(ContinueGetThedataSignal()),m_pChangeTwoToOneObject,SLOT(SendTwoToSqlSlot()));
   // connect(m_pChangeTwoToOneObject,SIGNAL(DataToMySqlSignal(double*,double*,int,int,int)),m_pMySqlObjectOne,SLOT(ProcessDataSlot(double*,double*,int,int,int)));

}

void GS_WindowOne::InitAcquisitionSlot()
{
    connect(this,SIGNAL(ChangeAcquisitionOneDefaultSignal(QString,QString,QString,QString)),m_pAcquisitionDialog,SLOT(InitAcquisitionOneDefaultSlot(QString,QString,QString,QString)));
    connect(this,SIGNAL(ChangeAcquisitionOneNowSignal(QString,QString,QString,QString)),m_pAcquisitionDialog,SLOT(InitAcquisitionOneNowSlot(QString,QString,QString,QString)));
    connect(this,SIGNAL(ChangeAcquisitionTwoDefaultSignal(QString,QString,QString,QString)),m_pAcquisitionDialog,SLOT(InitAcquisitionTwoDefaultSlot(QString,QString,QString,QString)));
    connect(this,SIGNAL(ChangeAcquisitionTwoNowSignal(QString,QString,QString,QString)),m_pAcquisitionDialog,SLOT(InitAcquisitionTwoNowSlot(QString,QString,QString,QString)));
    connect(m_pAcquisitionDialog,SIGNAL(TheFirstDeviceParaSignal(ConfigureAcquisition)),m_pAcquisitionObjectOne,SLOT(GetTheAcquisitionParaSlot(ConfigureAcquisition)));
    connect(m_pAcquisitionDialog,SIGNAL(TheSecondDeviceParaSignal(ConfigureAcquisition)),m_pAcquisitionObjectTwo,SLOT(GetTheAcquisitionParaSlot(ConfigureAcquisition)));
    connect(this,SIGNAL(StartTheAcquisitionOneSignal()),m_pAcquisitionObjectOne,SLOT(StartTheAcquisitionSlot()));
    connect(this,SIGNAL(StartTheAcquisitionTwoSignal()),m_pAcquisitionObjectTwo,SLOT(StartTheAcquisitionSlot()));
    connect(this,SIGNAL(StopTheAcquisitionOneSignal()),m_pAcquisitionObjectOne,SLOT(StopTheAcqusitionSlot()));
    connect(this,SIGNAL(StopTheAcquisitionTwoSignal()),m_pAcquisitionObjectTwo,SLOT(StopTheAcqusitionSlot()));
}

void GS_WindowOne::OpenTheSetFrequencyDialogSlot()
{
    this->hide();
    m_pFrequencyDialog->exec();

}

void GS_WindowOne::OpenTheSetMySqlDialogSlot()
{
    this->hide();
    m_pMysqlDialog->exec();

}

void GS_WindowOne::OpenTheSetIpDialogSlot()
{
    this->hide();
    m_pTcpParaDialog->exec();

}

void GS_WindowOne::OpenTheSetAcquisitionSlot()
{
    this->hide();
    m_pAcquisitionDialog->exec();


}

void GS_WindowOne::FrequecyParameterChangeSlot()
{
    qDebug()<<QStringLiteral("变频器改变成功槽");
    this->show();
}

void GS_WindowOne::IpParameterChangeSlot()
{
    //qDebug()<<QStringLiteral("IP改变成功槽");
    this->show();
}

void GS_WindowOne::MySqlChangeSlot()
{
    // qDebug()<<QStringLiteral("SQL改变成功槽");
    this->show();

}

void GS_WindowOne::AcquisitionChangeSlot()
{
    //qDebug()<<QStringLiteral("采集卡改变成功槽");
    this->show();

}

void GS_WindowOne::ListenTheTcpSlot()
{
    qDebug()<<"TheListenTimeout";
    emit TheTcpListenSignal(m_pTcpParaDialog->m_IpParameter.TheIp,m_pTcpParaDialog->m_IpParameter.ThePort);
}

void GS_WindowOne::ChangeMySqlStatusSlot()
{
    m_pTimer1SOpenMySql->stop();
    ui->m_label_StatusMySqlW->setStyleSheet(m_green_SheetStyle);
}

void GS_WindowOne::ChangeTcpLinkStatusSuccessSlot()
{
    ui->m_label_StatusTCP->setStyleSheet(m_green_SheetStyle);
}

void GS_WindowOne::ChangeTcpDisconnectSlot()
{
    ui->m_label_StatusTCP->setStyleSheet(m_red_SheetStyle);

}

void GS_WindowOne::ChangeAcquisitionRedStatusSlot()
{
    //m_pTimer1SCheckAcquisition->stop();
    ui->m_label_StatusAccquisition->setStyleSheet(m_red_SheetStyle);

}

void GS_WindowOne::ChangeAcquisitionGreenStatusSlot()
{
    m_pTimer1SCheckAcquisition->stop();
    ui->m_label_StatusAccquisition->setStyleSheet(m_green_SheetStyle);
}

void GS_WindowOne::InitTheDefaultDeviceSlot(DevicePara thedata)
{
    m_struct_DefaultDevice=thedata;
    emit ChangeFrequencyDefaultSignal(m_struct_DefaultDevice.qString_theWorkSpeed,m_struct_DefaultDevice.qString_theWorkAccelerate,
                                      m_struct_DefaultDevice.qString_theWorkDecelerate,m_struct_DefaultDevice.qString_theJogSpeed);

    emit ChangeAcquisitionOneDefaultSignal(m_struct_DefaultDevice.qString_theAcquisitionOne_Frequency,m_struct_DefaultDevice.qString_theAcquisitionOne_SectionLength,m_struct_DefaultDevice.qString_theAcquisitionOne_ChannelCount
                                           ,m_struct_DefaultDevice.qString_theAcquisitionOne_ChannelStart);
    emit ChangeAcquisitionTwoDefaultSignal(m_struct_DefaultDevice.qString_theAcquisitionTwo_Frequency,m_struct_DefaultDevice.qString_theAcquisitionTwo_SectionLength,m_struct_DefaultDevice.qString_theAcquisitionTwo_ChannelCount
                                           ,m_struct_DefaultDevice.qString_theAcquisitionTwo_ChannelStart);


}

void GS_WindowOne::InitTheNowDeviceSlot(DevicePara thedata)
{
    m_struct_NowDevice=thedata;
    emit ChangeFrequencyNowSignal(m_struct_NowDevice.qString_theWorkSpeed,m_struct_NowDevice.qString_theWorkAccelerate,
                                  m_struct_NowDevice.qString_theWorkDecelerate,m_struct_NowDevice.qString_theJogSpeed);
    emit ChangeAcquisitionOneNowSignal(m_struct_NowDevice.qString_theAcquisitionOne_Frequency,m_struct_NowDevice.qString_theAcquisitionOne_SectionLength,m_struct_NowDevice.qString_theAcquisitionOne_ChannelCount
                                       ,m_struct_NowDevice.qString_theAcquisitionOne_ChannelStart);
    emit ChangeAcquisitionTwoNowSignal(m_struct_NowDevice.qString_theAcquisitionTwo_Frequency,m_struct_NowDevice.qString_theAcquisitionTwo_SectionLength,m_struct_NowDevice.qString_theAcquisitionTwo_ChannelCount
                                       ,m_struct_NowDevice.qString_theAcquisitionTwo_ChannelStart);

}
void GS_WindowOne::ChangeTheFrequencySlot(QString Speed, QString Current, QString Frequency)
{
    i_text++;
    ui->m_lineED_Speed->setText(Speed);
    ui->m_lineED_Frequency->setText(Frequency);
    ui->m_lineED_Current->setText(Current);
    qDebug()<<"i="<<i_text;
}

void GS_WindowOne::StartTheAcquisitionSlot()
{
    emit StartTheAcquisitionOneSignal();
    emit StartTheAcquisitionTwoSignal();
}

void GS_WindowOne::StopTheAcquisitionSlot()
{
    emit StopTheAcquisitionOneSignal();
    emit StopTheAcquisitionTwoSignal();
    emit StopDrawChartSignal(3);
}

void GS_WindowOne::ChangeTcpListeningStatusSlot()
{
    m_pTimer1STcpSimen->stop();
    ui->m_label_StatusTCP->setStyleSheet(m_yellow_SheetStyle);
}
