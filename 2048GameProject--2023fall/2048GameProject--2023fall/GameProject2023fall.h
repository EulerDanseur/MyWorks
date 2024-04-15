#pragma once

#include <QtWidgets/QWidget>
#include "ui_GameProject2023fall.h"

class GameProject2023fall : public QWidget
{
    Q_OBJECT

public:
    GameProject2023fall(QWidget *parent = nullptr);
    ~GameProject2023fall();

private:
    Ui::GameProject2023fallClass ui;
};
