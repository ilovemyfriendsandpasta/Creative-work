#include "graph.h"
#include <QTextStream>
#include <QMessageBox>
#include <map>
#include <QDebug>

QString str;

// Создание нового объекта QGraphicsScene
Graph::Graph(QWidget *parent) : QGraphicsView(parent) {
    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-320, -320, 640, 640);
    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    scale(qreal(0.8), qreal(0.8));
    setMinimumSize(650, 650);
}

void Graph::itemMoved() {
    if(!timerId) {
        timerId = startTimer(1000 / 25);
    }
}

void Graph::timerEvent(QTimerEvent *event) {
    Q_UNUSED(event);
    const QList<QGraphicsItem *> items = scene -> items();
    for(Vertex *temp : qAsConst(vertexList)){
        temp->calculateForces();
    }
    bool itemsMoved = false;
    for(Vertex *temp : qAsConst(vertexList)){
        if(temp->advancePosition()){
            itemsMoved = true;
        }
    }

    if(!itemsMoved){
        killTimer(timerId);
        timerId = 0;
    }
}

// Рисование сцены
void Graph::drawBackground(QPainter *painter, const QRectF &rect) {
    Q_UNUSED(rect);

    // Определение новых размеров сцены
    QRectF sceneRect = this->sceneRect();
    QRectF newSceneRect = QRectF(sceneRect.x(), sceneRect.y(), 650, 650);

    // Рисуем фон сцены
    painter->fillRect(newSceneRect, Qt::white);

    // Создание виджета в области rect
    createTabWidget(rect);
}

