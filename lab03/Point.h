//
// Created by buksa on 10/1/2025.
//

#ifndef LAB3_POINT_H
#define LAB3_POINT_H
#include <iostream>

const int M = 2000;
class Point{
private:
    int x, y;
public:
    Point( int x=0, int y=0);
    int getX() const;
    int getY() const;
    double distanceTo(const Point& point)const;

    void print() const {
        std::cout << "(" << x << ", " << y << ")";
    }
};

#endif //LAB3_POINT_H