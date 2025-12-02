#include <iostream>

#include "StudnetServiceImpl.h"

int main() {
    /*StudentService* service = new StudentServiceImpl(&dao);
    cout << "Individual results: " << endl;
    int id = 0;
    while (id !=-1) {
        cout << "Enter ID (-1 for EXIT): ";
        cin >> id;
        if (id ==-1) {
            break;
        }
        if (!service->isEnrolled(id)) {
            cout << "Student id=" << id << " not found" << endl;
            continue;
        }
        cout << "Student id=" << id << " results: " << endl;
        bool passed = service->isPassed(id);
        cout << "\tpassed: " << (passed ? "yes" : "no") << endl;
        if (!passed) {
            continue;
        }
        vector<string> subjects = service->getSubjects(id);
        for (int i = 0; i < subjects.size(); ++i) {
            cout << "\t" << subjects[i] << ": " <<
            service->getResultBySubject(id, subjects[i]) << endl;
        }
        cout << "\taverage: " << service->getAverage(id) << endl;
    }
    delete service;*/
}