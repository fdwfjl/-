#ifndef GS_PROCESSSTATUSOBJECT_H
#define GS_PROCESSSTATUSOBJECT_H

#include <QObject>

class gs_processstatusobject : public QObject
{
    Q_OBJECT
public:
    explicit gs_processstatusobject(QObject *parent = nullptr);
signals:
    void ChangeTheFrequencyStatusSignal(QString Speed,QString Current,QString Frequency);
public slots:
    void processTheStatusSlot(QString sdata);
};

#endif // GS_PROCESSSTATUSOBJECT_H
