#pragma once

#include <QWidget>

class BallController;
class BallGridWidget;

class BallWindow : public QWidget {
public:
    BallWindow();

    void setBallPosition(int row, int column);

private:
    BallGridWidget* grid;
};
