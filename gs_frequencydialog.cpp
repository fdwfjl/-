#include "gs_frequencydialog.h"
#include "ui_gs_frequencydialog.h"
#include <QDebug>
#include <QMessageBox>
#include <QTimer>

gs_FrequencyDialog::gs_FrequencyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gs_FrequencyDialog)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    m_bFrequencySwitch=false;
    m_bAirSwitch=false;
    ui->m_btn_ControlFrequency->setText("Start");
    ui->m_btn_ControlAir->setText("Close");
    ui->m_tabwidget->setCurrentIndex(0);
    ui->m_combox_WorkDirect->setCurrentIndex(0);
    ui->m_combox_JogDirect->setCurrentIndex(1);
    m_pTimer500ms=new QTimer(this);
    m_pTimer500ms->setInterval(500);
    InitSlot();
}



gs_FrequencyDialog::~gs_FrequencyDialog()
{
    delete ui;
   // qDebug()<<QStringLiteral("删除变频器设置成功!");
}

void gs_FrequencyDialog::InitSlot()
{
    connect(ui->m_btn_Sure,SIGNAL(clicked()),this,SLOT(FrequencyParaSureSlot()));
    connect(ui->m_btn_Default,SIGNAL(clicked()),this,SLOT(FrequencyParaDefaultSlot()));
    connect(ui->m_btn_ControlFrequency,SIGNAL(clicked()),this,SLOT(FrequencyStartOrStopSlot()));
    connect(ui->m_btn_ControlAir,SIGNAL(clicked()),this,SLOT(AirStartOrStopSlot()));
    connect(ui->m_btn_readStatus,SIGNAL(clicked()),this,SLOT(FrequencyReadStatusSlot()));
    connect(m_pTimer500ms,SIGNAL(timeout()),this,SLOT(FrequencyReadStatusSlot()));
}

void gs_FrequencyDialog::closeEvent(QCloseEvent *e)
{
    Q_UNUSED(e);
    accept();
}

void gs_FrequencyDialog::StartTheTimerSlot()
{
    m_pTimer500ms->start();
}

void gs_FrequencyDialog::ShowTheStatusSlot(QString workSpeed, QString workCurrent, QString workFrequency)
{
    ui->m_lineED_FrequencySpeed->setText(workSpeed);
    ui->m_lineED_FrequencyPin->setText(workFrequency);
    ui->m_lineED_FrequencyCurrent->setText(workCurrent);
}

void gs_FrequencyDialog::FrequencyParaSureSlot()
{
    int currentIndex=ui->m_tabwidget->currentIndex();
    switch(currentIndex)
    {
    case WorkMode:
        theFrequencyPara.String_workSpeed=ui->m_lineED_WorkCircle->text();
        theFrequencyPara.String_workAccelerate=ui->m_lineED_WorkAcc->text();
        theFrequencyPara.String_workDecelerate=ui->m_lineED_WorkDec->text();
        if(theFrequencyLastPara.String_workSpeed!=theFrequencyPara.String_workSpeed)
        {
            theFrequencyLastPara.String_workSpeed=theFrequencyPara.String_workSpeed;
            QString btmWorkSpeed=QString("03:%1").arg(theFrequencyPara.String_workSpeed);
            emit WorkSpeedChangeSignal(btmWorkSpeed);
        }
        if(theFrequencyLastPara.String_workAccelerate!=theFrequencyPara.String_workAccelerate)
        {
            theFrequencyLastPara.String_workAccelerate!=theFrequencyPara.String_workAccelerate;
            QString btmWorkAcc=QString("01:%1").arg(theFrequencyPara.String_workAccelerate);
            emit WorkAccelerateChangeSignal(btmWorkAcc);
        }
        if(theFrequencyLastPara.String_workDecelerate!=theFrequencyPara.String_workDecelerate)
        {
            theFrequencyLastPara.String_workDecelerate=theFrequencyPara.String_workDecelerate;
            QString btmWorkDec=QString("02:%1").arg(theFrequencyPara.String_workDecelerate);
            emit WorkDecelerateChangeSignal(btmWorkDec);
        }
        break;

    case JogMode:
        theFrequencyPara.String_jogSpeed=ui->m_lineED_JogCircle->text();
        if(theFrequencyLastPara.String_jogSpeed!=theFrequencyPara.String_jogSpeed)
        {
            theFrequencyLastPara.String_jogSpeed=theFrequencyPara.String_jogSpeed;
            QString btmJogSpeed=QString("04:%1").arg(theFrequencyPara.String_jogSpeed);
            emit JogSpeedChangeSignal(btmJogSpeed);
        }
        break;

    };



}

