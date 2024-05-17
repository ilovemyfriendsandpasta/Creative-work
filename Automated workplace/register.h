#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include<QMessageBox>
#include"mainwindow.h"

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();
signals:
    void signalDB(QString a, QString b, QString s, QString n, QString p);
private slots:
    void on_RegistrationBtn_clicked();

    void on_pushButton_clicked();

private:
    Ui::Register *ui;
    MainWindow* window;
};

#endif // REGISTER_H
