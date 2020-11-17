/********************************************************************************
** Form generated from reading UI file 'gs_tcpparadialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GS_TCPPARADIALOG_H
#define UI_GS_TCPPARADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_gs_TcpParaDialog
{
public:
    QLabel *label;
    QLineEdit *m_lineED_IP;
    QLineEdit *m_lineED_Port;
    QLabel *label_2;

    void setupUi(QDialog *gs_TcpParaDialog)
    {
        if (gs_TcpParaDialog->objectName().isEmpty())
            gs_TcpParaDialog->setObjectName(QStringLiteral("gs_TcpParaDialog"));
        gs_TcpParaDialog->resize(331, 234);
        label = new QLabel(gs_TcpParaDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 70, 41, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        m_lineED_IP = new QLineEdit(gs_TcpParaDialog);
        m_lineED_IP->setObjectName(QStringLiteral("m_lineED_IP"));
        m_lineED_IP->setGeometry(QRect(120, 70, 161, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        m_lineED_IP->setFont(font1);
        m_lineED_IP->setAlignment(Qt::AlignCenter);
        m_lineED_IP->setReadOnly(true);
        m_lineED_Port = new QLineEdit(gs_TcpParaDialog);
        m_lineED_Port->setObjectName(QStringLiteral("m_lineED_Port"));
        m_lineED_Port->setGeometry(QRect(120, 130, 161, 31));
        m_lineED_Port->setFont(font1);
        m_lineED_Port->setCursorPosition(4);
        m_lineED_Port->setAlignment(Qt::AlignCenter);
        m_lineED_Port->setReadOnly(true);
        label_2 = new QLabel(gs_TcpParaDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 130, 61, 31));
        label_2->setFont(font);

        retranslateUi(gs_TcpParaDialog);

        QMetaObject::connectSlotsByName(gs_TcpParaDialog);
    } // setupUi

    void retranslateUi(QDialog *gs_TcpParaDialog)
    {
        gs_TcpParaDialog->setWindowTitle(QApplication::translate("gs_TcpParaDialog", "\347\275\221\347\273\234\345\217\202\346\225\260", Q_NULLPTR));
        label->setText(QApplication::translate("gs_TcpParaDialog", "IP:", Q_NULLPTR));
        m_lineED_IP->setText(QApplication::translate("gs_TcpParaDialog", "192.168.3.50", Q_NULLPTR));
        m_lineED_Port->setText(QApplication::translate("gs_TcpParaDialog", "3321", Q_NULLPTR));
        label_2->setText(QApplication::translate("gs_TcpParaDialog", "PORT:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class gs_TcpParaDialog: public Ui_gs_TcpParaDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GS_TCPPARADIALOG_H
