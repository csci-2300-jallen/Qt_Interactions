#include "model/BallModel.h"

int BallModel::getRow() const {
    return row;
}

int BallModel::getColumn() const {
    return column;
}

void BallModel::moveUp() {
    if (row > 0) {
        row--;
    }
}

void BallModel::moveDown() {
    if (row < gridSize - 1) {
        row++;
    }
}

void BallModel::moveLeft() {
    if (column > 0) {
        column--;
    }
}

void BallModel::moveRight() {
    if (column < gridSize - 1) {
        column++;
    }
}
