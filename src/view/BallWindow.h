#pragma once

#include <QWidget>

class BallController;
class BallGridWidget;

class BallWindow : public QWidget {
public:
    BallWindow();

    void setBallPosition(int row, int column);
    void setController(BallController* controller);

private:
    BallGridWidget* grid;
    BallController* controller = nullptr;

protected:
    void keyPressEvent(QKeyEvent* event) override;
};
