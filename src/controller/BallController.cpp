#include "controller/BallController.h"

#include "model/BallModel.h"
#include "view/BallWindow.h"

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

void BallController::refreshView() {
    view->setBallPosition(model->getRow(), model->getColumn());
}
