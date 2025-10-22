//
// Created by buksa on 10/22/2025.
//

#include "user.h"

#include <iostream>
using namespace std;

User::User(int id, const string &name) {
    this->id = id;
    this->name = name;
}

void User::addresult(int quizId, double score) {
    result[quizId] = score;
}

void User::displayresult() const {
    cout << "Eredmenyek: - " << name << endl;
    if (result.empty()) {
        cout << "Nincs meg eredmeny" << endl;
        return;
    }
    for (const pair<int, double>& pair : result) {
        cout << "Kviz: " << pair.first << ": " << pair.second << endl;
    }

}

string User::getName() const {
    return name;
}

int User::getId() const {
    return id;
}
