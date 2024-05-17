#include "vertex.h"
#include "edge.h"
#include "graph.h"

#include <QtMath>

#define M_PI 3.1415926

// Конструктор класса Edge
Edge::Edge(Vertex *source, Vertex *dest, double weight) {
    this->source = source; // Устанавливаем начальную вершину
    this->dest = dest; // Устанавливаем конечную вершину
    setAcceptedMouseButtons(Qt::NoButton); // Устанавливаем кнопку мыши, которая принимается
    source->addEdge(this); // Добавляем данное ребро к списку ребер начальной вершины
    this->weight = weight; // Устанавливаем вес ребра
    color = "white"; // Устанавливаем цвет ребра по умолчанию
}

// Деструктор класса Edge
Edge::~Edge() {
    // Деструктор по умолчанию - пока не содержит дополнительной логики
}

// Возвращает начальную вершину ребра
Vertex *Edge::sourceVertex() const {
    return source; // Возвращаем начальную вершину
}

// Возвращает конечную вершину ребра
Vertex *Edge::destVertex() const {
    return dest; // Возвращаем конечную вершину
}

// Метод для регулировки параметров ребра
void Edge::adjust() {
    // Проверяем, что начальная и конечная вершины существуют
    if (!source || !dest) {
        return; // В случае отсутствия вершин выходим из метода
    }

    // Создаем линию, соединяющую начальную и конечную вершины
    QLineF line(mapFromItem(source, 0, 0), mapFromItem(dest, 0, 0));

    // Вычисляем длину линии
    qreal length = line.length();

    // Подготавливаем геометрию для изменений
    prepareGeometryChange();

    // Если длина линии больше 20, устанавливаем точки начала и конца с отступом
    if (length > qreal(20.)) {
        QPointF edgeOffset((line.dx() * 10) / length, (line.dy() * 10) / length);
        sourcePoint = line.p1() + edgeOffset; // Устанавливаем точку начала ребра с учетом отступа
        destPoint = line.p2() - edgeOffset; // Устанавливаем точку конца ребра с учетом отступа
    } else {
        // Если длина линии меньше или равна 20, начальная и конечная точки совпадают
        sourcePoint = destPoint = line.p1();
    }
}

// Метод для вычисления ограничивающего прямоугольника ребра
QRectF Edge::boundingRect() const {
    // Если начальная или конечная вершина не существует, возвращается пустой прямоугольник
    if (!source || !dest) {
        return QRectF();
    }

    qreal penWidth = 1; // Ширина пера
    qreal extra = (penWidth + arrowSize) / 2.0; // Дополнительное пространство для стрелки
    // Создаем и возвращаем ограничивающий прямоугольник, нормализуем его
    return QRectF(sourcePoint, QSizeF(destPoint.x() - sourcePoint.x(), destPoint.y() - sourcePoint.y())).normalized().adjusted(-extra, -extra, extra, extra);
}

// Метод для отрисовки ребра
void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    // Если начальная или конечная вершина не существует, завершаем метод
    if (!source || !dest) {
        return;
    }

    // Создаем линию, соединяющую начальную и конечную точки
    QLineF line(sourcePoint, destPoint);

    // Получаем длину линии
    qreal length = line.length();

    // Если длина линии меньше допустимого значения, выходим
    if (qFuzzyCompare(length, qreal(0.))) {
        return;
    }

    // Устанавливаем кисть и перо для рисования линии
    painter->setBrush(Qt::black);
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    // Вычисляем сокращенные точки начала и конца ребра для корректировки длины
    QPointF sourceEdge = line.pointAt(0.1);
    QPointF destEdge = line.pointAt(0.9);

    // Рисуем линию с уменьшенными концами
    painter->drawLine(QLineF(sourceEdge, destEdge));

    // Настройка шрифта для увеличения размера текста
    QFont font = painter->font();
    font.setPointSize(font.pointSize() + 4);
    painter->setFont(font);

    // Рисуем текст с весом ребра между начальной и конечной точками
    QRectF textRect(sourcePoint, destPoint);
    painter->drawText(textRect, Qt::AlignCenter, QString::number(weight));
}

// Возвращает вес ребра
double Edge::getWeight() {
    return weight;
}

// Устанавливает вес ребра
void Edge::setWeight(double weight) {
    this->weight = weight; // Устанавливаем переданный вес
}

// Возвращает цвет ребра
QString Edge::getColor() {
    return color; // Возвращаем текущий цвет ребра
}

// Устанавливает цвет ребра и обновляет отображение
void Edge::setColor(QString color) {
    this->color = color; // Устанавливаем переданный цвет
    qApp->processEvents(); // Обрабатываем события приложения для обновления
    update(); // Обновляем отображение ребра
}
