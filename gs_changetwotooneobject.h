#ifndef GS_CHANGETWOTOONEOBJECT_H
#define GS_CHANGETWOTOONEOBJECT_H

#include <QObject>
class QTimer;
class gs_ChangeTwoToOneObject : public QObject
{
    Q_OBJECT
public:
    explicit gs_ChangeTwoToOneObject(QObject *parent = nullptr);
    ~gs_ChangeTwoToOneObject();
private:
    double* p[10000][2]={0};
    int m_iChannelOneCount;
    int m_iChannelTwoCount;
    int m_iSectionLength;
    int m_iProcessOneDecadeChart;
    int m_iProcessTwoDecadeChart;
    int m_iProcessOneTimesChart;
    int m_iProcessTwoTimesChart;
    int m_iSendSignalDecadeChart;
    int m_iSendSignalTimesChart;

    int m_iProcessOneDecadeSql;
    int m_iProcessTwoDecadeSql;
    int m_iProcessOneTimesSql;
    int m_iProcessTwoTimesSql;
    int m_iSendSignalDecadeSql;
    int m_iSendSignalTimesSql;



    QTimer*m_p10msTimer;
private:
    void InitPara();
    void InitSlot();

private:
    int GetDataOneChartNumber();
    int GetDataTwoChartNumber();
    int GetProcessAllChartNumber();

    int GetDataOneSqlNumber();
    int GetDataTwoSqlNumber();
    int GetProcessAllSqlNumber();


signals:
    void DataToChartSignal(double* dataOne,double* dataTwo,int SectionLength,int ChannelCountOne,int ChannelCountTwo);
    void DataToMySqlSignal(double* dataOne,double* dataTwo,int SectionLength,int ChannelCountOne,int ChannelCountTwo);
    void DataChartFinishSignal();
    void DataSqlFinishSignal();
    void ProcessOnePutIntoSuccessSignal(int count);
    void ProcessTwoPutIntoSuccessSignal(int count);
    void CanGetDataChartSignal();
    void CanGetDataSqlSignal();

public slots:
    void ProcessOneSlot(double*sdata,int iSectionLength,int ChannelOneCount);
    void ProcessTwoSlot(double*sdata,int iSectionLength,int ChannelTwoCount);
    void GetChartDataSlot(int i);
    void GetSqlDataSlot(int i);
private slots:
    void IfCanStartSlot();
};

#endif // GS_CHANGETWOTOONEOBJECT_H
