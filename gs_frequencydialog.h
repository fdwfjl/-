#ifndef GS_FREQUENCYDIALOG_H
#define GS_FREQUENCYDIALOG_H

#include <QDialog>

class QTimer;
namespace Ui {
class gs_FrequencyDialog;
}
struct FrequencyPara
{
    QString String_workSpeed;
    QString String_workAccelerate;
    QString String_workDecelerate;
    QString String_jogSpeed;
};

enum FrequencyMode
{
    WorkMode=0,
    JogMode=1
};
enum FrequencyDirection
{
    Forward=0,
    Reverse=1
};


class gs_FrequencyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit gs_FrequencyDialog(QWidget *parent = 0);
    ~gs_FrequencyDialog();

private:
    Ui::gs_FrequencyDialog *ui;
public:
    FrequencyPara theFrequencyPara;
    FrequencyPara theFrequencyLastPara;
    FrequencyPara theFrequencyDefaultPara;

private:
    const QString m_frequencyForwardStart="00:01";
    const QString m_frequencyForwardStop="00:00";
    const QString m_AirStart="00:02";
    const QString m_AirStop="00:03";
    const QString m_JogForwardStart="00:04";
    const QString m_JogForwardStop="00:05";
    const QString m_ReadStatus="00:06";
    const QString m_frequencyReverseStop="00:07";
    const QString m_frequencyReverseStart="00:08";
    const QString m_JogReverseStop="00:09";
    const QString m_JogReverseStart="00:10";

    bool m_bDirection;
    bool m_bFrequencySwitch;
    bool m_bAirSwitch;

    QTimer*m_pTimer500ms;



private:
    void InitSlot();
    virtual void closeEvent(QCloseEvent *e) override;

signals:
    void WriteToTcpDataSignal(QString sdata);  //变频器开始结束正反转的信号
    void FrequencyParaSureSignal(QString theSpeed,QString theAccelerate,QString Decelerate);
    void FrequencyParaDefaultSureSignal();
    void RefreshUISuccessSignal();
    void WorkSpeedChangeSignal(QString speed);
    void WorkAccelerateChangeSignal(QString acceleration);
    void WorkDecelerateChangeSignal(QString deceleration);
    void JogSpeedChangeSignal(QString speed);


public slots:
    void StartTheTimerSlot();
    void ShowTheStatusSlot(QString workSpeed,QString workCurrent,QString workFrequency);
    void FromMySqlSlot(QString workSpeed,QString workAcc,QString workDec,QString jogSpeed);
    void FromMySqlDefaultSlot(QString workSpeed,QString workAcc,QString workDec,QString jogSpeed);
private slots:
    void FrequencyParaSureSlot();
    void FrequencyParaDefaultSlot();
    void FrequencyStartOrStopSlot();
    void AirStartOrStopSlot();
    void FrequencyReadStatusSlot();

public slots:
    void RefreshTheUISlot();


};

#endif // GS_FREQUENCYDIALOG_H
