#include <iostream>
#include "Point.h"
#include "utils.h"
using namespace std;

int main(int argc, char** argv) {
    Point p1(2,3);
    cout<<"p1( "<<p1.getX()<<","<<p1.getY()<<")"<<endl;
    Point p2(100, 200);
    cout<<"p2( "<<p2.getX()<<","<<p2.getY()<<")"<<endl;
    Point * pp1 = new Point(300, 400);
    Point * pp2 = new Point(500, 1000);
    cout<<"pp1( "<<pp1->getX()<<","<<pp1->getY()<<")"<<endl;
    cout<<"pp2( "<<pp2->getX()<<","<<pp2->getY()<<")"<<endl;
    cout << "Kiirato metodus teszt: " << endl;
    p1.print();
    p2.print();
    pp1->print();
    pp2->print();

    cout << "p1 es p2 tavolsaga: " << distance(p1, p2) << endl;
    cout << "pp1 ss pp2 tavolsaga: " << distance(*pp1, *pp2) << endl;

    Point a(0,0), b(0,2), c(2,0), d(2,2);
    cout << "Negyzet ellenorzes: ";
    if (isSquare(a, b, c, d))
        cout << "Kocka" << endl;
    else
        cout << "Nem kocka" << endl;

    cout << endl << "Teszt fajlbol (points.txt):" << endl;
    testIsSquare("points.txt");
    delete pp1;
    delete pp2;

    pair<Point, Point> closest = closestPoints(array, 100);

    return 0;
}