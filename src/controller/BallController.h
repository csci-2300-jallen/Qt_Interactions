#pragma once

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

private:
    void refreshView();

    BallModel* model;
    BallWindow* view;
};
