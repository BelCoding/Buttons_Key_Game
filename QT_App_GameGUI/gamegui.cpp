#include "gamegui.h"
#include "ui_gamegui.h"
#include "led.h"

GameGUI::GameGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameGUI)
{
    game_obj.RestartGame();
    ui->setupUi(this);

    //QVBoxLayout *l=new QVBoxLayout(this);
    led1=new LED;
    led1->setOnColor(Qt::red);
    led1->setStatus(true);
    //    l->addWidget(led1);

    led2=new LED;
    led2->setOnColor(Qt::red);
    led2->setStatus(true);
//    l->addWidget(led2);
    led3=new LED;
    led3->setOnColor(Qt::red);
    led3->setStatus(true);
//    l->addWidget(led3);

    ui->horizontalLayout_3->addWidget(led1);
    ui->horizontalLayout_3->addWidget(led2);
    ui->horizontalLayout_3->addWidget(led3);

    ui->label_pressedButtons_WIN->setText("");
    ui->label_pressedButtons->setText("---");


}

GameGUI::~GameGUI()
{
    delete ui;
}

int clasifyColors(LED *led, std::string color){

    if( bel::strComparePlus("Red", color) == 0 ){
       led->setOnColor(Qt::red);
       return 0;
    }

    if( bel::strComparePlus("Green", color) == 0 ){
        led->setOnColor(Qt::green);
        return 1;
    }

    if( bel::strComparePlus("Orange", color) == 0 ){ // We use blue instead of Orange to represent the Orange.
        led->setOnColor(Qt::blue);
        return 0;
    }

return 0;
}

void GameGUI::handleButton(const char c)
{
    game_obj.NewPressedButton(c);
    game_obj.UpdateLeds(game_obj.pressed_buttons);

    int g = clasifyColors(led1, game_obj.current_leds[0]) + clasifyColors(led2, game_obj.current_leds[1]) + clasifyColors(led3, game_obj.current_leds[2]);

    if(g == 3) // When the 3 colors are Green, you already found the key.
        ui->label_pressedButtons_WIN->setText("Well Done!!");

    std::string str = "   ";
    for(int i=0; i < 3; i++){ str[i] = game_obj.pressed_buttons[2-i]; }
    QString last_butt = QString::fromStdString(str);

    ui->label_pressedButtons->setText(last_butt);    

}

void GameGUI::on_Restart_clicked()
{

    game_obj.RestartGame();
    ui->label_pressedButtons->setText("---");
    ui->label_pressedButtons_WIN->setText("");

    led1->setOnColor(Qt::red);
    led2->setOnColor(Qt::red);
    led3->setOnColor(Qt::red);

}

void GameGUI::on_ButtonA_clicked()
{
	handleButton('A');
}

void GameGUI::on_ButtonB_clicked()
{
	handleButton('B');
}

void GameGUI::on_ButtonC_clicked()
{
	handleButton('C');
}
