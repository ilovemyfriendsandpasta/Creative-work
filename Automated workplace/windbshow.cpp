#include "windbshow.h"
#include "ui_windbshow.h"

WinDBshow::WinDBshow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinDBshow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE"); //подключение драйвера SQL
    db.setDatabaseName("./InfSklad.db"); //создаем БД в папке с проектом
    if (db.open()){
        qDebug("open");
    }
    else{
        qDebug("no open");
    }

    query = new QSqlQuery(db);
    query->exec("CREATE TABLE InfSklad(Название text, Количество int, 'Веc (единица)' int, 'Общий вес' float);");


    model = new QSqlTableModel(this, db);
    model->setTable("InfSklad");
    model->select();
    ui->tableView_Sklad->setModel(model);
    ui->tableView_Sklad->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableView_Sklad->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableView_Sklad->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableView_Sklad->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
}

WinDBshow::~WinDBshow()
{
    delete ui;
}

void WinDBshow::on_tabWidget_currentChanged(int index)
{
    if (index == 0){
        db = QSqlDatabase::addDatabase("QSQLITE"); //подключение драйвера SQL
        db.setDatabaseName("./InfSklad.db"); //создаем БД в папке с проектом
        if (db.open()){
            qDebug("open");
        }
        else{
            qDebug("no open");
        }

        query = new QSqlQuery(db);
        query->exec("CREATE TABLE InfSklad(Название text, Количество int, 'Веc (единица)' int, 'Общий вес' float);");


        model = new QSqlTableModel(this, db);
        model->setTable("InfSklad");
        model->select();
        ui->tableView_Sklad->setModel(model);
        ui->tableView_Sklad->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
        ui->tableView_Sklad->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
        ui->tableView_Sklad->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
        ui->tableView_Sklad->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
        return;
    }
    if (index == 1){
        db2 = QSqlDatabase::addDatabase("QSQLITE"); //подключение драйвера SQL
        db2.setDatabaseName("./InfSklad.db"); //создаем БД в папке с проектом
        if (db2.open()){
            qDebug("open");
        }
        else{
            qDebug("no open");
        }

        query2 = new QSqlQuery(db2);
        query2->exec("CREATE TABLE InfTransport("
                    "id INT, "
                    "'ФИО Водителя', "
                    "'Номер ТС' text, "
                    "'Модель ТС' text, "
                    "'Грузоподъемность' int);");


        model2 = new QSqlTableModel(this, db2);
        model2->setTable("InfTransport");
        model2->select();
        ui->tableView_Transport->setModel(model2);
        ui->tableView_Transport->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
        ui->tableView_Transport->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
        ui->tableView_Transport->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
        ui->tableView_Transport->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
        ui->tableView_Transport->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
        return;
    }
    if (index == 2){
        db3 = QSqlDatabase::addDatabase("QSQLITE"); //подключение драйвера SQL
        db3.setDatabaseName("./InfSklad.db"); //создаем БД в папке с проектом
        if (db3.open()){
            qDebug("open");
        }
        else{
            qDebug("no open");
        }

        query3 = new QSqlQuery(db3);
        query3->exec("CREATE TABLE InfDrivers("
                    "id INT,"
                    "'ФИО Водителя' text, "
                    "'Номер ТС' text, "
                    "'Текущее местоположение' text, "
                    "'Товары' text);");


        model3 = new QSqlTableModel(this, db3);
        model3->setTable("InfDrivers");
        model3->select();
        ui->tableView_Drivers->setModel(model3);
        ui->tableView_Drivers->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
        ui->tableView_Drivers->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
        ui->tableView_Drivers->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
        ui->tableView_Drivers->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
        ui->tableView_Drivers->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
    }
}


void WinDBshow::on_addBtn_clicked()
{
    model->insertRow(model->rowCount());
}


void WinDBshow::on_delBtn_clicked()
{
    model->removeRow(row);
}


void WinDBshow::on_addBtn_2_clicked()
{
    model2->insertRow(model2->rowCount());
}


void WinDBshow::on_delBtn_2_clicked()
{
    model2->removeRow(row2);
}


void WinDBshow::on_addBtn_3_clicked()
{
    model3->insertRow(model3->rowCount());
}


void WinDBshow::on_delBtn_3_clicked()
{
    model3->removeRow(row3);
}


void WinDBshow::on_tableView_Sklad_clicked(const QModelIndex &index)
{
    row = index.row();
}


void WinDBshow::on_tableView_Transport_clicked(const QModelIndex &index)
{
    row2 = index.row();
}


void WinDBshow::on_tableView_Drivers_clicked(const QModelIndex &index)
{
    row3 = index.row();
}

