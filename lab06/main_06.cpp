#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "user.h"
#include "quiz.h"
#include "quizgame.h"
#include "quizitem.h"

using namespace std;

int main() {
    User user1(1, "Teszt Elek");
    Quiz quiz1(1, "It kviz");
    ifstream file("in.txt");
    if (!file.is_open()) {
        cout << "Nem sikerult megnyitni a fajlt!" << endl;
        return 1;
    }

    string line;
    string question;
    vector<string> answers;
    int correctAnswer = -1;
    int id = 1;

    while (getline(file, line)) {
        if (line.empty()) continue;
        if (line[0] == 'Q') {
            if (!question.empty()) {
                QuizItem item(id++, question, answers, correctAnswer - 1);
                quiz1.addItem(item);
                answers.clear();
            }
            question = line.substr(2);
        }
        else if (line[0] == 'A') {
            answers.push_back(line.substr(2));
        }
        else {
            correctAnswer = stoi(line);
        }
    }
    if (!question.empty()) {
        QuizItem item(id++, question, answers, correctAnswer - 1);
        quiz1.addItem(item);
    }

    quiz1.finalize();
    file.close();

    QuizGame game(user1, quiz1);
    game.play();

    user1.displayresult();

    return 0;
}