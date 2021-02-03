/**
  @file enemy.h
  @version 1.0
  @title Class Enemy
  @brief Hereda QObject y QGraphicsItem de la librereria de Qt creator, esta clase
  representan enemigos de la clase player (instancia de la clase character.h).
  */
#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include <QGraphicsScene>
#include "bullet.h"

class Enemy: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    /**
     * @brief Enemy, constructor de la clase enemy.h.
     * @param posx, posción ene le eje x donde aparece el enemigo en scene
     (instancia de la clase QGraphicsScene).
     * @param parent
     */
    Enemy(int posx,QObject *parent = nullptr);
    /**
     * @brief ~Enemy, destructor de la clase enemy.h.
     */
    ~Enemy();

    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);

protected:
    double w,h,col;
    QPixmap *pixmap;
    QTimer *timer;
    QTimer *timerM;
    double health;

public slots:
    /**
     * @brief actualize, se usa para generar el sprite de la clase enemy.h.
     */
    void actualize();
    /**
     * @brief Move, comprueba colisiones de esta clase, con la clase bullet.h, además,
     mueve a Enemy 5 pixeles cada vez que es ejecutada.
     */
    void Move();

};

#endif // ENEMY_H