void Graph::createTabWidget(const QRectF &rect) {
    Q_UNUSED(rect);

    QRectF sceneRect = this->sceneRect();

    QWidget *commandsWidget = new QWidget;
    int xPosition = sceneRect.left() - 30;  // Отступ по оси X
    int yPosition = sceneRect.top() + 30;   // Отступ по оси Y

    commandsWidget->setGeometry(xPosition - 25, yPosition, sceneRect.width() / 5, sceneRect.height() - 50);

    // Устанавливаем стиль виджета с белым фоном без границы
    commandsWidget->setStyleSheet("background-color: white;");

    QVBoxLayout *vertexTabLayout = new QVBoxLayout(commandsWidget);

    QFont textFont;
    textFont.setPointSize(12);  // Размер шрифта кнопок

    // Создаем текстовую метку "Работа с вершинами"
    QLabel *verticesLabel = new QLabel("Работа с вершинами:");
    QFont boldItalicFont2;
    boldItalicFont2.setPointSize(12);
    boldItalicFont2.setBold(true);  // Жирный шрифт
    boldItalicFont2.setStyle(QFont::StyleItalic);  // Курсивный текст
    verticesLabel->setFont(boldItalicFont2);
    verticesLabel->setAlignment(Qt::AlignLeft);
    verticesLabel->setFixedSize(250, 30);  // Размер метки
    vertexTabLayout->addWidget(verticesLabel);

    QPushButton *addVertexButton = new QPushButton("Добавить вершину");
    addVertexButton->setFont(textFont);
    addVertexButton->setMaximumSize(QSize(200, 40));
    vertexTabLayout->addWidget(addVertexButton);
    connect(addVertexButton, &QPushButton::clicked, this, &Graph::insertVertex);

    // Кнопка "Удалить вершину"
    QPushButton *eraseVertexButton = new QPushButton("Удалить вершину");
    eraseVertexButton->setFont(textFont);
    eraseVertexButton->setMaximumSize(QSize(200, 40));
    vertexTabLayout->addWidget(eraseVertexButton);
    connect(eraseVertexButton, &QPushButton::clicked, this, &Graph::createEraseVertexWindow);

    // Создаем текстовую метку "Работа с ребрами"
    QLabel *edgesLabel = new QLabel("Работа с ребрами:");
    QFont boldItalicFont;
    boldItalicFont.setPointSize(12);
    boldItalicFont.setBold(true);  // Жирный шрифт
    boldItalicFont.setStyle(QFont::StyleItalic);  // Курсивный текст
    edgesLabel->setFont(boldItalicFont);
    edgesLabel->setAlignment(Qt::AlignLeft);
    edgesLabel->setFixedSize(200, 30);  // Размер метки
    vertexTabLayout->addWidget(edgesLabel);

    // Кнопка "Добавить ребро"
    QPushButton *addEdgeButton = new QPushButton("Добавить ребро");
    addEdgeButton->setFont(textFont);
    addEdgeButton->setMaximumSize(QSize(200, 40));
    vertexTabLayout->addWidget(addEdgeButton);
    connect(addEdgeButton, &QPushButton::clicked, this, &Graph::createAddEdgeWindow);

    // Кнопка "Изменить вес вершины"
    QPushButton *updateWeightButton = new QPushButton("Изменить вес");
    updateWeightButton->setFont(textFont);
    updateWeightButton->setMaximumSize(QSize(200, 40));
    vertexTabLayout->addWidget(updateWeightButton);
    connect(updateWeightButton, &QPushButton::clicked, this, &Graph::createUpdateWeightWindow);

    // Кнопка "Удалить ребро"
    QPushButton *eraseEdgeButton = new QPushButton("Удалить ребро");
    eraseEdgeButton->setFont(textFont);
    eraseEdgeButton->setMaximumSize(QSize(200, 40));
    vertexTabLayout->addWidget(eraseEdgeButton);
    connect(eraseEdgeButton, &QPushButton::clicked, this, &Graph::createEraseEdgeWindow);

    // Создаем метку "Работа с графом" с жирным курсивным текстом
    QLabel *graphLabel = new QLabel("Работа с графом:");
    QFont boldItalicFont3;
    boldItalicFont3.setPointSize(12);
    boldItalicFont3.setBold(true);  // Жирный шрифт
    boldItalicFont3.setStyle(QFont::StyleItalic);  // Курсивный текст
    graphLabel->setFont(boldItalicFont3);
    graphLabel->setAlignment(Qt::AlignLeft);
    graphLabel->setFixedSize(200, 30);  // Размер метки
    vertexTabLayout->addWidget(graphLabel);

    // Кнопка "Открыть функции"
    QPushButton *funcButton = new QPushButton("Функции");
    funcButton->setFont(textFont);
    funcButton->setMaximumSize(QSize(200, 40));
    vertexTabLayout->addWidget(funcButton);
    connect(funcButton, &QPushButton::clicked, this, &Graph::createFunctionWindow);

    // Кнопка "Матрица смежности"
    QPushButton *adjMatrixButton = new QPushButton("Матрица смежности");
    adjMatrixButton->setFont(textFont);
    adjMatrixButton->setMaximumSize(QSize(200, 40));
    vertexTabLayout->addWidget(adjMatrixButton);
    connect(adjMatrixButton, &QPushButton::clicked, this, &Graph::createAdjMatrixWindow);

    // Кнопка "Удалить граф"
    QPushButton *clearButton = new QPushButton("Удалить граф");
    clearButton->setFont(textFont);
    clearButton->setMaximumSize(QSize(200, 40));
    vertexTabLayout->addWidget(clearButton);
    connect(clearButton, &QPushButton::clicked, this, &Graph::clear);

    scene->addWidget(commandsWidget);
}

