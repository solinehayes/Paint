#ifndef LINES_H
#define LINES_H

#include <QPointF>
#include <QWidget>


class Lines {
private:
    QPainterPath path;
    QColor couleur=Qt::magenta;
    int brushSize=1;
    Qt::PenStyle penStyle=Qt::SolidLine;

   public:
    QPainterPath getPath(){return path; }
    QColor getColor() {return couleur;}
    int getBrushSize() {return brushSize;}
    Qt::PenStyle getPenStyle() {return penStyle;}


    void setColor(QColor color) {couleur=color;}
    void setBrushSize(int size) {brushSize=size;}
    void setPenStyle(Qt::PenStyle style) {penStyle=style;}

    Lines(QPainterPath chemin, QColor color, int size, Qt::PenStyle style) {
        path=chemin;
        couleur=color;
        brushSize=size;
        penStyle=style;
    }

    Lines(QPainterPath chemin){ path=chemin;}
};

#endif // LINES_H
