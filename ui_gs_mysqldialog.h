/********************************************************************************
** Form generated from reading UI file 'gs_mysqldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GS_MYSQLDIALOG_H
#define UI_GS_MYSQLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_gs_MysqlDialog
{
public:
    QTextEdit *m_textED_ShowSqlName;
    QLabel *label;
    QLineEdit *m_lineED_CurrentSqlName;
    QGroupBox *groupBox_3;
    QLabel *label_2;
    QLineEdit *m_lineED_ChangeSqlName;
    QPushButton *m_btn_SureMySql;
    QPushButton *m_btn_DownLoad;
    QPushButton *m_btn_DefaultMySql;

    void setupUi(QDialog *gs_MysqlDialog)
    {
        if (gs_MysqlDialog->objectName().isEmpty())
            gs_MysqlDialog->setObjectName(QStringLiteral("gs_MysqlDialog"));
        gs_MysqlDialog->resize(589, 580);
        m_textED_ShowSqlName = new QTextEdit(gs_MysqlDialog);
        m_textED_ShowSqlName->setObjectName(QStringLiteral("m_textED_ShowSqlName"));
        m_textED_ShowSqlName->setGeometry(QRect(20, 40, 551, 161));
        label = new QLabel(gs_MysqlDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 250, 181, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        m_lineED_CurrentSqlName = new QLineEdit(gs_MysqlDialog);
        m_lineED_CurrentSqlName->setObjectName(QStringLiteral("m_lineED_CurrentSqlName"));
        m_lineED_CurrentSqlName->setGeometry(QRect(220, 250, 351, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        m_lineED_CurrentSqlName->setFont(font1);
        m_lineED_CurrentSqlName->setAlignment(Qt::AlignCenter);
        groupBox_3 = new QGroupBox(gs_MysqlDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 20, 571, 201));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        groupBox_3->setFont(font2);
        label_2 = new QLabel(gs_MysqlDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 350, 181, 51));
        label_2->setFont(font);
        m_lineED_ChangeSqlName = new QLineEdit(gs_MysqlDialog);
        m_lineED_ChangeSqlName->setObjectName(QStringLiteral("m_lineED_ChangeSqlName"));
        m_lineED_ChangeSqlName->setGeometry(QRect(220, 350, 351, 51));
        m_lineED_ChangeSqlName->setFont(font1);
        m_lineED_ChangeSqlName->setAlignment(Qt::AlignCenter);
        m_btn_SureMySql = new QPushButton(gs_MysqlDialog);
        m_btn_SureMySql->setObjectName(QStringLiteral("m_btn_SureMySql"));
        m_btn_SureMySql->setGeometry(QRect(20, 470, 151, 61));
        m_btn_SureMySql->setFont(font1);
        m_btn_DownLoad = new QPushButton(gs_MysqlDialog);
        m_btn_DownLoad->setObjectName(QStringLiteral("m_btn_DownLoad"));
        m_btn_DownLoad->setGeometry(QRect(220, 470, 151, 61));
        m_btn_DownLoad->setFont(font1);
        m_btn_DefaultMySql = new QPushButton(gs_MysqlDialog);
        m_btn_DefaultMySql->setObjectName(QStringLiteral("m_btn_DefaultMySql"));
        m_btn_DefaultMySql->setGeometry(QRect(420, 470, 151, 61));
        m_btn_DefaultMySql->setFont(font1);
        groupBox_3->raise();
        m_textED_ShowSqlName->raise();
        label->raise();
        m_lineED_CurrentSqlName->raise();
        label_2->raise();
        m_lineED_ChangeSqlName->raise();
        m_btn_SureMySql->raise();
        m_btn_DownLoad->raise();
        m_btn_DefaultMySql->raise();

        retranslateUi(gs_MysqlDialog);

        QMetaObject::connectSlotsByName(gs_MysqlDialog);
    } // setupUi

    void retranslateUi(QDialog *gs_MysqlDialog)
    {
        gs_MysqlDialog->setWindowTitle(QApplication::translate("gs_MysqlDialog", "\346\225\260\346\215\256\345\272\223\345\217\202\346\225\260", Q_NULLPTR));
        label->setText(QApplication::translate("gs_MysqlDialog", "\345\275\223\345\211\215\350\241\250\357\274\232", Q_NULLPTR));
        m_lineED_CurrentSqlName->setText(QApplication::translate("gs_MysqlDialog", "abc", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("gs_MysqlDialog", "\350\241\250\346\230\276\347\244\272\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("gs_MysqlDialog", "\344\277\256\346\224\271\350\241\250\357\274\232", Q_NULLPTR));
        m_lineED_ChangeSqlName->setText(QApplication::translate("gs_MysqlDialog", "abc", Q_NULLPTR));
        m_btn_SureMySql->setText(QApplication::translate("gs_MysqlDialog", "\347\241\256\345\256\232", Q_NULLPTR));
        m_btn_DownLoad->setText(QApplication::translate("gs_MysqlDialog", "\344\277\235\345\255\230\346\234\254\345\234\260", Q_NULLPTR));
        m_btn_DefaultMySql->setText(QApplication::translate("gs_MysqlDialog", "\346\201\242\345\244\215\351\273\230\350\256\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class gs_MysqlDialog: public Ui_gs_MysqlDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GS_MYSQLDIALOG_H
