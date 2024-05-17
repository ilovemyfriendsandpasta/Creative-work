#ifndef WINDBSHOW_H
#define WINDBSHOW_H

#include <QDialog>
#include<QSqlDatabase>
#include<QSqlTableModel>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlError>

namespace Ui {
class WinDBshow;
}

class WinDBshow : public QDialog
{
    Q_OBJECT

public:
    explicit WinDBshow(QWidget *parent = nullptr);
    ~WinDBshow();

private slots:
    void on_tabWidget_currentChanged(int index);

    void on_addBtn_clicked();

    void on_delBtn_clicked();

    void on_addBtn_2_clicked();

    void on_delBtn_2_clicked();

    void on_addBtn_3_clicked();

    void on_delBtn_3_clicked();

    void on_tableView_Sklad_clicked(const QModelIndex &index);

    void on_tableView_Transport_clicked(const QModelIndex &index);

    void on_tableView_Drivers_clicked(const QModelIndex &index);

private:
    Ui::WinDBshow *ui;

    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;

    QSqlDatabase db2;
    QSqlQuery *query2;
    QSqlTableModel *model2;

    QSqlDatabase db3;
    QSqlQuery *query3;
    QSqlTableModel *model3;

    int row; //номер активной строки
    int row2; //номер активной строки
    int row3; //номер активной строки
};

#endif // WINDBSHOW_H
