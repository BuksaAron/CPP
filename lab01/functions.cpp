//
// Created by buksa.aron on 9/17/2025.
//

#include <cmath>
#include <utility>

int countBits(int number) {
    int count = 0;
    while (number != 0) {
        if  (number % 2 == 1) {
            count++;
        }
        number = number / 2;
    }
    return count;
}

bool setBit(int& number, int order) {
    if (order < 0 || order > 31) {
        return false;
    }
    number |= (1 << order);
    return true;
}

double mean(double array[], int numElements){
    if(numElements == 0){
        return NAN;
    }
    double sum = 0;
    for (int i = 0; i < numElements; i++) {
        sum += array[i];
    }
    return sum / numElements;
}

double stddev(double array[], int numElements){
    if(numElements == 0){
        return NAN;
    }
    double sum = 0.0, mn, sd = 0.0;
    for (int i = 0; i < numElements; i++) {
        sum += array[i];
    }
    mn = sum / numElements;
    for (int i = 0; i < numElements; i++) {
        sd += pow((array[i] - mn), 2);
    }
    return sqrt(sd / numElements);
}

std::pair<double, double> max2(double array[], int numElements) {
    std::pair<double, double> maxnum = {0.0, 0.0};
    if(numElements == 0) {
        maxnum = {NAN, NAN};
        return maxnum;
    }
    for (int i = 0; i < numElements; i++) {
        if (array[i] > maxnum.first) {
            maxnum.second = maxnum.first;
            maxnum.first = array[i];
        }
        if (array[i] < maxnum.first && array[i] > maxnum.second) {
            maxnum.second = array[i];
        }
    }
    return maxnum;
}
