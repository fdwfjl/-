#ifndef GS_REGISTERDIALOG_H
#define GS_REGISTERDIALOG_H

#include <QDialog>

namespace Ui {
class gs_registerDialog;
}

class gs_registerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit gs_registerDialog(QWidget *parent = 0);
    ~gs_registerDialog();

private:
    Ui::gs_registerDialog *ui;

private:
    void InitSlot();

private slots:
    void ToAcceptSlot();
    void ToReceptSlot();

};

#endif // GS_REGISTERDIALOG_H
