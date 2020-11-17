/********************************************************************************
** Form generated from reading UI file 'gs_registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GS_REGISTERDIALOG_H
#define UI_GS_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_gs_registerDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *m_lineED_User;
    QLabel *label_3;
    QLineEdit *m_lineED_Password;
    QPushButton *m_btn_SignIn;
    QPushButton *m_btn_Exit;

    void setupUi(QDialog *gs_registerDialog)
    {
        if (gs_registerDialog->objectName().isEmpty())
            gs_registerDialog->setObjectName(QStringLiteral("gs_registerDialog"));
        gs_registerDialog->resize(350, 470);
        gs_registerDialog->setMinimumSize(QSize(350, 470));
        gs_registerDialog->setMaximumSize(QSize(350, 470));
        label = new QLabel(gs_registerDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 350, 470));
        label->setPixmap(QPixmap(QString::fromUtf8("../../myproject/mymain2.png")));
        label_2 = new QLabel(gs_registerDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 30, 91, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(26);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setStyleSheet(QLatin1String("\n"
"color: rgb(0, 0, 0);"));
        m_lineED_User = new QLineEdit(gs_registerDialog);
        m_lineED_User->setObjectName(QStringLiteral("m_lineED_User"));
        m_lineED_User->setGeometry(QRect(130, 30, 201, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        m_lineED_User->setFont(font1);
        m_lineED_User->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(gs_registerDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 110, 91, 41));
        label_3->setFont(font);
        label_3->setStyleSheet(QLatin1String("\n"
"color: rgb(0, 0, 0);"));
        m_lineED_Password = new QLineEdit(gs_registerDialog);
        m_lineED_Password->setObjectName(QStringLiteral("m_lineED_Password"));
        m_lineED_Password->setGeometry(QRect(130, 110, 201, 41));
        m_lineED_Password->setEchoMode(QLineEdit::Password);
        m_lineED_Password->setAlignment(Qt::AlignCenter);
        m_btn_SignIn = new QPushButton(gs_registerDialog);
        m_btn_SignIn->setObjectName(QStringLiteral("m_btn_SignIn"));
        m_btn_SignIn->setGeometry(QRect(25, 350, 125, 80));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font2.setPointSize(24);
        font2.setBold(true);
        font2.setWeight(75);
        m_btn_SignIn->setFont(font2);
        m_btn_Exit = new QPushButton(gs_registerDialog);
        m_btn_Exit->setObjectName(QStringLiteral("m_btn_Exit"));
        m_btn_Exit->setGeometry(QRect(200, 350, 125, 80));
        m_btn_Exit->setFont(font2);

        retranslateUi(gs_registerDialog);

        QMetaObject::connectSlotsByName(gs_registerDialog);
    } // setupUi

    void retranslateUi(QDialog *gs_registerDialog)
    {
        gs_registerDialog->setWindowTitle(QApplication::translate("gs_registerDialog", "\347\231\273\345\275\225\347\225\214\351\235\242", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("gs_registerDialog", "\350\264\246\345\217\267\357\274\232", Q_NULLPTR));
        m_lineED_User->setText(QApplication::translate("gs_registerDialog", "David", Q_NULLPTR));
        label_3->setText(QApplication::translate("gs_registerDialog", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        m_lineED_Password->setText(QApplication::translate("gs_registerDialog", "123456789", Q_NULLPTR));
        m_btn_SignIn->setText(QApplication::translate("gs_registerDialog", "\347\231\273\345\275\225", Q_NULLPTR));
        m_btn_Exit->setText(QApplication::translate("gs_registerDialog", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class gs_registerDialog: public Ui_gs_registerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GS_REGISTERDIALOG_H
