#pragma once

class MessageModel;
class BallModel;
class BallController;
class BallWindow;
class MainWindow;

class AppController {
public:
    AppController(MessageModel* model, MainWindow* view);

    void initialize();
    void handleUpdateMessage();
    void openBallWindow();

private:
    MessageModel* model;
    MainWindow* view;
    BallModel* ballModel = nullptr;
    BallWindow* ballWindow = nullptr;
    BallController* ballController = nullptr;
};
