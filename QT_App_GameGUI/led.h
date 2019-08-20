#ifndef LED_H
#define LED_H

#include <QWidget>

class LED : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(bool status READ status WRITE setStatus)
    Q_PROPERTY(QColor onColor READ onColor WRITE setOnColor)
    Q_PROPERTY(QColor offColor READ offColor WRITE setOffColor)
public:
    explicit LED(int diameter=50, QColor on=Qt::red, QColor off=Qt::gray, QWidget *parent=nullptr);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

    bool status(){ return _status; }
    QColor onColor(){ return _onColor; }
    QColor offColor(){ return _offColor; }

signals:

public slots:
    void setStatus(bool status);
    void setOnColor(QColor color);
    void setOffColor(QColor color);

private:
    void paintEvent(QPaintEvent *event) override;

    int _diameter;
    QColor _onColor;
    QColor _offColor;
    bool _status;
};

#endif // LED_H
