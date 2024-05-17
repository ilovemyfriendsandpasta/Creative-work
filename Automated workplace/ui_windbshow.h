/********************************************************************************
** Form generated from reading UI file 'windbshow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDBSHOW_H
#define UI_WINDBSHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WinDBshow
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QTableView *tableView_Sklad;
    QPushButton *addBtn;
    QPushButton *delBtn;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QTableView *tableView_Transport;
    QPushButton *addBtn_2;
    QPushButton *delBtn_2;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QTableView *tableView_Drivers;
    QPushButton *addBtn_3;
    QPushButton *delBtn_3;

    void setupUi(QDialog *WinDBshow)
    {
        if (WinDBshow->objectName().isEmpty())
            WinDBshow->setObjectName(QString::fromUtf8("WinDBshow"));
        WinDBshow->resize(800, 600);
        gridLayout = new QGridLayout(WinDBshow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(WinDBshow);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tableView_Sklad = new QTableView(tab);
        tableView_Sklad->setObjectName(QString::fromUtf8("tableView_Sklad"));

        gridLayout_2->addWidget(tableView_Sklad, 0, 0, 1, 2);

        addBtn = new QPushButton(tab);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));

        gridLayout_2->addWidget(addBtn, 1, 0, 1, 1);

        delBtn = new QPushButton(tab);
        delBtn->setObjectName(QString::fromUtf8("delBtn"));

        gridLayout_2->addWidget(delBtn, 1, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tableView_Transport = new QTableView(tab_2);
        tableView_Transport->setObjectName(QString::fromUtf8("tableView_Transport"));

        gridLayout_3->addWidget(tableView_Transport, 0, 0, 1, 2);

        addBtn_2 = new QPushButton(tab_2);
        addBtn_2->setObjectName(QString::fromUtf8("addBtn_2"));

        gridLayout_3->addWidget(addBtn_2, 1, 0, 1, 1);

        delBtn_2 = new QPushButton(tab_2);
        delBtn_2->setObjectName(QString::fromUtf8("delBtn_2"));

        gridLayout_3->addWidget(delBtn_2, 1, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_4 = new QGridLayout(tab_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tableView_Drivers = new QTableView(tab_3);
        tableView_Drivers->setObjectName(QString::fromUtf8("tableView_Drivers"));

        gridLayout_4->addWidget(tableView_Drivers, 0, 0, 1, 2);

        addBtn_3 = new QPushButton(tab_3);
        addBtn_3->setObjectName(QString::fromUtf8("addBtn_3"));

        gridLayout_4->addWidget(addBtn_3, 1, 0, 1, 1);

        delBtn_3 = new QPushButton(tab_3);
        delBtn_3->setObjectName(QString::fromUtf8("delBtn_3"));

        gridLayout_4->addWidget(delBtn_3, 1, 1, 1, 1);

        tabWidget->addTab(tab_3, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(WinDBshow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(WinDBshow);
    } // setupUi

    void retranslateUi(QDialog *WinDBshow)
    {
        WinDBshow->setWindowTitle(QApplication::translate("WinDBshow", "\320\241\320\262\320\265\320\264\320\265\320\275\320\270\321\217 \320\276 \321\201\320\272\320\273\320\260\320\264\320\265", nullptr));
        addBtn->setText(QApplication::translate("WinDBshow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        delBtn->setText(QApplication::translate("WinDBshow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("WinDBshow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \321\201\320\272\320\273\320\260\320\264\320\265", nullptr));
        addBtn_2->setText(QApplication::translate("WinDBshow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        delBtn_2->setText(QApplication::translate("WinDBshow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("WinDBshow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \321\202\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\265", nullptr));
        addBtn_3->setText(QApplication::translate("WinDBshow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        delBtn_3->setText(QApplication::translate("WinDBshow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("WinDBshow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\262\320\276\320\264\320\270\321\202\320\265\320\273\321\217\321\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WinDBshow: public Ui_WinDBshow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDBSHOW_H
