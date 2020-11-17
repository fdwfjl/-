#ifndef GS_TCPPARADIALOG_H
#define GS_TCPPARADIALOG_H

#include <QDialog>

namespace Ui {
class gs_TcpParaDialog;
}

struct IpParameter
{
   QString TheIp;
   QString ThePort;
};



class gs_TcpParaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit gs_TcpParaDialog(QWidget *parent = 0);
    ~gs_TcpParaDialog();

public:
    IpParameter m_IpParameter;


private:
    void InitSlot();

virtual void closeEvent(QCloseEvent *e) override;




private slots:
    void TheIpParameterSureSlot();
    void TheIpParameterDafaultSlot();





private:
    Ui::gs_TcpParaDialog *ui;
};

#endif // GS_TCPPARADIALOG_H
