#include "view/BallWindow.h"

#include <QLabel>
#include <QPainter>
#include <QVBoxLayout>

class BallGridWidget : public QWidget {
public:
    BallGridWidget(QWidget* parent = nullptr) : QWidget(parent) {
        setMinimumSize(250, 250);
    }

    void setBallPosition(int newRow, int newColumn) {
        row = newRow;
        column = newColumn;
        update();
    }

protected:
    void paintEvent(QPaintEvent*) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        const int gridSize = 5;
        const int cellWidth = width() / gridSize;
        const int cellHeight = height() / gridSize;

        // Draw the grid lines.
        painter.setPen(Qt::gray);
        for (int i = 0; i <= gridSize; i++) {
            painter.drawLine(i * cellWidth, 0, i * cellWidth, gridSize * cellHeight);
            painter.drawLine(0, i * cellHeight, gridSize * cellWidth, i * cellHeight);
        }

        // Draw the ball in the current row and column.
        const int diameter = qMin(cellWidth, cellHeight) - 12;
        const int x = column * cellWidth + (cellWidth - diameter) / 2;
        const int y = row * cellHeight + (cellHeight - diameter) / 2;

        painter.setBrush(Qt::blue);
        painter.setPen(Qt::NoPen);
        painter.drawEllipse(x, y, diameter, diameter);
    }

private:
    int row = 2;
    int column = 2;
};

BallWindow::BallWindow() {
    setWindowTitle("Ball Grid");
    setAttribute(Qt::WA_DeleteOnClose);

    // This lets the window receive keyboard input.
    setFocusPolicy(Qt::StrongFocus);
    resize(320, 340);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    grid = new BallGridWidget(this);
    QLabel* hint = new QLabel("Use the arrow keys to move the ball", this);
    hint->setAlignment(Qt::AlignCenter);

    mainLayout->addWidget(hint);
    mainLayout->addWidget(grid);
}

void BallWindow::setBallPosition(int row, int column) {
    grid->setBallPosition(row, column);
}
