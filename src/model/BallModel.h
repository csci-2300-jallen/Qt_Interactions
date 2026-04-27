#pragma once

class BallModel {
public:
    int getRow() const;
    int getColumn() const;

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

private:
    static const int gridSize = 5;
    int row = 2;
    int column = 2;
};
