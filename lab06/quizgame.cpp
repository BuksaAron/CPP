//
// Created by buksa on 10/22/2025.
//

#include "quizgame.h"
#include <iostream>
#include "user.h"

using namespace std;

QuizGame::QuizGame(User &user, Quiz &quiz) : user_(user), quiz_(quiz) {}

void QuizGame::play() {
    if (!quiz_.getIsReady()) {
        cout << "A kviz meg nincs lezarva!" << endl;
        return;
    }
    const vector<QuizItem> &items = quiz_.getItem();
    int count = 0;
    cout << "\n--- " << quiz_.getName() << " ---\n";
    for (vector<QuizItem>::const_iterator it = items.begin(); it != items.end(); ++it) {
        it->displayQuestions();
        cout << "Valaszod (1-4): ";
        int answer;
        cin >> answer;

        if (it->checkAnswer(answer)) {
            ++count;
        }
    }

    double score = (double)count / items.size() * 100.0;
    cout << "\nEredmény: " << score << "%\n";

    user_.addresult(quiz_.getId(), score);
}
