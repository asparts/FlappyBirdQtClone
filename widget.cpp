#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsPixmapItem>
#include "pillaritem.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    scene = new Scene(this);
    scene->setSceneRect(-256, -256, 512, 512);

    QGraphicsPixmapItem * pixItem = new QGraphicsPixmapItem(QPixmap(":/sky.png"));
    scene->addItem(pixItem);

    pixItem->setPos(QPointF(0,0) - QPointF(pixItem->boundingRect().width()/2, pixItem->boundingRect().height()/2));

    scene->addLine(-400,0,400,0);
    scene->addLine(0,-400,0,400);

//    PillarItem * pillar = new PillarItem();
//    scene->addItem(pillar);


    ui->graphicsView->setScene(scene);
}

Widget::~Widget()
{
    delete ui;
}

