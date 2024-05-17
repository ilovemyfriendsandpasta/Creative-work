/********************************************************************************
** Form generated from reading UI file 'secondwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecondWindow
{
public:
    QGridLayout *gridLayout;
    QTabWidget *TabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_6;
    QTextEdit *textEdit_2;
    QWidget *tabTransport;
    QGridLayout *gridLayout_3;
    QTableView *tableView_Transport;
    QPushButton *addBtn_2;
    QPushButton *delBtn_2;
    QWidget *tabDrivers;
    QGridLayout *gridLayout_2;
    QPushButton *ZakazBtn;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *switchCityComboBox;
    QLabel *distLabel;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QComboBox *TransportComboBox;
    QSpacerItem *horizontalSpacer;
    QLabel *weightLabel;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QVBoxLayout *verticalLayout;
    QComboBox *vidGryza_combobox;
    QLabel *helpLabel;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *EndValue;
    QLabel *SumSell;
    QSpacerItem *horizontalSpacer_4;
    QWidget *tabChat;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton;
    QLineEdit *nickname_lineEdit;
    QTextBrowser *textBrowser;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *SecondWindow)
    {
        if (SecondWindow->objectName().isEmpty())
            SecondWindow->setObjectName(QString::fromUtf8("SecondWindow"));
        SecondWindow->resize(800, 600);
        QFont font;
        font.setFamily(QString::fromUtf8("Calibri"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        SecondWindow->setFont(font);
        SecondWindow->setStyleSheet(QString::fromUtf8("SecondWindow{\n"
"	background-color:rgb(166,227,233);\n"
"}"));
        gridLayout = new QGridLayout(SecondWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        TabWidget = new QTabWidget(SecondWindow);
        TabWidget->setObjectName(QString::fromUtf8("TabWidget"));
        TabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane\n"
"{\n"
"	border: 1px;\n"
"	background: rgb(203,241,245);\n"
"}\n"
"QTabBar::tab\n"
"{\n"
"	background:rgb(203,241,245)\n"
"}\n"
"QTabBar::tab:selected\n"
"{\n"
"	background:rgb(227,253,253)\n"
"}\n"
"\n"
"QTabBar::tab:hover\n"
"{\n"
"	background:rgb(127,255,212)\n"
"}"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_6 = new QGridLayout(tab);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        textEdit_2 = new QTextEdit(tab);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Verdana"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        textEdit_2->setFont(font1);

        gridLayout_6->addWidget(textEdit_2, 0, 0, 1, 1);

        TabWidget->addTab(tab, QString());
        tabTransport = new QWidget();
        tabTransport->setObjectName(QString::fromUtf8("tabTransport"));
        gridLayout_3 = new QGridLayout(tabTransport);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tableView_Transport = new QTableView(tabTransport);
        tableView_Transport->setObjectName(QString::fromUtf8("tableView_Transport"));
        tableView_Transport->horizontalHeader()->setMinimumSectionSize(31);

        gridLayout_3->addWidget(tableView_Transport, 0, 0, 1, 2);

        addBtn_2 = new QPushButton(tabTransport);
        addBtn_2->setObjectName(QString::fromUtf8("addBtn_2"));

        gridLayout_3->addWidget(addBtn_2, 1, 0, 1, 1);

        delBtn_2 = new QPushButton(tabTransport);
        delBtn_2->setObjectName(QString::fromUtf8("delBtn_2"));

        gridLayout_3->addWidget(delBtn_2, 1, 1, 1, 1);

        TabWidget->addTab(tabTransport, QString());
        tabDrivers = new QWidget();
        tabDrivers->setObjectName(QString::fromUtf8("tabDrivers"));
        gridLayout_2 = new QGridLayout(tabDrivers);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        ZakazBtn = new QPushButton(tabDrivers);
        ZakazBtn->setObjectName(QString::fromUtf8("ZakazBtn"));
        ZakazBtn->setMinimumSize(QSize(150, 30));

        gridLayout_2->addWidget(ZakazBtn, 2, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(tabDrivers);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setPointSize(12);
        label_2->setFont(font2);

        horizontalLayout->addWidget(label_2);

        comboBox = new QComboBox(tabDrivers);
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(tabDrivers);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font2);

        horizontalLayout_3->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        switchCityComboBox = new QComboBox(tabDrivers);
        switchCityComboBox->addItem(QString());
        switchCityComboBox->addItem(QString());
        switchCityComboBox->addItem(QString());
        switchCityComboBox->addItem(QString());
        switchCityComboBox->addItem(QString());
        switchCityComboBox->addItem(QString());
        switchCityComboBox->addItem(QString());
        switchCityComboBox->setObjectName(QString::fromUtf8("switchCityComboBox"));

        horizontalLayout_2->addWidget(switchCityComboBox);

        distLabel = new QLabel(tabDrivers);
        distLabel->setObjectName(QString::fromUtf8("distLabel"));
        QFont font3;
        font3.setPointSize(14);
        distLabel->setFont(font3);

        horizontalLayout_2->addWidget(distLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(tabDrivers);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);

        horizontalLayout_4->addWidget(label_3);

        TransportComboBox = new QComboBox(tabDrivers);
        TransportComboBox->addItem(QString());
        TransportComboBox->addItem(QString());
        TransportComboBox->addItem(QString());
        TransportComboBox->setObjectName(QString::fromUtf8("TransportComboBox"));

        horizontalLayout_4->addWidget(TransportComboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        weightLabel = new QLabel(tabDrivers);
        weightLabel->setObjectName(QString::fromUtf8("weightLabel"));

        horizontalLayout_4->addWidget(weightLabel);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(tabDrivers);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_5->addWidget(label_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        vidGryza_combobox = new QComboBox(tabDrivers);
        vidGryza_combobox->addItem(QString());
        vidGryza_combobox->addItem(QString());
        vidGryza_combobox->addItem(QString());
        vidGryza_combobox->addItem(QString());
        vidGryza_combobox->addItem(QString());
        vidGryza_combobox->addItem(QString());
        vidGryza_combobox->addItem(QString());
        vidGryza_combobox->addItem(QString());
        vidGryza_combobox->setObjectName(QString::fromUtf8("vidGryza_combobox"));

        verticalLayout->addWidget(vidGryza_combobox);

        helpLabel = new QLabel(tabDrivers);
        helpLabel->setObjectName(QString::fromUtf8("helpLabel"));
        QFont font4;
        font4.setPointSize(10);
        helpLabel->setFont(font4);
        helpLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(helpLabel);


        horizontalLayout_5->addLayout(verticalLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_5);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        EndValue = new QLabel(tabDrivers);
        EndValue->setObjectName(QString::fromUtf8("EndValue"));
        EndValue->setFont(font2);

        horizontalLayout_6->addWidget(EndValue);

        SumSell = new QLabel(tabDrivers);
        SumSell->setObjectName(QString::fromUtf8("SumSell"));
        SumSell->setFont(font2);

        horizontalLayout_6->addWidget(SumSell);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        gridLayout_2->addLayout(horizontalLayout_6, 1, 0, 1, 2);

        TabWidget->addTab(tabDrivers, QString());
        tabChat = new QWidget();
        tabChat->setObjectName(QString::fromUtf8("tabChat"));
        gridLayout_4 = new QGridLayout(tabChat);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        pushButton = new QPushButton(tabChat);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_4->addWidget(pushButton, 0, 0, 1, 1);

        nickname_lineEdit = new QLineEdit(tabChat);
        nickname_lineEdit->setObjectName(QString::fromUtf8("nickname_lineEdit"));

        gridLayout_4->addWidget(nickname_lineEdit, 0, 1, 1, 1);

        textBrowser = new QTextBrowser(tabChat);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout_4->addWidget(textBrowser, 1, 0, 1, 2);

        lineEdit = new QLineEdit(tabChat);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_4->addWidget(lineEdit, 2, 0, 1, 2);

        pushButton_2 = new QPushButton(tabChat);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_4->addWidget(pushButton_2, 2, 3, 1, 1);

        pushButton_3 = new QPushButton(tabChat);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Calibri"));
        font5.setPointSize(10);
        font5.setBold(false);
        font5.setWeight(50);
        pushButton_3->setFont(font5);

        gridLayout_4->addWidget(pushButton_3, 0, 3, 1, 1);

        TabWidget->addTab(tabChat, QString());

        gridLayout->addWidget(TabWidget, 0, 0, 1, 1);


        retranslateUi(SecondWindow);

        TabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SecondWindow);
    } // setupUi

    void retranslateUi(QDialog *SecondWindow)
    {
        SecondWindow->setWindowTitle(QApplication::translate("SecondWindow", "\320\220\320\262\321\202\320\276\320\241\320\272\320\273\320\260\320\264", nullptr));
        textEdit_2->setHtml(QApplication::translate("SecondWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Verdana'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">TransMove Logistics</span> - \321\215\321\202\320\276 \320\272\321\200\321\203\320\277\320\275\320\260\321\217 \320\273\320\276\320\263\320\270\321\201\321\202\320\270\321\207\320\265\321\201\320\272\320\260\321\217 \320\272\320\276\320\274\320\277\320\260\320\275\320\270\321\217 \321\201 \321\204\320\276\320\272\321\203\321\201\320\276\320\274 \320\275\320\260 \321\200\321\213\320\275\320\272\320\265 \320\240\320\276\321\201\321\201\320\270\320\270. \320\235\320\260\321\210\320\260 \320\272\320\276\320\274\320\277\320\260\320\275"
                        "\320\270\321\217 \321\201\320\277\320\265\321\206\320\270\320\260\320\273\320\270\320\267\320\270\321\200\321\203\320\265\321\202\321\201\321\217 \320\275\320\260 \320\276\321\200\320\263\320\260\320\275\320\270\320\267\320\260\321\206\320\270\320\270 \320\263\321\200\321\203\320\267\320\276\320\277\320\265\321\200\320\265\320\262\320\276\320\267\320\276\320\272 \320\270 \320\273\320\276\320\263\320\270\321\201\321\202\320\270\321\207\320\265\321\201\320\272\320\270\321\205 \321\200\320\265\321\210\320\265\320\275\320\270\320\271 \320\262\320\275\321\203\321\202\321\200\320\270 \321\201\321\202\321\200\320\260\320\275\321\213, \321\201\321\202\321\200\320\265\320\274\321\217\321\201\321\214 \320\276\320\261\320\265\321\201\320\277\320\265\321\207\320\270\321\202\321\214 \321\215\321\204\321\204\320\265\320\272\321\202\320\270\320\262\320\275\321\213\320\265 \320\270 \320\270\320\275\320\275\320\276\320\262\320\260\321\206\320\270\320\276\320\275\320\275\321\213\320\265 \320\273\320\276\320\263\320\270\321\201\321"
                        "\202\320\270\321\207\320\265\321\201\320\272\320\270\320\265 \321\201\320\265\321\200\320\262\320\270\321\201\321\213. </p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" text-decoration: underline;\">\320\243\321\201\320\273\321\203\320\263\320\270: </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1. \320\222\320\275\321\203\321\202\321\200\320\265\320\275\320\275\320\270\320\265 \320\263\321\200\321\203\320\267\320\276\320\277\320\265\321\200\320\265\320\262\320\276\320\267\320\272\320\270: \320\235\320\260\320\264\320\265\320\266\320\275\320\276\320\265 \321\202\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\320\275"
                        "\320\270\320\265 \320\263\321\200\321\203\320\267\320\276\320\262 \320\277\320\276 \320\262\321\201\320\265\320\271 \321\202\320\265\321\200\321\200\320\270\321\202\320\276\321\200\320\270\320\270 \320\240\320\276\321\201\321\201\320\270\320\270. </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">2. \320\241\320\276\320\262\321\200\320\265\320\274\320\265\320\275\320\275\321\213\320\265 \321\201\320\272\320\273\320\260\320\264\321\201\320\272\320\270\320\265 \321\203\321\201\320\273\321\203\320\263\320\270 \320\270 \321\201\320\270\321\201\321\202\320\265\320\274\321\213 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217 \320\267\320\260\320\277\320\260\321\201\320\260\320\274\320\270. </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">3. \320\233\320\276\320\263\320\270\321\201\321\202\320\270\320\272\320\260 \320\270 \320\274"
                        "\320\260\321\200\321\210\321\200\321\203\321\202\320\270\320\267\320\260\321\206\320\270\321\217: \320\237\320\273\320\260\320\275\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\276\320\277\321\202\320\270\320\274\320\260\320\273\321\214\320\275\321\213\321\205 \320\274\320\260\321\200\321\210\321\200\321\203\321\202\320\276\320\262 \320\270 \320\276\320\261\321\201\320\273\321\203\320\266\320\270\320\262\320\260\320\275\320\270\320\265 \320\277\320\276\321\201\321\202\320\260\320\262\320\276\320\272. </p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" text-decoration: underline;\">\320\246\320\265\320\275\320\275\320\276\321\201\321\202\320\270 \320\272\320\276\320\274\320\277\320\260\320\275\320\270\320\270: </span></p>\n"
"<p style=\" m"
                        "argin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1. \320\235\320\260\320\264\320\265\320\266\320\275\320\276\321\201\321\202\321\214: \320\223\320\260\321\200\320\260\320\275\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\275\320\276\320\265 \320\272\320\260\321\207\320\265\321\201\321\202\320\262\320\276 \320\270 \321\201\320\262\320\276\320\265\320\262\321\200\320\265\320\274\320\265\320\275\320\275\320\276\321\201\321\202\321\214 \320\277\320\276\321\201\321\202\320\260\320\262\320\276\320\272.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">2. \320\223\320\270\320\261\320\272\320\276\321\201\321\202\321\214: \320\223\320\270\320\261\320\272\320\270\320\265 \321\200\320\265\321\210\320\265\320\275\320\270\321\217 \320\270 \320\277\320\265\321\200\321\201\320\276\320\275\320\260\320\273\320\270\320\267\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321"
                        "\213\320\271 \320\277\320\276\320\264\321\205\320\276\320\264 \320\272 \320\272\320\273\320\270\320\265\320\275\321\202\320\260\320\274. </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">3. \320\237\321\200\320\276\321\204\320\265\321\201\321\201\320\270\320\276\320\275\320\260\320\273\320\270\320\267\320\274: \320\236\320\277\321\213\321\202\320\275\321\213\320\265 \321\201\320\277\320\265\321\206\320\270\320\260\320\273\320\270\321\201\321\202\321\213 \320\270 \320\272\320\276\320\274\320\260\320\275\320\264\320\260 \320\273\320\276\320\263\320\270\321\201\321\202\320\276\320\262 \320\264\320\273\321\217 \321\200\320\265\321\210\320\265\320\275\320\270\321\217 \320\273\321\216\320\261\321\213\321\205 \320\267\320\260\320\264\320\260\321\207.</p></body></html>", nullptr));
        TabWidget->setTabText(TabWidget->indexOf(tab), QApplication::translate("SecondWindow", "\320\236 \320\232\320\276\320\274\320\277\320\260\320\275\320\270\320\270", nullptr));
        addBtn_2->setText(QApplication::translate("SecondWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        delBtn_2->setText(QApplication::translate("SecondWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        TabWidget->setTabText(TabWidget->indexOf(tabTransport), QApplication::translate("SecondWindow", "\320\227\320\260\320\272\320\260\320\267\321\213", nullptr));
        ZakazBtn->setText(QApplication::translate("SecondWindow", "\320\241\320\264\320\265\320\273\320\260\321\202\321\214 \320\267\320\260\320\272\320\260\320\267", nullptr));
        label_2->setText(QApplication::translate("SecondWindow", "\320\236\321\202\320\272\321\203\320\264\320\260 \320\264\320\276\321\201\321\202\320\260\320\262\320\270\321\202\321\214:", nullptr));
        comboBox->setItemText(0, QApplication::translate("SecondWindow", "\320\237\320\265\321\200\320\274\321\214", nullptr));

        label->setText(QApplication::translate("SecondWindow", "\320\232\321\203\320\264\320\260 \320\264\320\276\321\201\321\202\320\260\320\262\320\270\321\202\321\214:", nullptr));
        switchCityComboBox->setItemText(0, QString());
        switchCityComboBox->setItemText(1, QApplication::translate("SecondWindow", "\320\234\320\276\321\201\320\272\320\262\320\260", nullptr));
        switchCityComboBox->setItemText(2, QApplication::translate("SecondWindow", "\320\241\320\260\320\275\320\272\321\202-\320\237\320\265\321\202\320\265\321\200\320\261\321\203\321\200\320\263", nullptr));
        switchCityComboBox->setItemText(3, QApplication::translate("SecondWindow", "\320\235\320\270\320\266\320\275\320\270\320\271 \320\235\320\276\320\262\320\263\320\276\321\200\320\276\320\264", nullptr));
        switchCityComboBox->setItemText(4, QApplication::translate("SecondWindow", "\320\241\320\260\320\274\320\260\321\200\320\260", nullptr));
        switchCityComboBox->setItemText(5, QApplication::translate("SecondWindow", "\320\222\320\276\320\273\320\263\320\276\320\263\321\200\320\260\320\264", nullptr));
        switchCityComboBox->setItemText(6, QApplication::translate("SecondWindow", "\320\232\321\200\320\260\321\201\320\275\320\276\320\264\320\260\321\200", nullptr));

        distLabel->setText(QApplication::translate("SecondWindow", "0 \320\272\320\274", nullptr));
        label_3->setText(QApplication::translate("SecondWindow", "\320\242\320\270\320\277 \321\202\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\260:", nullptr));
        TransportComboBox->setItemText(0, QString());
        TransportComboBox->setItemText(1, QApplication::translate("SecondWindow", "\320\233\320\265\320\263\320\272\320\276\320\262\320\276\320\271 \320\260\320\262\321\202\320\276\320\274\320\276\320\261\320\270\320\273\321\214", nullptr));
        TransportComboBox->setItemText(2, QApplication::translate("SecondWindow", "\320\223\321\200\321\203\320\267\320\276\320\262\320\276\320\271 \320\260\320\262\321\202\320\276\320\274\320\276\320\261\320\270\320\273\321\214", nullptr));

        weightLabel->setText(QString());
        label_4->setText(QApplication::translate("SecondWindow", "\320\222\320\270\320\264 \320\263\321\200\321\203\320\267\320\260: ", nullptr));
        vidGryza_combobox->setItemText(0, QString());
        vidGryza_combobox->setItemText(1, QApplication::translate("SecondWindow", "\320\235\320\260\321\201\321\213\320\277\320\275\321\213\320\265", nullptr));
        vidGryza_combobox->setItemText(2, QApplication::translate("SecondWindow", "\320\237\320\276\321\200\320\276\321\210\320\272\320\276\320\276\320\261\321\200\320\260\320\267\320\275\321\213\320\265", nullptr));
        vidGryza_combobox->setItemText(3, QApplication::translate("SecondWindow", "\320\235\320\260\320\273\320\270\320\262\320\275\321\213\320\265", nullptr));
        vidGryza_combobox->setItemText(4, QApplication::translate("SecondWindow", "\320\223\320\260\320\267\320\276\320\276\320\261\321\200\320\260\320\267\320\275\321\213\320\265", nullptr));
        vidGryza_combobox->setItemText(5, QApplication::translate("SecondWindow", "\320\250\321\202\321\203\321\207\320\275\321\213\320\265", nullptr));
        vidGryza_combobox->setItemText(6, QApplication::translate("SecondWindow", "\320\241\320\272\320\276\321\200\320\276\320\277\320\276\321\200\321\202\321\217\321\211\320\270\320\265\321\201\321\217", nullptr));
        vidGryza_combobox->setItemText(7, QApplication::translate("SecondWindow", "\320\236\320\277\320\260\321\201\320\275\321\213\320\265", nullptr));

        helpLabel->setText(QString());
        EndValue->setText(QApplication::translate("SecondWindow", "\320\230\321\202\320\276\320\263\320\276\320\262\320\260\321\217 \321\201\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214:", nullptr));
        SumSell->setText(QApplication::translate("SecondWindow", "0", nullptr));
        TabWidget->setTabText(TabWidget->indexOf(tabDrivers), QApplication::translate("SecondWindow", "\320\241\320\264\320\265\320\273\320\260\321\202\321\214 \320\267\320\260\320\272\320\260\320\267", nullptr));
        pushButton->setText(QApplication::translate("SecondWindow", "connect", nullptr));
        pushButton_2->setText(QApplication::translate("SecondWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_3->setText(QApplication::translate("SecondWindow", "C\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265\n"
" \321\201\320\272\320\273\320\260\320\264\320\260", nullptr));
        TabWidget->setTabText(TabWidget->indexOf(tabChat), QApplication::translate("SecondWindow", "\320\247\320\260\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecondWindow: public Ui_SecondWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H
