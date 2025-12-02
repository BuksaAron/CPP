//
// Created by buksa on 11/26/2025.
//

#include "Student.h"
#include <sstream>
#include <stdexcept>

// Konstruktor
Student::Student(int id, const std::string &firstName, const std::string &lastName)
    : id(id), firstName(firstName), lastName(lastName), average(0.0) {}

// Getterek
int Student::getId() const { return id; }

void Student::setId(int id) {
    this->id = id;
}

const string & Student::getFirstName() const {
    return firstName;
}

const string & Student::getLastName() const {
    return lastName;
}


void Student::addGrade(const std::string& subject, double grade) {
    grades[subject] = grade;
}

// Jegy lekérdezése
double Student::getGrade(const std::string& subject) const {
    if (grades.find(subject) == grades.end()) {
        throw std::out_of_range("Grade for subject " + subject + " not found for student " + std::to_string(id));
    }
    return grades.at(subject);
}

const std::map<std::string, double>& Student::getGrades() const {
    return grades;
}

double Student::getAverage() const {
    return average;
}

void Student::computeAverage() {
    if (grades.empty()) {
        average = 0.0;
        return;
    }
    double sum = 0.0;
    for (const auto& pair : grades) {
        sum += pair.second;
    }
    average = sum / grades.size();
}

ostream& operator<<(std::ostream& os, const Student& student) {
    os << "ID: " << student.id << ", Name: " << student.lastName << " " << student.firstName
       << ", Avg: " << student.average << ", Grades: {";
    bool first = true;
    for (const auto& pair : student.grades) {
        if (!first) os << ", ";
        os << pair.first << ": " << pair.second;
        first = false;
    }
    os << "}";
    return os;
}