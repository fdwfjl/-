#ifndef GS_TCPSIMENSOBJECT_H
#define GS_TCPSIMENSOBJECT_H

#include <QObject>

class QTcpServer;
class QTcpSocket;
class gs_tcpsimensobject : public QObject
{
    Q_OBJECT
public:
    explicit gs_tcpsimensobject(QObject *parent = nullptr);
    ~gs_tcpsimensobject();
private:
    QTcpServer*m_pTcpServer;
    QTcpSocket*m_pTcpSocket;
    QString m_StringIP;
    int m_iPort;

private:
    void InitPara();
    void InitSlot();

signals:
    void ListeningSignal();
    void ConnectSuccessSignal();
    void DisconnectSignal();
    void WriteCountSignal(int Count);
    void ReadDataSignal(QString thedata);
    void WriteFailSignal();

private slots:
    void ConnectServeSlot();
    void DisconnectServerSlot();
    void ServeReadSlot();




public slots:
    void ListenServeSlot(QString Ip,QString Port);
    void ServeWriteSlot(QString thedata);
};

#endif // GS_TCPSIMENSOBJECT_H
