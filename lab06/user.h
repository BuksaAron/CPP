//
// Created by buksa on 10/22/2025.
//

#ifndef LAB6_USER_H
#define LAB6_USER_H
#include <map>
#include <string>


using namespace std;

class User {
private:
    int id;
    string name;
    map<int, double> result;
public:
    User(int id, const string& name);
    void addresult(int quizId, double score);
    //void displayresult() const;
    string getName() const;
    int getId() const;

};
#endif //LAB6_USER_H