/********************************************************************************
** Form generated from reading UI file 'gs_frequencydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GS_FREQUENCYDIALOG_H
#define UI_GS_FREQUENCYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gs_FrequencyDialog
{
public:
    QPushButton *m_btn_ControlFrequency;
    QPushButton *m_btn_ControlAir;
    QPushButton *m_btn_Default;
    QPushButton *m_btn_Sure;
    QTabWidget *m_tabwidget;
    QWidget *m_tab_WorkPara;
    QLabel *label;
    QLineEdit *m_lineED_WorkCircle;
    QLabel *label_2;
    QLineEdit *m_lineED_WorkAcc;
    QLineEdit *m_lineED_WorkDec;
    QLabel *label_3;
    QComboBox *m_combox_WorkDirect;
    QLabel *label_4;
    QWidget *m_tab_JogPara;
    QLabel *label_5;
    QLineEdit *m_lineED_JogCircle;
    QLabel *label_8;
    QComboBox *m_combox_JogDirect;
    QPushButton *m_btn_readStatus;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_9;
    QLineEdit *m_lineED_FrequencySpeed;
    QLineEdit *m_lineED_FrequencyPin;
    QLineEdit *m_lineED_FrequencyCurrent;

    void setupUi(QDialog *gs_FrequencyDialog)
    {
        if (gs_FrequencyDialog->objectName().isEmpty())
            gs_FrequencyDialog->setObjectName(QStringLiteral("gs_FrequencyDialog"));
        gs_FrequencyDialog->resize(323, 731);
        m_btn_ControlFrequency = new QPushButton(gs_FrequencyDialog);
        m_btn_ControlFrequency->setObjectName(QStringLiteral("m_btn_ControlFrequency"));
        m_btn_ControlFrequency->setGeometry(QRect(30, 540, 101, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        m_btn_ControlFrequency->setFont(font);
        m_btn_ControlAir = new QPushButton(gs_FrequencyDialog);
        m_btn_ControlAir->setObjectName(QStringLiteral("m_btn_ControlAir"));
        m_btn_ControlAir->setGeometry(QRect(190, 540, 101, 51));
        m_btn_ControlAir->setFont(font);
        m_btn_Default = new QPushButton(gs_FrequencyDialog);
        m_btn_Default->setObjectName(QStringLiteral("m_btn_Default"));
        m_btn_Default->setGeometry(QRect(190, 450, 101, 51));
        m_btn_Default->setFont(font);
        m_btn_Sure = new QPushButton(gs_FrequencyDialog);
        m_btn_Sure->setObjectName(QStringLiteral("m_btn_Sure"));
        m_btn_Sure->setGeometry(QRect(30, 450, 101, 51));
        m_btn_Sure->setFont(font);
        m_tabwidget = new QTabWidget(gs_FrequencyDialog);
        m_tabwidget->setObjectName(QStringLiteral("m_tabwidget"));
        m_tabwidget->setGeometry(QRect(20, 180, 271, 241));
        m_tab_WorkPara = new QWidget();
        m_tab_WorkPara->setObjectName(QStringLiteral("m_tab_WorkPara"));
        label = new QLabel(m_tab_WorkPara);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 54, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        m_lineED_WorkCircle = new QLineEdit(m_tab_WorkPara);
        m_lineED_WorkCircle->setObjectName(QStringLiteral("m_lineED_WorkCircle"));
        m_lineED_WorkCircle->setGeometry(QRect(100, 30, 113, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        m_lineED_WorkCircle->setFont(font2);
        label_2 = new QLabel(m_tab_WorkPara);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 80, 61, 21));
        label_2->setFont(font1);
        m_lineED_WorkAcc = new QLineEdit(m_tab_WorkPara);
        m_lineED_WorkAcc->setObjectName(QStringLiteral("m_lineED_WorkAcc"));
        m_lineED_WorkAcc->setGeometry(QRect(100, 80, 113, 20));
        m_lineED_WorkAcc->setFont(font2);
        m_lineED_WorkDec = new QLineEdit(m_tab_WorkPara);
        m_lineED_WorkDec->setObjectName(QStringLiteral("m_lineED_WorkDec"));
        m_lineED_WorkDec->setGeometry(QRect(100, 130, 113, 20));
        m_lineED_WorkDec->setFont(font2);
        label_3 = new QLabel(m_tab_WorkPara);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 130, 71, 21));
        label_3->setFont(font1);
        m_combox_WorkDirect = new QComboBox(m_tab_WorkPara);
        m_combox_WorkDirect->setObjectName(QStringLiteral("m_combox_WorkDirect"));
        m_combox_WorkDirect->setGeometry(QRect(100, 180, 111, 22));
        m_combox_WorkDirect->setFont(font2);
        m_combox_WorkDirect->setLayoutDirection(Qt::LeftToRight);
        label_4 = new QLabel(m_tab_WorkPara);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 180, 71, 21));
        label_4->setFont(font1);
        m_tabwidget->addTab(m_tab_WorkPara, QString());
        m_tab_JogPara = new QWidget();
        m_tab_JogPara->setObjectName(QStringLiteral("m_tab_JogPara"));
        label_5 = new QLabel(m_tab_JogPara);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 30, 54, 21));
        label_5->setFont(font1);
        m_lineED_JogCircle = new QLineEdit(m_tab_JogPara);
        m_lineED_JogCircle->setObjectName(QStringLiteral("m_lineED_JogCircle"));
        m_lineED_JogCircle->setGeometry(QRect(100, 30, 113, 21));
        m_lineED_JogCircle->setFont(font2);
        label_8 = new QLabel(m_tab_JogPara);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 100, 71, 21));
        label_8->setFont(font1);
        m_combox_JogDirect = new QComboBox(m_tab_JogPara);
        m_combox_JogDirect->setObjectName(QStringLiteral("m_combox_JogDirect"));
        m_combox_JogDirect->setGeometry(QRect(100, 100, 111, 22));
        m_combox_JogDirect->setFont(font2);
        m_tabwidget->addTab(m_tab_JogPara, QString());
        m_btn_readStatus = new QPushButton(gs_FrequencyDialog);
        m_btn_readStatus->setObjectName(QStringLiteral("m_btn_readStatus"));
        m_btn_readStatus->setGeometry(QRect(100, 610, 131, 41));
        label_6 = new QLabel(gs_FrequencyDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 20, 61, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        label_6->setFont(font3);
        label_7 = new QLabel(gs_FrequencyDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 70, 61, 31));
        label_7->setFont(font3);
        label_9 = new QLabel(gs_FrequencyDialog);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 120, 61, 31));
        label_9->setFont(font3);
        m_lineED_FrequencySpeed = new QLineEdit(gs_FrequencyDialog);
        m_lineED_FrequencySpeed->setObjectName(QStringLiteral("m_lineED_FrequencySpeed"));
        m_lineED_FrequencySpeed->setGeometry(QRect(110, 20, 111, 31));
        m_lineED_FrequencySpeed->setFont(font1);
        m_lineED_FrequencySpeed->setReadOnly(true);
        m_lineED_FrequencyPin = new QLineEdit(gs_FrequencyDialog);
        m_lineED_FrequencyPin->setObjectName(QStringLiteral("m_lineED_FrequencyPin"));
        m_lineED_FrequencyPin->setGeometry(QRect(110, 70, 111, 31));
        m_lineED_FrequencyPin->setFont(font1);
        m_lineED_FrequencyPin->setReadOnly(true);
        m_lineED_FrequencyCurrent = new QLineEdit(gs_FrequencyDialog);
        m_lineED_FrequencyCurrent->setObjectName(QStringLiteral("m_lineED_FrequencyCurrent"));
        m_lineED_FrequencyCurrent->setGeometry(QRect(110, 120, 111, 31));
        m_lineED_FrequencyCurrent->setFont(font1);
        m_lineED_FrequencyCurrent->setReadOnly(true);
        m_tabwidget->raise();
        m_btn_ControlFrequency->raise();
        m_btn_ControlAir->raise();
        m_btn_Default->raise();
        m_btn_Sure->raise();
        m_btn_readStatus->raise();
        label_6->raise();
        label_7->raise();
        label_9->raise();
        m_lineED_FrequencySpeed->raise();
        m_lineED_FrequencyPin->raise();
        m_lineED_FrequencyCurrent->raise();

        retranslateUi(gs_FrequencyDialog);

        m_tabwidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(gs_FrequencyDialog);
    } // setupUi

    void retranslateUi(QDialog *gs_FrequencyDialog)
    {
        gs_FrequencyDialog->setWindowTitle(QApplication::translate("gs_FrequencyDialog", "\345\217\230\351\242\221\345\231\250\345\217\202\346\225\260", Q_NULLPTR));
        m_btn_ControlFrequency->setText(QString());
        m_btn_ControlAir->setText(QString());
        m_btn_Default->setText(QApplication::translate("gs_FrequencyDialog", "\351\273\230\350\256\244\345\200\274", Q_NULLPTR));
        m_btn_Sure->setText(QApplication::translate("gs_FrequencyDialog", "\347\241\256\350\256\244", Q_NULLPTR));
        label->setText(QApplication::translate("gs_FrequencyDialog", "\350\275\254\351\200\237:", Q_NULLPTR));
        label_2->setText(QApplication::translate("gs_FrequencyDialog", " \345\212\240\351\200\237\345\272\246:", Q_NULLPTR));
        label_3->setText(QApplication::translate("gs_FrequencyDialog", " \345\207\217\351\200\237\345\272\246:", Q_NULLPTR));
        m_combox_WorkDirect->clear();
        m_combox_WorkDirect->insertItems(0, QStringList()
         << QApplication::translate("gs_FrequencyDialog", "\346\255\243\350\275\254", Q_NULLPTR)
         << QApplication::translate("gs_FrequencyDialog", "\345\217\215\350\275\254", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("gs_FrequencyDialog", "    \346\226\271\345\220\221:", Q_NULLPTR));
        m_tabwidget->setTabText(m_tabwidget->indexOf(m_tab_WorkPara), QApplication::translate("gs_FrequencyDialog", "\345\267\245\344\275\234\345\217\202\346\225\260", Q_NULLPTR));
        label_5->setText(QApplication::translate("gs_FrequencyDialog", "\350\275\254\351\200\237:", Q_NULLPTR));
        label_8->setText(QApplication::translate("gs_FrequencyDialog", "  \346\226\271\345\220\221:", Q_NULLPTR));
        m_combox_JogDirect->clear();
        m_combox_JogDirect->insertItems(0, QStringList()
         << QApplication::translate("gs_FrequencyDialog", "\346\255\243\350\275\254", Q_NULLPTR)
         << QApplication::translate("gs_FrequencyDialog", "\345\217\215\350\275\254", Q_NULLPTR)
        );
        m_tabwidget->setTabText(m_tabwidget->indexOf(m_tab_JogPara), QApplication::translate("gs_FrequencyDialog", "Jog\345\217\202\346\225\260", Q_NULLPTR));
        m_btn_readStatus->setText(QApplication::translate("gs_FrequencyDialog", "\350\257\273\345\217\226\347\212\266\346\200\201", Q_NULLPTR));
        label_6->setText(QApplication::translate("gs_FrequencyDialog", "\351\200\237\345\272\246:", Q_NULLPTR));
        label_7->setText(QApplication::translate("gs_FrequencyDialog", "\351\242\221\347\216\207:", Q_NULLPTR));
        label_9->setText(QApplication::translate("gs_FrequencyDialog", "\347\224\265\346\265\201:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class gs_FrequencyDialog: public Ui_gs_FrequencyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GS_FREQUENCYDIALOG_H
