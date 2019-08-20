#include "led.h"

#include <QPainter>
#include <QPaintEvent>
#include <QGradient>
#include <QLinearGradient>
#include <QRadialGradient>

LED::LED(int diameter, QColor on, QColor off, QWidget *parent)
    : QWidget(parent), _diameter(diameter), _onColor(on), _offColor(off), _status(false)
{}

QSize LED::minimumSizeHint() const {
    return QSize(_diameter, _diameter);
}

QSize LED::sizeHint() const {
    return minimumSizeHint();
}

void LED::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);

    QRect fullRect=event->rect();
    int size=qMin(fullRect.height(), fullRect.width());
    fullRect.setSize(QSize(size,size));

    int r=size*.1;
    QRect rect=fullRect.adjusted(r,r,-r,-r);

    // Outer Bezel
    QLinearGradient outerBezelGrad(rect.topLeft(), rect.bottomLeft());
    //outerBezelGrad.setStops(QGradient(QGradient::RiskyConcrete).stops());
    outerBezelGrad.setStops(
        QGradientStops() << QGradientStop(0, QColor("#c4c5c7"))
                         << QGradientStop(0.52, QColor("#dcdddf"))
                         << QGradientStop(1, QColor("#ebebeb"))
    );
    painter.setBrush(outerBezelGrad);
    painter.drawEllipse(rect);

    // Inner Bezel
    rect.adjust(r,r,-r,-r);
    QLinearGradient innerBezelGrad(rect.bottomLeft(), rect.topLeft());
    //innerBezelGrad.setStops(QGradient(QGradient::RichMetal).stops());
    innerBezelGrad.setStops(
        QGradientStops() << QGradientStop(0, QColor("#d7d2cc"))
                         << QGradientStop(1, QColor("#304352"))
    );
    painter.setBrush(innerBezelGrad);
    painter.drawEllipse(rect);

    // Main Color
    QColor mainColor((_status)?_onColor:_offColor);
    rect.adjust(r/2,r/2,-r/2,-r/2);
    QLinearGradient mainColorGrad(rect.bottomLeft(), rect.topLeft());
    mainColorGrad.setStops(
        QGradientStops() << QGradientStop(0, mainColor.light())
                         << QGradientStop(1, mainColor.dark())
    );
    painter.setBrush(mainColorGrad);
    painter.drawEllipse(rect);

    // HighLight
    rect.adjust(rect.width()/6, r/4, -rect.width()/6, -rect.height()*2/5.);
    QLinearGradient highlightGrad(rect.topLeft(), rect.bottomLeft());
    highlightGrad.setStops(
        QGradientStops() << QGradientStop(0, QColor(255,255,255,192))
                         << QGradientStop(1, QColor(255,255,255,0))
    );
    painter.setBrush(highlightGrad);
    painter.drawEllipse(rect);

    if(!_status) return;

    // Glow
    QRadialGradient glowGrad(fullRect.center(), fullRect.width()/2);

    QColor faint(_onColor);
    faint.setAlphaF(.5);

    QColor faintest(_onColor);
    faintest.setAlphaF(0);

    glowGrad.setStops(
        QGradientStops() << QGradientStop(0, faint)
                         << QGradientStop(1, faintest)
    );
    painter.setBrush(glowGrad);
    painter.drawEllipse(fullRect);
}

void LED::setStatus(bool status){
    if(status==_status) return;
    _status=status;
    repaint();
}

void LED::setOnColor(QColor color){
    if(color==_onColor) return;
    _onColor=color;
    repaint();
}

void LED::setOffColor(QColor color){
    if(color==_offColor) return;
    _offColor=color;
    repaint();
}
