#include <iostream>
#include "hello.h"
#include "functions.h"
#include <cmath>
#include <utility>
#include <sstream>  // stringstream, istringstream, ostringstream
#include <string>

using namespace std;

int main() {
    /*
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
    */
    cout << endl << "2 feladat:" << endl;
    string szoveg1 = "Ez egy pelda szoveg  tobb   szokozzel.";
    cout << "A szavak szama: " << countWords(szoveg1) << endl;
    cout << endl << "3 feladat:" << endl;

    string szoveg2 = "Hello world!";
    cout << "Eredeti: " << szoveg2 << endl;

    string kodolt = code(szoveg2);
    cout << "Kodolt:  " << kodolt << endl;

    string dekodolt = decode(kodolt);
    cout << "Dekodolt:" << dekodolt << endl;

    cout << endl << "4 feladat:" << endl;
    string sor;
    cout << "Adj meg sorokat:" << endl;

    while (true) {
        getline(cin, sor);
        if (sor.empty()) {
            break;
        }
        cout << capitalizeWords(sor) << endl;
    }
    return 0;
}

