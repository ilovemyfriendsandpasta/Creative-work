#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QMessageBox>
#include<QSqlQuery>
#include<QSqlError>
#include<QDebug>
#include<QSqlDatabase>
#include<QMap>

namespace Ui {
class Dialog;
}

class DialogWin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogWin(QWidget *parent = nullptr);
    ~DialogWin();
public slots:
    void data_to_dialog(QString from, QString to, QString type_transport, QString money, QString cargo);
signals:
    void signal_to_push_data_db(QString from, QString to, QString type_transport, QString money);
private slots:
    void on_Sell_Btn_clicked();

private:
    Ui::Dialog *ui;
    QString data_from;
    QString data_to;
    QString data_transport;
    QString data_money;
    QString data_cargo;

    QSqlDatabase db;
    QSqlQuery *query;

    QMap<QString, QString> time;

};

#endif // DIALOG_H
