#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QSqlDatabase>
#include<QSqlTableModel>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlError>
#include<QTableView>
#include<QTcpSocket>
#include"secondwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void slot_to_push_DB(QString a, QString b, QString s, QString n, QString p);

    void on_ButtonLogin_clicked();


    void on_RegisterBtn_clicked();
signals:
    void signal_proof_login_and_password(QString a, QString b);
    void signal_push_name_to_second_window(QString s, QString n, QString p);
private:
    Ui::MainWindow *ui;
    SecondWindow* win;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;

};
#endif // MAINWINDOW_H
