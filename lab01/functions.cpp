//
// Created by buksa.aron on 9/17/2025.
//

#include <cmath>
#include <utility>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

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

int countWords(string text) {
    istringstream iss(text);
    string word;
    int count = 0;

    while (iss >> word) {
        count++;
    }

    return count;
}

string code(string text) {
    string result = text;

    for (size_t i = 0; i < result.size(); i++) {
        if (result[i] >= 'a' && result[i] <= 'z') {
            if (result[i] == 'z') {
                result[i] = 'a';
            } else {
                result[i] = result[i] + 1;
            }
        } else if (result[i] >= 'A' && result[i] <= 'Z') {
            if (result[i] == 'Z') {
                result[i] = 'A';
            } else {
                result[i] = result[i] + 1;
            }
        }
    }

    return result;
}

string decode(string text) {
    string result = text;

    for (size_t i = 0; i < result.size(); i++) {
        if (result[i] >= 'a' && result[i] <= 'z') {
            if (result[i] == 'a') {
                result[i] = 'z';
            } else {
                result[i] = result[i] - 1;
            }
        } else if (result[i] >= 'A' && result[i] <= 'Z') {
            if (result[i] == 'A') {
                result[i] = 'Z';
            } else {
                result[i] = result[i] - 1;
            }
        }
    }

    return result;
}

string capitalizeWords(string text) {
    istringstream iss(text);
    string word;
    string result;

    while (iss >> word) {
        // első karakter nagybetű
        if (!word.empty()) {
            word[0] = toupper(word[0]);
        }

        // többi karakter kisbetű
        for (size_t i = 1; i < word.size(); i++) {
            word[i] = tolower(word[i]);
        }

        if (!result.empty()) {
            result += " ";
        }
        result += word;
    }

    return result;
}
