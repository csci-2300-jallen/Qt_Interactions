#include "controller/AppController.h"
#include "controller/BallController.h"
#include "model/BallModel.h"
#include "model/MessageModel.h"
#include "view/BallWindow.h"
#include "view/MainWindow.h"

#include <QObject>
#include <QPushButton>
#include <QString>

AppController::AppController(MessageModel* model, MainWindow* view)
    : model(model), view(view) {}

void AppController::initialize() {
    view->setMessage(QString::fromStdString(model->getMessage()));

    QObject::connect(
        view->getUpdateButton(),
        &QPushButton::clicked,
        [this]() {
            handleUpdateMessage();
        }
    );

    QObject::connect(
        view->getOpenBallWindowButton(),
        &QPushButton::clicked,
        [this]() {
            openBallWindow();
        }
    );
}

void AppController::handleUpdateMessage() {
    std::string newMessage = view->getInputText().toStdString();
    model->setMessage(newMessage);
    view->setMessage(QString::fromStdString(model->getMessage()));
}

void AppController::openBallWindow() {
    if (ballWindow != nullptr) {
        ballWindow->raise();
        ballWindow->activateWindow();
        return;
    }

    ballModel = new BallModel();
    ballWindow = new BallWindow();
    ballController = new BallController(ballModel, ballWindow);
    ballController->initialize();

    QObject::connect(ballWindow, &QObject::destroyed, [this]() {
        delete ballController;
        delete ballModel;
        ballController = nullptr;
        ballModel = nullptr;
        ballWindow = nullptr;
    });

    ballWindow->show();
}
