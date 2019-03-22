#include "Drawzone.h"

 void Drawzone::mousePressEvent(QMouseEvent * event) {
    QPainterPath chemin=QPainterPath(event->pos());
    Lines line=Lines(chemin,couleur,brushSize,penStyle);
    drawing.push_back(line);
    drawing[drawing.size()-1].getPath().moveTo(event->pos());
    update();
 }

 void Drawzone::mouseMoveEvent(QMouseEvent * event) {
     drawing[drawing.size()-1].getPath().lineTo(event->pos());
     update();

 }

 void Drawzone::mouseReleaseEvent(QMouseEvent * event) {
      drawing[drawing.size()-1].getPath().lineTo(event->pos());
      drawing[drawing.size()-1].getPath().closeSubpath();
     update();

 }


 void Drawzone::paintEvent(QPaintEvent * e) {
     QWidget::paintEvent(e);
     QPen pen;
     QPainter painter(this);

    for(unsigned int i=0; i<drawing.size(); i++){
        pen.setWidth(drawing[i].getBrushSize());
         pen.setBrush(drawing[i].getColor());
         pen.setStyle(drawing[i].getPenStyle());

         painter.setPen(pen);
         painter.drawPath(drawing[i].getPath());
    }

 }
