//
// Created by buksa on 10/22/2025.
//

#include "quizitem.h"
#include <iostream>

QuizItem::QuizItem(int id, const string &question, const vector<string> &answers, int correctAnswer) {
    this->id = id;
    this->questions = question;
    this->answers = answers;
    this->correctAnswer = correctAnswer;
}

int QuizItem::getId() const {
    return this->id;
}

void QuizItem::displayQuestions() const {
    cout << questions << endl;
    for (int i = 0; i < answers.size(); ++i) {
        cout << " " << i + 1 << " " << answers[i] << endl;
    }
}

bool QuizItem::checkAnswer(int answerIndex) const {
    return (answerIndex - 1) == correctAnswer;
}


