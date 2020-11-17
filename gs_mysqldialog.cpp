#include "gs_mysqldialog.h"
#include "ui_gs_mysqldialog.h"

gs_MysqlDialog::gs_MysqlDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gs_MysqlDialog)
{
    ui->setupUi(this);
}

gs_MysqlDialog::~gs_MysqlDialog()
{
    delete ui;
}

void gs_MysqlDialog::closeEvent(QCloseEvent *e)
{
    accept();
}