// Метод для создания окна с матрицей смежности
void Graph::createAdjMatrixWindow() {
    // Проверка наличия вершин в списке
    if(vertexList.empty()) {
        qDebug() << "Список вершин пуст!";
        return;
    }

    // Создание нового виджета таблицы QTableWidget для матрицы
    int rows = vertexList.size() + 1;
    int cols = vertexList.size() + 1;
    QTableWidget *AdjMatrixWindow = new QTableWidget(rows, cols);

    // Установка размеров столбцов и строк для заголовков матрицы
    AdjMatrixWindow->setColumnWidth(0, 30);
    AdjMatrixWindow->setRowHeight(0, 30);

    // Заполнение первой строки и столбца индексами вершин
    for (int i = 0; i < vertexList.size(); i++) {
        AdjMatrixWindow->setRowHeight(1+i, 30);
        AdjMatrixWindow->setItem(0, i+1, new QTableWidgetItem(QString::number(i)));
        AdjMatrixWindow->item(0, i+1)->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);

        AdjMatrixWindow->setItem(1+i, 0, new QTableWidgetItem(QString::number(i)));
        AdjMatrixWindow->item(1+i, 0)->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);

        // Заполнение матрицы значениями весов рёбер
        for (int j = 0; j < vertexList.size(); j++) {
            int weight = 0; // Инициализация веса нулем
            for (Edge *edge : vertexList[i]->getEdges()) {
                if (edge->destVertex()->getIndex() == j) {
                    weight = edge->getWeight(); // Если есть ребро, записываем его вес
                    break;
                }
            }
            AdjMatrixWindow->setItem(1+i, j+1, new QTableWidgetItem(QString::number(weight)));
            AdjMatrixWindow->item(1+i, j+1)->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        }

        // Установка ширины для столбцов
        AdjMatrixWindow->setColumnWidth(i+1, 30);
    }

    // Установка заголовка для окна матрицы и отображение окна
    AdjMatrixWindow->setWindowTitle("Матрица смежности");
    AdjMatrixWindow->show();
}

// Получение размера списка вершин
int Graph::getVertexNum() {
    return vertexList.size();
}

void Graph::scaleView(qreal scaleFactor) {
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if(factor < 0.07 || factor > 100){
        return;
    }
    scale(scaleFactor, scaleFactor);
}

// Вставка вершины
void Graph::insertVertex() {
    // Определение индекса новой вершины
    int vertexIndex = vertexList.size();
    // Создание новой вершины с учетом текущего индекса
    vertexList.append(new Vertex(this, vertexIndex));
    // Установка позиции новой вершины в начальные координаты (0, 0)
    vertexList[vertexIndex]->setPos(0, 0);
    // Добавление новой вершины на сцену
    scene->addItem(vertexList[vertexIndex]);
    // Увеличение счетчика количества вершин в графе
    vertexNum++;
}

// Обновление индексов вершин в графе
void Graph::updateIndex() {
    for(int i = 0; i < vertexList.size(); i++) {
        // Установка нового индекса вершины соответствующим значением в списке
        vertexList[i]->setIndex(i);
    }
}

// Удаление вершины
void Graph::eraseVertex(int vertexIndex) {
    // Получение указателя на вершину, которую необходимо удалить
    Vertex *temp = vertexList[vertexIndex];
    // Удаление всех ребер, связанных с вершиной
    for(Edge *edge : temp->getEdges()) {
        eraseEdge(vertexIndex, edge->destVertex()->getIndex());
    }
    // Очистка всех ребер, связанных с вершиной
    temp->clearEdge();
    // Удаление вершины со сцены
    scene->removeItem(temp);
    // Уменьшение общего количества рёбер в графе
    edgeNum -= vertexList[vertexIndex]->getEdges().size() * 2;
    // Удаление вершины из списка вершин по её индексу
    vertexList.erase(vertexList.begin() + vertexIndex);
    // Обновление индексов вершин после удаления
    updateIndex();
    // Уменьшение общего количества вершин в графе
    vertexNum--;
}

// Вставка ребра
void Graph::insertEdge(int source, int dest, double weight) {
    // Проверка наличия связи между вершинами
    if (checkAdjacent(source, dest)) {
        return; // Если связь уже существует, выходим из метода
    }

    // Добавление двунаправленного ребра между вершинами с весом
    scene->addItem(new Edge(vertexList[source], vertexList[dest], weight)); // Создание ребра от source к dest
    scene->addItem(new Edge(vertexList[dest], vertexList[source], weight)); // Создание ребра от dest к source
    edgeNum += 2; // Увеличение общего количества ребер в графе
}

// Изменение веса ребра
void Graph::updateWeight(int source, int dest, double weight){
    // Проверка на наличие связи между вершинами
    if (!checkAdjacent(source, dest)){ // Если вершины не соединены, выход из метода
        return;
    }

    // Обновление веса ребра у обеих вершин
    vertexList[source]->updateWeight(dest, weight); // Обновление веса у вершины source (исходная вершина)
    vertexList[dest]->updateWeight(source, weight); // Обновление веса у вершины dest (конечная вершина)
}

