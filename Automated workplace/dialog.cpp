#include "dialog.h"
#include "ui_dialog.h"

DialogWin::DialogWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    time["Москва"] = "≈ 16ч";
    time["Санкт-Петербург"] = "≈ 23ч";
    time["Нижний Новгород"] = "≈ 13ч";
    time["Волгоград"] = "≈ 22ч";
    time["Краснодар"] = "≈ 1дн., 5ч";
    time["Самара"] = "≈ 12ч";
    time[""] = "";
}

DialogWin::~DialogWin()
{
    delete ui;
}

void DialogWin::data_to_dialog(QString from, QString to, QString type_transport, QString money, QString cargo)
{
    ui->InfoLabel->setText("Откуда: " + from + "\nКуда: " + to + "\nТип транспорта: "
                           + type_transport + "\nВид груза: " + cargo + "\nВремя доставки: " + time[to] + "\nСумма заказа: " + money);
    data_from = from; data_to = to; data_transport = type_transport; data_money = money; data_cargo = cargo;
    qDebug() << data_from << data_to << data_transport << data_money;
    db = QSqlDatabase::addDatabase("QSQLITE"); //подключение драйвера SQL
    db.setDatabaseName("./DataZakaz.db"); //создаем БД в папке с проектом
    if (db.open()){
        qDebug("База данных запустилась");
    }
    else{
        qDebug("no open");
    }

    query = new QSqlQuery(db);
    query->exec("CREATE TABLE ZakazDB (FromPlace text, ToPlace text, Transport text, Amount text, TypeOfCargo text);");
}

void DialogWin::on_Sell_Btn_clicked()
{
    qDebug() << query->lastError() << db.lastError();
    query->exec("CREATE TABLE ZakazDB (FromPlace text, ToPlace text, Transport text, Amount text, TypeOfCargo text);");
    //    qDebug() << query->lastError() << db.lastError();
    query->prepare("INSERT INTO ZakazDB (FromPlace, ToPlace, Transport, Amount, TypeOfCargo) VALUES (:From, :To, :Transport, :Amount, :TypeOfCargo)");
    qDebug() << query->lastError() << db.lastError();

    // Задаем значения для параметров запроса
    query->bindValue(":From", data_from);
    query->bindValue(":To", data_to);
    query->bindValue(":Transport", data_transport);
    query->bindValue(":Amount", data_money);
    query->bindValue(":TypeOfCargo", data_cargo);
    if (!query->exec()) {
        qDebug() << "Ошибка при выполнении запроса:" << query->lastError().text();
    }
    QMessageBox::information(this, "Статус заказа", "Заказ успешно оформлен!");
}

