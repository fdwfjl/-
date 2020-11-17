/********************************************************************************
** Form generated from reading UI file 'gs_acquisitiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GS_ACQUISITIONDIALOG_H
#define UI_GS_ACQUISITIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_gs_AcquisitionDialog
{
public:
    QLabel *label;
    QComboBox *m_comebox_Device;
    QLabel *label_3;
    QComboBox *m_comebox_StartChannel;
    QLabel *label_4;
    QComboBox *m_comebox_ChannelCount;
    QLabel *label_5;
    QLineEdit *m_lineED_ClockRate;
    QLabel *label_6;
    QLineEdit *m_lineED_SectionLength;
    QGroupBox *groupBox;
    QPushButton *m_btn_AcquisitionSure;
    QPushButton *m_btn_AcquisitionDefault;

    void setupUi(QDialog *gs_AcquisitionDialog)
    {
        if (gs_AcquisitionDialog->objectName().isEmpty())
            gs_AcquisitionDialog->setObjectName(QStringLiteral("gs_AcquisitionDialog"));
        gs_AcquisitionDialog->setEnabled(true);
        gs_AcquisitionDialog->resize(463, 495);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(100);
        sizePolicy.setVerticalStretch(100);
        sizePolicy.setHeightForWidth(gs_AcquisitionDialog->sizePolicy().hasHeightForWidth());
        gs_AcquisitionDialog->setSizePolicy(sizePolicy);
        gs_AcquisitionDialog->setMaximumSize(QSize(463, 900));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        gs_AcquisitionDialog->setFont(font);
        label = new QLabel(gs_AcquisitionDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 40, 61, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        m_comebox_Device = new QComboBox(gs_AcquisitionDialog);
        m_comebox_Device->setObjectName(QStringLiteral("m_comebox_Device"));
        m_comebox_Device->setGeometry(QRect(130, 40, 211, 31));
        label_3 = new QLabel(gs_AcquisitionDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 130, 101, 31));
        label_3->setFont(font1);
        m_comebox_StartChannel = new QComboBox(gs_AcquisitionDialog);
        m_comebox_StartChannel->setObjectName(QStringLiteral("m_comebox_StartChannel"));
        m_comebox_StartChannel->setGeometry(QRect(230, 130, 71, 31));
        label_4 = new QLabel(gs_AcquisitionDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 180, 101, 31));
        label_4->setFont(font1);
        m_comebox_ChannelCount = new QComboBox(gs_AcquisitionDialog);
        m_comebox_ChannelCount->setObjectName(QStringLiteral("m_comebox_ChannelCount"));
        m_comebox_ChannelCount->setGeometry(QRect(230, 180, 71, 31));
        label_5 = new QLabel(gs_AcquisitionDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(60, 230, 101, 31));
        label_5->setFont(font1);
        m_lineED_ClockRate = new QLineEdit(gs_AcquisitionDialog);
        m_lineED_ClockRate->setObjectName(QStringLiteral("m_lineED_ClockRate"));
        m_lineED_ClockRate->setGeometry(QRect(230, 230, 131, 31));
        m_lineED_ClockRate->setFont(font);
        label_6 = new QLabel(gs_AcquisitionDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 280, 141, 31));
        label_6->setFont(font1);
        m_lineED_SectionLength = new QLineEdit(gs_AcquisitionDialog);
        m_lineED_SectionLength->setObjectName(QStringLiteral("m_lineED_SectionLength"));
        m_lineED_SectionLength->setGeometry(QRect(230, 280, 131, 31));
        m_lineED_SectionLength->setFont(font);
        groupBox = new QGroupBox(gs_AcquisitionDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 100, 431, 241));
        m_btn_AcquisitionSure = new QPushButton(gs_AcquisitionDialog);
        m_btn_AcquisitionSure->setObjectName(QStringLiteral("m_btn_AcquisitionSure"));
        m_btn_AcquisitionSure->setGeometry(QRect(20, 380, 131, 71));
        m_btn_AcquisitionDefault = new QPushButton(gs_AcquisitionDialog);
        m_btn_AcquisitionDefault->setObjectName(QStringLiteral("m_btn_AcquisitionDefault"));
        m_btn_AcquisitionDefault->setGeometry(QRect(310, 380, 131, 71));
        groupBox->raise();
        label->raise();
        m_comebox_Device->raise();
        label_3->raise();
        m_comebox_StartChannel->raise();
        label_4->raise();
        m_comebox_ChannelCount->raise();
        label_5->raise();
        m_lineED_ClockRate->raise();
        label_6->raise();
        m_lineED_SectionLength->raise();
        m_btn_AcquisitionSure->raise();
        m_btn_AcquisitionDefault->raise();

        retranslateUi(gs_AcquisitionDialog);

        QMetaObject::connectSlotsByName(gs_AcquisitionDialog);
    } // setupUi

    void retranslateUi(QDialog *gs_AcquisitionDialog)
    {
        gs_AcquisitionDialog->setWindowTitle(QApplication::translate("gs_AcquisitionDialog", "\351\207\207\351\233\206\345\215\241\350\256\276\347\275\256", Q_NULLPTR));
        label->setText(QApplication::translate("gs_AcquisitionDialog", "\350\256\276\345\244\207:", Q_NULLPTR));
        label_3->setText(QApplication::translate("gs_AcquisitionDialog", "\345\274\200\345\247\213\351\200\232\351\201\223:", Q_NULLPTR));
        label_4->setText(QApplication::translate("gs_AcquisitionDialog", "\351\200\232\351\201\223\344\270\252\346\225\260:", Q_NULLPTR));
        label_5->setText(QApplication::translate("gs_AcquisitionDialog", "\351\207\207\346\240\267\351\242\221\347\216\207:", Q_NULLPTR));
        label_6->setText(QApplication::translate("gs_AcquisitionDialog", "\345\215\225\351\200\232\351\201\223\351\207\207\346\240\267\346\225\260:", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("gs_AcquisitionDialog", "\345\217\202\346\225\260\350\256\276\347\275\256:", Q_NULLPTR));
        m_btn_AcquisitionSure->setText(QApplication::translate("gs_AcquisitionDialog", "\347\241\256\345\256\232", Q_NULLPTR));
        m_btn_AcquisitionDefault->setText(QApplication::translate("gs_AcquisitionDialog", "\351\273\230\350\256\244\345\200\274", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class gs_AcquisitionDialog: public Ui_gs_AcquisitionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GS_ACQUISITIONDIALOG_H
