#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include<QSqlDatabase>
#include<QSqlTableModel>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlError>
#include<QTableView>
#include<QTcpSocket>
#include<QTime>
#include<QMap>
#include <QFile>
#include <QTextStream>
#include"server.h"
#include"dialog.h"
#include"windbshow.h"

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();
public slots:
    void proof_login_and_password(QString a, QString b);
    //void push_data_to_db_zakaz(QString from, QString to, QString type_transport, QString money);
    void push_name_to_second_window(QString s, QString n, QString p);
signals:
    void signal_data_to_dialog(QString from, QString to, QString type_transport, QString money, QString cargo);
private slots:
    void on_addBtn_clicked();

    void on_delBtn_clicked();

    void on_tableView_Sklad_clicked(const QModelIndex &index);

    void on_addBtn_2_clicked();

    void on_delBtn_2_clicked();

    void on_tableView_Transport_clicked(const QModelIndex &index);

    void on_TabWidget_currentChanged(int index);

    void on_pushButton_clicked();
    void slotReadyRead();

    void on_pushButton_2_clicked();

    void on_lineEdit_returnPressed();

    void on_pushButton_3_clicked();

    void on_switchCityComboBox_activated(const QString &arg1);

    void on_TransportComboBox_activated(int index);

    void on_ZakazBtn_clicked();

    void on_vidGryza_combobox_activated(const QString &arg1);

private:
    Ui::SecondWindow *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;

    QSqlDatabase db2;
    QSqlQuery *query2;
    QSqlTableModel *model2;

    QSqlDatabase db3;
    QSqlQuery *query3;
    QSqlTableModel *model3;

    QMap<QString, QString> dist;

    int row; //номер активной строки
    int row2; //номер активной строки
    int row3; //номер активной строки
//***********Сервер**************//
    QTcpSocket* socket;
    QByteArray Data;
    void SendToServer(QString str);
    quint16 nextBlockSize;
    QString rem_nickname;
//******************************//
    double sum = 0;
    bool flag = false;
    bool sup = false;

    DialogWin *dialog_window;

};

#endif // SECONDWINDOW_H
