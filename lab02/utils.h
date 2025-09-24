//
// Created by buksa on 9/24/2025.
//

#ifndef CPP_2024_UTILS_H
#define CPP_2024_UTILS_H
double distance(const Point& a, const Point& b);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);
void testIsSquare(const char * filename);
Point* createArray(int numPoints);
void printArray(Point* points, int numPoints);

std::pair<Point, Point> closestPoints(Point* points, int numPoints);

std::pair<Point, Point> farthestPoints(Point* points, int numPoints);
void sortPoints(Point* points, int numPoints);
#endif //CPP_2024_UTILS_H