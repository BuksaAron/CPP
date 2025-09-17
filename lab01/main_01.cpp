#include <iostream>
#include "hello.h"
#include "functions.h"
#include <cmath>
#include <utility>

using namespace std;

int main() {
    cout << "1 feladat:" << endl;
    for (int i = 0; i <= 127; i++) {
        cout << i << ": " << countBits(i) << endl;
    }
    cout << endl << "2 feladat:" << endl;

    for (int i = 0; i < 35; ++i) {
        int n = 0;
        if(setBit(n, i)) {
        cout<<i<<" ---> " << n <<endl;
    } else {
        cout<<"Impossible operation!" << endl;
    }
    }
    cout << endl << "3 feladat:" << endl;
    double array[] = {1.1, 5.5, 2.2, 3.3, 4.4, 6.6};
    int noe = 6;
    cout << mean(array, noe) << endl;
    cout << endl << "4 feladat:" << endl;
    cout << stddev(array, noe) << endl;
    cout << endl << "5 feladat:" << endl;
    std::pair<double, double> result = max2(array, noe);
    cout << result.first << " " << result.second << endl;
    return 0;
}
