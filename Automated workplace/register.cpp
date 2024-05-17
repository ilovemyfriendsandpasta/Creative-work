#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    window = new MainWindow;
    connect(this, &Register::signalDB, window, &MainWindow::slot_to_push_DB);
}

Register::~Register()
{
    delete ui;
}

void Register::on_RegistrationBtn_clicked()
{
    emit signalDB(ui->Login->text(), ui->Password->text(), ui->Surname->text(), ui->Name->text(), ui->Patronymic->text());
    QMessageBox::information(this, "Регистрация", "Вы успешно зарегистрировались!");
}


void Register::on_pushButton_clicked()
{
    MainWindow* window_authoriztion = new MainWindow;
    window_authoriztion->show();
    this->close();
}

