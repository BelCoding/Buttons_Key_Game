/********************************************************************************
** Form generated from reading UI file 'gamegui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEGUI_H
#define UI_GAMEGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameGUI
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_pressedButtons;
    QLabel *label_pressedButtons_WIN;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *ButtonA;
    QPushButton *ButtonB;
    QPushButton *ButtonC;
    QPushButton *Restart;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GameGUI)
    {
        if (GameGUI->objectName().isEmpty())
            GameGUI->setObjectName(QStringLiteral("GameGUI"));
        GameGUI->resize(400, 300);
        centralWidget = new QWidget(GameGUI);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 10, 321, 221));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));

        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_pressedButtons = new QLabel(layoutWidget);
        label_pressedButtons->setObjectName(QStringLiteral("label_pressedButtons"));
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans Mono"));
        font.setPointSize(22);
        font.setItalic(false);
        label_pressedButtons->setFont(font);

        horizontalLayout_4->addWidget(label_pressedButtons);

        label_pressedButtons_WIN = new QLabel(layoutWidget);
        label_pressedButtons_WIN->setObjectName(QStringLiteral("label_pressedButtons_WIN"));
        label_pressedButtons_WIN->setFont(font);

        horizontalLayout_4->addWidget(label_pressedButtons_WIN);


        verticalLayout_3->addLayout(horizontalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ButtonA = new QPushButton(layoutWidget);
        ButtonA->setObjectName(QStringLiteral("ButtonA"));

        horizontalLayout->addWidget(ButtonA);

        ButtonB = new QPushButton(layoutWidget);
        ButtonB->setObjectName(QStringLiteral("ButtonB"));

        horizontalLayout->addWidget(ButtonB);

        ButtonC = new QPushButton(layoutWidget);
        ButtonC->setObjectName(QStringLiteral("ButtonC"));

        horizontalLayout->addWidget(ButtonC);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        Restart = new QPushButton(layoutWidget);
        Restart->setObjectName(QStringLiteral("Restart"));

        verticalLayout_2->addWidget(Restart);


        verticalLayout_3->addLayout(verticalLayout_2);

        GameGUI->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GameGUI);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        GameGUI->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GameGUI);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GameGUI->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GameGUI);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GameGUI->setStatusBar(statusBar);

        retranslateUi(GameGUI);

        QMetaObject::connectSlotsByName(GameGUI);
    } // setupUi

    void retranslateUi(QMainWindow *GameGUI)
    {
        GameGUI->setWindowTitle(QApplication::translate("GameGUI", "GameGUI", Q_NULLPTR));
        label_pressedButtons->setText(QApplication::translate("GameGUI", "-", Q_NULLPTR));
        label_pressedButtons_WIN->setText(QString());
        ButtonA->setText(QApplication::translate("GameGUI", "A", Q_NULLPTR));
        ButtonB->setText(QApplication::translate("GameGUI", "B", Q_NULLPTR));
        ButtonC->setText(QApplication::translate("GameGUI", "C", Q_NULLPTR));
        Restart->setText(QApplication::translate("GameGUI", "Restart", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GameGUI: public Ui_GameGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEGUI_H
