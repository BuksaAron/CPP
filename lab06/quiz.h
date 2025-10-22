//
// Created by buksa on 10/22/2025.
//

#ifndef LAB6_QUIZ_H
#define LAB6_QUIZ_H
#include <string>
#include <vector>

#include "quizitem.h"

using namespace std;

class Quiz {
private:
    int id;
    string name;
    vector<QuizItem> items;
    bool isReady;

public:
    Quiz(int id, const string& name);

    void addItem(const QuizItem& item);
    void finalize();
    bool getIsReady() const;
    const vector<QuizItem>& getItem() const;
    int getId() const;
    string getName() const;
};

#endif //LAB6_QUIZ_H