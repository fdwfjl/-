#include "gs_windowone.h"
#include <QApplication>
#include "gs_registerdialog.h"
#include <QStyleFactory>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle(QStyleFactory::create("GTK+"));
    GS_WindowOne w;
    gs_registerDialog dialog;
    dialog.setFixedSize(350,470);
    int resultDialog=dialog.exec();
    if(resultDialog==QDialog::Rejected)
    {
        a.exit(0);
        return 0;
    }
    else if(resultDialog==QDialog::Accepted)
    {
        w.setFixedSize(w.size());
        w.show();
    }

    return a.exec();
}
