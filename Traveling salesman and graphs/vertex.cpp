#include "vertex.h"
#include "edge.h"
#include "graph.h"

#include <QVector>

// Конструктор класса Vertex
Vertex::Vertex(Graph *graph, int index) : graph(graph) {
    // Устанавливаем флаги для вершины
    setFlag(ItemIsMovable); // Возможность перемещать вершину
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache); // Режим кэширования координат
    setZValue(-1); // Устанавливаем Z-позицию
    vertexIndex = index; // Устанавливаем индекс вершины
    degree = 0; // Инициализируем степень вершины
    color = "white"; // Инициализируем цвет вершины
}

// Деструктор класса Vertex
Vertex::~Vertex(){
    clearEdge(); // Очищаем связи с другими вершинами
    degree = 0; // Обнуляем степень вершины
}

// Возвращает цвет вершины
QString Vertex::getColor(){
    return this->color; // Возвращаем текущий цвет вершины
}

// Устанавливает цвет вершины и обновляет отображение
void Vertex::setColor(QString color){
    this->color = color; // Устанавливаем переданный цвет
    qApp->processEvents(); // Обрабатываем события приложения для обновления
    update(); // Обновляем отображение вершины
}


// Метод для добавления ребра к вершине
void Vertex::addEdge(Edge *edge) {
    edgeList << edge; // Добавляем ребро в список ребер вершины
    edge->adjust(); // Вызываем метод регулировки ребра
    degree++; // Увеличиваем степень вершины на 1
}

// Метод для получения списка ребер, инцидентных вершине
QVector<Edge *> Vertex::getEdges() const {
    return edgeList; // Возвращаем список ребер вершины
}

// Метод для вычисления сил, действующих на вершину
void Vertex::calculateForces() {
    if (!scene() || scene()->mouseGrabberItem() == this) {
        newPos = pos(); // Если сцена не активна или вершина перемещается, новая позиция равна текущей позиции
        return;
    }

    qreal xvel = 0;
    qreal yvel = 0;
    const QList<QGraphicsItem *> items = scene()->items(); // Получаем список элементов на сцене
    for (QGraphicsItem *item : items) {
        Vertex *temp = qgraphicsitem_cast<Vertex *>(item); // Приводим элемент к типу Vertex
        if (!temp) {
            continue;
        }
        QPointF vec = mapToItem(temp, 0, 0); // Переводим координаты вершины в координаты другой вершины
        qreal dx = vec.x();
        qreal dy = vec.y();
        double l = 2.0 * (dx * dx + dy * dy); // Длина вектора
        if (l > 0 && l < 600) {
            xvel += (dx * 150.0) / l; // Вычисление скорости по x
            yvel += (dy * 150.0) / l; // Вычисление скорости по y
        }
    }
    if (qAbs(xvel) < 0.1 && qAbs(yvel) < 0.1) {
        xvel = yvel = 0; // Если скорости очень малы, устанавливаем их в 0
    }

    QRectF sceneRect = scene()->sceneRect(); // Получаем границы сцены
    newPos = pos() + QPointF(xvel, yvel); // Устанавливаем новую позицию с учетом скоростей
    newPos.setX(qMin(qMax(newPos.x(), sceneRect.left() + 10), sceneRect.right() - 10)); // Ограничиываем движение по оси x
    newPos.setY(qMin(qMax(newPos.y(), sceneRect.top() + 145), sceneRect.bottom() - 10)); // Ограничиваем движение по оси y
}

// Метод для передвижения вершины в ее новую позицию
bool Vertex::advancePosition() {
    if(newPos == pos()) {
        return false; // Если новая позиция совпадает с текущей, вершина не передвигается
    }
    setPos(newPos); // Устанавливаем новую позицию для вершины
    return true; // Возвращаем true, если вершина была перемещена
}

// Метод для получения степени вершины
int Vertex::getDegree() {
    return degree; // Возвращаем степень вершины
}

// Метод для получения индекса вершины
int Vertex::getIndex() {
    return vertexIndex; // Возвращаем индекс вершины
}

// Метод для установки нового индекса у вершины
void Vertex::setIndex(int index) {
    vertexIndex = index; // Устанавливаем новый индекс для вершины
    qApp->processEvents(); // Обрабатываем события приложения для обновления
    update(); // Обновляем вершину на экране
}

// Метод для проверки существования пути от вершины к указанному индексу
bool Vertex::pathExist(int dest) {
    for (Edge *temp : edgeList) { // Перебираем все ребра текущей вершины
        if (temp->destVertex()->getIndex() == dest) { // Если у ребра конечная вершина имеет указанный индекс
            return true; // Возвращаем true - путь существует
        }
    }
    return false; // Если путь не найден, возвращаем false
}

