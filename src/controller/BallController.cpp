#include "controller/BallController.h"

#include "model/BallModel.h"
#include "view/BallWindow.h"

#include <QEvent>
#include <QKeyEvent>

BallController::BallController(BallModel* model, BallWindow* view)
    : model(model), view(view) {}

void BallController::initialize() {
    view->installEventFilter(this);
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

bool BallController::eventFilter(QObject* watched, QEvent* event) {
    if (watched != view || event->type() != QEvent::KeyPress) {
        return QObject::eventFilter(watched, event);
    }

    QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);

    if (keyEvent->key() == Qt::Key_Up) {
        moveUp();
        return true;
    }

    if (keyEvent->key() == Qt::Key_Down) {
        moveDown();
        return true;
    }

    if (keyEvent->key() == Qt::Key_Left) {
        moveLeft();
        return true;
    }

    if (keyEvent->key() == Qt::Key_Right) {
        moveRight();
        return true;
    }

    return QObject::eventFilter(watched, event);
}
