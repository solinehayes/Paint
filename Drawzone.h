#ifndef DRAWZONE_H
#define DRAWZONE_H

#include "lines.h"

#include <QWidget>
#include <QPointF>
#include <QPainter>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPen>
#include <QColor>

using namespace std;


class Drawzone : public QWidget
{
public:
    Drawzone(QWidget * parent): QWidget(parent)  {setMinimumSize(700,700);}

    void mousePressEvent(QMouseEvent * event) ;
    void mouseReleaseEvent(QMouseEvent * event) ;
    void mouseMoveEvent(QMouseEvent * event);
    void paintEvent(QPaintEvent * e);

    std::vector<Lines> getDrawing() {return drawing;}


    void setColor(QColor color) {couleur=color;}
    void setSize(int taille) {brushSize=taille; }
    void setStyle(Qt::PenStyle style) {penStyle=style;}


private:
    std::vector<Lines> drawing;
    QPainterPath path;
    QColor couleur=Qt::black;
    int brushSize=1;
    Qt::PenStyle penStyle=Qt::SolidLine;



};

#endif // DRAWZONE_H
