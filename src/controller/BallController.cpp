#include "controller/BallController.h"

#include "model/BallModel.h"
#include "view/BallWindow.h"

#include <QKeyEvent>

BallController::BallController(BallModel* model, BallWindow* view)
    : model(model), view(view) {}

void BallController::initialize() {
    view->setController(this);
    refreshView();
}

void BallController::moveUp() {
    model->moveUp();
    refreshView();
}

void BallController::moveDown() {
    model->moveDown();
    refreshView();
}

void BallController::moveLeft() {
    model->moveLeft();
    refreshView();
}

void BallController::moveRight() {
    model->moveRight();
    refreshView();
}

bool BallController::handleKeyPress(QKeyEvent* event) {
    if (event->key() == Qt::Key_Up) {
        moveUp();
        return true;
    }

    if (event->key() == Qt::Key_Down) {
        moveDown();
        return true;
    }

    if (event->key() == Qt::Key_Left) {
        moveLeft();
        return true;
    }

    if (event->key() == Qt::Key_Right) {
        moveRight();
        return true;
    }

    return false;
}

void BallController::refreshView() {
    view->setBallPosition(model->getRow(), model->getColumn());
}