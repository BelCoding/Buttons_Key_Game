#ifndef GAMEGUI_H
#define GAMEGUI_H

#include <QMainWindow>
#include "keygame.hpp"
#include "led.h"

namespace Ui {
class GameGUI;
}

class GameGUI : public QMainWindow
{
    Q_OBJECT

public:

    game::ButtonsKey game_obj;
    LED *led1, *led2, *led3;
    explicit GameGUI(QWidget *parent = 0);
    ~GameGUI();

private slots:

	void handleButton(const char c);

    void on_Restart_clicked();

    void on_ButtonA_clicked();

    void on_ButtonB_clicked();

    void on_ButtonC_clicked();

private:
    Ui::GameGUI *ui;
};

#endif // GAMEGUI_H
