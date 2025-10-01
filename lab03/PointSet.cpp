//
// Created by buksa on 10/1/2025.
//

#include "PointSet.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <ctime>
using namespace std;

PointSet::PointSet(int n) {
    this->n = n;
    srand(time(0));
    while ((int)points.size() < n) {
        int x = rand() % (M + 1);
        int y = rand() % (M + 1);
        Point p(x, y);

        bool unique = true;
        for (int i = 0; i < (int)points.size(); i++) {
            if (p.getX() == points[i].getX() && p.getY() == points[i].getY()) {
                unique = false;
                break;
            }
        }
        if (unique) {
            points.push_back(p);
        }
    }

    computeDistances();
}

void PointSet::computeDistances() {
    distances.clear();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            distances.push_back(points[i].distanceTo(points[j]));
        }
    }
}

double PointSet::maxDistance() const {
    return  *max_element(distances.begin(), distances.end());
}

double PointSet::minDistance() const {
    return *min_element(distances.begin(), distances.end());
}

int PointSet::numDistances() const {
    return (int)distances.size();
}

void PointSet::printPoints() const {
    for (int i = 0; i < (int)points.size(); i++) {
        points[i].print();
        cout << " ";
    }
    cout << endl;
}

void PointSet::printDistances() const {
    for (int i = 0; i < (int)distances.size(); i++) {
        cout << fixed << setprecision(2) << distances[i] << " ";
    }
    cout << endl;
}

void PointSet::sortPointsX() {
    sort(points.begin(), points.end(), [](const Point &a, const Point &b) {return a.getX() < b.getX();});
}

void PointSet::sortPointsY() {
    sort(points.begin(), points.end(), [](const Point &a, const Point &b) {return a.getY() < b.getY();});
}

void PointSet::sortDistances() {
    sort(distances.begin(), distances.end());
}

int PointSet::numDistinctDistances() {
    set<double> s(distances.begin(), distances.end());
    return (int)s.size();
}
