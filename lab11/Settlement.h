//
// Created by buksa on 11/26/2025.
//

#ifndef LAB11_SETTLEMENT_H
#define LAB11_SETTLEMENT_H
#include <string>
using namespace std;
class Settlement {
private:
    string name = "";
    string county = "";
    int population = 0;
    // constructor, getters, setters, inserter operator
public:
    Settlement(string name, string country, int pop);
    Settlement(const Settlement &other);
    string GetName() const;
    string GetCountry() const;
    int GetPopulation() const;
    friend ostream& operator<<(ostream& os, const Settlement& s);
};

#endif //LAB11_SETTLEMENT_H