#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    dialog_window = new DialogWin;
    connect(this, &SecondWindow::signal_data_to_dialog, dialog_window, &DialogWin::data_to_dialog);
    this->setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint);
    dist["Москва"] = "1470";
    dist["Санкт-Петербург"] = "1496";
    dist["Нижний Новгород"] = "762";
    dist["Волгоград"] = "1292";
    dist["Краснодар"] = "1864";
    dist["Самара"] = "660";
    dist[""] = "";
    ui->pushButton_3->hide();
    ui->nickname_lineEdit->hide();
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::proof_login_and_password(QString a, QString b)
{
    if (a == "sup" && b == "sup"){
        sup = true;
    }
}

//void SecondWindow::push_data_to_db_zakaz(QString from, QString to, QString type_transport, QString money)
//{
//    QSqlQuery query;
//    query.prepare("SELECT * FROM ZakazDB WHERE Откуда = :Откуда and Куда = :Куда and Транспорт = :Транспорт and Сумма = :Сумма");
//    query.bindValue(":Откуда", from);
//    query.bindValue(":Куда", to);
//    query.bindValue(":Транспорт", type_transport);
//    query.bindValue(":Сумма", money);
//}

void SecondWindow::push_name_to_second_window(QString s, QString n, QString p)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./DataRegistration.db");
    if (!db.open()) {
        qDebug() << "Ошибка при открытии базы данных";
    }

    // Выполняем SQL запрос
    QSqlQuery query;
    QString sqlQuery = "SELECT * FROM RegistrationDB WHERE Login = :searchValue";
    query.prepare(sqlQuery);
    query.bindValue(":searchValue", p);

    if (!query.exec()) {
        qDebug() << "Ошибка выполнения запроса";
    }

    // Получаем данные из результата запроса
    while (query.next()) {
        QString resultColumn1 = query.value(2).toString(); // Данные первой колонки
        QString resultColumn2 = query.value(3).toString(); // Данные второй колонки
        QString resultColumn3 = query.value(4).toString(); // Данные второй колонки
        // Продолжаем получать данные из других колонок по индексу
        rem_nickname = resultColumn1 + " " + resultColumn2[0] + "." + resultColumn3[0] + ".";

        qDebug() << "Результат запроса: " << resultColumn1 << ", " << resultColumn2;
    }
}

void SecondWindow::on_addBtn_clicked()
{
    model->insertRow(model->rowCount());
}


void SecondWindow::on_delBtn_clicked()
{
    model->removeRow(row);
}


void SecondWindow::on_tableView_Sklad_clicked(const QModelIndex &index)
{
    row = index.row();
}


void SecondWindow::on_addBtn_2_clicked()
{
    model->insertRow(model->rowCount());
}


void SecondWindow::on_delBtn_2_clicked()
{
    model->removeRow(row2);
}


void SecondWindow::on_tableView_Transport_clicked(const QModelIndex &index)
{
    row2 = index.row();
}


void SecondWindow::on_TabWidget_currentChanged(int index)
{
    if (index == 0){
    }
    if (index == 1){
        db = QSqlDatabase::addDatabase("QSQLITE"); //подключение драйвера SQL
        db.setDatabaseName("./DataZakaz.db"); //создаем БД в папке с проектом
        if (db.open()){
            qDebug("open");
        }
        else{
            qDebug("no open");
        }
        query = new QSqlQuery(db);

        query->exec("CREATE TABLE ZakazDB (FromPlace text, ToPlace text, Transport text, Amount text, TypeOfCargo text);");
        model = new QSqlTableModel(this, db);
        model->setTable("ZakazDB");
        model->select();
        ui->tableView_Transport->setModel(model);
        ui->tableView_Transport->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
        ui->tableView_Transport->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
        ui->tableView_Transport->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
        ui->tableView_Transport->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    }

    if (index == 2){

    }
    if (index == 3){
        socket = new QTcpSocket(this);
        connect(socket, &QTcpSocket::readyRead,this, &SecondWindow::slotReadyRead);
        connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
        nextBlockSize = 0;
        if (sup == true){
            ui->nickname_lineEdit->hide();
            ui->pushButton_3->show();
            rem_nickname = "Техподдержка";
        }
    }
}