// Удаление ребра
void Graph::eraseEdge(int source, int dest) {
    // Проверяем наличие связи между вершинами source и dest
    if (!checkAdjacent(source, dest)) {//если вершины не соединены - выход
        return;
    }

    // Удаление ребра для начальной вершины
    for (Edge *edge : vertexList[source]->getEdges()) {
        if (edge->destVertex()->getIndex() == dest) {
            vertexList[source]->eraseEdge(dest); // Удаляем ребро
            scene->removeItem(edge); // Удаляем его графическое представление
        }
    }

    // Удаление ребра для конечной вершины
    for (Edge *edge : vertexList[dest]->getEdges()){
        if (edge->destVertex()->getIndex() == source) {
            vertexList[dest]->eraseEdge(source); // Удаляем ребро
            scene->removeItem(edge); // Удаляем его графическое представление
        }
    }

    // Уменьшение количества рёбер в графе
    edgeNum -= 2;
}

// Проверка, соединены ли вершины
bool Graph::checkAdjacent(int source, int dest) {
    return vertexList[source]->pathExist(dest); // Возвращает результат проверки наличия связи между вершинами
}

// Возвращает количество входящих и исходящих рёбер из данной вершины по указанному индексу
int Graph::getDegree(int vertexIndex) {
    return vertexList[vertexIndex]->getDegree();
}

// Последовательно удаляет все вершины графа, начиная с вершины с индексом 0
void Graph::clear() {
    while (!vertexList.empty()) {
        eraseVertex(0);
    }
}

// Возвращение матрицы смежности
int ** Graph::GetAdjMatrix() {
    // Создание двумерного массива для матрицы смежности
    int **AdjMatrix = new int*[vertexNum];

    // Выделение памяти и инициализация значений в матрице
    for (int i = 0; i < vertexNum; i++) {
        AdjMatrix[i] = new int[vertexNum]{};
    }

    // Заполнение матрицы смежности весами рёбер
    for (int i = 0; i < vertexNum; i++) {
        for (int j = 0; j < vertexNum; j++) {
            AdjMatrix[i][j] = 0; // Инициализация всех элементов нулями
        }
    }

    for (Vertex* i : vertexList) {
        for (Edge* j: i->getEdges()) {
            AdjMatrix[i->getIndex()][j->destVertex()->getIndex()] = j->getWeight(); // Присваивание веса ребра в матрицу
        }
    }

    return AdjMatrix;
}

// Удаление матрицы смежности
void Graph::RemoveAdjMatrix(int ** AdjMatrix) {
    // Освобождение выделенной памяти
    for (int i = 0; i < vertexNum; i++) {
        delete[] AdjMatrix[i];
    }

    // Удаление самого двумерного массива
    delete[] AdjMatrix;
}

// Создание окна для удаления выбранной вершины
void Graph::createEraseVertexWindow() {
    // Создаем новое окно QWidget для удаления вершины
    window = new QWidget;

    // Создаем поле для ввода номера вершины
    input1 = new QLineEdit;

    // Создаем QLabel для отображения текстовой информации
    QLabel *label = new QLabel;
    label->setFrameStyle(QFrame::Box | QFrame::Plain); // Устанавливаем стиль рамки для Label

    // Создаем кнопку "OK" для подтверждения удаления вершины
    QPushButton *okButton = new QPushButton(tr("OK"));

    // Создаем сетку для размещения виджетов
    QGridLayout *layout = new QGridLayout;

    // Добавляем Label "Введите номер вершины" в первую строку и столбец
    layout->addWidget(new QLabel(tr("Введите номер вершины:")), 0, 0);

    // Добавляем поле ввода (LineEdit) в первую строку и второй столбец сетки
    layout->addWidget(input1, 0, 1);

    // Добавляем кнопку "OK" во вторую строку и второй столбец, прижимаем справа
    layout->addWidget(okButton, 1, 1, Qt::AlignRight);

    // Установка фиксированного размера окна в соответствии с содержимым
    layout->setSizeConstraint(QLayout::SetFixedSize);

    // Устанавливаем созданную сетку на окно
    window->setLayout(layout);

    // Устанавливаем заголовок окна
    window->setWindowTitle("Удаление вершины");

    // Подключаем действие "eraseVertexSlot" к кнопке "OK"
    connect(okButton, &QPushButton::clicked, this, &Graph::eraseVertexSlot);

    // Отображаем окно на экране
    window->show();
}

