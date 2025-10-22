//
// Created by buksa on 10/22/2025.
//

#ifndef LAB6_QUIZITEM_H
#define LAB6_QUIZITEM_H
#include <string>
#include <vector>
using namespace std;

class QuizItem {
private:
    int id;
    string questions;
    vector<string> answers;
    int correctAnswer;

public:
    QuizItem(int id, const string& question, const vector<string>& answers, int correctAnswer);
    int getId() const;
    void displayQuestions() const;
    bool checkAnswer(int answer) const;
};

#endif //LAB6_QUIZITEM_H