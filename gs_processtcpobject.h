#ifndef GS_PROCESSTCPOBJECT_H
#define GS_PROCESSTCPOBJECT_H

#include <QObject>

class QTimer;
class gs_processtcpobject : public QObject
{
    Q_OBJECT
public:
    explicit gs_processtcpobject(QObject *parent = nullptr);

private:
    int m_iReceiveCount;
    int m_iSendCount;
    QTimer*m_pTimer1S;
    QString receiveData[100]={0};


 private:
    void InitPara();
    void InitSlot();

signals:
    void SendToTcpSignal(QString sorder);  //发送到Tcp的数
    void SendToMainSignal(QString sorder);//这是变频器状态读取的信号

public slots:

    void ReceiveTheOrderSlot(QString sorder);//保存命令到容器里
    void SendTheOrderSlot(QString sorder);   //发送容器里的命令到Simen

private slots:
    void The1STimerSlot();


};

#endif // GS_PROCESSTCPOBJECT_H