void SecondWindow::on_pushButton_clicked()
{
    socket->connectToHost("127.0.0.1", 2323);
}

void SecondWindow::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_12);
    if (in.status() == QDataStream::Ok){
        /*QString str;
        in >> str;
        ui->textBrowser->append(str);*/
        for (;;){
            if (nextBlockSize == 0){
                if (socket->bytesAvailable() < 2){
                    break;
                }
                in >> nextBlockSize;
            }
            if (socket->bytesAvailable() < nextBlockSize){
                break;
            }
            QString str;
            QString str2;
            QTime time;
            in >> time >> str >> str2;
            nextBlockSize = 0;
            //QString a = "admin: ";
            ui->textBrowser->append(time.toString() + " <" + str2 + "> " + str);
        }
    }
    else{
        ui->textBrowser->append("read error");
    }
}

void SecondWindow::SendToServer(QString str)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_12);
    out << qint16(0) << QTime::currentTime() << rem_nickname << str;
    out.device()->seek(0);
    out << qint16(Data.size() - sizeof(qint16));
    socket->write(Data);
    ui->lineEdit->clear();
}


void SecondWindow::on_pushButton_2_clicked()
{
    SendToServer(ui->lineEdit->text());
}


void SecondWindow::on_lineEdit_returnPressed()
{
    SendToServer(ui->lineEdit->text());
    qDebug() << ui->lineEdit->text();
}


void SecondWindow::on_pushButton_3_clicked()
{
    WinDBshow* window;
    window = new WinDBshow;
    window->show();
    this->close();
}


void SecondWindow::on_switchCityComboBox_activated(const QString &arg1)
{
    ui->distLabel->setText(dist[arg1]+ " км");
    double temp = dist[arg1].toDouble() * 20 / 100;
    sum = temp * 46.3;
    ui->SumSell->setText(QString::number(sum) +" рублей");
}


void SecondWindow::on_TransportComboBox_activated(int index)
{
    if (index == 0){
        ui->weightLabel->setText(""); return;
    }
    if (index == 1 && !flag){
        sum += 5000;
        flag = true;
    }
    if (index == 2 && flag == true){
        sum-= 5000;
        flag = false;
    }
    ui->SumSell->setText(QString::number(sum) +" рублей");
    if (index == 1){
        ui->weightLabel->setText("Грузоподъемность ≈ 500кг"); return;
    }
    if (index == 2) {
        ui->weightLabel->setText("Грузоподъемность ≈ 1500кг"); return;
    }
}


void SecondWindow::on_ZakazBtn_clicked()
{
    dialog_window->show();
    emit signal_data_to_dialog(ui->comboBox->itemText(ui->comboBox->currentIndex()),
                               ui->switchCityComboBox->itemText(ui->switchCityComboBox->currentIndex()),
                               ui->TransportComboBox->itemText(ui->TransportComboBox->currentIndex()),
                               QString::number(sum), ui->vidGryza_combobox->itemText(ui->vidGryza_combobox->currentIndex()));
}


void SecondWindow::on_vidGryza_combobox_activated(const QString &arg1)
{
    if (arg1 == "Насыпные"){
        ui->helpLabel->setText("песок, щебень, руда, т.п.");
        return;
    }
    if (arg1 == "Порошкообразные"){
        ui->helpLabel->setText("мука, цемент, известь, т.п.");
        return;
    }
    if (arg1 == "Наливные"){
        ui->helpLabel->setText("разные виды жидкостей");
        return;
    }
    if (arg1 == "Газообразные"){
        ui->helpLabel->setText("кислород, азот, пропан, т.п.");
        return;
    }
    if (arg1 == "Штучные"){
        ui->helpLabel->setText("любые товары, имеющие поштучную номенклатуру");
        return;
    }
    if (arg1 == "Скоропортящиеся"){
        ui->helpLabel->setText("любые товары, имеющие ограниченный срок годности");
        return;
    }
    if (arg1 == "Опасные"){
        ui->helpLabel->setText("любые объекты и вещества, \nпредставляющие опасность для человека или окружающей среды");
        return;
    }
    else ui->helpLabel->setText("");

}

