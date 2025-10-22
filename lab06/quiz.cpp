//
// Created by buksa on 10/22/2025.
//

#include "quiz.h"

Quiz::Quiz(int id, const string &name) {
    this->id = id;
    this->name = name;
    this->isReady = false;
}

void Quiz::addItem(const QuizItem &item) {
    if (getIsReady() == false)
        items.push_back(item);
}

void Quiz::finalize() {
    isReady == true;
}

bool Quiz::getIsReady() const {
    return isReady;
}

const vector<QuizItem> & Quiz::getItem() const {
    return items;
}

int Quiz::getId() const {
    return id;
}

string Quiz::getName() const {
    return name;
}
