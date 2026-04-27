#pragma once

class QKeyEvent;

class BallModel;
class BallWindow;

class BallController {
public:
    BallController(BallModel* model, BallWindow* view);

    void initialize();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    bool handleKeyPress(QKeyEvent* event);

private:
    void refreshView();

    BallModel* model;
    BallWindow* view;
};
