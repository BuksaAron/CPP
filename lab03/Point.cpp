//
// Created by buksa on 10/1/2025.
//

#include "Point.h"
#include <cmath>
#include <iostream>
#include <stdexcept>

Point::Point(int x, int y) {
    if (x < 0 || x > M || y < 0 || y > M) {
        throw std::out_of_range("Coordinates must be between 0 and M");
    }
    this->x = x;
    this->y = y;
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

double Point::distanceTo(const Point& point) const {
    int dx = x - point.x;
    int dy = y - point.y;
    return std::sqrt(dx * dx + dy * dy);
}
