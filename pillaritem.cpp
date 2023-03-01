#include "pillaritem.h"
#include <QRandomGenerator>
#include <QGraphicsScene>
#include <QDebug>

PillarItem::PillarItem() :
    topPillar(new QGraphicsPixmapItem(QPixmap(":/pipe.png"))),
    botPillar(new QGraphicsPixmapItem(QPixmap(":/pipe.png")))
{

    topPillar->setPos(QPointF(0,0) - QPointF(topPillar->boundingRect().width()/2, topPillar->boundingRect().height() +60));
    botPillar->setPos(QPointF(0,0) - QPointF(-botPillar->boundingRect().width()/2 + 50, -60));

    addToGroup(topPillar);
    addToGroup(botPillar);

    yPos = QRandomGenerator::global()->bounded(150); //1-150
    int xRandomizer = QRandomGenerator::global()->bounded(200); //1-200

    setPos(QPoint(0,0) + QPoint(260 + xRandomizer, yPos));

    xAnimation = new QPropertyAnimation(this, "x", this);
    xAnimation->setStartValue(260 + xRandomizer);
    xAnimation->setEndValue(-260);
    xAnimation->setEasingCurve(QEasingCurve::Linear);
    xAnimation->setDuration(1500);

    connect(xAnimation, &QPropertyAnimation::finished, [=](){
        scene()->removeItem(this);
        delete this;
    });

    xAnimation->start();



}

qreal PillarItem::x() const
{
    return m_x;
}
PillarItem::~PillarItem()
{
    qDebug() << "Deleted Pillar";
}

void PillarItem::setX(const qreal &newX)
{
    qDebug() << "Pillar Position:" << newX;
    m_x = newX;
    setPos(QPointF(0,0) + QPointF(newX, yPos));
}
