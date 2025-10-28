//
// Created by buksa on 10/22/2025.
//

#ifndef LAB6_QUIZGAME_H
#define LAB6_QUIZGAME_H
#include "user.h"
#include "quiz.h"
using namespace std;

class QuizGame {
private:
    User& user_;
    Quiz& quiz_;

public:
    QuizGame(User& user, Quiz& quiz);
    void play();
};
#endif //LAB6_QUIZGAME_H