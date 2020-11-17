#ifndef GS_MYSQLDIALOG_H
#define GS_MYSQLDIALOG_H

#include <QDialog>

namespace Ui {
class gs_MysqlDialog;
}

class gs_MysqlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit gs_MysqlDialog(QWidget *parent = 0);
    ~gs_MysqlDialog();

private:
    Ui::gs_MysqlDialog *ui;
private:

    virtual void closeEvent(QCloseEvent *e) override;

};

#endif // GS_MYSQLDIALOG_H
