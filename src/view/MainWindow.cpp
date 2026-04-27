#include "view/MainWindow.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow() {
    setWindowTitle("MVC Hello");
    resize(400, 200);

    QWidget* central = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(central);

    label = new QLabel("", this);
    label->setAlignment(Qt::AlignCenter);

    input = new QLineEdit(this);
    input->setPlaceholderText("Enter a message");

    updateButton = new QPushButton("Update Message", this);
    openBallWindowButton = new QPushButton("Open Ball Window", this);

    layout->addWidget(label);
    layout->addWidget(input);
    layout->addWidget(updateButton);
    layout->addWidget(openBallWindowButton);

    setCentralWidget(central);
}

void MainWindow::setMessage(const QString& text) {
    label->setText(text);
}

QString MainWindow::getInputText() const {
    return input->text();
}

QPushButton* MainWindow::getUpdateButton() const {
    return updateButton;
}

QPushButton* MainWindow::getOpenBallWindowButton() const {
    return openBallWindowButton;
}
