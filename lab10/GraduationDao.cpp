//
// Created by buksa on 11/26/2025.
//

#include "GraduationDao.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

void GraduationDao::enrollStudents(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Cannot open file: " + filename);
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int id;
        string lastName, firstName;

        if (ss >> id >> lastName >> firstName) {
            students.emplace(id, Student(id, firstName, lastName));
        }
    }
    file.close();
}

void GraduationDao::readGradesSubject(const string& subject, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Cannot open file: " + filename);
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int id;
        double grade;
        char separator;

        if (ss >> id >> separator >> grade) {
            auto it = students.find(id);
            if (it != students.end()) {
                it->second.addGrade(subject, grade);
            }
        }
    }
    file.close();
}

void GraduationDao::computeAverage() {
    for (auto& pair : students) {
        pair.second.computeAverage();
    }
}

int GraduationDao::numEnrolled() const {
    return students.size();
}

int GraduationDao::numPassed() const {
    int passedCount = 0;
    for (const auto& pair : students) {
        const Student& student = pair.second;
        if (student.getGrades().size() >= 6 && student.getAverage() >= 5.0) {
            passedCount++;
        }
    }
    return passedCount;
}

Student GraduationDao::findById(int id) const {
    auto it = students.find(id);
    if (it != students.end()) {
        return (it->second);
    }
    throw out_of_range("Student with ID " + to_string(id) + " not found.");
}

double GraduationDao::getAverageBySubject(const string& subject) const {
    double sum = 0.0;
    int count = 0;
    for (const auto& pair : students) {
        try {
            double grade = pair.second.getGrade(subject);
            sum += grade;
            count++;
        } catch (const out_of_range& e) {
        }
    }
    return count > 0 ? sum / count : 0.0;
}

const map<int, Student>& GraduationDao::getStudents() const {
    return students;
}