#pragma once

#include <QObject>

class BallModel;
class BallWindow;

class BallController : public QObject {
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

protected:
    bool eventFilter(QObject* watched, QEvent* event) override;
};
