//
// Created by buksa on 11/26/2025.
//
#include <iostream>
#include "Settlement.h"

Settlement::Settlement(string name, string country, int pop) {
    this->name = name;
    this->county = country;
    this->population = pop;
}

Settlement::Settlement(const Settlement &other) {
    this->name = other.name;
    this->county = other.county;
    this->population = other.population;
}

string Settlement::GetName() const {
    return name;
}

string Settlement::GetCountry() const {
    return county;
}

int Settlement::GetPopulation() const {
    return population;
}

ostream & operator<<(ostream &os, const Settlement &s) {
    os << s.name << " " << s.county << " " << s.population << endl;
    return os;
}
