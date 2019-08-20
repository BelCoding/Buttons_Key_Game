#define LED_INDICATOR_H

#include <QWidget>
#include <QBrush>
#include <QRadialGradient>

class LED_Indicator : public QWidget
{
    Q_OBJECT

public:
 LED_Indicator(int diameter, QColor on_color, QColor off_color, QWidget *parent = 0);
     void Set_Status(int on_off);
     QSize minimumSizeHint() const Q_DECL_OVERRIDE;
     QSize sizeHint() const Q_DECL_OVERRIDE;
private slots:

private:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    int m_diameter;
    int m_on_off;
    QColor m_on_color;
    QColor m_off_color;
};
#endif // LED_INDICATOR_H