// Устанавливает новую позицию вершины с учетом ограничений границ сцены
void Vertex::setPosition(double xvel, double yvel) {
    QRectF sceneRect = scene()->sceneRect(); // Получаем границы сцены
    newPos = pos() + QPointF(xvel, yvel); // Вычисляем новую позицию
    newPos.setX(qMin(qMax(newPos.x(), sceneRect.left() + 10), sceneRect.right() - 10)); // Ограничиваем координаты по оси X
    newPos.setY(qMin(qMax(newPos.y(), sceneRect.top() + 145), sceneRect.bottom() - 10)); // Ограничиваем координаты по оси Y
}

// Добавляет новое ребро (дугу) к вершине с указанным индексом-получателем и весом
void Vertex::insertEdge(int dest, double weight) {
    const QList<QGraphicsItem *> items = scene()->items(); // Получаем список объектов на сцене
    for(QGraphicsItem *item : items) {
        Vertex *temp = qgraphicsitem_cast<Vertex *>(item); // Преобразуем объект в вершину (Vertex)
        if (!temp) {
            continue;
        }
        if (temp->getIndex() == dest) { // Если индекс совпадает с целевой вершиной
            Edge *edge = new Edge(this, temp, weight); // Создаем новое ребро
            edgeList.append(edge); // Добавляем ребро в список ребер вершины
            return;
        }
    }
}

// Обновляет вес ребра, ведущего к вершине с указанным индексом-получателем
void Vertex::updateWeight(int dest, double weight) {
    for (Edge *temp : edgeList) { // Перебираем список ребер вершины
        if (temp->destVertex()->getIndex() == dest) { // Если целевая вершина совпадает с индексом
            temp->setWeight(weight); // Устанавливаем новый вес для ребра
        }
    }
}

// Удаляет ребро, ведущее к вершине с указанным индексом-получателем
void Vertex::eraseEdge(int dest) {
    if (!pathExist(dest)) { // Если путь к целевой вершине не существует
        return; // Выходим из метода
    }

    for (int i = 0; i < edgeList.size(); i++) { // Проходим по всем ребрам
        if (edgeList[i]->destVertex()->getIndex() == dest) { // Если конечная вершина совпадает с целевой
            edgeList.erase(edgeList.begin() + i); // Удаляем ребро из списка
        }
    }
    degree--; // Уменьшаем степень вершины
}

// Удаляет все ребра вершины и сбрасывает степень на 0
void Vertex::clearEdge() {
    edgeList.clear(); // Очищаем список ребер
    degree = 0; // Сбрасываем степень вершины
}

// Меняет цвет ребра, ведущего к вершине с указанным индексом-получателем, на черный
void Vertex::changeEdgeColor(int dest) {
    for (Edge *edge : edgeList) { // Перебираем все ребра в списке ребер вершины
        if (edge->destVertex()->getIndex() == dest) { // Если конечная вершина совпадает с целевой вершиной
            edge->setColor("black"); // Устанавливаем цвет ребра в черный
        }
    }
}

// Возвращает текущую позицию вершины
QPointF Vertex::getPos() {
    return newPos; // Возвращает координаты новой позиции вершины
}

QRectF Vertex::boundingRect() const {
    return QRectF(-25, -25, 50, 50).adjusted(-2, -2, 2, 2);
}

QPainterPath Vertex::shape() const {
    QPainterPath path;
    path.addEllipse(QPointF(0, 0), 25, 25);
    return path;
}

void Vertex::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->setBrush(QColor(173, 216, 230));
    painter->setPen(Qt::black);
    painter->drawEllipse(-25, -25, 50, 50);
    QString index = QString::number(vertexIndex);

    // Установка большего шрифта для текста внутри вершины
    QFont font = painter->font();
    font.setPointSize(font.pointSize() + 4); // Увеличиваем размер шрифта на 4 пункта
    painter->setFont(font);

    painter->drawText(QRect(-25, -25, 50, 50), Qt::AlignCenter, index);
    update();
}


// Метод, вызываемый при изменении состояния элемента
QVariant Vertex::itemChange(GraphicsItemChange change, const QVariant &value) {
    switch(change) {
    case ItemPositionHasChanged:
        for (Edge *edge : qAsConst(edgeList)) { // Перебираем все ребра вершины
            graph->itemMoved(); // Вызываем событие перемещения элемента
            edge->adjust(); // Корректируем положение ребер
            for (Edge *reverseEdge : edge->destVertex()->getEdges()) {
                reverseEdge->adjust(); // Корректируем смежные ребра
            }
        }
        graph->itemMoved(); // Вызываем событие перемещения элемента
        break;
    default:
        break;
    }
    return QGraphicsItem::itemChange(change, value);
}

// Обработка нажатия на вершину
void Vertex::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    update(); // Обновляем вид вершины
    QGraphicsItem::mousePressEvent(event); // Обрабатываем событие нажатия на вершину
}

// Обработка отпускания кнопки мыши
void Vertex::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    update(); // Обновляем вид вершины
    QGraphicsItem::mouseReleaseEvent(event); // Обрабатываем событие отпускания кнопки мыши
}