// Удаление выбранной вершины
void Graph::eraseVertexSlot() {
    int srcIndex = input1->text().toInt(); // Получение индекса вершины для удаления из поля ввода
    window->close(); // Закрытие окна после получения номера вершины

    // Проверка на корректность введенного индекса вершины
    if (srcIndex >= vertexList.size()) {
        return; // Если номер вершины некорректен, завершаем выполнение метода
    }

    eraseVertex(srcIndex); // Вызов метода для удаления выбранной вершины из графа
}

// Создание окна для добавления ребра
void Graph::createAddEdgeWindow() {
    window = new QWidget; // Создание нового виджета окна
    input1 = new QLineEdit; // Поле ввода для начальной вершины
    input2 = new QLineEdit; // Поле ввода для конечной вершины
    input3 = new QLineEdit; // Поле ввода для веса дуги
    QLabel *label = new QLabel; // Заголовок или метка для ввода
    label->setFrameStyle(QFrame::Box | QFrame::Plain); // Установка стиля рамки для метки
    QPushButton *okButton = new QPushButton(tr("OK")); // Кнопка подтверждения

    QGridLayout *layout = new QGridLayout; // Создание сетки для расположения элементов
    layout->addWidget(new QLabel(tr("Начальная вершина:")), 0, 0); // Добавление метки для начальной вершины
    layout->addWidget(input1, 0, 1); // Добавление поля ввода для начальной вершины
    layout->addWidget(new QLabel(tr("Конечная вершина:")), 1, 0); // Добавление метки для конечной вершины
    layout->addWidget(input2, 1, 1); // Добавление поля ввода для конечной вершины
    layout->addWidget(new QLabel(tr("Вес:")), 2, 0); // Добавление метки для веса дуги
    layout->addWidget(input3, 2, 1); // Добавление поля ввода для веса дуги
    layout->addWidget(okButton, 3, 1, Qt::AlignRight); // Добавление кнопки "OK" в последнюю строку справа
    layout->setSizeConstraint(QLayout::SetFixedSize); // Установка фиксированного размера окна с учётом содержимого
    window->setLayout(layout); // Установка сетки в качестве макета окна

    window->setWindowTitle("Добавление ребра"); // Установка заголовка окна
    connect(okButton, &QPushButton::clicked, this, &Graph::addEdgeSlot); // Связывание кнопки "OK" с методом добавления дуги
    window->show(); // Отображение окна
}

// Добавления ребра
void Graph::addEdgeSlot() {
    int srcIndex = input1->text().toInt(); // Получение индекса начальной вершины из поля ввода
    int destIndex = input2->text().toInt(); // Получение индекса конечной вершины из поля ввода
    double edgeWeight = input3->text().toDouble(); // Получение веса ребра из поля ввода

    // Проверка на корректность введенных данных
    if (srcIndex >= vertexList.size() || destIndex >= vertexList.size() || edgeWeight <= 0) {
        return; // Прекращаем выполнение, если данные некорректны
    }

    insertEdge(srcIndex, destIndex, edgeWeight); // Добавляем ребро между указанными вершинами с указанным весом
}

