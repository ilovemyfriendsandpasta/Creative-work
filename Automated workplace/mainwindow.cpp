#include "mainwindow.h"
#include "ui_mainwindow.h"
#define PERCENT_OF_SCREEN (25 / 100) //чтобы окно запускалось по центру
#include<QMessageBox>
#include<QScreen>
#include"register.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    win = new SecondWindow;
    connect(this, &MainWindow::signal_proof_login_and_password, win, &SecondWindow::proof_login_and_password);
    connect(this, &MainWindow::signal_push_name_to_second_window, win, &SecondWindow::push_name_to_second_window);

    db = QSqlDatabase::addDatabase("QSQLITE"); //подключение драйвера SQL
    db.setDatabaseName("./DataRegistration.db"); //создаем БД в папке с проектом
    if (db.open()){
        qDebug("open");
    }
    else{
        qDebug("no open");
    }

    query = new QSqlQuery(db);
    query->exec("CREATE TABLE RegistrationDB('Login' text, 'Password' text,"
                "'Surname' text, 'Name' text, 'Patronymic' text);");
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ButtonLogin_clicked() //кнопка авторизации
{
    // Подготовка параметризованного запроса
        QSqlQuery query;
        query.prepare("SELECT * FROM RegistrationDB WHERE Login = :Login and Password = :Password");
        query.bindValue(":Login", ui->lineEdit->text());
        query.bindValue(":Password", ui->PasswordLine->text());

        // Выполнение запроса
        if (!query.exec()) {
            qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
        }

        // Проверка наличия результатов
        if (query.next()) {
//            StockWindow window2;
//            window2.setModal(true);
//            this->hide();
//            window2.exec();
            emit signal_proof_login_and_password(ui->lineEdit->text(), ui->PasswordLine->text());

            if (!query.exec("SELECT * FROM RegistrationDB")) {
                qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
                return;
            }
            while (query.next()) {
                QString n = query.value(2).toString(); // Получаем значение первого поля
                QString s = query.value(3).toString(); // Получаем значение второго поля
                QString p = query.value(4).toString(); // Получаем значение первого поля

                emit signal_push_name_to_second_window(n,s,ui->lineEdit->text());
            }

            QMessageBox::information(this, "Авторизация", "Вы успешно авторизовались!");
            win->show();
            this->close();
        } else {
            QMessageBox::warning(this, "Авторизация", "Неверный логин или пароль!");
        }
}




void MainWindow::on_RegisterBtn_clicked()
{
    Register windowReg;
    windowReg.setModal(true);
    this->hide();
    windowReg.exec();
}

void MainWindow::slot_to_push_DB(QString a, QString b, QString s, QString n, QString p)
{
    // Подготавливаем SQL запрос для вставки данных
    query->exec("CREATE TABLE RegistrationDB('Login' text, 'Password' text,"
                "'Surname' text, 'Name' text, 'Patronymic' text);");
    query->prepare("INSERT INTO RegistrationDB (Login, Password, Surname, Name, Patronymic) VALUES "
                   "(:Login, :Password, :Surname, :Name, :Patronymic)");

    // Задаем значения для параметров запроса
    query->bindValue(":Login", a);
    query->bindValue(":Password", b);
    query->bindValue(":Surname", s);
    query->bindValue(":Name", n);
    query->bindValue(":Patronymic", p);

    // Выполняем запрос
    if (!query->exec()) {
        qDebug() << "Ошибка при выполнении запроса:" << query->lastError().text();
    } else {
        qDebug() << "Данные успешно добавлены в таблицу!";
    }
}

