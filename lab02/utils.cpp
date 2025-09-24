//
// Created by buksa on 9/24/2025.
//

#include <fstream>
#include <iostream>

#include "Point.h"

#include "utils.h"

#include <algorithm>
#include <cmath>
#include <random>

using namespace std;

double distance(const Point& a, const Point& b) {
    return std::sqrt((a.getX() - b.getX()) * (a.getX() - b.getX()) +
                     (a.getY() - b.getY()) * (a.getY() - b.getY()));
}

bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d) {
    double d1 = distance(a,b);
    double d2 = distance(a,c);
    double d3 = distance(a,d);
    double d4 = distance(b,c);
    double d5 = distance(b,d);
    double d6 = distance(c,d);
}


void testIsSquare(const char * filename) {
    std::ifstream f(filename);
    if (!f.is_open()) {
        exit(404);
    }
    for (int i = 0; i < 8; i++) {
        int x1, x2, x3, x4, y1, y2, y3, y4;
        while (f >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
            Point a(x1, y1), b(x2, y2), c(x3, y3), d(x4, y4);

            cout << "Pontok: " << endl;
            a.print(); b.print(); c.print(); d.print();

            if (isSquare(a, b, c, d))
                cout << "Kocka" << endl;
            else
                cout << "Nem kocka" << endl;

            cout << "-------------------" << endl;
        }

        f.close();
    }
}

Point* createArray(int numPoints) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);
    Point *array = new Point[numPoints];
    int x,y;
    for (int i = 0; i < numPoints; i++) {
        int x = dist(gen);
        int y = dist(gen);
        array[i] = Point(x, y);
    }
    return array;
}


void printArray(Point* points, int numPoints) {
    for (int i = 0; i < numPoints; i++) {
        std::cout << i << ": ";
        points[i].print();
    }
}

pair<Point, Point> closestPoints(Point* points, int numPoints) {
    int minimum = INT_MAX;
    Point x, y;
    for (int i = 0; i < numPoints; ++i) {
        for (int j = i + 1; j < numPoints; ++j) {
            if (distance(points[i], points[j]) < minimum) {
                minimum = distance(points[i], points[j]);
                x = points[i];
                y = points[j];
            }
        }
    }
    return make_pair(x, y);
}

pair<Point, Point> farthestPoints(Point* points, int numPoints) {
    int maximum = INT_MIN;
    Point x, y;
    for (int i = 0; i < numPoints; ++i) {
        for (int j = i + 1; j < numPoints; ++j) {
            if (distance(points[i], points[j]) > maximum) {
                maximum = distance(points[i], points[j]);
                x = points[i];
                y = points[j];
            }
        }
    }
    return make_pair(x, y);
}

void sortPoints(Point* points, int numPoints) {
    sort(points, points+numPoints, [](const Point &a,const Point &b){return a.getX() < b.getX();});
}