// Создание окна для удаления выбранного ребра
void Graph::createEraseEdgeWindow() {
    window = new QWidget; // Создание нового виджета окна
    input1 = new QLineEdit; // Поле ввода для номера начальной вершины ребра
    input2 = new QLineEdit; // Поле ввода для номера конечной вершины ребра
    QLabel *label = new QLabel; // Метка для указания полей ввода
    label->setFrameStyle(QFrame::Box | QFrame::Plain); // Установка стиля рамки метки
    QPushButton *okButton = new QPushButton(tr("OK")); // Кнопка подтверждения действия

    QGridLayout *layout = new QGridLayout; // Создание сетки для размещения элементов
    layout->addWidget(new QLabel(tr("Начальная вершина:")), 0, 0); // Добавление метки для номера начальной вершины
    layout->addWidget(input1, 0, 1); // Добавление поля ввода для номера начальной вершины
    layout->addWidget(new QLabel(tr("Конечная вершины:")), 1, 0); // Добавление метки для номера конечной вершины
    layout->addWidget(input2, 1, 1); // Добавление поля ввода для номера конечной вершины
    layout->addWidget(okButton, 2, 1, Qt::AlignRight); // Добавление кнопки "OK" в последнюю строку справа
    layout->setSizeConstraint(QLayout::SetFixedSize); // Установка фиксированного размера окна с учётом содержимого
    window->setLayout(layout); // Установка сетки в качестве макета окна

    window->setWindowTitle("Удаление ребра"); // Установка заголовка окна
    connect(okButton, &QPushButton::clicked, this, &Graph::eraseEdgeSlot); // Связывание кнопки "OK" с методом удаления ребра
    window->show(); // Отображение окна
}

// Удаление выбранного ребра
void Graph::eraseEdgeSlot() {
    int srcIndex = input1->text().toInt(); // Получение индекса начальной вершины из поля ввода
    int destIndex = input2->text().toInt(); // Получение индекса конечной вершины из поля ввода
    window->close(); // Закрытие окна после ввода данных

    if (srcIndex >= vertexList.size() || destIndex >= vertexList.size()) {
        return; // Проверка на корректность введенных данных - прекратить выполнение при ошибке
    }

    eraseEdge(srcIndex, destIndex); // Вызов метода удаления ребра, если данные корректны
}

// Окно для изменения веса ребра
void Graph::createUpdateWeightWindow() {
    window = new QWidget; // Создание нового виджета окна
    input1 = new QLineEdit; // Поле ввода для начальной вершины
    input2 = new QLineEdit; // Поле ввода для конечной вершины
    input3 = new QLineEdit; // Поле ввода для нового веса
    QLabel *label = new QLabel;

    label->setFrameStyle(QFrame::Box | QFrame::Plain); // Установка стиля для метки
    QPushButton *okButton = new QPushButton(tr("OK")); // Кнопка подтверждения изменения

    QGridLayout *layout = new QGridLayout; // Создание сетки для управления расположением элементов
    layout->addWidget(new QLabel(tr("Начальная вершина:")), 0, 0);
    layout->addWidget(input1, 0, 1);
    layout->addWidget(new QLabel(tr("Конечная вершина:")), 1, 0);
    layout->addWidget(input2, 1, 1);
    layout->addWidget(new QLabel(tr("Новый вес:")), 2, 0);
    layout->addWidget(input3, 2, 1);
    layout->addWidget(okButton, 3, 1, Qt::AlignRight); // Передача кнопки в сетку, выравнивание справа

    layout->setSizeConstraint(QLayout::SetFixedSize); // Фиксация размеров окна
    window->setLayout(layout); // Установка сетки в окне
    window->setWindowTitle("Изменение веса ребра"); // Установка заголовка окна

    connect(okButton, &QPushButton::clicked, this, &Graph::updateWeightSlot); // Подключение сигнала к слоту для изменения веса
    window->show(); // Отображение окна
}

// Обновление веса ребра
void Graph::updateWeightSlot() {
    int srcIndex = input1->text().toInt(); // Получаем индекс начальной вершины
    int destIndex = input2->text().toInt(); // Получаем индекс конечной вершины
    double edgeWeight = input3->text().toDouble(); // Получаем новый вес ребра
    window->close(); // Закрываем окно

    // Проверка входных параметров
    if (srcIndex >= vertexList.size() || destIndex >= vertexList.size() || edgeWeight <= 0) {
        return;
    }

    updateWeight(srcIndex, destIndex, edgeWeight); // Вызываем метод для обновления веса
}