void gs_FrequencyDialog::FromMySqlSlot(QString workSpeed, QString workAcc, QString workDec, QString jogSpeed)
{
    theFrequencyPara.String_workSpeed=workSpeed;
    theFrequencyPara.String_workAccelerate=workAcc;
    theFrequencyPara.String_workDecelerate=workDec;
    theFrequencyPara.String_jogSpeed=jogSpeed;
    theFrequencyLastPara=theFrequencyPara;
    ui->m_lineED_WorkCircle->setText(theFrequencyPara.String_workSpeed);
    ui->m_lineED_WorkAcc->setText(theFrequencyPara.String_workAccelerate);
    ui->m_lineED_WorkDec->setText(theFrequencyPara.String_workDecelerate);
    ui->m_lineED_JogCircle->setText(theFrequencyPara.String_jogSpeed);

}

void gs_FrequencyDialog::FromMySqlDefaultSlot(QString workSpeed, QString workAcc, QString workDec, QString jogSpeed)
{
    theFrequencyDefaultPara.String_workSpeed=workSpeed;
    theFrequencyDefaultPara.String_workAccelerate=workAcc;
    theFrequencyDefaultPara.String_workDecelerate=workDec;
    theFrequencyDefaultPara.String_jogSpeed=jogSpeed;
}

void gs_FrequencyDialog::FrequencyParaDefaultSlot()
{
    ui->m_lineED_WorkCircle->setText(theFrequencyDefaultPara.String_workSpeed);
    ui->m_lineED_WorkAcc->setText(theFrequencyDefaultPara.String_workAccelerate);
    ui->m_lineED_WorkDec->setText(theFrequencyDefaultPara.String_workDecelerate);
    ui->m_lineED_JogCircle->setText(theFrequencyDefaultPara.String_jogSpeed);
    emit FrequencyParaDefaultSureSignal();

}

void gs_FrequencyDialog::FrequencyStartOrStopSlot()
{

    m_bFrequencySwitch=!m_bFrequencySwitch;
    int currentIndex=ui->m_tabwidget->currentIndex();
    switch(currentIndex)
    {
    case WorkMode:
    {
        int currentDirect=ui->m_combox_WorkDirect->currentIndex();
        switch(currentDirect)
        {
        case Forward:
            if(m_bFrequencySwitch==true)
            {
                emit WriteToTcpDataSignal(m_frequencyForwardStart);
                ui->m_btn_ControlFrequency->setText("Stop");
                qDebug()<<"FrequencyStart;";
            }
            else
            {
                emit WriteToTcpDataSignal(m_frequencyForwardStop);
                ui->m_btn_ControlFrequency->setText("Start");
                qDebug()<<"FrequencyStop;";
            }

            break;
        case Reverse:
            if(m_bFrequencySwitch==true)
            {
                emit WriteToTcpDataSignal(m_frequencyReverseStart);
                ui->m_btn_ControlFrequency->setText("Stop");
            }
            else
            {
                emit WriteToTcpDataSignal(m_frequencyReverseStop);
                ui->m_btn_ControlFrequency->setText("Start");
            }
            break;
        }
       break;
    }
    case JogMode:
    {
        int currentJogDirect=ui->m_combox_JogDirect->currentIndex();
        switch(currentJogDirect)
        {
        case Forward:
            if(m_bFrequencySwitch==true)
            {
                emit WriteToTcpDataSignal(m_JogForwardStart);
                ui->m_btn_ControlFrequency->setText("Stop");
            }
            else
            {
                emit WriteToTcpDataSignal(m_JogForwardStop);
                ui->m_btn_ControlFrequency->setText("Start");
            }
            break;
        case Reverse:
            if(m_bFrequencySwitch==true)
            {
                emit WriteToTcpDataSignal(m_JogReverseStart);
                ui->m_btn_ControlFrequency->setText("Stop");
            }
            else
            {
                emit WriteToTcpDataSignal(m_JogReverseStop);
                ui->m_btn_ControlFrequency->setText("Start");
            }
            break;
        }
        break;
    }
    };


}

void gs_FrequencyDialog::AirStartOrStopSlot()
{
    qDebug()<<"two";
    m_bAirSwitch=!m_bAirSwitch;
    if(m_bAirSwitch==true)
    {
        WriteToTcpDataSignal(m_AirStart);
        ui->m_btn_ControlAir->setText("Relax");
    }
    else if(m_bAirSwitch==false)
    {
        WriteToTcpDataSignal(m_AirStop);
        ui->m_btn_ControlAir->setText("Eat");
    }
    qDebug()<<m_bAirSwitch;

}

void gs_FrequencyDialog::FrequencyReadStatusSlot()
{
    emit WriteToTcpDataSignal(m_ReadStatus);
}


void gs_FrequencyDialog::RefreshTheUISlot()
{

    emit RefreshUISuccessSignal();
}