// Создание окна с функциями
void Graph::createFunctionWindow() {
    window = new QWidget; // Создаем новое окно
    input1 = new QLineEdit;
    input5 = new QLineEdit;
    QLabel *label = new QLabel;
    label->setText("1. Поиск в глубину\n2. Поиск в ширину\n3. Алгоритм Дейкстры\n4. Задача Коммивояжёра\n"); // Указываем доступные функции

    QPushButton *okButton = new QPushButton(tr("OK")); // Кнопка для запуска выбранной функции

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(label, 0, 0); // Добавляем текстовую метку
    layout->addWidget(new QLabel(tr("Номер функции:")), 1, 0); // Метка для ввода номера функции
    layout->addWidget(input5, 1, 1); // Поле для ввода номера функции
    layout->addWidget(new QLabel(tr("Номер начальной вершины:")), 2, 0); // Метка для ввода начальной вершины
    layout->addWidget(input1, 2, 1); // Поле для ввода начальной вершины
    layout->addWidget(okButton, 3, 0, Qt::AlignRight); // Размещаем кнопку OK справа
    layout->setSizeConstraint(QLayout::SetFixedSize); // Задаем фиксированный размер макета
    window->setLayout(layout); // Устанавливаем макет в окно
    window->setWindowTitle("Выбор функции"); // Устанавливаем заголовок окна

    connect(okButton, &QPushButton::clicked, this, &Graph::StartSelectedFunction); // Подключаем кнопку к слоту
    window->show(); // Показываем окно
}

void Graph::runDFS(int temp, bool* visited) {
    if (!visited[temp]) {
        visited[temp] = true;
        str += "Вершина " + QString::number(temp) + " посещена\n";
    }

    Vertex *tempVertex = vertexList[temp];
    for (Edge *tempEdge : tempVertex->getEdges()) {//проход по соседям
        if (!visited[tempEdge->destVertex()->getIndex()]) {
            runDFS(tempEdge->destVertex()->getIndex(), visited);
        }
    }
}

// Не знаю насколько он правильно выводит
void Graph::runBFS(int index, bool* visited, QQueue<int>* bfsQueue) {
    bfsQueue->enqueue(index);  // Начинаем с добавления стартовой вершины в очередь
    visited[index] = true;  // Помечаем данную вершину как посещенную

    while (!bfsQueue->isEmpty()) {
        int currVertex = bfsQueue->dequeue();  // Извлекаем первую вершину из очереди
        str += "Вершина " + QString::number(currVertex) + " посещена\n";

        Vertex *tempVertex = vertexList[currVertex];
        for (Edge *tempEdge : tempVertex->getEdges()) {
            int adjVertex = tempEdge->destVertex()->getIndex();  // Получаем индекс смежной вершины

            // Проверяем, посещали ли эту вершину ранее во время данного обхода
            if (!visited[adjVertex]) {
                //str += "Вершина " + QString::number(adjVertex) + " посещена\n";
                visited[adjVertex] = true;  // Помечаем смежную вершину как посещенную
                bfsQueue->enqueue(adjVertex);  // Добавляем смежную вершину в очередь для дальнейшего обхода
            }
        }
    }
}

void Graph::runDijkstra(int vertexIndex) {
    // Получение матрицы смежности графа
    int** AdjMatrix = GetAdjMatrix();

    // Список расстояний от начальной вершины до остальных вершин
    QVector<int> distance(vertexNum, INT_MAX);
    distance[vertexIndex] = 0;

    // Словарь для хранения длин пути и вершин
    map<int, int> m;
    m[0] = vertexIndex;

    // Начало алгоритма
    while (!m.empty()) {
        auto current = m.begin();
        int m_length = current->first;
        int m_vertex = current->second;
        m.erase(current);

        // Расчет кратчайшего пути и обновление списков расстояний
        if (m_length <= distance[m_vertex]) {
            distance[m_vertex] = m_length;

            for (int i = 0; i < vertexNum; i++) {
                if (AdjMatrix[m_vertex][i] != 0 && distance[m_vertex] != INT_MAX && i != vertexIndex && distance[i] > distance[m_vertex] + AdjMatrix[m_vertex][i]) {
                    distance[i] = distance[m_vertex] + AdjMatrix[m_vertex][i];
                    m[distance[i]] = i;
                }
            }
        }
    }

    // Формирование результатов
    for (int i = 0; i < vertexNum; i++) {
        if (i != vertexIndex && distance[i] != INT_MAX) {
            str += "Расстояние от вершины " + QString::number(vertexIndex) + " до вершины " + QString::number(i) + " равно " + QString::number(distance[i]) + '\n';
        }
    }

    // Освобождение памяти и удаление матрицы смежности
    RemoveAdjMatrix(AdjMatrix);
}

void Graph::runTSP(int vertexIndex) {
    int** AdjMatrix = GetAdjMatrix();
    QVector<QVector<int>> AdjMatrixVec;
    for (int i = 0; i < vertexNum; ++i) {
        QVector<int> tempVec;
        for (int j = 0; j < vertexNum; ++j) {
            tempVec.append(AdjMatrix[i][j]);
        }
        AdjMatrixVec.append(tempVec);
    }

    QVector<int> visited(vertexNum, 0);  // Флаги для посещенных вершин
    visited[vertexIndex] = 1;  // Начало пути с начальной вершины
    int currentVertex = vertexIndex;
    int totalDistance = 0;
    QString pathStr = QString::number(vertexIndex);

    // Поиск наименьшего суммарного расстояния
    for (int count = 1; count < vertexNum; ++count) {
        int nextVertex = -1;
        int minDistance = INT_MAX;

        // Выбор следующей вершины с минимальным расстоянием
        for (int v = 0; v < vertexNum; ++v) {
            if (v != currentVertex && !visited[v] && AdjMatrix[currentVertex][v] != 0) {
                if (AdjMatrix[currentVertex][v] < minDistance) {
                    minDistance = AdjMatrix[currentVertex][v];
                    nextVertex = v;
                }
            }
        }

        // Обновление информации о маршруте и расстоянии
        if (nextVertex != -1) {
            pathStr += " -> " + QString::number(nextVertex);
            totalDistance += minDistance;
            visited[nextVertex] = 1;
            currentVertex = nextVertex;
        }
    }

    // Добавление обратного пути и расчет окончательного расстояния
    if (AdjMatrix[currentVertex][vertexIndex] != 0) {
        totalDistance += AdjMatrix[currentVertex][vertexIndex];
        pathStr += " -> " + QString::number(vertexIndex);
        str = pathStr + " = " + QString::number(totalDistance);
    } else {
        str = "No path back to the starting vertex!";
    }

    RemoveAdjMatrix(AdjMatrix);
}


void Graph::StartSelectedFunction() {
    int index = input1->text().toInt();
    int NumOfFunction = input5->text().toInt();
    if (index >= 0 && index < vertexList.size() && NumOfFunction >= 0 && NumOfFunction < 5) {
        enum Functions {
            DFS = 1, BFS, Dijkstra, Travel
        };
        switch (NumOfFunction) {
        case(Functions::DFS): {
            bool* visited = new bool[vertexList.size()];
            runDFS(index, visited);
            createDFSWindow();
            delete[] visited;
            break;
        }
        case(Functions::BFS): {
            bool* visited = new bool[vertexList.size()];
            runBFS(index, visited, new QQueue<int>);
            createBFSWindow();
            delete[] visited;
            break;
        }
        case(Functions::Dijkstra): {
            runDijkstra(index);
            createDijkstraWindow();
            break;
        }
        case(Functions::Travel): {
            runTSP(index);
            createTSPWindow();
            break;
        }
        }
    }
}

void Graph::createDFSWindow() {
    window = new QWidget;
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(new QLabel(str), 0, 0);
    str = "";
    window->setLayout(layout);
    window->setWindowTitle("Поиск в глубину");
    window->show();
}

void Graph::createBFSWindow() {
    window = new QWidget;
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(new QLabel(str), 0, 0);
    str = "";
    window->setLayout(layout);
    window->setWindowTitle("Поиск в ширину");
    window->show();
}

void Graph::createDijkstraWindow() {
    window = new QWidget;
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(new QLabel(str), 0, 0);
    str = "";
    window->setLayout(layout);
    window->setWindowTitle("Алгоритм Дейкстры");
    window->show();
}

void Graph::createTSPWindow() {
    window = new QWidget;
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(new QLabel(str), 0, 0);
    str = "";
    window->setLayout(layout);
    window->setWindowTitle("Решение задачи Коммивояжёра");
    window->show();
}
